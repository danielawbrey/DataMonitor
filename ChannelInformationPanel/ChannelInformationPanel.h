#ifndef CHANNELINFORMATIONPANEL_H
#define CHANNELINFORMATIONPANEL_H

#include "./ChannelListWidgetItems/ChannelListWidgetItem.h"
#include "Taskbar.h"
#include "PanelDataContainer.h"

#include <iostream>
#include <QGridLayout>
#include <QFrame>

class ChannelInformationPanel: public QFrame {    
    public:
        enum channelDiplay { channelInformation = 1, channelMetrics = 2, channelProperties = 3 };
        
        Taskbar *taskbar;
        PanelDataContainer *panelDataContainer;

        explicit ChannelInformationPanel(QFrame *parent = nullptr);
        void setChannelInformation(ChannelListWidgetItem *channelListWidgetItem);
        void hideTab();
        void showChannelInfo();
        void showCommsConfig();
        void showCommsData();
        void switchPanelDisplay(int channelDisplayType);

    private:
        bool dataPanelHidden = false;

    signals:
        void valueChanged(int newValue);
};

#endif