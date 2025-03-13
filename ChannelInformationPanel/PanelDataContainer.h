#ifndef PANELDATACONTAINER_H
#define PANELDATACONTAINER_H

#include <iostream>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QString>

class PanelDataContainer : public QWidget {
    Q_OBJECT

    public:
        PanelDataContainer(QWidget *parent = nullptr);
        QGroupBox *groupBox;
        QLineEdit *rangeMin, *rangeMax, *channelName;

        void showChannelInfo();
        void showCommsConfig();
        void showCommsData();
        void setPanelData(int rangeMin, int rangeMax, QString channelName);
        void updateChannel();
    
    signals:
        void valueChanged(QString rangeMin, QString rangeMax, QString channelName);
};

#endif