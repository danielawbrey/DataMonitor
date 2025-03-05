#ifndef OUTPUTCHANNEL_H
#define OUTPUTCHANNEL_H

#include <string>

class OutputChannel {
    public:
        explicit OutputChannel();
        void setChannelName(string channelName);
        string getChannelName();
};

#endif