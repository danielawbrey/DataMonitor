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
    // Q_OBJECT
    
    public:
        QPushButton *deleteButton;

        explicit ChannelListWidgetItem(QString name, QWidget *parent = nullptr);
        // void setChannelName(QString *name);
        void setSliderValue();
        int getSliderMinimumValue();
        int getSliderMaximumValue();
        void setSliderMinimumValue(int rangeMin);
        void setSliderMaximumValue(int rangeMax);
        void setChannelName(QString channelName);
        // void deleteChannel();
        QString getChannelName();

    private:
        int currentSliderValue, sliderMaxValue, sliderMinValue;
        QString channelName;
        QSlider *slider;
        QLineEdit *sliderValue;
        QLabel *label;
        UdpClient *client;
};

#endif