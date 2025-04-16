#include "InputChannelTab.h"

InputChannelTab::InputChannelTab(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *pageLayout = new QVBoxLayout();
    
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    QPushButton *addButton = new QPushButton("Add Channel");
    addButton->setMinimumWidth(100);
    addButton->setMaximumWidth(150);
    connect(addButton, &QPushButton::clicked, this, &InputChannelTab::addChannel);
    buttonLayout->addWidget(addButton);

    QPushButton *deleteButton = new QPushButton("Delete Channel");
    deleteButton->setMinimumWidth(100);
    deleteButton->setMaximumWidth(150);
    connect(deleteButton, &QPushButton::clicked, this, &InputChannelTab::deleteChannel);
    buttonLayout->addWidget(deleteButton);

    buttonLayout->setAlignment(Qt::AlignLeft);

    pageLayout->addLayout(buttonLayout);

    QGridLayout *channelDataLayout = new QGridLayout();

    channelList = new QListWidget();
    connect(channelList, &QListWidget::itemClicked, this, [this]() {
        QListWidgetItem *clickedItem = channelList->currentItem();
        if(clickedItem) {
            ChannelListWidgetItem* clickedListItem = clickedItem->data(Qt::UserRole).value<ChannelListWidgetItem*>();

            instantiateChannelInformationPanel(clickedListItem);

            connect(channelInformationPanel->infoWidget, &ChannelInfoWidget::valueChanged, this, [this](QString rangeMin, 
                                                                                                        QString rangeMax, 
                                                                                                        QString channelName) {
                QListWidgetItem* updatedListItem = channelList->currentItem();
                if(updatedListItem) {
                    ChannelListWidgetItem *listItem = updatedListItem->data(Qt::UserRole).value<ChannelListWidgetItem*>();
                    listItem->setChannelName(channelName);
                    listItem->setSliderMaximumValue(rangeMax.toInt());
                    listItem->setSliderMinimumValue(rangeMin.toInt());
                }
            });


            connect(channelInformationPanel->configWidget, &CommsConfigWidget::valueChanged, this, [this](QString ipAddress, 
                                                                                                          QString portNumber, 
                                                                                                          QString bufferSize) {
                QListWidgetItem* updatedListItem = channelList->currentItem();
                if(updatedListItem) {
                    ChannelListWidgetItem *listItem = updatedListItem->data(Qt::UserRole).value<ChannelListWidgetItem*>();
                    listItem->setChannelIpAddress(ipAddress);
                    listItem->setChannelPortNumber(portNumber.toInt());
                    listItem->setChannelBufferSize(bufferSize.toInt());
                }
            });
        }
    });

    connect(channelList, &QListWidget::currentRowChanged, this, [this]() {
        QListWidgetItem *clickedItem = channelList->currentItem();
        if(clickedItem) {
            ChannelListWidgetItem* clickedListItem = clickedItem->data(Qt::UserRole).value<ChannelListWidgetItem*>();
            instantiateChannelInformationPanel(clickedListItem);
        }
    });
    
    channelDataLayout->addWidget(channelList, 0, 0, 1, 1);
    channelInformationPanel = new ChannelInformationPanel();
    channelDataLayout->addWidget(channelInformationPanel, 0, 1, -1, 1);
    pageLayout->addLayout(channelDataLayout);

    setLayout(pageLayout);
};

void InputChannelTab::addChannel() {
    channelListWidgetItem = new ChannelListWidgetItem();

    QListWidgetItem *item = new QListWidgetItem(channelList);
    item->setSizeHint(channelListWidgetItem->sizeHint());
    channelList->addItem(item);
    item->setData(Qt::UserRole, QVariant::fromValue<ChannelListWidgetItem*>(channelListWidgetItem));
    channelList->setItemWidget(item, channelListWidgetItem);
}

void InputChannelTab::deleteChannel() {
    QListWidgetItem *listItem = channelList->takeItem(channelList->currentRow());
    delete listItem;
}

void InputChannelTab::instantiateChannelInformationPanel(ChannelListWidgetItem *channelListWidgetItem) {
    channelInformationPanel->setChannelInformation(channelListWidgetItem);
}