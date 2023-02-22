#include <QApplication>
#include <QKeyEvent>
#include <QScrollBar>
#include <QWheelEvent>
#include <QSound>
#include <QThread>
#include <QIcon>
#include "Juego.h"
#include "Object.h"
#include "Entity.h"
#include "Mario.h"

Juego* Juego::uniqueInstance = 0;
Juego* Juego::instance()
{
	if(uniqueInstance == 0)
        uniqueInstance = new Juego();
	return uniqueInstance;
}


Juego::Juego(QGraphicsView *parent) : QGraphicsView(parent)
{
	scene = new QGraphicsScene();
	setScene(scene);
	scale(2.0,2.0);
	centerOn(0,0);
	setInteractive(false);
	setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
	setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    setWindowTitle("Juego Mario Bros");
    setWindowIcon(QIcon(":/imagenes/icon.png"));
    scene->setSceneRect(0, 0, 199, 225);

    QObject::connect(&engine, SIGNAL(timeout()), this, SLOT(advance()));
    engine.setInterval(10);

    music = new QSound(":/musica/overworld.wav");
	music->setLoops(QSound::Infinite);
	mario = 0;
    reset();

    this->setFixedHeight(2.0 * 225);
    this->setFixedWidth(400);
}

void Juego::reset()
{
    cur_state = READY;
    mario = 0;
    engine.stop();
    music->stop();
    scene->clear();
    scene->setBackgroundBrush(QBrush(Qt::white));

}

void Juego::start()
{
    if(cur_state == READY)
    {
        scene->clear();
        engine.start();
        mario = Nivel::load("Nivel-1", scene);

        if(!mario)
        {
        }
        else
            music->play();

        cur_state = RUNNING;
    }
}

void Juego::keyPressEvent(QKeyEvent *e)
{
    if(cur_state == READY)
        start();

    if(cur_state != RUNNING)
        return;

    if(e->key() == Qt::Key_Right || e->key() == Qt::Key_Left)
    {
        mario->setMoving(true);
        mario->setDirection(e->key() == Qt::Key_Right ? Direction::RIGHT : Direction::LEFT);
    }

    if(e->key() == Qt::Key_Up)
        mario->jump();
    {
        if(e->key() == Qt::Key_Down)
            mario->stop();
    }
}

void Juego::keyReleaseEvent(QKeyEvent *e)
{
	if(cur_state != RUNNING)
		return;

    if(e->key() == Qt::Key_Right || e->key() == Qt::Key_Left)
        mario->setMoving(false);

	if(e->key() == Qt::Key_Z)
		mario->setRunning(false);
}



void Juego::advance()
{

    if(cur_state != RUNNING)
		return;

	if(mario->isDying() || mario->isTransforming())
	{	
		mario->animate();
		mario->advance();
		return;
	}

    for(auto & item : scene->items())
    {
		Object* obj = dynamic_cast<Object*>(item);
		if(obj)
		{
			obj->animate();
			obj->advance();

			Entity* entity_obj = dynamic_cast<Entity*>(obj);
			if(entity_obj && entity_obj->isDead())
			{

				scene->removeItem(entity_obj);
				delete entity_obj;
			}
		}
    }

    centerOn(mario);
}
