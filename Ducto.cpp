#include "Ducto.h"

Ducto::Ducto(QPoint position, int size) : Inert()
{
	if(size == 0)
        setPixmap(QPixmap(loadTexture(":/imagenes/pipe-small.png")));

	setPos(position-QPoint(0, pixmap().height()));
}
