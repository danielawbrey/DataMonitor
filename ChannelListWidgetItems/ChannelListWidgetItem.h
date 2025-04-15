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
        int getPacketSize();
        int getPortNumber();
        void setChannelIpAddress(QString ipAddress);
        void setChannelPortNumber(int portNumber);
        void setChannelPacketSize(int packetSize);
        void setSliderMinimumValue(int rangeMin);
        void setSliderMaximumValue(int rangeMax);
        void setChannelName(QString channelName);
        QString getChannelName();
        QString getIpAddress();

    private:
        int currentSliderValue, sliderMaxValue, sliderMinValue, portNumber, packetSize;
        QString channelName, ipAddress;
        QSlider *slider;
        QLineEdit *sliderValue;
        QLabel *label;
        UdpClient *client;
        inline static int counter;
};

#endif