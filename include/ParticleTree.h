
#ifndef PARTICLEEDITOR_PARTICLETREE_H_
#define PARTICLEEDITOR_PARTICLETREE_H_

#include <QTreeWidget>
#include <QAction>

class ParticleTree : public QTreeWidget
{
	Q_OBJECT
public:
	ParticleTree();
	~ParticleTree();

	void updateData();

	void addParticleItem( int ID, const std::string &name );

	void contextMenuEvent(QContextMenuEvent *event);

private slots:
	void slotProperty();

private:
	QAction *_actionProperty;
};

#endif
