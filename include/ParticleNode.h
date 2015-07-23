
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
	ParticleNode( int ID, const std::string &name );
	~ParticleNode();

	int getID() { return _ID; }
	std::string getName() { return _name; }

private:
	osgParticle::Particle							_particle;

	osg::ref_ptr<osgParticle::ModularEmitter>		_emitter;
	osg::ref_ptr<osgParticle::ParticleSystem>		_ps;
	osg::ref_ptr<osgParticle::RandomRateCounter>	_counter;

private:
	int				_ID;
	std::string		_name;
	
private:
	double			_lifeTime;		//生命周期
	
	float 			_sizeMin;		//大小范围
	float 			_sizeMax;
	float 			_alphaMin;		//透明度范围
	float 			_alphaMax;
	
	osg::Vec4		_colorMin;		//颜色范围
	osg::Vec4		_colorMax;
	
	float 			_radius;		//半径	与大小区别？？
	float 			_mass;			//质量
	
	std::string 	_imageFile;		//贴图
	
	float 			_rateMin;		//速度范围
	float 			_rateMax;
	
};

#endif

