#include "OutputChannelTab.h"

OutputChannelTab::OutputChannelTab(QWidget *parent): QWidget(parent) {
    QVBoxLayout *pageLayout = new QVBoxLayout();

    QPushButton *addButton = new QPushButton("Add Channel");
    addButton->setMinimumWidth(100);
    addButton->setMaximumWidth(150);
    connect(addButton, &QPushButton::clicked, this, &OutputChannelTab::addChannel);
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
    channelDataLayout->addWidget(channelInformationPanel,0,1,-1,1);

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
    channelInformationPanel->setHidden(false);
}