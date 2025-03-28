SOURCES += main.cpp \
           ./Tabs/InputChannelTab.cpp \
           ./Tabs/OutputChannelTab.cpp \
           ./ChannelListWidgetItems/ChannelListWidgetItem.cpp \
           ./ChannelInformationPanel/ChannelInformationPanel.cpp \
           ./ChannelInformationPanel/Taskbar.cpp \
           ./ChannelInformationPanel/PanelDataContainer.cpp \
           ./UDP/UdpClient.cpp \
           ./ChannelInformationPanel/StackPanelWidgets/ChannelInfoWidget.cpp \
           ./ChannelInformationPanel/StackPanelWidgets/CommsConfigWidget.cpp \
           ./ChannelInformationPanel/StackPanelWidgets/CommsDataWidget.cpp \

HEADERS += ./Tabs/InputChannelTab.h \
           ./Tabs/OutputChannelTab.h \
           ./ChannelListWidgetItems/ChannelListWidgetItem.h \
           ./ChannelInformationPanel/ChannelInformationPanel.h \
           ./ChannelInformationPanel/Taskbar.h \
           ./ChannelInformationPanel/PanelDataContainer.h \
           ./UDP/UdpClient.h \
            ./ChannelInformationPanel/StackPanelWidgets/ChannelInfoWidget.h \
           ./ChannelInformationPanel/StackPanelWidgets/ChannelConfigWidget.h \
           ./ChannelInformationPanel/StackPanelWidgets/ChannelDataWidget.h \

QT += widgets