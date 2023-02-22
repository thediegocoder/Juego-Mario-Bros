#ifndef NIVEL_H
#define NIVEL_H


#include <QGraphicsScene>
#include <QString>

#include "Mario.h"

class Nivel
{
    public:

        static Mario* load(QString level_name, QGraphicsScene * scene);
};

#endif // NIVEL_H
