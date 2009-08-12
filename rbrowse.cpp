#include "rbrowse.h"


bool  rbrowse::setHost(QString  host,QString  username,QString  password){
rhost=host;
rtreeview->setRootIndex(rdirmodel->index(rhost));
rlistview->setRootIndex(rdirmodel->index(rhost));
return true;
}


rbrowse::rbrowse(QWidget *parent):QWidget(parent){
  rdirmodel = new QFileSystemModel;
//    rdirmodel->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);
      rdirmodel->setRootPath("/");
   rlistview = new QListView;
   rlistview->setModel(rdirmodel);
      rlistview->setRootIndex(rdirmodel->index(""));

   rtreeview = new QTreeView;
    rtreeview->setSortingEnabled(true);
    rtreeview->sortByColumn(0,Qt::AscendingOrder);
    rtreeview->setModel(rdirmodel);
    rtreeview->setAnimated(true);
    rtreeview->setIndentation(20);
    rtreeview->setColumnWidth(0,100);
    rtreeview->hideColumn(1);
    rtreeview->hideColumn(2);
    rtreeview->hideColumn(3);
    rtreeview->setHeaderHidden(true);
    //   rtreeview->setRootIndex(rdirmodel->index("//192.168.1.86"));
          rtreeview->setRootIndex(rdirmodel->index(""));
   QObject::connect(rtreeview, SIGNAL(clicked(const QModelIndex&)),
                     rlistview, SLOT(setRootIndex(const QModelIndex&)));
   QObject::connect(rlistview, SIGNAL(clicked(const QModelIndex&)),
                     rtreeview, SLOT(setCurrentIndex(const QModelIndex&)));
   QObject::connect(rlistview, SIGNAL(doubleClicked(const QModelIndex&)),
                     rlistview, SLOT(setRootIndex(const QModelIndex&)));

   QVBoxLayout *layout = new QVBoxLayout;
   layout->addWidget(rtreeview);
   layout->addWidget(rlistview);
   this->setLayout(layout);
}



void rbrowse::contextMenuEvent(QContextMenuEvent *event){
QAction *downAct = new QAction("&download",this);
    downAct->setIcon(QIcon(":/images/download.png"));
    downAct->setShortcut(Qt::CTRL + Qt::Key_D);
    downAct->setStatusTip("Download directorys or files");
    QObject::connect(downAct, SIGNAL(triggered()), this, SIGNAL(rdownloadIt()));
QAction *openAct = new QAction("&open",this);
    openAct->setIcon(QIcon(":/images/open.png"));
    openAct->setShortcut(Qt::CTRL + Qt::Key_O);
    openAct->setStatusTip("Open directorys or files");
   QObject::connect(openAct, SIGNAL(triggered()), this, SLOT(openIt()));
QMenu *menu = new QMenu;;
menu->addAction(downAct);
menu->addAction(openAct);
menu->exec(event->globalPos());
}


QString rbrowse::rfilepath(){
QFileInfo *rfileinfo = new QFileInfo(rdirmodel->fileInfo(rtreeview->currentIndex()));
QString rfilepath= rfileinfo->absoluteFilePath();
return (rfilepath);
}

bool  rbrowse::risdir(){
bool risdir = (rdirmodel->isDir(rtreeview->currentIndex()) || rdirmodel->isDir(rlistview->currentIndex()));
return (risdir);
}

void rbrowse::openIt(){
if(rdirmodel->isDir(rtreeview->currentIndex()) || rdirmodel->isDir(rlistview->currentIndex()) )
    {rtreeview->expand(rtreeview->currentIndex());
    rlistview->setRootIndex(rtreeview->currentIndex());}
else
{
QFileInfo *fileinfo = new QFileInfo(rdirmodel->fileInfo(rtreeview->currentIndex()));
QString qfilepath= fileinfo->absoluteFilePath();
QString prog;
prog="cmd.exe /C ";
QString qarg;
qarg=prog+"\""+qfilepath+"\"";

QProcess *openpro = new QProcess;
openpro->start(qarg);
}
}

bool rbrowse::setIcon(){
rlistview->setViewMode(QListView::IconMode);
return true;
}

bool rbrowse::setList(){
rlistview->setViewMode(QListView::ListMode);
return true;
}


