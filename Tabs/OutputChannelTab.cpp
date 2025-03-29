#include "OutputChannelTab.h"

OutputChannelTab::OutputChannelTab(QWidget *parent): QWidget(parent) {
    QVBoxLayout *pageLayout = new QVBoxLayout();

    QHBoxLayout *buttonLayout = new QHBoxLayout();

    QPushButton *addButton = new QPushButton("Add Channel");
    addButton->setMinimumWidth(100);
    addButton->setMaximumWidth(150);
    connect(addButton, &QPushButton::clicked, this, &OutputChannelTab::addChannel);
    buttonLayout->addWidget(addButton);

    QPushButton *deleteButton = new QPushButton("Delete Channel");
    deleteButton->setMinimumWidth(100);
    deleteButton->setMaximumWidth(150);
    connect(deleteButton, &QPushButton::clicked, this, &OutputChannelTab::deleteChannel);
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
        }
    });

    channelDataLayout->addWidget(channelList, 0,0,1,1);

    channelInformationPanel = new ChannelInformationPanel();
    channelInformationPanel->stackWidget->setHidden(true);
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

void OutputChannelTab::deleteChannel() {
    std::cout << "OutputChannelTab::deleteChannel()" << std::endl;
}

void OutputChannelTab::instantiateChannelInformationPanel(ChannelListWidgetItem *channelListWidgetItem) {
    channelInformationPanel->setHidden(false);
    channelInformationPanel->setChannelInformation(channelListWidgetItem);
}