#include "easysmb.h"
#include "lbrowse.h"
#include "rbrowse.h"

#include <QtGui>
#include <QApplication>


int main(int argc,char *argv[])
{
    QApplication app(argc,argv);

    easysmb  *es = new easysmb;
    es->setWindowTitle("EasySMB");
    es->setWindowIcon(QIcon(":/images/ubuntu.ico"));
    es->resize(800,600);
    es->show();

    return app.exec();
}
