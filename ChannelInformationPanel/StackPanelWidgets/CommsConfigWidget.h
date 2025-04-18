#ifndef COMMS_CONFIG_WIDGET
#define COMMS_CONFIG_WIDGET

#include <QVBoxLayout>
#include <QComboBox>
#include <QHBoxLayout>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QString>

class CommsConfigWidget: public QWidget {
    Q_OBJECT
    
    signals:
        void valueChanged(QString ipAddress, QString portNumber, QString bufferSize, int protocolSelectionIndex);
    public:
        CommsConfigWidget(QWidget *parent = nullptr);
        void setPanelData(QString ipAddress, int portNumber, int bufferSize, int protocolSelectionIndex);
        void updateChannel();
    private:
        QComboBox *comboBox;
        QLineEdit *ipAddressLineEdit, *portNumberLineEdit, *bufferSizeLineEdit;
};

#endif