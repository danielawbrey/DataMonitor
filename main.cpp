#include "./Tabs/InputChannelTab.h"
#include "./Tabs/OutputChannelTab.h"

#include <QApplication>
#include <QWidget>
#include <QTabWidget>
#include <QGridLayout>
#include <QMainWindow>
#include <QPushButton>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QMainWindow window;
    window.setMinimumSize(960, 540);
    window.resize(1920,1080);
    window.setWindowTitle("Channel List");
    window.showMaximized();

    QTabWidget *tabWidget = new QTabWidget();
    InputChannelTab *inputChannelTab  = new InputChannelTab();
    tabWidget->addTab(inputChannelTab, "Input Channel");
    OutputChannelTab *outputChannelTab = new OutputChannelTab();
    tabWidget->addTab(outputChannelTab, "Output Channel");
    window.setCentralWidget(tabWidget);

    return app.exec();
}