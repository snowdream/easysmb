#include "host.h"
#include <QHBoxLayout>

host::host(QWidget *parent):QWidget(parent){
        ipl = new QLabel("IP:");
        ipe = new QLineEdit;
        ipe->setFocus();
        namel = new QLabel("username:");
        namee = new QLineEdit;
        passwdl = new QLabel("password:");
        passwde = new QLineEdit;
        ipe->setMaxLength(60);
        namee->setMaxLength(40);
	passwde->setMaxLength(40);

	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(ipl);
	layout->addWidget(ipe);
	layout->addWidget(namel);
	layout->addWidget(namee);
	layout->addWidget(passwdl);
	layout->addWidget(passwde);
	setLayout(layout);
}

QString host::sethost(){
QString host;
host ="//"+ipe->text ();
return (host);
}

QString host:: setusername(){
QString username;
username =namee->text ();
return (username);
}

QString host::setpassword(){
QString password;
password =passwde->text ();
return (password);
}
