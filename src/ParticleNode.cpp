
#include "ParticleNode.h"

#include <osg/Geode>
#include <osgParticle/ParticleSystemUpdater>

ParticleNode::ParticleNode( int ID, const std::string &name )
:_ID(ID)
,_name( name )
,_lifeTime( 3.0 )
,_sizeMin( 0.75 )
,_sizeMax( 3.0 )
,_alphaMin( 0.0 )
,_alphaMax( 1.5 )
,_colorMin( osg::Vec4(1, 0.5, 0.3, 1.5) )
,_colorMax( osg::Vec4(0, 0.7, 1.0, 0.0) )
,_radius( 0.05 )
,_mass( 0.05 )
,_imageFile( "Images/smoke.rgb" )
,_rateMin( 60 )
,_rateMax( 60 )
{
	_particle.setLifeTime( _lifeTime );
	_particle.setSizeRange( osgParticle::rangef( _sizeMin, _sizeMax ) );
	_particle.setAlphaRange( osgParticle::rangef( _alphaMin, _alphaMax ) );
	_particle.setColorRange( osgParticle::rangev4( _colorMin, _colorMax ) );
	_particle.setRadius( _radius );
	_particle.setMass( _mass );
	
	_ps = new osgParticle::ParticleSystem;
	_ps->setDefaultAttributes( _imageFile, false, false );
	_ps->setDefaultParticleTemplate( _particle );

	_counter = new osgParticle::RandomRateCounter;
	_counter->setRateRange( _rateMin, _rateMax );
	
	
	_emitter = new osgParticle::ModularEmitter;
	_emitter->setParticleSystem( _ps );
	_emitter->setCounter( _counter );

	osg::ref_ptr<osgParticle::ParticleSystemUpdater> psu = new osgParticle::ParticleSystemUpdater;
	psu->addParticleSystem(_ps);
	
	
	osg::ref_ptr<osg::Geode> _geode = new osg::Geode;
	_geode->addDrawable( _ps );
	
	addChild(_emitter);
	addChild( _geode );
	addChild(psu);
	
}

ParticleNode::~ParticleNode()
{
	
}



