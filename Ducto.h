#ifndef DUCTO_H
#define DUCTO_H

#include "Inert.h"
#include <QString>

class Ducto : public Inert
{
    public:

        Ducto(QPoint position, int size);

        virtual QString name() { return "Ducto"; }

        virtual void hit(Object *what, Direction fromDir) { /* do nothing */ }
};

#endif // DUCTO_H
