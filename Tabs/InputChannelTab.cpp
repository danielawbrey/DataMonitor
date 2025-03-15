#include "InputChannelTab.h"

InputChannelTab::InputChannelTab(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *pageLayout = new QVBoxLayout();
    
    QPushButton *addButton = new QPushButton("Add Channel");
    addButton->setMinimumWidth(100);
    addButton->setMaximumWidth(150);
    connect(addButton, &QPushButton::clicked, this, &InputChannelTab::addChannel);
    pageLayout->addWidget(addButton);
    
    QGridLayout *channelDataLayout = new QGridLayout();

    channelList = new QListWidget();
    connect(channelList, &QListWidget::itemClicked, this, [this](QListWidgetItem *clickedItem) {
        if (clickedItem) {
            instantiateChannelInformationPanel(channelListWidgetItem);

            connect(channelInformationPanel->panelDataContainer, &PanelDataContainer::valueChanged, this, [this](QString rangeMin, 
                                                                                                                 QString rangeMax, 
                                                                                                                 QString channelName) {
                QListWidgetItem* currentItem = channelList->currentItem();
                if(currentItem) {
                    ChannelListWidgetItem* listItem = currentItem->data(Qt::UserRole).value<ChannelListWidgetItem*>();
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

void InputChannelTab::addChannel() {
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

void InputChannelTab::deleteChannel(QString channelName) {
    std::cout << channelName.toStdString() << std::endl;
}

void InputChannelTab::instantiateChannelInformationPanel(ChannelListWidgetItem *channelListWidgetItem) {
    channelInformationPanel->setHidden(false);
    channelInformationPanel->setChannelInformation(channelListWidgetItem);
}