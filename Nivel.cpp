#include "Nivel.h"
#include <iostream>

#include "Fondo.h"
#include "Mario.h"
#include "Ducto.h"
#include "Bloques.h"

#include <QSoundEffect>


Mario* Nivel::load(QString level_name, QGraphicsScene * scene)
{
    Mario* mario = 0;

    if(level_name == "Nivel-1")
    {

        scene->setBackgroundBrush(QBrush(QColor(99,133,251)));

		int terrain_level = 200;

        new Bloques(QRect(0,terrain_level,20*10,30));

        new Bloques(QRect(-10, 0, 10, 200));
        new Bloques(QRect(200, 0, 10, 200));

        new  Fondo(QPoint(0,terrain_level),       ":/imagenes/hill-big.png");
        new  Fondo(QPoint(1*16,terrain_level-5.5*16),  ":/imagenes/cloud-big.png");

        new Ducto(QPoint(7*16, terrain_level), 0);

        mario = new Mario(QPoint(16*2.5, terrain_level));


    }

    return mario;
}
