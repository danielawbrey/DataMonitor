#include "PanelDataContainer.h"

PanelDataContainer::PanelDataContainer(QWidget *parent) : QWidget(parent) {
    setMinimumWidth(300);
    setMaximumWidth(400);

    groupBox = new QGroupBox("Channel Information", this);
    groupBox->setMaximumHeight(400);

    QVBoxLayout *layout = new QVBoxLayout();

    QPushButton *applyChangesButton = new QPushButton("Apply changes");
    applyChangesButton->setMinimumWidth(125);
    layout->addWidget(applyChangesButton, 0, Qt::AlignRight);

    QHBoxLayout *channelNameLayout = new QHBoxLayout();
    QLabel *nameLabel = new QLabel("Channel Name");
    channelNameLayout->addWidget(nameLabel);
    channelName = new QLineEdit();
    channelName->setMaximumWidth(125);
    channelNameLayout->addWidget(channelName);
    layout->addLayout(channelNameLayout);

    QHBoxLayout *rangeMinLayout = new QHBoxLayout();
    QLabel *rangeMinLabel = new QLabel("Range Minimum");
    rangeMinLayout->addWidget(rangeMinLabel);
    rangeMin = new QLineEdit();
    rangeMin->setMaximumWidth(125);
    rangeMinLayout->addWidget(rangeMin);
    layout->addLayout(rangeMinLayout);

    QHBoxLayout *rangeMaxLayout = new QHBoxLayout();
    QLabel *rangeMaxLabel = new QLabel("Range Maximum");
    rangeMaxLayout->addWidget(rangeMaxLabel);
    rangeMax = new QLineEdit();
    rangeMax->setMaximumWidth(125);
    rangeMaxLayout->addWidget(rangeMax);
    layout->addLayout(rangeMaxLayout);
    
    groupBox->setLayout(layout);

    QVBoxLayout *parentLayout = new QVBoxLayout();
    parentLayout->addWidget(groupBox);
    setLayout(parentLayout);
};