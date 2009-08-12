#ifndef LBROWSE_H
#define LBROWSE_H

#include <QtGui>

QT_BEGIN_NAMESPACE
class QListView;
class QTreeView;
class  QAction;
class QActionGroup;
class  QMenu;
QT_END_NAMESPACE

class lbrowse : public QWidget
{
	Q_OBJECT
public:
	lbrowse(QWidget *parent = 0);
        bool   lisdir();
        QString lfilepath();
        bool setIcon();
        bool setList();
signals:
        void  luploadIt();
private slots:
       void contextMenuEvent(QContextMenuEvent *event);
        void  openIt();
private:
        QFileSystemModel *ldirmodel;
        QListView  *llistview ;
        QTreeView *ltreeview;
};
#endif

