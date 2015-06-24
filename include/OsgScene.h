
#ifndef PARTICLEEDITOR_OSGSCENE_H_
#define PARTICLEEDITOR_OSGSCENE_H_

/*
 OSG场景的初始化以及场景属性的保存
  */
  
#include <osg/Referenced>
#include <osgViewer/Viewer>
 
class OsgScene : public osg::Referenced
{
public:
	OsgScene();
	~OsgScene();
	
	osgViewer::Viewer* getViewer();
public:
	static osg::ref_ptr<OsgScene> getInstance();
	static osg::ref_ptr<OsgScene> _sInstance;
	
private:
	osg::ref_ptr<osgViewer::Viewer> _viewer;
		
};

#endif
