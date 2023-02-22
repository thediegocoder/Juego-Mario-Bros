#ifndef BLOQUES_H
#define BLOQUES_H

#include "Inert.h"
#include <QString>

class Bloques : public Inert
{
	public:

        Bloques(QRect rect);

        virtual QString name() { return "Terrain"; }

        virtual void hit(Object *what, Direction fromDir) { /* do nothing */ }
};

#endif // BLOQUES_H
