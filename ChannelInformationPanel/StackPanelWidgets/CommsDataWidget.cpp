#include "CommsDataWidget.h"

CommsDataWidget::CommsDataWidget(QWidget *parent) : QWidget(parent) {
    QGroupBox *groupBox = new QGroupBox("Channel Metrics", this);
    groupBox->setMaximumHeight(400);

    QVBoxLayout *layout = new QVBoxLayout();

    groupBox->setLayout(layout);

    QVBoxLayout *parentLayout = new QVBoxLayout();
    parentLayout->addWidget(groupBox);
    setLayout(parentLayout);    
};