#ifndef OUTPUTCHANNELTAB_CHANNEL
#define OUTPUTCHANNELTAB_CHANNEL

#include "./ChannelInformationPanel/ChannelInformationPanel.h"
#include "./ChannelListWidgetItems/ChannelListWidgetItem.h"
#include "./ChannelInformationPanel/Taskbar.h"
#include "./ChannelInformationPanel/StackPanelWidgets/ChannelInfoWidget.h"

#include <iostream>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <QGridLayout>
#include <QListWidgetItem>
#include <QString>

class OutputChannelTab: public QWidget {
    Q_OBJECT

    public:
        explicit OutputChannelTab(QWidget *parent = nullptr);
        void addChannel();
        void deleteChannel();
        void instantiateChannelInformationPanel(ChannelListWidgetItem *channelListWidgetItem);
        
    private:
        QListWidget *channelList;
        ChannelListWidgetItem *channelListWidgetItem;
        ChannelInformationPanel *channelInformationPanel;
        Taskbar *taskbar;
        bool channelInformationPanelHidden;
};

#endif
