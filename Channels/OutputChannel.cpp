#include "OutputChannel.h"

class OutputChannel {
    string channelName;

    OutputChannel(string channelName) {
        self.channelName = channelName;
    }

    void setChannelName(string channelName) {
        self.channelName = channelName;
    }

    string getChannelName() {
        return self.channelName;
    }
};