#include "./Tabs/InputChannelTab.h"

#include <QApplication>
#include <QWidget>
#include <QTabWidget>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QString>

class MainWindow: public QMainWindow {
    public:
        void loadProfile() {
            QString fileName = QFileDialog::getOpenFileName(nullptr, "Select File");
        }

        void saveProfile() {
            QString fileName = QFileDialog::getSaveFileName(nullptr, "Select File");
        }

        void saveProfileAs() {
            QString fileName = QFileDialog::getSaveFileName(nullptr, "Select File");
        }

        void newProfile() {
            QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "/home/Desktop/profile.xml", tr("Profiles (*.xml)"));
        }

        MainWindow(QWidget *parent = nullptr): QMainWindow(parent) {
            QMainWindow mainWindow;

            QMenuBar *menuBar = new QMenuBar();
            QMenu *profileMenu = menuBar->addMenu(tr("&Profile"));
            QAction *newProfileAction = new QAction(tr("&New Profile"), this);
            connect(newProfileAction, &QAction::triggered, this, &MainWindow::newProfile);
            profileMenu->addAction(newProfileAction);
            QAction *loadProfileAction = new QAction(tr("&Load Profile"), this);
            connect(loadProfileAction, &QAction::triggered, this, &MainWindow::loadProfile);
            profileMenu->addAction(loadProfileAction);
            setMenuBar(menuBar);

            QTabWidget *tabWidget = new QTabWidget();
            InputChannelTab *inputChannelTab  = new InputChannelTab();
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