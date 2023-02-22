#ifndef MARIO_H
#define MARIO_H

#include "Entity.h"
#include <QString>

class Mario : public Entity
{
    protected:

       int transformation_counter;

        int transformation_duration;

        static const int jump_duration_tiny  = 30;

        static const int jump_duration_small = 70;

        static const int jump_duration_big   = 90;

        static const int walk_div    = 6;

        static const int running_div = 4;

        static const int transf_div  = 5;

        QPixmap texture_walk[2][3];

        QPixmap texture_stand[2];

        QPixmap texture_jump[2];

        QPixmap texture_dead;

        QPixmap texture_stop;

        QPixmap texture_small_to_big[4];

        bool big;

        bool fire;

        bool bouncing;

        bool running;

        bool transforming;

        void bounce();

        void startTransformation();

        void endTransformation();

    public:

        Mario(QPoint position);

        bool isBig(){return big;}

        bool isTransforming(){return transforming;}

        void setRunning(bool _running);

        virtual QString name(){ return "Mario";}

        virtual void animate();

        virtual void hit(Object *what, Direction fromDir);

        virtual void die();

        void mushroomEat(bool red = true);

        void flowerEat();

        void hurt();

        void jump();

        void stop();
};

#endif // MARIO_H
