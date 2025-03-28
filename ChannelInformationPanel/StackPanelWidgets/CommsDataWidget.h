#ifndef COMMS_DATA_WIDGET
#define COMMS_DATA_WIDGET

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

class CommsDataWidget: public QWidget {
    public:
        CommsDataWidget(QWidget *parent = nullptr);
};

#endif