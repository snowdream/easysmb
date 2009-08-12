#ifndef RBROWSE_H
#define RBROWSE_H

#include <QtGui>


QT_BEGIN_NAMESPACE
class QListView;
class QTreeView;
class  QAction;
class QActionGroup;
class  QMenu;
class  QVBoxLayout;
QT_END_NAMESPACE

class rbrowse : public QWidget
{
        Q_OBJECT

public:
        rbrowse(QWidget *parent = 0);
         bool   risdir();
        QString rfilepath();
        QString  rhost;
        bool  setHost(QString  rhost,QString  rusername,QString  rpassword);
        bool setIcon();
        bool setList();
signals:
        void rdownloadIt();
private slots:
       void contextMenuEvent(QContextMenuEvent *event);
        void openIt();
private:
        QFileSystemModel *rdirmodel;
        QTreeView *rtreeview ;
        QListView  *rlistview;
  };
#endif

