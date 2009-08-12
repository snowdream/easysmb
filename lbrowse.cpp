#include "lbrowse.h"



lbrowse::lbrowse(QWidget *parent):QWidget(parent){
   ldirmodel = new QFileSystemModel;
   // ldirmodel->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);
   ldirmodel->setRootPath("/");
   llistview = new QListView;
   llistview->setModel(ldirmodel);
   llistview->setRootIndex(ldirmodel->index("c:/"));

    ltreeview = new QTreeView;
    ltreeview->setSortingEnabled(true);
    ltreeview->sortByColumn(0,Qt::DescendingOrder);
    ltreeview->setModel(ldirmodel);
    ltreeview->setAnimated(true);
    ltreeview->setIndentation(20);
    ltreeview->setColumnWidth(0,100);
    ltreeview->hideColumn(1);
    ltreeview->hideColumn(2);
    ltreeview->hideColumn(3);
    ltreeview->setHeaderHidden(true);
    //ltreeview->setRootIndex(ldirmodel->index("/"));

   QVBoxLayout *layout = new QVBoxLayout;
   layout->addWidget(ltreeview);
   layout->addWidget(llistview);
   this->setLayout(layout);
    QObject::connect(ltreeview, SIGNAL(clicked(const QModelIndex&)),
                     llistview, SLOT(setRootIndex(const QModelIndex&)));
   QObject::connect(llistview, SIGNAL(clicked(const QModelIndex&)),
                     ltreeview, SLOT(setCurrentIndex(const QModelIndex&)));
   QObject::connect(llistview, SIGNAL(doubleClicked(const QModelIndex&)),
                     llistview, SLOT(setRootIndex(const QModelIndex&)));
}



void lbrowse::contextMenuEvent(QContextMenuEvent *event)
{
    QAction *upAct = new QAction("&upload",this);
    upAct->setIcon(QIcon(":/images/upload.png"));
    upAct->setShortcut(Qt::CTRL + Qt::Key_U);
    upAct->setStatusTip("Upload directorys or files");
    QObject::connect(upAct, SIGNAL(triggered()), this, SIGNAL(luploadIt()));
    QAction *openAct = new QAction("&open",this);
    openAct->setIcon(QIcon(":/images/open.png"));
    openAct->setShortcut(Qt::CTRL + Qt::Key_O);
    openAct->setStatusTip("Open directorys or files");
   QObject::connect(openAct, SIGNAL(triggered()), this, SLOT(openIt()));
QMenu *menu = new QMenu;
menu->addAction(upAct);
menu->addAction(openAct);
menu->exec(event->globalPos());
}


QString lbrowse::lfilepath(){
QFileInfo *lfileinfo = new QFileInfo(ldirmodel->fileInfo(ltreeview->currentIndex()));
QString lfilepath= lfileinfo->absoluteFilePath();
return (lfilepath);
}


bool  lbrowse::lisdir(){
bool lisdir =(ldirmodel->isDir(ltreeview->currentIndex()) || ldirmodel->isDir(llistview->currentIndex()));
return (lisdir);
}



void lbrowse::openIt(){
if(ldirmodel->isDir(ltreeview->currentIndex()) || ldirmodel->isDir(llistview->currentIndex()) )
    {ltreeview->expand(ltreeview->currentIndex());
    llistview->setRootIndex(ltreeview->currentIndex());}
else
{
QFileInfo *fileinfo = new QFileInfo(ldirmodel->fileInfo(ltreeview->currentIndex()));
QString qfilepath= fileinfo->absoluteFilePath();
QString prog;
prog="cmd.exe /C ";
QString qarg;
qarg=prog+"\""+qfilepath+"\"";
QProcess *openpro = new QProcess;
openpro->start(qarg);
}
}

bool lbrowse::setIcon(){
llistview->setViewMode(QListView::IconMode);
return true;
    }

bool lbrowse::setList(){
llistview->setViewMode(QListView::ListMode);
return true;
}
