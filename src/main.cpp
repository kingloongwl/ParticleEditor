﻿
#include "MainWindow.h"
#include <QtGui/QApplication>

int main( int argc, char **argv )
{
	QApplication app( argc, argv );
	MainWindow mw;
	mw.showMaximized();

    int result = app.exec();
    return result;
}
