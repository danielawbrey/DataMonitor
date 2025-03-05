#include "ChannelListWidgetItem.h"

ChannelListWidgetItem::ChannelListWidgetItem(QString name, QWidget *parent) : QWidget(parent), channelName(name) {
    QHBoxLayout *layout = new QHBoxLayout();

    QLabel *label = new QLabel(name);
    layout->addWidget(label);

    sliderValue = new QLineEdit();
    sliderValue->setText(QString::number(0));
    sliderValue->setMinimumWidth(50);
    sliderValue->setMaximumWidth(100);
    layout->addWidget(sliderValue);

    slider = new QSlider(Qt::Horizontal);
    connect(slider, &QSlider::valueChanged, this, &ChannelListWidgetItem::setSliderValue);
    slider->setValue(0);
    slider->setMinimum(-100);
    slider->setMaximum(100);
    layout->addWidget(slider);

    deleteButton = new QPushButton("Delete");
    // connect(deleteButton, &QPushButton::clicked, this, &ChannelListWidgetItem::deleteChannel);
    layout->addWidget(deleteButton, 0, Qt::AlignLeft);

    setLayout(layout);
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
    return channelName;
}