#ifndef PANELDATACONTAINER_H
#define PANELDATACONTAINER_H

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>

class PanelDataContainer : public QWidget {
    Q_OBJECT

    public:
        PanelDataContainer(QWidget *parent = nullptr);
        QGroupBox *groupBox;
        QLineEdit *rangeMin, *rangeMax, *channelName;
};

#endif