#ifndef COMMS_INFO_WIDGET
#define COMMS_INFO_WIDGET

#include <QWidget>
#include <iostream>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QString>

class ChannelInfoWidget: public QWidget {
    Q_OBJECT

    public:
        ChannelInfoWidget(QWidget *parent = nullptr);
        void setPanelData(int rangeMin, int rangeMax, QString channelName);
        void updateChannel();
    signals:
        void valueChanged(QString rangeMin, QString rangeMax, QString channelName);
    private:
        QGroupBox *groupBox;
        QLineEdit *rangeMin, *rangeMax, *channelName;
};

#endif