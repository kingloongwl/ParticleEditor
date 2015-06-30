
#include "OsgScene.h"
#include "SquareGrid.h"

#include <osgGA/StateSetManipulator>
#include <osgGA/TrackballManipulator>
#include <osgViewer/ViewerEventHandlers>
#include <osgQt/GraphicsWindowQt>
#include <osg/DisplaySettings>

osg::ref_ptr<OsgScene> OsgScene::_sInstance = NULL;

OsgScene::OsgScene()
{
	_viewer = new osgViewer::Viewer;
	_viewer->addEventHandler( new osgViewer::StatsHandler );
	_viewer->addEventHandler( new osgViewer::ThreadingHandler );
	_viewer->addEventHandler( new osgGA::StateSetManipulator );

	//若使用多线程模式，在主窗口关闭时，后台进程没有退出
	_viewer->setThreadingModel( osgViewer::ViewerBase::SingleThreaded );
	
	osg::ref_ptr<osg::DisplaySettings> ds = osg::DisplaySettings::instance();
	osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
	traits->windowName = "";
	traits->windowDecoration = false;
	traits->x = 0;
	traits->y = 0;
	traits->width = 100;
	traits->height = 100;
	traits->doubleBuffer = true;
	traits->alpha = ds->getMinimumNumAlphaBits();
	traits->stencil = ds->getMinimumNumStencilBits();
	traits->sampleBuffers = ds->getMultiSamples();
	
	osg::ref_ptr<osg::Camera> camera = _viewer->getCamera();
	camera->setGraphicsContext( new osgQt::GraphicsWindowQt( traits.get() ) );
	camera->setClearColor( osg::Vec4( 0.2, 0.2, 0.6, 1.0 ) );
	camera->setViewport( new osg::Viewport( 0, 0, traits->width, traits->height ) );
	
	double fovy, z1, z2, aspectRatio;
	camera->getProjectionMatrixAsPerspective( fovy, aspectRatio, z1, z2 );
	camera->setProjectionMatrixAsPerspective( fovy, traits->width/traits->height, z1, z2 );
	
	_viewer->setCameraManipulator( new osgGA::TrackballManipulator );
	
	
	_sceneRoot = new osg::Group;
	_sceneRoot->addChild( new SquareGrid );
	_viewer->setSceneData( _sceneRoot );
	
}

OsgScene::~OsgScene()
{

}

osg::ref_ptr<OsgScene> OsgScene::getInstance()
{
	if ( OsgScene::_sInstance == NULL )
	{
		OsgScene::_sInstance = new OsgScene();
	}
	
	return OsgScene::_sInstance;
}

osgViewer::Viewer* OsgScene::getViewer()
{
	return _viewer.get();
}

