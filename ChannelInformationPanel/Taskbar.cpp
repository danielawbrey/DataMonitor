#include "Taskbar.h"

Taskbar::Taskbar(QFrame *parent) : QFrame(parent) {
    QGridLayout *layout = new QGridLayout();
    
    channelInfoButton = new QPushButton();
    channelInfoButton->setToolTip("Channel information");
    QIcon infoIcon("/home/daniel/Documents/DataMonitor/Images/tv.jpg");
    channelInfoButton->setIcon(infoIcon);
    channelInfoButton->setIconSize(QSize(32,32));
    layout->addWidget(channelInfoButton, 0, 0, Qt::AlignCenter | Qt::AlignTop);

    commsConfigButton = new QPushButton();
    commsConfigButton->setToolTip("Channel communication metrics");
    QIcon commsIcon("/home/daniel/Documents/DataMonitor/Images/data.jpg");
    commsConfigButton->setIcon(commsIcon);
    commsConfigButton->setIconSize(QSize(32,32));
    layout->addWidget(commsConfigButton, 1, 0, Qt::AlignCenter | Qt::AlignTop);

    commsDataButton = new QPushButton();
    commsDataButton->setToolTip("Channel communication properties");
    QIcon dataIcon("/home/daniel/Documents/DataMonitor/Images/comms.png");
    commsDataButton->setIcon(dataIcon);
    commsDataButton->setIconSize(QSize(32,32));
    layout->addWidget(commsDataButton, 2, 0, Qt::AlignCenter | Qt::AlignTop);

    QSpacerItem *spacer = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout->addItem(spacer, 3, 0, 1, 1);

    hideButton = new QPushButton();
    hideButton->setToolTip("Hide panel");
    QIcon hideIcon("/home/daniel/Documents/DataMonitor/Images/exit.png");
    hideButton->setIcon(hideIcon);
    hideButton->setIconSize(QSize(32,32));
    layout->addWidget(hideButton, 4, 0, Qt::AlignCenter | Qt::AlignTop);

    setFrameShape(QFrame::Box);
    setStyleSheet("QFrame { border-left: 1px solid black; border-right: none; border-top: none; border-bottom: none; background-color: red; };");
    setMinimumWidth(50);
    setMaximumWidth(60);
    setLayout(layout);
};