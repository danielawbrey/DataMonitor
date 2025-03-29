#ifndef CHANNELINFORMATIONPANEL_H
#define CHANNELINFORMATIONPANEL_H

#include "./ChannelListWidgetItems/ChannelListWidgetItem.h"
#include "ChannelInformationPanel/StackPanelWidgets/ChannelInfoWidget.h"
#include "ChannelInformationPanel/StackPanelWidgets/CommsConfigWidget.h"
#include "ChannelInformationPanel/StackPanelWidgets/CommsDataWidget.h"
#include "Taskbar.h"

#include <iostream>
#include <QGridLayout>
#include <QFrame>
#include <QStackedWidget>

class ChannelInformationPanel: public QFrame {    
    public:
        enum channelDiplay { channelInformation = 1, channelMetrics = 2, channelProperties = 3 };
        
        QStackedWidget *stackWidget;
        ChannelInfoWidget *infoWidget;
        CommsConfigWidget *configWidget;
        CommsDataWidget *dataWidget;
        Taskbar *taskbar;
        // PanelDataContainer *panelDataContainer;

        explicit ChannelInformationPanel(QFrame *parent = nullptr);
        void setChannelInformation(ChannelListWidgetItem *channelListWidgetItem);
        // void hideTab();
        void showChannelInfo();
        void showCommsConfig();
        void showCommsData();

    private:
        bool dataPanelHidden = false;

    signals:
        void valueChanged(int newValue);
};

#endif