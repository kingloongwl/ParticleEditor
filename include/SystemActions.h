
#ifndef PARTICLEEDITOR_SYSTEMACTIONS_H_
#define PARTICLEEDITOR_SYSTEMACTIONS_H_


#include "Singleton.h"

#include <QAction>

class SystemActions : public Singleton<SystemActions>
{
public:
	SystemActions();
	~SystemActions();

public:
	QAction		*_fileNew;

	QAction		*_editTemplate;
};

#endif
