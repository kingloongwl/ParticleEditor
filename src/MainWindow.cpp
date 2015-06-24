
#include "MainWindow.h"
#include "OsgWidget.h"

MainWindow::MainWindow()
{
	OsgWidget *osgWid = new OsgWidget( this );
	
    setCentralWidget( osgWid );
}

MainWindow::~MainWindow()
{

}
