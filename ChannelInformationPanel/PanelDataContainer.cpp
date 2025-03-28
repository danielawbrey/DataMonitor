#include "PanelDataContainer.h"

PanelDataContainer::PanelDataContainer(QWidget *parent) : QWidget(parent) {
    // groupBox = new QGroupBox("Channel Metrics", this);
    // groupBox->setMaximumHeight(400);

    // QVBoxLayout *layout = new QVBoxLayout();

    // QHBoxLayout *ipAddressLayout = new QHBoxLayout();
    // QLabel *ipAddressLabel = new QLabel("IP Address");
    // ipAddressLayout->addWidget(ipAddressLabel);
    // QLineEdit *ipAddress = new QLineEdit();
    // ipAddress->setMaximumWidth(125);
    // ipAddressLayout->addWidget(ipAddress);
    // layout->addLayout(ipAddressLayout);

    // QHBoxLayout *portNumberLayout = new QHBoxLayout();
    // QLabel *nameLabel = new QLabel("Port Number");
    // portNumberLayout->addWidget(nameLabel);
    // channelName = new QLineEdit();
    // channelName->setMaximumWidth(125);
    // portNumberLayout->addWidget(channelName);
    // layout->addLayout(portNumberLayout);

    // QHBoxLayout *bufferSizeLayout = new QHBoxLayout();
    // QLabel *bufferSizeLabel = new QLabel("Buffer Size");
    // bufferSizeLayout->addWidget(bufferSizeLabel);
    // QLineEdit *bufferSize = new QLineEdit();
    // bufferSize->setMaximumWidth(125);
    // bufferSizeLayout->addWidget(bufferSize);
    // layout->addLayout(bufferSizeLayout);
    
    // groupBox->setLayout(layout);

    // QVBoxLayout *parentLayout = new QVBoxLayout();
    // parentLayout->addWidget(groupBox);
    // setLayout(parentLayout);

    // showChannelInfo();

    setMinimumWidth(300);
    setMaximumWidth(400);
};

void PanelDataContainer::showChannelInfo() {
    std::cout << "PanelDataContainer::showChannelInfo()" << std::endl;

    groupBox = new QGroupBox("Channel Information", this);
    groupBox->setMaximumHeight(400);

    QVBoxLayout *layout = new QVBoxLayout();

    QPushButton *applyChangesButton = new QPushButton("Apply changes");
    connect(applyChangesButton, &QPushButton::clicked, this, &PanelDataContainer::updateChannel);
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
}

void PanelDataContainer::showCommsConfig() {
    std::cout << "PanelDataContainer::showCommsConfig()" << std::endl;

    groupBox = new QGroupBox("Channel Communication Properties", this);
    groupBox->setMaximumHeight(400);

    QVBoxLayout *layout = new QVBoxLayout();

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
    channelName = new QLineEdit();
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
}

void PanelDataContainer::showCommsData() {
    std::cout << "PanelDataContainer::showCommsData()" << std::endl;

    groupBox = new QGroupBox("Channel Metrics", this);
    groupBox->setMaximumHeight(400);

    QVBoxLayout *layout = new QVBoxLayout();

    groupBox->setLayout(layout);

    QVBoxLayout *parentLayout = new QVBoxLayout();
    parentLayout->addWidget(groupBox);
    setLayout(parentLayout);
}

void PanelDataContainer::setPanelData(int rangeMin, int rangeMax, QString channelName) {
    this->rangeMax->setText(QString::number(rangeMax));
    this->rangeMin->setText(QString::number(rangeMin));
    this->channelName->setText(channelName);
}

void PanelDataContainer::updateChannel() {
    emit valueChanged(rangeMin->text(), rangeMax->text(), channelName->text());
}