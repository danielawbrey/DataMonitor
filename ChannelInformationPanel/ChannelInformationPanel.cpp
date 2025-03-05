#include "ChannelInformationPanel.h"

ChannelInformationPanel::ChannelInformationPanel(QFrame *parent) : QFrame(parent) {
    QGridLayout *mainLayout = new QGridLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);

    panelDataContainer = new PanelDataContainer();
    mainLayout->addWidget(panelDataContainer, 0, 0, 1, 1, Qt::AlignCenter | Qt::AlignTop);

    taskbar = new Taskbar();
    mainLayout->addWidget(taskbar, 0, 1, 1, -1);

    setFrameShape(QFrame::Box);
    setLineWidth(1); 
    setMinimumWidth(250);
    setMaximumWidth(375);
    setLayout(mainLayout);
};

void ChannelInformationPanel::hideTab() {}

void ChannelInformationPanel::setChannelInformation(ChannelListWidgetItem *channelListWidgetItem) {}