
#ifndef PARTICLEEDITOR_OSGWIDGET_H_
#define PARTICLEEDITOR_OSGWIDGET_H_

/*
	将OSG填入Qt界面中
*/

#include <QtGui/QWidget>
#include <QtCore/QTimer>

#include <osgViewer/Viewer>

class OsgWidget : public QWidget
{
public:
	OsgWidget( QWidget* parent = 0, Qt::WindowFlags f = 0 );
	~OsgWidget();
	
protected:
	virtual void paintEvent( QPaintEvent * );
	
private:
	osg::ref_ptr<osgViewer::Viewer> _viewer;
	QTimer _timer;
	
};


#endif
