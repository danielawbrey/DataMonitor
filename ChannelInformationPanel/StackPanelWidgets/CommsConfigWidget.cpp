#include "CommsConfigWidget.h"

CommsConfigWidget::CommsConfigWidget(QWidget *parent) : QWidget(parent) {
    // std::cout << "PanelDataContainer::showCommsConfig()" << std::endl;

    QGroupBox *groupBox = new QGroupBox("Channel Communication Properties", this);
    groupBox->setMaximumHeight(400);

    QVBoxLayout *layout = new QVBoxLayout();

    QPushButton *applyChangesButton = new QPushButton("Apply changes");
    // connect(applyChangesButton, &QPushButton::clicked, this, &ChannelInfoWidget::updateChannel);
    applyChangesButton->setMinimumWidth(125);
    layout->addWidget(applyChangesButton, 0, Qt::AlignRight);

    QHBoxLayout *ipAddressLayout = new QHBoxLayout();
    QLabel *ipAddressLabel = new QLabel("IP Address");
    ipAddressLayout->addWidget(ipAddressLabel);
    QLineEdit *ipAddress = new QLineEdit();
    ipAddress->setMaximumWidth(125);
    ipAddressLayout->addWidget(ipAddress);
    layout->addLayout(ipAddressLayout);

    QHBoxLayout *portNumberLayout = new QHBoxLayout();
    QLabel *nameLabel = new QLabel("Port Number");
    portNumberLayout->addWidget(nameLabel);
    QLineEdit *channelName = new QLineEdit();
    channelName->setMaximumWidth(125);
    portNumberLayout->addWidget(channelName);
    layout->addLayout(portNumberLayout);

    QHBoxLayout *bufferSizeLayout = new QHBoxLayout();
    QLabel *bufferSizeLabel = new QLabel("Buffer Size");
    bufferSizeLayout->addWidget(bufferSizeLabel);
    QLineEdit *bufferSize = new QLineEdit();
    bufferSize->setMaximumWidth(125);
    bufferSizeLayout->addWidget(bufferSize);
    layout->addLayout(bufferSizeLayout);
    
    groupBox->setLayout(layout);

    QVBoxLayout *parentLayout = new QVBoxLayout();
    parentLayout->addWidget(groupBox);
    setLayout(parentLayout);
};