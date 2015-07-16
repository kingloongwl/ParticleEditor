
#ifndef PARTICLEEDITOR_PARTICLENODEMANAGER_H_
#define PARTICLEEDITOR_PARTICLENODEMANAGER_H_

#include "Singleton.h"
#include "ParticleNode.h"


class ParticleNodeManager : public Singleton<ParticleNodeManager>
{
public:
	ParticleNodeManager();
	~ParticleNodeManager();

	bool addParticleNode(int particleID);
	ParticleNode* getParticleNode(int particleID);

	int getMaxID();

	typedef std::map<int, osg::ref_ptr<ParticleNode>> ParticleNodeMap;
	const ParticleNodeMap& getParticleNodeMap() { return _particleNodeMap; }
private:
	ParticleNodeMap		_particleNodeMap;
};

#endif
