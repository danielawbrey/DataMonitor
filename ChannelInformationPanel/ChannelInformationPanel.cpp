#include "ChannelInformationPanel.h"

ChannelInformationPanel::ChannelInformationPanel(QFrame *parent) : QFrame(parent) {
    setFrameShape(QFrame::Box);
    setLineWidth(1); 
    setMinimumWidth(250);
    setMaximumWidth(375);

    QGridLayout *mainLayout = new QGridLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);

    panelDataContainer = new PanelDataContainer();
    mainLayout->addWidget(panelDataContainer, 0, 0, 1, 1, Qt::AlignCenter | Qt::AlignTop);

    taskbar = new Taskbar();
    mainLayout->addWidget(taskbar, 0, 1, 1, -1);

    setLayout(mainLayout);
};

void ChannelInformationPanel::hideTab() {
    hidden = !hidden;
    // groupBox->setHidden(hidden);

    // if(hidden) {
    //     setMinimumWidth(80);
    //     setMaximumWidth(160);
    // }
    // else {
    //     setMinimumWidth(250);
    //     setMaximumWidth(500);
    // }
}

// void ChannelInformationPanel::setChannelInformation(ChannelListWidgetItem *channelListWidgetItem) {
//     channelName->setText(channelListWidgetItem->getChannelName());
//     rangeMin->setText(QString::number(channelListWidgetItem->getSliderMinimumValue()));
//     rangeMax->setText(QString::number(channelListWidgetItem->getSliderMaximumValue()));
// }