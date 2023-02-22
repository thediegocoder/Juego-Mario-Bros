#include <QApplication>
#include "Juego.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    Juego::instance()->show();

    return app.exec();
}
