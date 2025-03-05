#ifndef CHANNELLISTWIDGETITEM_H
#define CHANNELLISTWIDGETITEM_H

#include <iostream>
#include <QWidget>
#include <QHBoxLayout>
#include <QString>
#include <QSlider>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <string>

class ChannelListWidgetItem: public QWidget {
    // Q_OBJECT
    
    public:
        QPushButton *deleteButton;

        explicit ChannelListWidgetItem(QString name, QWidget *parent = nullptr);
        // void setChannelName(QString *name);
        void setSliderValue();
        int getSliderMinimumValue();
        int getSliderMaximumValue();
        // void deleteChannel();
        QString getChannelName();

    private:
        int currentSliderValue, sliderMaxValue, sliderMinValue;
        QString channelName;
        QSlider *slider;
        QLineEdit *sliderValue;
        QLabel *label;
};

#endif