#include "Mario.h"
#include "Enemy.h"
#include "Juego.h"
#include <QSound>

Mario::Mario(QPoint position) : Entity()
{

    moving  = false;
    running = false;
    bouncing = false;
    big = false;
    fire = false;
    transforming = false;
    transformation_counter = 0;


    jumping_duration = jump_duration_small;
    death_duration = 300;
    transformation_duration = freeze_duration;

    texture_walk[0][0] = QPixmap(loadTexture(":/imagenes/mario-small-walk-0.png"));
    texture_walk[0][1] = QPixmap(loadTexture(":/imagenes/mario-small-walk-1.png"));
    texture_walk[0][2] = QPixmap(loadTexture(":/imagenes/mario-small-walk-2.png"));
    texture_walk[1][0] = QPixmap(loadTexture(":/imagenes/mario-big-walk-0.png"));
    texture_walk[1][1] = QPixmap(loadTexture(":/imagenes/mario-big-walk-1.png"));
    texture_walk[1][2] = QPixmap(loadTexture(":/imagenes/mario-big-walk-2.png"));
    texture_stand[0]   = QPixmap(loadTexture(":/imagenes/mario-small-stand.png"));
    texture_stand[1]   = QPixmap(loadTexture(":/imagenes/mario-big-stand.png"));
    texture_jump[0]    = QPixmap(loadTexture(":/imagenes/mario-small-jump.png"));
    texture_jump[1]    = QPixmap(loadTexture(":/imagenes/mario-big-jump.png"));
    texture_dead	   = QPixmap(loadTexture(":/imagenes/mario-small-fall.png"));
    texture_stop	   = QPixmap(loadTexture(":/imagenes/mario-big-.png"));
    texture_small_to_big[0] = texture_stand[0];
    texture_small_to_big[1] = QPixmap(loadTexture(":/imagenes/mario-med-stand.bmp"));
    texture_small_to_big[2] = texture_stand[1];
    texture_small_to_big[3] = QPixmap(loadTexture(":/imagenes/mario-med-stand.bmp"));

    setPixmap(texture_stand[0]);
    setPos(position-QPoint(0, pixmap().height()));


    setZValue(3);
}


void Mario::jump()
{

    if(jumping)
        return;


    startJumping();


    if(jumping)
        QSound::play( ":/musica/jump-small.wav");
}

void Mario::stop()
{

}



void Mario::startTransformation()
{

    transforming = true;


    transformation_counter = big ? 0 : 2*transf_div;


    freeze();
}


void Mario::endTransformation()
{

    transforming = false;


    transformation_counter = 0;


    int dy = pixmap().height()-(big ? texture_stand[1] : texture_stand[0]).height();
    setY(y()+dy);
}


void Mario::animate()
{

    if(jumping == false && bouncing)
    {
        bouncing = false;
        jumping_duration = big ? jump_duration_big : jump_duration_small;
    }


    if(phantom)
    {
        phantom_counter++;
        if(phantom_counter > phantom_duration)
            endPhantom();
    }


    if(transforming)
    {
        transformation_counter++;
        if(transformation_counter > transformation_duration)
            endTransformation();
    }


    if(transforming)
    {
        int prev = ((transformation_counter-1)/transf_div)%4;
        int curr = (transformation_counter/transf_div)%4;
        int dy = texture_small_to_big[prev].height()-texture_small_to_big[curr].height();
        setPixmap(texture_small_to_big[(transformation_counter/transf_div)%4]);
        setY(y()+dy);
    }
    else if(dying || dead)
        setPixmap(texture_dead);
    else if(moving && !jumping && !falling)
        setPixmap(texture_walk[big][(walk_counter++/(running ? running_div : walk_div))%3]);
    else if(jumping || falling)
        setPixmap(texture_jump[big]);
    else
        setPixmap(texture_stand[big]);


    if(dir == LEFT)
        setPixmap(pixmap().transformed(QTransform().scale(-1,1)));
}


void Mario::hit(Object *what, Direction fromDir)
{

    Enemy *enemy = dynamic_cast<Enemy*>(what);
    if(enemy)
    {

        if(fromDir == DOWN && enemy->isHurtable())
        {

            bounce();
        }


    }
}


void Mario::bounce()
{
    falling = false;
    bouncing = true;
    jumping_duration = jump_duration_tiny;
    startJumping();
}


void Mario::die()
{

    Entity::die();


    collidable = false;


    QSound::play(":/musica/death.wav");


    freeze();


    jumping_speed = 1;
    falling_speed = 1;
    startJumping();
}



void Mario::setRunning(bool _running)
{

    if(running == _running)
        return;


    running = _running;


    if(running)
        moving_speed *= 2;
    else
        moving_speed /= 2;
}
