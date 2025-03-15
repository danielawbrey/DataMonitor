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
    connect(channelList, &QListWidget::itemClicked, this, [this]() {
        QListWidgetItem *clickedItem = channelList->currentItem();
        if(clickedItem) {
            ChannelListWidgetItem* clickedListItem = clickedItem->data(Qt::UserRole).value<ChannelListWidgetItem*>();
            instantiateChannelInformationPanel(clickedListItem);

            connect(channelInformationPanel->panelDataContainer, &PanelDataContainer::valueChanged, this, [this](QString rangeMin, 
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
    // connect(channelListWidgetItem->deleteButton, &QPushButton::clicked, this, [this]() {
    //     deleteChannel(channelListWidgetItem->getChannelName());
    // });

    QListWidgetItem *item = new QListWidgetItem(channelList);
    item->setSizeHint(channelListWidgetItem->sizeHint());
    channelList->addItem(item);
    item->setData(Qt::UserRole, QVariant::fromValue<ChannelListWidgetItem*>(channelListWidgetItem));
    channelList->setItemWidget(item, channelListWidgetItem);
}

void OutputChannelTab::deleteChannel(QString channelName) {
    std::cout << channelName.toStdString() << std::endl;
}

void OutputChannelTab::instantiateChannelInformationPanel(ChannelListWidgetItem *channelListWidgetItem) {
    channelInformationPanel->setHidden(false);
    channelInformationPanel->setChannelInformation(channelListWidgetItem);
}