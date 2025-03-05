#include "InputChannel.h"

class InputChannel {
    InputChannel(QString channelName) {
        self.channelName = channelName;
    }

    void setChannelName(string channelName) {
        self.channelName = channelName;
    }

    QString getChannelName() {
        return self.channelName;
    }
};