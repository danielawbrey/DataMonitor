#include "ChannelInformationPanel.h"

ChannelInformationPanel::ChannelInformationPanel(QFrame *parent) : QFrame(parent) {
    QGridLayout *mainLayout = new QGridLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);

    stackWidget = new QStackedWidget();
    infoWidget = new ChannelInfoWidget(); 
    stackWidget->addWidget(infoWidget);
    configWidget = new CommsConfigWidget();
    stackWidget->addWidget(configWidget);
    dataWidget = new CommsDataWidget();
    stackWidget->addWidget(dataWidget);
    mainLayout->addWidget(stackWidget, 0, 0, 1, 1, Qt::AlignCenter | Qt::AlignTop);

    stackWidget->setCurrentIndex(0);

    taskbar = new Taskbar();
    connect(taskbar->channelInfoButton, &QPushButton::clicked, this, &ChannelInformationPanel::showChannelInfo);
    connect(taskbar->commsConfigButton, &QPushButton::clicked, this, &ChannelInformationPanel::showCommsConfig);
    connect(taskbar->commsDataButton, &QPushButton::clicked, this, &ChannelInformationPanel::showCommsData);
    connect(taskbar->hideButton, &QPushButton::clicked, this, &ChannelInformationPanel::hideTab);
    mainLayout->addWidget(taskbar, 0, 1, 1, -1);

    setFrameShape(QFrame::Box);
    setLineWidth(1); 
    setMaximumWidth(375);

    setLayout(mainLayout);
};

void ChannelInformationPanel::hideTab() {
    dataPanelHidden = !dataPanelHidden;
    stackWidget->setHidden(dataPanelHidden);
}

void ChannelInformationPanel::showChannelInfo() {
    stackWidget->setCurrentIndex(0);
}

void ChannelInformationPanel::showCommsConfig() {
    stackWidget->setCurrentIndex(1);
}

void ChannelInformationPanel::showCommsData() {
    stackWidget->setCurrentIndex(2);
}

void ChannelInformationPanel::setChannelInformation(ChannelListWidgetItem *channelListWidgetItem) {
    infoWidget->setPanelData(channelListWidgetItem->getSliderMinimumValue(), 
                             channelListWidgetItem->getSliderMaximumValue(), 
                             channelListWidgetItem->getChannelName());
                             
    configWidget->setPanelData(channelListWidgetItem->getIpAddress(),
                               channelListWidgetItem->getPortNumber(),
                               channelListWidgetItem->getBufferSize());
}