

#include "OsgWidget.h"
#include "OsgScene.h"

#include <QtGui/QGridLayout>


#include <osgQt/GraphicsWindowQt>

OsgWidget::OsgWidget( QWidget *parent, Qt::WindowFlags f )
: QWidget( parent, f )
{
	_viewer = OsgScene::getInstance()->getViewer();
	
	if ( _viewer.valid() && _viewer->getCamera() )
	{
		osgQt::GraphicsWindowQt *gw = dynamic_cast<osgQt::GraphicsWindowQt*>( _viewer->getCamera()->getGraphicsContext() );
		
		if ( gw )
		{
			QGridLayout *qgl = new QGridLayout;
			setLayout( qgl );
			qgl->addWidget( gw->getGLWidget() );
			
			
			connect( &_timer, SIGNAL(timeout()), this, SLOT(update()) );
			_timer.start( 10 );
		}
	}
	
}

OsgWidget::~OsgWidget()
{
	_timer.stop();
	if ( _viewer )
	{
		_viewer->done();
	}
	OsgScene::getInstance().release();
}

void OsgWidget::paintEvent( QPaintEvent * )
{
	if ( _viewer )
	{
		_viewer->frame();
	}
}

