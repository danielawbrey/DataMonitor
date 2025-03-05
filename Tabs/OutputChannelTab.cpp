#include "OutputChannelTab.h"

OutputChannelTab::OutputChannelTab(QWidget *parent): QWidget(parent) {
    QVBoxLayout *pageLayout = new QVBoxLayout();
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    QPushButton *addButton = new QPushButton("Add Channel");
    addButton->setMinimumWidth(100);
    addButton->setMaximumWidth(150);
    connect(addButton, &QPushButton::clicked, this, &OutputChannelTab::addChannel);
    buttonLayout->addWidget(addButton, 0, Qt::AlignLeft);
    pageLayout->addWidget(addButton);
    
    QGridLayout *channelDataLayout = new QGridLayout();

    channelList = new QListWidget();
    connect(channelList, &QListWidget::itemClicked, this, [this](QListWidgetItem *clickedItem) {
        if (clickedItem) {
            instantiateChannelInformationPanel(channelListWidgetItem);
        }
    });
    channelDataLayout->addWidget(channelList, 0,0,1,1);

    channelInformationPanel = new ChannelInformationPanel();
    channelInformationPanel->setHidden(true);
    // channelInformationPanel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    channelInformationPanelHidden = true;
    channelDataLayout->addWidget(channelInformationPanel,0,1,-1,1);

    // taskbar = new Taskbar();
    // taskbar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    // channelDataLayout->addWidget(taskbar, 0, Qt::AlignRight | Qt::AlignTop);

    pageLayout->addLayout(channelDataLayout);

    setLayout(pageLayout);
};

void OutputChannelTab::addChannel() {
    channelListWidgetItem = new ChannelListWidgetItem("Lorem Ipsum");
    connect(channelListWidgetItem->deleteButton, &QPushButton::clicked, this, [this]() {
        deleteChannel(channelListWidgetItem->getChannelName());
    });
    QListWidgetItem *item = new QListWidgetItem(channelList);
    item->setSizeHint(channelListWidgetItem->sizeHint());
    channelList->addItem(item);
    channelList->setItemWidget(item, channelListWidgetItem);
}

void OutputChannelTab::deleteChannel(QString channelName) {
    std::cout << channelName.toStdString() << std::endl;
}

void OutputChannelTab::instantiateChannelInformationPanel(ChannelListWidgetItem *channelListWidgetItem) {
    channelInformationPanelHidden = !channelInformationPanelHidden;
    // channelInformationPanel->setChannelInformation(channelListWidgetItem);
    channelInformationPanel->setHidden(false);
}