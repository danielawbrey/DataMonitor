#include "./Tabs/InputChannelTab.h"

#include <tinyxml2/tinyxml2.h>

#include <QApplication>
#include <QWidget>
#include <QTabWidget>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QFile>
#include <QString>
#include <QMessageBox>
#include <QStandardPaths>
#include <QListWidget>

class MainWindow: public QMainWindow {
    public:
        void loadProfile() {
            QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
            QString defaultFile = desktopPath + "/profile.xml";
            QString fileName = QFileDialog::getOpenFileName(this, "Select Profile", defaultFile, "XML Files (*.xml);;All Files (*)");
            if(!fileName.isEmpty()) {
                QFile file(fileName);
                if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                    std::string testFile = fileName.toStdString();
                    
                    tinyxml2::XMLDocument doc;
                    tinyxml2::XMLError result = doc.LoadFile(testFile.c_str());
                
                    if (result == tinyxml2::XML_SUCCESS) {
                        std::cout << "XML file loaded successfully.\n";
                    } else {
                        std::cerr << "Failed to load XML file. Error code: " << result << "\n";
                    }

                    tinyxml2::XMLElement* root = doc.FirstChildElement();
                    if(root == NULL) {
                        std::cerr << "Failed to load file: No root element." << std::endl;
                        doc.Clear();
                    }

                    std::string rootElement = root->Value();
                    if(rootElement != "channels") {
                        std::cerr << "Failed to load file: No root element." << std::endl;
                        doc.Clear();
                    }

                    for(tinyxml2::XMLElement* xmlElement = root->FirstChildElement(); xmlElement != NULL; xmlElement = xmlElement->NextSiblingElement()) {
                        std::string name, minimum, maximum, ipAddress, port, bufferSize, selectionIndex;
                        
                        for(tinyxml2::XMLElement* xmlSubElement = xmlElement->FirstChildElement(); xmlSubElement != NULL; xmlSubElement = xmlSubElement->NextSiblingElement()) {
                            std::string elementName = xmlSubElement->Value();

                            if(elementName == "InfoWidget") {
                                for(tinyxml2::XMLElement* infoWidgetElement = xmlSubElement->FirstChildElement(); infoWidgetElement != NULL; infoWidgetElement = infoWidgetElement->NextSiblingElement()) {
                                    std::string infoWidgetElementName = infoWidgetElement->Value();

                                    if(infoWidgetElementName == "name") {
                                        name = infoWidgetElement->GetText();
                                    }

                                    if(infoWidgetElementName == "minimum") {
                                        minimum = infoWidgetElement->GetText();
                                    }

                                    if(infoWidgetElementName == "maximum") {
                                        maximum = infoWidgetElement->GetText();
                                    }
                                }
                            }

                            if(elementName == "CommsWidget") {
                                for(tinyxml2::XMLElement* commsWidgetElement = xmlSubElement->FirstChildElement(); commsWidgetElement != NULL; commsWidgetElement = commsWidgetElement->NextSiblingElement()) {
                                    std::string commsWidgetElementName = commsWidgetElement->Value();

                                    if(commsWidgetElementName == "ipAddress") {
                                        ipAddress = commsWidgetElement->GetText();
                                    }

                                    if(commsWidgetElementName == "port") {
                                        port = commsWidgetElement->GetText();
                                    }

                                    if(commsWidgetElementName == "bufferSize") {
                                        bufferSize = commsWidgetElement->GetText();
                                    }

                                    if(commsWidgetElementName == "selectionIndex") {
                                        selectionIndex = commsWidgetElement->GetText();
                                    }
                                }
                            }
                        }

                        // Construct channel list widget item and add it to the listwidget
                        std::cout << name << " " << minimum << " " << maximum << " " << ipAddress << " " << port << " " << bufferSize << " " << selectionIndex << std::endl;

                    }
                }
            }
        }

        void saveProfile() {
            QString fileName = QFileDialog::getSaveFileName(nullptr, "Select File");
        }

        void saveProfileAs() {
            QString fileName = QFileDialog::getSaveFileName(nullptr, "Select File");
        }

        void newProfile(InputChannelTab *inputChannelTab) {
            QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
            QString defaultFile = desktopPath + "/profile.xml";
            QString fileName = QFileDialog::getSaveFileName(this, "Save Profile", defaultFile, "XML Files (*.xml);;All Files (*)");
            if(!fileName.isEmpty()) {
                QFile file(fileName);
                if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    std::string testFile = fileName.toStdString();

                    tinyxml2::XMLDocument doc;

                    tinyxml2::XMLDeclaration* declaration = doc.NewDeclaration(R"(xml version="1.0" encoding="UTF-8")");
                    doc.InsertFirstChild(declaration);
                
                    tinyxml2::XMLElement* root = doc.NewElement("channels");
                    doc.InsertEndChild(root);
                    
                    QListWidget* listWidget = inputChannelTab->channelList;
                    for (int i = 0; i < listWidget->count(); ++i) {
                        QListWidgetItem* currentItem = listWidget->item(i);
                        // QListWidgetItem* updatedListItem = channelList->currentItem();
                        if(currentItem) {
                            ChannelListWidgetItem *listItem = currentItem->data(Qt::UserRole).value<ChannelListWidgetItem*>();

                            tinyxml2::XMLElement* channelElement = doc.NewElement("channel");

                            tinyxml2::XMLElement* infoWidgetElement = doc.NewElement("InfoWidget");
    
                            tinyxml2::XMLElement* nameElement = doc.NewElement("name");
                            const char* channelName = listItem->getChannelName().toStdString().c_str(); 
                            nameElement->SetText(channelName);
                            infoWidgetElement->InsertEndChild(nameElement);

                            tinyxml2::XMLElement* sliderMinElement = doc.NewElement("minimum");
                            int sliderMin = listItem->getSliderMinimumValue(); 
                            sliderMinElement->SetText(sliderMin);
                            infoWidgetElement->InsertEndChild(sliderMinElement);

                            tinyxml2::XMLElement* sliderMaxElement = doc.NewElement("maximum");
                            int sliderMax = listItem->getSliderMaximumValue(); 
                            sliderMaxElement->SetText(sliderMax);
                            infoWidgetElement->InsertEndChild(sliderMaxElement);

                            channelElement->InsertEndChild(infoWidgetElement);

                            tinyxml2::XMLElement* commsWidgetElement = doc.NewElement("CommsWidget");

                            tinyxml2::XMLElement* ipAddressElement = doc.NewElement("ipAddress");
                            const char* ipAddress = listItem->getIpAddress().toStdString().c_str(); 
                            ipAddressElement->SetText(ipAddress);
                            commsWidgetElement->InsertEndChild(ipAddressElement);

                            tinyxml2::XMLElement* portElement = doc.NewElement("port");
                            int port = listItem->getPortNumber(); 
                            portElement->SetText(port);
                            commsWidgetElement->InsertEndChild(portElement);

                            tinyxml2::XMLElement* bufferSizeElement = doc.NewElement("bufferSize");
                            int bufferSize = listItem->getBufferSize(); 
                            bufferSizeElement->SetText(bufferSize);
                            commsWidgetElement->InsertEndChild(bufferSizeElement);

                            tinyxml2::XMLElement* protocolElement = doc.NewElement("selectionIndex");
                            int protocolSelectionIndex = listItem->getProtocolSelectionIndex(); 
                            protocolElement->SetText(protocolSelectionIndex);
                            commsWidgetElement->InsertEndChild(protocolElement);

                            channelElement->InsertEndChild(commsWidgetElement);

                            root->InsertEndChild(channelElement);
                        }
                    }
 
                    tinyxml2::XMLError result = doc.SaveFile(testFile.c_str());
                
                    if (result == tinyxml2::XML_SUCCESS) {
                        std::cout << "XML file saved successfully.\n";
                    } else {
                        std::cerr << "Failed to save XML file. Error code: " << result << "\n";
                    }

                } else {
                    QMessageBox::warning(this, "Error", "Failed to save the file.");
                }
            }
        }

        MainWindow(QWidget *parent = nullptr): QMainWindow(parent) {
            QMainWindow mainWindow;

            InputChannelTab *inputChannelTab  = new InputChannelTab();

            QMenuBar *menuBar = new QMenuBar();
            QMenu *profileMenu = menuBar->addMenu(tr("&Profile"));
            QAction *newProfileAction = new QAction(tr("&New Profile"), this);
            // connect(newProfileAction, &QAction::triggered, this, &MainWindow::newProfile);
            connect(newProfileAction, &QAction::triggered, this, [this, inputChannelTab]() {
                newProfile(inputChannelTab);
            });
            profileMenu->addAction(newProfileAction);
            QAction *loadProfileAction = new QAction(tr("&Load Profile"), this);
            connect(loadProfileAction, &QAction::triggered, this, &MainWindow::loadProfile);
            profileMenu->addAction(loadProfileAction);
            setMenuBar(menuBar);

            QTabWidget *tabWidget = new QTabWidget();
            tabWidget->addTab(inputChannelTab, "Channels");
            this->setCentralWidget(tabWidget);

            QWidget *centralWidget = new QWidget();

            QVBoxLayout *layout = new QVBoxLayout();
            layout->addWidget(tabWidget);
            layout->setContentsMargins(5, 10, 5, 10);
            centralWidget->setLayout(layout);
            this->setCentralWidget(centralWidget);            

            this->setMinimumSize(960, 540);
            this->resize(1920, 1080);
            // this->setContentsMargins(5, 5, 5, 5);
            this->setWindowTitle("Channel List");
            this->showMaximized();
        }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}