
#include "SystemActions.h"

SystemActions::SystemActions()
{
	_fileNew = new QAction("New", NULL);

	_editTemplate = new QAction("Particle", NULL);
	_editTemplate->setCheckable(true);
}

SystemActions::~SystemActions()
{

}

