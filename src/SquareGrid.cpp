
#include "SquareGrid.h"

#include <osg/Geode>
#include <osg/Geometry>
#include <osg/LineWidth>
#include <osgDB/ReadFile>

SquareGrid::SquareGrid( int num, float dis )
: _num( num )
, _dis( dis )
{
	osg::Geode *geode = new osg::Geode;
	
	osg::Geometry *centerGeo = new osg::Geometry;
	
	float length = num * dis;
	osg::Vec3 centerL = osg::Vec3( -length, 0.0, 0.0 );
	osg::Vec3 centerR = osg::Vec3( length, 0.0, 0.0 );
	osg::Vec3 centerU = osg::Vec3( 0.0, length, 0.0 );
	osg::Vec3 centerD = osg::Vec3( 0.0, -length, 0.0 );
	
	//添加中间线（粗）
	osg::Vec3Array *vertices = new osg::Vec3Array;
	vertices->push_back( centerL );
	vertices->push_back( centerR );
	vertices->push_back( centerU );
	vertices->push_back( centerD );
	centerGeo->setVertexArray( vertices );
	
	osg::Vec3Array *normals = new osg::Vec3Array;
	normals->push_back( osg::Vec3(0.0, 0.0, 1.0) );
	centerGeo->setNormalArray( normals );
	centerGeo->setNormalBinding( osg::Geometry::BIND_OVERALL );
	
	osg::Vec4Array *colors = new osg::Vec4Array;
	colors->push_back( osg::Vec4( 0.0, 0.0, 0.0, 1.0 ) );
	centerGeo->setColorArray( colors );
	centerGeo->setColorBinding( osg::Geometry::BIND_OVERALL );
	
	centerGeo->addPrimitiveSet( new osg::DrawArrays( GL_LINES, 0, vertices->size() ) );

	centerGeo->getOrCreateStateSet()->setAttributeAndModes( new osg::LineWidth( 2.0 ), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE );
	geode->addDrawable( centerGeo );
	
	//添加边缘线
	osg::Geometry *edgeGeo = new osg::Geometry;
	osg::Vec3Array *edgeVertices = new osg::Vec3Array;
	for ( int i = 0; i < num; i++ )
	{
		edgeVertices->push_back( centerL + osg::Vec3( 0.0, (i+1) * dis, 0.0 ) );
		edgeVertices->push_back( centerR + osg::Vec3( 0.0, (i+1) * dis, 0.0 ) );
		
		edgeVertices->push_back( centerL - osg::Vec3( 0.0, (i+1) * dis, 0.0 ) );
		edgeVertices->push_back( centerR - osg::Vec3( 0.0, (i+1) * dis, 0.0 ) );
		
		edgeVertices->push_back( centerU + osg::Vec3( (i+1) * dis, 0.0, 0.0 ) );
		edgeVertices->push_back( centerD + osg::Vec3( (i+1) * dis, 0.0, 0.0 ) );
		
		edgeVertices->push_back( centerU - osg::Vec3( (i+1) * dis, 0.0, 0.0 ) );
		edgeVertices->push_back( centerD - osg::Vec3( (i+1) * dis, 0.0, 0.0 ) );
	}
	
	edgeGeo->setVertexArray( edgeVertices );
	
	edgeGeo->setNormalArray( normals );
	edgeGeo->setNormalBinding( osg::Geometry::BIND_OVERALL );
	edgeGeo->setColorArray( colors );
	edgeGeo->setColorBinding( osg::Geometry::BIND_OVERALL );
	
	edgeGeo->addPrimitiveSet( new osg::DrawArrays( GL_LINES, 0, edgeVertices->size() ) );
	
	geode->addDrawable( edgeGeo );
	
	_grid = new osg::Switch;
	_grid->addChild( geode );
	
	addChild( _grid );

	//添加坐标参考
	_axes = new osg::Switch;
	_axes->addChild( osgDB::readNodeFile( "axes.osgt" ) );
	addChild( _axes );
}

SquareGrid::~SquareGrid()
{
	
}

void SquareGrid::showGrid( bool show )
{
	if ( _grid.valid() )
	{
		_grid->setChildValue( 0, show );
	}
}

void SquareGrid::showAxes( bool show )
{
	if ( _axes.valid() )
	{
		_axes->setChildValue( 0, show );
	}
}

