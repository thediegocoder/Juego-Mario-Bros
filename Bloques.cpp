#include "Bloques.h"
#include <QBrush>
#include <QPainter>

Bloques::Bloques(QRect rect) : Inert()
{
    setPos(QPoint(rect.x(), rect.y()));

    QPixmap collage(loadTexture(":/imagenes/wall.png"));
	collage = collage.scaled(rect.width(), rect.height());
    QPainter painter(&collage);
    QPixmap single_block(loadTexture(":/imagenes/wall.png"));
    for(int y=0; y<rect.height(); y += single_block.height())
        for(int x=0; x<rect.width(); x += single_block.width())
            painter.drawPixmap(x, y, single_block);
    setPixmap(collage);

	setZValue(2);
}
