#include "CommsConfigWidget.h"

CommsConfigWidget::CommsConfigWidget(QWidget *parent) : QWidget(parent) {
    QGroupBox *groupBox = new QGroupBox("Channel Communication Properties", this);
    groupBox->setMaximumHeight(400);

    QVBoxLayout *layout = new QVBoxLayout();

    QPushButton *applyChangesButton = new QPushButton("Apply changes");
    connect(applyChangesButton, &QPushButton::clicked, this, &CommsConfigWidget::updateChannel);
    applyChangesButton->setMinimumWidth(125);
    layout->addWidget(applyChangesButton, 0, Qt::AlignRight);

    QHBoxLayout *protocolLayout = new QHBoxLayout();
    QLabel *protocolLabel = new QLabel("Protocol");
    protocolLayout->addWidget(protocolLabel);
    comboBox = new QComboBox();
    comboBox->setMinimumWidth(125);
    comboBox->insertItem(0, "TCP");
    comboBox->insertItem(1, "UDP");
    protocolLayout->addWidget(comboBox, 0, Qt::AlignRight);
    layout->addLayout(protocolLayout);

    QHBoxLayout *ipAddressLayout = new QHBoxLayout();
    QLabel *ipAddressLabel = new QLabel("IP Address");
    ipAddressLayout->addWidget(ipAddressLabel);
    ipAddressLineEdit = new QLineEdit();
    ipAddressLineEdit->setMaximumWidth(125);
    ipAddressLayout->addWidget(ipAddressLineEdit);
    layout->addLayout(ipAddressLayout);

    QHBoxLayout *portNumberLayout = new QHBoxLayout();
    QLabel *portNumberLabel = new QLabel("Port Number");
    portNumberLayout->addWidget(portNumberLabel);
    portNumberLineEdit = new QLineEdit();
    portNumberLineEdit->setMaximumWidth(125);
    portNumberLayout->addWidget(portNumberLineEdit);
    layout->addLayout(portNumberLayout);

    QHBoxLayout *bufferSizeLayout = new QHBoxLayout();
    QLabel *bufferSizeLabel = new QLabel("Buffer Size");
    bufferSizeLayout->addWidget(bufferSizeLabel);
    bufferSizeLineEdit = new QLineEdit();
    bufferSizeLineEdit->setMaximumWidth(125);
    bufferSizeLayout->addWidget(bufferSizeLineEdit);
    layout->addLayout(bufferSizeLayout);
    
    groupBox->setLayout(layout);

    QVBoxLayout *parentLayout = new QVBoxLayout();
    parentLayout->addWidget(groupBox);
    setLayout(parentLayout);
};

void CommsConfigWidget::setPanelData(QString ipAddress, int portNumber, int bufferSize, int protocolSelectionIndex) {
    ipAddressLineEdit->setText(ipAddress);
    portNumberLineEdit->setText(QString::number(portNumber));
    bufferSizeLineEdit->setText(QString::number(bufferSize));
    comboBox->setCurrentIndex(protocolSelectionIndex);
}

void CommsConfigWidget::updateChannel() {
    emit valueChanged(ipAddressLineEdit->text(), portNumberLineEdit->text(), bufferSizeLineEdit->text(), comboBox->currentIndex());
}