#include "Fondo.h"
#include <QBitmap>

Fondo::Fondo(QPoint position, QString _texture_path)
{

	collidable = false;

    texture_path = _texture_path;
    setPixmap((texture_path));

	setPos(position-QPoint(0, pixmap().height()));
}
