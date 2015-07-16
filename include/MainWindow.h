
#ifndef PARTICLEEDITOR_MAINWINDOW_H_
#define PARTICLEEDITOR_MAINWINDOW_H_

/*
	主窗口
*/

#include "ParticleTree.h"

#include <QMainWindow>
#include <QMenu>

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow();
	~MainWindow();

public slots:
	void fileNew();

	void editTemplate();
	
private:
	void connectSignalAndSlot();

	void initFileMenu();
	void initEditMenu();


	void initParticleTree();

private:
	ParticleTree	*_particleTree;
	QDockWidget		*_particleTreeDock;
};

#endif

