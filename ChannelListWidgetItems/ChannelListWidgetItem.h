#ifndef CHANNELLISTWIDGETITEM_H
#define CHANNELLISTWIDGETITEM_H

#include "./UDP/UdpClient.h"

#include <iostream>
#include <QWidget>
#include <QHBoxLayout>
#include <QString>
#include <QSlider>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

class ChannelListWidgetItem: public QWidget {    
    public:
        explicit ChannelListWidgetItem(QWidget *parent = nullptr);
        ~ChannelListWidgetItem();
        void setSliderValue();
        int getSliderMinimumValue();
        int getSliderMaximumValue();
        void setSliderMinimumValue(int rangeMin);
        void setSliderMaximumValue(int rangeMax);
        void setChannelName(QString channelName);
        QString getChannelName();

    private:
        int currentSliderValue, sliderMaxValue, sliderMinValue;
        QString channelName;
        QSlider *slider;
        QLineEdit *sliderValue;
        QLabel *label;
        UdpClient *client;
        inline static int counter;
};

#endif