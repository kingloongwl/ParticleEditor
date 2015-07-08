
#ifndef PARTICLEEDITOR_MAINWINDOW_H_
#define PARTICLEEDITOR_MAINWINDOW_H_

/*
	主窗口
*/

#include <QMainWindow>
#include <QMenu>

class MainWindow : public QMainWindow
{
public:
	MainWindow();
	~MainWindow();
	
private:
	void initFileMenu();

private:
	QMenu _fileMenu;
};

#endif

