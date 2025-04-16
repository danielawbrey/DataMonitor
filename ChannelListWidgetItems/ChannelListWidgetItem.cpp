#include "ChannelListWidgetItem.h"

ChannelListWidgetItem::ChannelListWidgetItem(QWidget *parent) : QWidget(parent) {
    client = new UdpClient();

    counter++;

    QHBoxLayout *layout = new QHBoxLayout();

    label = new QLabel("Channel " + QString::number(counter));
    label->setMinimumWidth(100);
    label->setMaximumWidth(150);
    layout->addWidget(label);

    sliderValue = new QLineEdit(QString::number(0));
    // sliderValue->setText(QString::number(0));
    sliderValue->setMinimumWidth(50);
    sliderValue->setMaximumWidth(100);
    layout->addWidget(sliderValue);

    slider = new QSlider(Qt::Horizontal);
    connect(slider, &QSlider::valueChanged, this, &ChannelListWidgetItem::setSliderValue);
    slider->setValue(0);
    slider->setMinimum(-100);
    slider->setMaximum(100);
    layout->addWidget(slider);

    setLayout(layout);
}

ChannelListWidgetItem::~ChannelListWidgetItem() {
    counter--;
}

void ChannelListWidgetItem::setChannelPortNumber(int portNumber) {
    this->portNumber = portNumber;
}

void ChannelListWidgetItem::setChannelBufferSize(int bufferSize) {
    this->bufferSize = bufferSize;
}

void ChannelListWidgetItem::setChannelIpAddress(QString ipAddress) {
    this->ipAddress = ipAddress;
}

void ChannelListWidgetItem::setSliderValue() {
    sliderValue->setText(QString::number(slider->value()));
}

int ChannelListWidgetItem::getSliderMinimumValue() {
    return slider->minimum();
}

int ChannelListWidgetItem::getSliderMaximumValue() {
    return slider->maximum();
}

QString ChannelListWidgetItem::getChannelName() {
    return label->text();
}

int ChannelListWidgetItem::getPortNumber() {
    return portNumber;
}

int ChannelListWidgetItem::getBufferSize() {
    return bufferSize;
}

int ChannelListWidgetItem::getProtocolSelectionIndex() {
    return protocolSelectionIndex;
}

QString ChannelListWidgetItem::getIpAddress() {
    return ipAddress;
}

void ChannelListWidgetItem::setProtocolSelectionIndex(int selectionIndex) {
    protocolSelectionIndex = selectionIndex;
}

void ChannelListWidgetItem::setSliderMinimumValue(int rangeMin) {
    slider->setMinimum(rangeMin);
}

void ChannelListWidgetItem::setSliderMaximumValue(int rangeMax) {
    slider->setMaximum(rangeMax);
}

void ChannelListWidgetItem::setChannelName(QString channelName) {
    label->setText(channelName);
}