#include "gamewindow.h"
#include <QApplication>

std::string DEFAULT_PATH_TO_GAME_MAP = "in.txt";

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    GameWindow w(DEFAULT_PATH_TO_GAME_MAP);
    w.show();
    return a.exec();
}
