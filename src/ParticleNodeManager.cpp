
#include "ParticleNodeManager.h"
#include "OsgScene.h"

ParticleNodeManager::ParticleNodeManager()
{

}

ParticleNodeManager::~ParticleNodeManager()
{

}

bool ParticleNodeManager::addParticleNode(int particleID)
{
	if (_particleNodeMap.find(particleID) != _particleNodeMap.end())
	{
		return false;
	}

	osg::ref_ptr<ParticleNode> particleNode = new ParticleNode(particleID, "NewParticle");
	OsgScene::getInstance().getSceneRoot()->addChild( particleNode );		//加上此句后Singleton就不识别NULL了，造成编译失败


	_particleNodeMap[particleID] = particleNode;

	return true;
}

ParticleNode* ParticleNodeManager::getParticleNode( int particleID )
{
	if (_particleNodeMap.find(particleID) == _particleNodeMap.end())
	{
		return NULL;
	}

	return _particleNodeMap[particleID];
}

int ParticleNodeManager::getMaxID()
{
	if (_particleNodeMap.size() == 0)
	{
		return 0;
	}

	std::map<int, osg::ref_ptr<ParticleNode>>::reverse_iterator rItr = _particleNodeMap.rbegin();
	return rItr->first;
}
