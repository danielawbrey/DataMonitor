#ifndef PANELDATACONTAINER_H
#define PANELDATACONTAINER_H

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QWidget>
#include <QFrame>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QIcon>
#include <QPixmap>
#include <QSize>

class PanelDataContainer : public QWidget {
    // Q_OBJECT

    public:
        PanelDataContainer(QWidget *parent = nullptr);
        QGroupBox *groupBox;
        QLineEdit *rangeMin, *rangeMax, *channelName;
};

#endif