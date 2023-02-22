#ifndef FONDO_H
#define FONDO_H

#include "Inert.h"
#include <QString>


class Fondo : public Inert
{
	protected:

        QString texture_path;

	public:

        Fondo(QPoint position, QString _texture_path);

        virtual QString name() {return QString("Fondo (") + texture_path + ")";}

        virtual void hit(Object *what, Direction fromDir) { /* do nothing */ };
};

#endif // FONDO_H
