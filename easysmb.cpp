#include "easysmb.h"



easysmb::easysmb(QWidget *parent):QMainWindow(parent){
//menu
         fileMenu = new QMenu("&File");
         downloadAct = new QAction("download",this);
         downloadAct->setIcon(QIcon(":/images/download.png"));
         downloadAct->setShortcut(Qt::CTRL + Qt::Key_D);
         downloadAct->setStatusTip("Download directorys or files");
         QObject::connect(downloadAct, SIGNAL(triggered()), this, SLOT(downloadIt()));

         uploadAct = new QAction("upload",this);
         uploadAct->setIcon(QIcon(":/images/upload.png"));
         uploadAct->setShortcut(Qt::CTRL + Qt::Key_U);
         uploadAct->setStatusTip("Upload directorys or files");
         QObject::connect(uploadAct, SIGNAL(triggered()), this, SLOT(uploadIt()));

         closeAct = new QAction("close",this);
         closeAct->setShortcut(Qt::CTRL + Qt::Key_X);
         QObject::connect(closeAct, SIGNAL(triggered()), this, SLOT(close()));

          fileMenu->addAction(uploadAct);
          fileMenu->addAction(downloadAct);
          fileMenu->addSeparator();
          fileMenu->addAction(closeAct);

          viewMenu = new QMenu("&View");
         iconAct = new QAction("Icon",this);
         iconAct->setShortcut(Qt::CTRL + Qt::Key_I);
         QObject::connect(iconAct, SIGNAL(triggered()), this, SLOT(setIcon()));

         listAct = new QAction("List",this);
         listAct->setShortcut(Qt::CTRL + Qt::Key_L);
         QObject::connect(listAct, SIGNAL(triggered()), this, SLOT(setList()));


          viewMenu->addAction(iconAct);
          viewMenu->addAction(listAct);

           aboutMenu = new QMenu("&About");
           aboutAct = new QAction("About",this);
           aboutMenu->addAction(aboutAct);

           aboutMenu->addAction(aboutAct);
           aboutAct->setShortcut(Qt::CTRL + Qt::Key_A);
           aboutAct->setStatusTip("About");
           QObject::connect(aboutAct, SIGNAL(triggered()), this, SLOT(showAbout()));

           this->menuBar()->addMenu(fileMenu);
           this->menuBar()->addMenu(viewMenu);
           this->menuBar()->addMenu(aboutMenu);
//toolbar

           toolBar = new QToolBar("QToolBar");
           toolBar->addAction(downloadAct);
           toolBar->addAction(uploadAct);
           toolBar->addSeparator();
           rh=new host;
           rh->setFocus();
           toolBar->addWidget(rh);
           this->addToolBar(toolBar);

// statusbar
           statusBar()->showMessage("Ready", 6000);

//Qtreeview

           lb = new lbrowse;
           rb = new rbrowse;
           QObject::connect(rb, SIGNAL(rdownloadIt()), this, SLOT(downloadIt()));
           QObject::connect(lb, SIGNAL(luploadIt()), this, SLOT(uploadIt()));

           QSplitter  *splitter = new QSplitter(Qt::Horizontal);
           splitter->addWidget(rb);
           splitter->addWidget(lb);

           this->setCentralWidget(splitter);
         }

void easysmb::uploadIt()
{
  if(rb->risdir()){
       if(lb->lisdir()){
         QProcess *downqp = new QProcess;
         QString order="xcopy /D/E/Y/H ";
         QString qarg;
         QString rbfilepath = rb->rfilepath();
         rbfilepath.replace(QString("/"), QString("\\"));
          QString lbfilepath = lb->lfilepath();
         lbfilepath.replace(QString("/"), QString("\\"));
         qarg =order+" \""+lbfilepath+"\" "+" \""+rbfilepath+"\"";
         downqp->start(qarg);
        if(downqp->waitForFinished(-1))
              statusBar()->showMessage("Upload Finished!", 6000);
        else
              statusBar()->showMessage("Error Occured!", 6000);
    }
        else {
         QProcess *downqp = new QProcess;
         QString order="xcopy /D/Y/H ";
         QString qarg;
         QString rbfilepath = rb->rfilepath();
         rbfilepath.replace(QString("/"), QString("\\"));
          QString lbfilepath = lb->lfilepath();
         lbfilepath.replace(QString("/"), QString("\\"));
         qarg =order+" \""+lbfilepath+"\" "+" \""+rbfilepath+"\"";
         downqp->start(qarg);
        if(downqp->waitForFinished(-1))
              statusBar()->showMessage("Upload Finished!", 6000);
        else
              statusBar()->showMessage("Error Occured!", 6000);
    }
}
else
statusBar()->showMessage("Please choose the directory in the left windows!", 6000);
}

void easysmb::downloadIt()
{
  if(lb->lisdir()){
      if(rb->risdir()){
         QProcess *downqp = new QProcess;
         QString order="xcopy /D/E/Y/H ";
         QString qarg;
         QString rbfilepath = rb->rfilepath();
         rbfilepath.replace(QString("/"), QString("\\"));
          QString lbfilepath = lb->lfilepath();
         lbfilepath.replace(QString("/"), QString("\\"));
         qarg =order+" \""+rbfilepath+"\" "+" \""+lbfilepath+"\"";
         downqp->start(qarg);
        if(downqp->waitForFinished(-1))
        statusBar()->showMessage("Download Finished!", 6000);
      else
        statusBar()->showMessage("Error Occured!", 6000);
        }
      else {
         QProcess *downqp = new QProcess;
         QString order="xcopy /D/Y/H ";
         QString qarg;
         QString rbfilepath = rb->rfilepath();
         rbfilepath.replace(QString("/"), QString("\\"));
          QString lbfilepath = lb->lfilepath();
         lbfilepath.replace(QString("/"), QString("\\"));
         qarg =order+" \""+rbfilepath+"\" "+" \""+lbfilepath+"\"";
         downqp->start(qarg);
        if(downqp->waitForFinished(-1))
        statusBar()->showMessage("Download Finished!", 6000);
       else
        statusBar()->showMessage("Error Occured!", 6000);
  }
  }
else
statusBar()->showMessage("Please choose the directory in the right windows!", 6000);
}




void easysmb::showAbout()
{
    QMessageBox::about(this, "About Easysmb",  "Easysmb is a software for Network Neighborhood to share files!");

}

void easysmb::setIcon()
{
if(rb->setIcon()&&lb->setIcon())
        statusBar()->showMessage("ICON VIEW", 6000);
}

void easysmb::setList(){
if(rb->setList()&&lb->setList())
        statusBar()->showMessage("LIST VIEW", 6000);
}


void easysmb::keyPressEvent(QKeyEvent *event){
if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return){
 if(rb->setHost(rh->sethost(),rh->setusername(),rh->setpassword())){
        statusBar()->showMessage("Host Connected!", 2000);
 }
}
 }


