#ifndef TASKBAR_H
#define TASKBAR_H

#include <QFrame>
#include <QGridLayout>
#include <QPushButton>
#include <QIcon>
#include <QSpacerItem>

class Taskbar : public QFrame
{
    Q_OBJECT

public:
    explicit Taskbar(QFrame *parent = nullptr);
    void hidePanel();
    QPushButton *channelInfoButton, *commsConfigButton, *commsDataButton, *hideButton;
};

#endif // TASKBAR_H
