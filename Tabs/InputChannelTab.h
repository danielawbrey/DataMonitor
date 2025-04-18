#ifndef INPUTCHANNELATAB_H
#define INPUTCHANNELTAB_H

#include "./ChannelListWidgetItems/ChannelListWidgetItem.h"
#include "./ChannelInformationPanel/ChannelInformationPanel.h"
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

class InputChannelTab: public QWidget {
    Q_OBJECT

    public:
        explicit InputChannelTab(QWidget *parent = nullptr);
        void addChannel();
        void deleteChannel();
        QListWidget getChannelList();
        QListWidget *channelList;
        void instantiateChannelInformationPanel(ChannelListWidgetItem *channelListWidgetItem);

    private:
        bool channelInformationPanelHidden;
        
        
        ChannelListWidgetItem *channelListWidgetItem;
        ChannelInformationPanel *channelInformationPanel;
        Taskbar *taskbar;
};

#endif
