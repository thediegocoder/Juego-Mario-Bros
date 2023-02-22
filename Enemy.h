#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include <QString>


class Enemy : public Entity
{
	protected:

        bool hurtable;

	public:

		Enemy();

		bool isHurtable(){return hurtable;}

        virtual QString name() = 0;

		virtual void animate()     = 0;

		virtual void hit(Object *what, Direction fromDir) = 0;

		virtual void hurt() = 0;
};

#endif // ENEMY_H
