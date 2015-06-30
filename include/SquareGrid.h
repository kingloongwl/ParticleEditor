
#ifndef PARTICLEEDITOR_SQUAREGRID_H_
#define PARTICLEEDITOR_SQUAREGRID_H_

#include <osg/Switch>

class SquareGrid : public osg::Group
{
public:
	SquareGrid( int num = 10, float dis = 1.0 );
	~SquareGrid();
	
	void showGrid( bool show );
	void showAxes( bool show );
	
private:
	osg::ref_ptr<osg::Switch> _grid;
	osg::ref_ptr<osg::Switch> _axes;

	int 	_num;
	float 	_dis;
};

#endif
