#include "ChannelInformationPanel.h"

ChannelInformationPanel::ChannelInformationPanel(QFrame *parent) : QFrame(parent) {
    QGridLayout *mainLayout = new QGridLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);

    // panelDataContainer = new PanelDataContainer();
    // mainLayout->addWidget(panelDataContainer, 0, 0, 1, 1, Qt::AlignCenter | Qt::AlignTop);

    stackWidget = new QStackedWidget();

    ChannelInfoWidget *infoWidget = new ChannelInfoWidget(); 
    stackWidget->addWidget(infoWidget);
    CommsConfigWidget *configWidget = new CommsConfigWidget();
    stackWidget->addWidget(configWidget);
    CommsDataWidget *dataWidget = new CommsDataWidget();
    stackWidget->addWidget(dataWidget);
    mainLayout->addWidget(stackWidget, 0, 0, 1, 1, Qt::AlignCenter | Qt::AlignTop);

    stackWidget->setCurrentIndex(0);

    taskbar = new Taskbar();
    connect(taskbar->channelInfoButton, &QPushButton::clicked, this, &ChannelInformationPanel::showChannelInfo);
    connect(taskbar->commsConfigButton, &QPushButton::clicked, this, &ChannelInformationPanel::showCommsConfig);
    connect(taskbar->commsDataButton, &QPushButton::clicked, this, &ChannelInformationPanel::showCommsData);
    // connect(taskbar->hideButton, &QPushButton::clicked, this, &ChannelInformationPanel::hideTab);
    mainLayout->addWidget(taskbar, 0, 1, 1, -1);

    setFrameShape(QFrame::Box);
    setLineWidth(1); 
    setMinimumWidth(250);
    setMaximumWidth(375);
    setLayout(mainLayout);
};

// void ChannelInformationPanel::hideTab() {
//     dataPanelHidden = !dataPanelHidden;
//     panelDataContainer->setHidden(dataPanelHidden);
// }

void ChannelInformationPanel::showChannelInfo() {
    // switchPanelDisplay(1);
    stackWidget->setCurrentIndex(0);
}

void ChannelInformationPanel::showCommsConfig() {
    // switchPanelDisplay(2);
    stackWidget->setCurrentIndex(1);
}

void ChannelInformationPanel::showCommsData() {
    // switchPanelDisplay(3);
    stackWidget->setCurrentIndex(2);
}

// void ChannelInformationPanel::switchPanelDisplay(int channelDisplayType) {
//     switch(channelDisplayType) {
//         case channelInformation:
//             panelDataContainer->showChannelInfo();
//             break;
//         case channelMetrics:
//             panelDataContainer->showCommsData();
//             break;
//         case channelProperties:
//             panelDataContainer->showCommsConfig();
//             break;
//     }
// }

// void ChannelInformationPanel::setChannelInformation(ChannelListWidgetItem *channelListWidgetItem) {
//     panelDataContainer->setPanelData(channelListWidgetItem->getSliderMinimumValue(), 
//                                      channelListWidgetItem->getSliderMaximumValue(), 
//                                      channelListWidgetItem->getChannelName());
// }