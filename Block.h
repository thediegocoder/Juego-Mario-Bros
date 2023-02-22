#pragma once

#include "Inert.h"

class Block : public Inert
{
	public:

		Block(QPoint position);

        // pure virtual methods that must be implemented
        virtual QString name() { return "Block"; }
        virtual void hit(Object *what, Direction fromDir);
};
