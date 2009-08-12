#ifndef EASYSMB_H
#define EASYSMB_H

#include "rbrowse.h"
#include "lbrowse.h"
#include "host.h"
#include <QMainWindow>
#include <QtGui>

class easysmb : public QMainWindow
{
        Q_OBJECT

public:
        easysmb(QWidget *parent = 0);
private slots:
        void keyPressEvent(QKeyEvent *event);
        void uploadIt();
        void downloadIt();
        void  showAbout();
        void setIcon();
        void setList();
private:
        QAction *uploadAct;
        QAction *downloadAct;
        QAction *iconAct;
        QAction *listAct;
        QAction *aboutAct;
        QAction *closeAct;
        QMenu *fileMenu;
        QMenu *viewMenu;
        QMenu *aboutMenu;
        QToolBar *toolBar;
        host *rh;
        lbrowse *lb;
        rbrowse *rb;
    };
#endif

