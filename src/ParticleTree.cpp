
#include "ParticleTree.h"
#include "ParticleNodeManager.h"

#include <QMenu>
#include <QContextMenuEvent>

ParticleTree::ParticleTree()
{
	setHeaderHidden(true);

	QTreeWidgetItem *rootItem = new QTreeWidgetItem;
	rootItem->setText(0,"Root");

	addTopLevelItem(rootItem);

	_actionProperty = new QAction("Property", this);
	connect(_actionProperty, SIGNAL(triggered()), this, SLOT(slotProperty()));

}

ParticleTree::~ParticleTree()
{

}

void ParticleTree::updateData()
{
	QTreeWidgetItem *rootItem = topLevelItem(0);
	if (rootItem == NULL)
	{
		return;
	}

	std::map<int, osg::ref_ptr<ParticleNode>> particleMap = ParticleNodeManager::getInstance().getParticleNodeMap();
	if (particleMap.size() <= 0)
	{
		return;
	}


	for (std::map<int, osg::ref_ptr<ParticleNode>>::iterator itr = particleMap.begin(); itr != particleMap.end(); itr++)
	{
		QTreeWidgetItem *item = new QTreeWidgetItem;
		item->setText(0, QString(itr->second->getName().c_str()));
		item->setData(0, Qt::UserRole, itr->first);

		rootItem->addChild(item);
	}
}

void ParticleTree::addParticleItem(int ID, const std::string &name)
{
	QTreeWidgetItem *rootItem = topLevelItem(0);
	if (rootItem == NULL)
	{
		return;
	}

	QTreeWidgetItem *item = new QTreeWidgetItem;
	item->setText(0, QString(name.c_str()));
	item->setData(0, Qt::UserRole, ID);

	rootItem->addChild(item);
}

void ParticleTree::slotProperty()
{

}

void ParticleTree::contextMenuEvent(QContextMenuEvent *event)
{
	QTreeWidgetItem *item = itemAt(event->pos());
	if (!item || !item->parent() )
	{
		return;
	}

	QMenu menu;
	menu.addAction(_actionProperty);

	menu.exec( QCursor::pos() );
}
