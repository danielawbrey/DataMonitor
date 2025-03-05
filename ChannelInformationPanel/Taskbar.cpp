#include "Taskbar.h"

Taskbar::Taskbar(QFrame *parent) : QFrame(parent) {
    setFrameShape(QFrame::Box);

    setStyleSheet("QFrame { border-left: 1px solid black; border-right: none; border-top: none; border-bottom: none; background-color: red; };");

    setMinimumWidth(50);
    setMaximumWidth(60);

    QGridLayout *layout = new QGridLayout();
    
    channelInfoButton = new QPushButton();
    // connect(hideButton, &QPushButton::clicked, this, &Taskbar::hideTab);
    QIcon infoIcon("/home/daniel/Documents/DataMonitor/Images/tv.jpg");
    channelInfoButton->setIcon(infoIcon);
    channelInfoButton->setIconSize(QSize(32,32));
    layout->addWidget(channelInfoButton, 0, 0, Qt::AlignCenter | Qt::AlignTop);

    commsConfigButton = new QPushButton();
    // connect(hideButton, &QPushButton::clicked, this, &Taskbar::hideTab);
    QIcon commsIcon("/home/daniel/Documents/DataMonitor/Images/data.jpg");
    commsConfigButton->setIcon(commsIcon);
    commsConfigButton->setIconSize(QSize(32,32));
    layout->addWidget(commsConfigButton, 1, 0, Qt::AlignCenter | Qt::AlignTop);

    commsDataButton = new QPushButton();
    // connect(hideButton, &QPushButton::clicked, this, &Taskbar::hideTab);
    QIcon dataIcon("/home/daniel/Documents/DataMonitor/Images/comms.png");
    commsDataButton->setIcon(dataIcon);
    commsDataButton->setIconSize(QSize(32,32));
    layout->addWidget(commsDataButton, 2, 0, Qt::AlignCenter | Qt::AlignTop);

    QSpacerItem *spacer = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout->addItem(spacer, 3, 0, 1, 1);

    exitButton = new QPushButton();
    // connect(hideButton, &QPushButton::clicked, this, &Taskbar::hideTab);
    QIcon exitIcon("/home/daniel/Documents/DataMonitor/Images/exit.png");
    exitButton->setIcon(exitIcon);
    exitButton->setIconSize(QSize(32,32));
    layout->addWidget(exitButton, 4, 0, Qt::AlignCenter | Qt::AlignTop);

    setLayout(layout);
};