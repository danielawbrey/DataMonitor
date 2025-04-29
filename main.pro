SOURCES += main.cpp \
           ./Tabs/InputChannelTab.cpp \
           ./Tabs/OutputChannelTab.cpp \
           ./ChannelListWidgetItems/ChannelListWidgetItem.cpp \
           ./ChannelInformationPanel/ChannelInformationPanel.cpp \
           ./ChannelInformationPanel/Taskbar.cpp \
           ./UDP/UdpClient.cpp \
           ./ChannelInformationPanel/StackPanelWidgets/ChannelInfoWidget.cpp \
           ./ChannelInformationPanel/StackPanelWidgets/CommsConfigWidget.cpp \
           ./ChannelInformationPanel/StackPanelWidgets/CommsDataWidget.cpp \
           ./MainWindow.cpp \

HEADERS += ./Tabs/InputChannelTab.h \
           ./Tabs/OutputChannelTab.h \
           ./ChannelListWidgetItems/ChannelListWidgetItem.h \
           ./ChannelInformationPanel/ChannelInformationPanel.h \
           ./ChannelInformationPanel/Taskbar.h \
           ./UDP/UdpClient.h \
           ./ChannelInformationPanel/StackPanelWidgets/ChannelInfoWidget.h \
           ./ChannelInformationPanel/StackPanelWidgets/CommsConfigWidget.h \
           ./ChannelInformationPanel/StackPanelWidgets/CommsDataWidget.h \
           ./MainWindow.h \

INCLUDEPATH += /usr/include/tinyxml2
LIBS += -ltinyxml2

QT += widgets