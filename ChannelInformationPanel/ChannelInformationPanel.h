#ifndef CHANNELINFORMATIONPANEL_H
#define CHANNELINFORMATIONPANEL_H

#include "./ChannelListWidgetItems/ChannelListWidgetItem.h"
#include "Taskbar.h"
#include "PanelDataContainer.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QWidget>
#include <QFrame>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QIcon>
#include <QPixmap>
#include <QSize>

class ChannelInformationPanel: public QFrame {
    public:
        explicit ChannelInformationPanel(QFrame *parent = nullptr);
        // void setChannelInformation(ChannelListWidgetItem *channelListWidgetItem);
        void hideTab();

    private:
        // QLineEdit *rangeMin, *rangeMax, *channelName;
        // QGroupBox *groupBox;
        Taskbar *taskbar;
        PanelDataContainer *panelDataContainer;
        bool hidden = false;
};

#endif