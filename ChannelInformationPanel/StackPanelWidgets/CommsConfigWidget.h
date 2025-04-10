#ifndef COMMS_CONFIG_WIDGET
#define COMMS_CONFIG_WIDGET

#include <QWidget>
#include <iostream>
#include <QVBoxLayout>
#include <QComboBox>
#include <QHBoxLayout>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QString>

class CommsConfigWidget: public QWidget {
    public:
        CommsConfigWidget(QWidget *parent = nullptr);
        QComboBox *comboBox;
};

#endif