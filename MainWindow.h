#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "./Tabs/InputChannelTab.h"

#include "ChannelListWidgetItems/ChannelListWidgetItem.h"

#include <tinyxml2/tinyxml2.h>

#include <QApplication>
#include <QListWidgetItem>
#include <QWidget>
#include <QTabWidget>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QFile>
#include <QString>
#include <QMessageBox>
#include <QStandardPaths>
#include <QListWidget>

class MainWindow: public QMainWindow {
    public:
        explicit MainWindow(QWidget *parent = nullptr);
        void newProfile(InputChannelTab *inputChannelTab);
        void loadProfile(InputChannelTab *inputChannelTab);
        
    private:
        bool profileLoaded = false;
};

#endif