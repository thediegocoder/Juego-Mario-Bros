#ifndef INERT_H
#define INERT_H

#include "Object.h"
#include <QString>

class Inert : public Object
{
    public:

		Inert();

        virtual QString name()     = 0;

        virtual void animate()         { /* do nothing */ }

        virtual void advance()         { /* do nothing */ }

        virtual void solveCollisions() { /* do nothing */ }

        virtual void hit(Object *what, Direction fromDir) = 0;
};

#endif // INERT_H
