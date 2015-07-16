
#include "MainWindow.h"
#include "OsgWidget.h"
#include "OsgScene.h"
#include "SystemActions.h"
#include "ParticleNode.h"
#include "ParticleNodeManager.h"

#include <QMenuBar>
#include <QDockWidget>

MainWindow::MainWindow()
{
	OsgWidget *osgWid = new OsgWidget( this );
	
    setCentralWidget( osgWid );

	initParticleTree();

	initFileMenu();
	initEditMenu();

	connectSignalAndSlot();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initParticleTree()
{
	_particleTree = new ParticleTree;
	
	_particleTreeDock = new QDockWidget(this);
	_particleTreeDock->setWidget(_particleTree);
	_particleTreeDock->setFeatures(QDockWidget::AllDockWidgetFeatures);

	addDockWidget(Qt::LeftDockWidgetArea, _particleTreeDock);
	_particleTreeDock->hide();
}

void MainWindow::connectSignalAndSlot()
{
	connect(SystemActions::getInstance()._fileNew, SIGNAL(triggered()), this, SLOT(fileNew()));
	connect(SystemActions::getInstance()._editTemplate, SIGNAL(triggered()), this, SLOT(editTemplate()));
}

void MainWindow::initFileMenu()
{
	QMenu *fileMenu = new QMenu("File");
	fileMenu->addAction( SystemActions::getInstance()._fileNew );

	menuBar()->addMenu(fileMenu);
}

void MainWindow::initEditMenu()
{
	QMenu *editMenu = new QMenu("Edit");
	editMenu->addAction(SystemActions::getInstance()._editTemplate);

	menuBar()->addMenu(editMenu);
}

void MainWindow::fileNew()
{
	int newID = ParticleNodeManager::getInstance().getMaxID();

	if (ParticleNodeManager::getInstance().addParticleNode(newID + 1))
	{
		_particleTree->addParticleItem(newID + 1, "NewParticle");
	}
	
}

void MainWindow::editTemplate()
{
	if (SystemActions::getInstance()._editTemplate->isChecked())
	{
		_particleTreeDock->show();
	}
	else
	{
		_particleTreeDock->hide();
	}
}
