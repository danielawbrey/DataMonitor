#ifndef INPUTCHANNEL_H
#define INPUTCHANNEL_H

#include <QString>

class InputChannel {
    public:
        explicit InputChannel();
        void setChannelName(string channelName);
        QString getChannelName();

    private:
        QString channelName;
};

#endif