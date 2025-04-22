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
        explicit ChannelListWidgetItem(std::string channelName, int minimum, int maximum, std::string ipAddress, int portNumber, int bufferSize, int protocolSelectionIndex, QWidget *parent = nullptr);
        ~ChannelListWidgetItem();
        void setSliderValue();
        int getSliderMinimumValue();
        int getSliderMaximumValue();
        int getBufferSize();
        int getPortNumber();
        int getProtocolSelectionIndex();
        void setChannelIpAddress(QString ipAddress);
        void setChannelPortNumber(int portNumber);
        void setChannelBufferSize(int bufferSize);
        void setSliderMinimumValue(int rangeMin);
        void setSliderMaximumValue(int rangeMax);
        void setChannelName(QString channelName);
        void setProtocolSelectionIndex(int protocolIndex);
        QString getChannelName();
        QString getIpAddress();

    private:
        int bufferSize = 1024;
        int portNumber = 8080;
        int protocolSelectionIndex = 0;

        int currentSliderValue, sliderMaxValue, sliderMinValue;
        QString channelName, ipAddress = "192.168.0.1";
        QSlider *slider;
        QLineEdit *sliderValue;
        QLabel *label;
        UdpClient *client;
        inline static int counter;
};

#endif