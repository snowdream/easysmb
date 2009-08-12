#ifndef HOST_H
#define HOST_H

#include <QtGui>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QLabel;
class QKeyEvent;
QT_END_NAMESPACE

class host : public QWidget
{
	Q_OBJECT

public:
        host(QWidget *parent = 0);
        QString sethost();
        QString setusername();
        QString setpassword();
private:
        QLabel *ipl;
        QLineEdit *ipe;
        QLabel *namel;
        QLineEdit *namee;
        QLabel *passwdl;
        QLineEdit *passwde;
    };
#endif
