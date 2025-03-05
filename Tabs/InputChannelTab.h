#ifndef INPUTCHANNELATAB_H
#define INPUTCHANNELTAB_H

#include "./ChannelListWidgetItems/ChannelListWidgetItem.h"
#include "./ChannelInformationPanel/ChannelInformationPanel.h"
#include "./ChannelInformationPanel/Taskbar.h"

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
        void deleteChannel(QString channelName);
        void instantiateChannelInformationPanel(ChannelListWidgetItem *channelListWidgetItem);

    private:
        QListWidget *channelList;
        ChannelListWidgetItem *channelListWidgetItem;
        ChannelInformationPanel *channelInformationPanel;
        Taskbar *taskbar;
        bool channelInformationPanelHidden;
};

#endif
