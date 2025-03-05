#ifndef CHANNELINFORMATIONPANEL_H
#define CHANNELINFORMATIONPANEL_H

#include "./ChannelListWidgetItems/ChannelListWidgetItem.h"
#include "Taskbar.h"
#include "PanelDataContainer.h"

#include <QGridLayout>
#include <QFrame>

class ChannelInformationPanel: public QFrame {
    // Q_OBJECT

    public:
        explicit ChannelInformationPanel(QFrame *parent = nullptr);
        void setChannelInformation(ChannelListWidgetItem *channelListWidgetItem);
        void hideTab();

    private:
        Taskbar *taskbar;
        PanelDataContainer *panelDataContainer;
        bool hidden = false;
};

#endif