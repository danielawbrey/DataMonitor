#include "ChannelInfoWidget.h"

ChannelInfoWidget::ChannelInfoWidget(QWidget *parent) : QWidget(parent) {
    groupBox = new QGroupBox("Channel Information", this);
    groupBox->setMaximumHeight(400);

    QVBoxLayout *groupBoxLayout = new QVBoxLayout();

    QPushButton *applyChangesButton = new QPushButton("Apply changes");
    connect(applyChangesButton, &QPushButton::clicked, this, &ChannelInfoWidget::updateChannel);
    applyChangesButton->setMinimumWidth(125);
    groupBoxLayout->addWidget(applyChangesButton, 0, Qt::AlignRight);

    QHBoxLayout *channelNameLayout = new QHBoxLayout();
    QLabel *nameLabel = new QLabel("Channel Name");
    channelNameLayout->addWidget(nameLabel);
    channelName = new QLineEdit();
    channelName->setMaximumWidth(125);
    channelNameLayout->addWidget(channelName);
    groupBoxLayout->addLayout(channelNameLayout);

    QHBoxLayout *rangeMinLayout = new QHBoxLayout();
    QLabel *rangeMinLabel = new QLabel("Range Minimum");
    rangeMinLayout->addWidget(rangeMinLabel);
    rangeMin = new QLineEdit();
    rangeMin->setMaximumWidth(125);
    rangeMinLayout->addWidget(rangeMin);
    groupBoxLayout->addLayout(rangeMinLayout);

    QHBoxLayout *rangeMaxLayout = new QHBoxLayout();
    QLabel *rangeMaxLabel = new QLabel("Range Maximum");
    rangeMaxLayout->addWidget(rangeMaxLabel);
    rangeMax = new QLineEdit();
    rangeMax->setMaximumWidth(125);
    rangeMaxLayout->addWidget(rangeMax);
    groupBoxLayout->addLayout(rangeMaxLayout);
    
    groupBox->setLayout(groupBoxLayout);

    QVBoxLayout *parentLayout = new QVBoxLayout();
    parentLayout->addWidget(groupBox);
    setLayout(parentLayout);
};

void ChannelInfoWidget::setPanelData(int rangeMin, int rangeMax, QString channelName) {
    this->rangeMax->setText(QString::number(rangeMax));
    this->rangeMin->setText(QString::number(rangeMin));
    this->channelName->setText(channelName);
}

void ChannelInfoWidget::updateChannel() {
    emit valueChanged(rangeMin->text(), rangeMax->text(), channelName->text());
}