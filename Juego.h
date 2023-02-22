#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QSound>
#include <QString>

#include "Mario.h"
#include "Nivel.h"

class Juego : public QGraphicsView
{ 
	Q_OBJECT 
	
	enum game_state{READY, RUNNING, PAUSE, GAME_OVER};

	private:

        static Juego* uniqueInstance;

        Juego(QGraphicsView *parent=0);

        QGraphicsScene *scene;

        Mario *mario;

        QTimer engine;

        game_state cur_state;

        QSound *music;

	protected:

		virtual void keyPressEvent(QKeyEvent *e);

		virtual void keyReleaseEvent(QKeyEvent *e);


	public: 
		
        static Juego* instance();

		QGraphicsScene* getScene(){return scene;}

	public slots:

        void advance();

        void reset();

		void start();
};

#endif // JUEGO_H
