
#ifndef PARTICLEEDITOR_PARTICLENODE_H_
#define PARTICLEEDITOR_PARTICLENODE_H_

#include <osg/MatrixTransform>
#include <osgParticle/ModularEmitter>
#include <osgParticle/ParticleSystem>
#include <osgParticle/Particle>
#include <osgParticle/RandomRateCounter>

class ParticleNode : public osg::MatrixTransform
{
public:
	ParticleNode();
	~ParticleNode();

private:
	osgParticle::Particle							_particle;

	osg::ref_ptr<osgParticle::ModularEmitter>		_emitter;
	osg::ref_ptr<osgParticle::ParticleSystem>		_ps;
	osg::ref_ptr<osgParticle::RandomRateCounter>	_counter;
	
private:
	double			_lifeTime;
	
	float 			_sizeMin;
	float 			_sizeMax;
	float 			_alphaMin;
	float 			_alphaMax;
	
	osg::Vec4		_colorMin;
	osg::Vec4		_colorMax;
	
	float 			_radius;
	float 			_mass;
	
	std::string 	_imageFile;
	
	float 			_rateMin;
	float 			_rateMax;
	
};

#endif

