#ifndef ENTITY_H
#define ENTITY_H


#include "Object.h"
#include <QString>


class Entity : public Object
{
    protected:

        int moving_speed;

        int moving_speed_div;

        int jumping_speed;

        int jumping_duration;

        int jump_counter;

        int death_counter;

        int walk_counter;

        int phantom_counter;

        int freeze_counter;

        int falling_speed;

        int death_duration;

        int phantom_duration;

        int freeze_duration;

        bool moving;

        bool jumping;

        bool falling;

        bool phantom;

        bool collectable;

        bool dying;

        bool dead;

        bool freezed;

        bool slow;

        QPointF prevPos;

        Object *walkable_object;

        Direction dir;


        virtual void startJumping();

        virtual void endJumping();

		virtual void startPhantom();

		virtual void endPhantom();

    public:

        Entity();

		bool isDead(){return dead;}

		bool isDying(){return dying;}

		bool isPhantom(){ return phantom; }

		bool isCollectable() { return collectable;}

		bool isFalling() {return falling;}

		virtual void setDirection(Direction _dir) { dir = _dir;}

		virtual void setMoving(bool _moving) { if(!dying) moving = _moving;}

        virtual QString name()     = 0;

        virtual void animate()         = 0;

        virtual void advance();

        virtual void solveCollisions();

        virtual void hit(Object *what, Direction fromDir) = 0;

		virtual void die();

		virtual void freeze(){ freezed = true;}
};

#endif // ENTITY_H
