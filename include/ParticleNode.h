
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
	double			_lifeTime;		//��������
	
	float 			_sizeMin;		//��С��Χ
	float 			_sizeMax;
	float 			_alphaMin;		//͸���ȷ�Χ
	float 			_alphaMax;
	
	osg::Vec4		_colorMin;		//��ɫ��Χ
	osg::Vec4		_colorMax;
	
	float 			_radius;		//�뾶	���С���𣿣�
	float 			_mass;			//����
	
	std::string 	_imageFile;		//��ͼ
	
	float 			_rateMin;		//�ٶȷ�Χ
	float 			_rateMax;
	
};

#endif

