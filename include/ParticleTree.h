
#ifndef PARTICLEEDITOR_PARTICLETREE_H_
#define PARTICLEEDITOR_PARTICLETREE_H_

#include <QTreeWidget>

class ParticleTree : public QTreeWidget
{
public:
	ParticleTree();
	~ParticleTree();

	void updateData();

	void addParticleItem( int ID, const std::string &name );
};

#endif
