#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QVector>
#include <QList>
#include <QTimer>
#include <QPair>
#include <QBrush>
#include <QString>
#include <QColor>

#include "labirintpart.h"
#include "heropacman.h"
#include "ghost.h"
#include "simplefood.h"
#include "gameconstants.h"
#include "superfood.h"
#include "blinkystrategy.h"
#include "pinkystrategy.h"
#include "inkystrategy.h"
#include "pockeystrategy.h"
#include "pathalgorithm.h"
#include "maploader.h"
#include "openfileexception.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

class GameWindow : public QMainWindow {
    Q_OBJECT

private:
 static const int STEP_TIME = 1000 / 50;
 static const int DEAD_MODE_TIME = 7500;
 static const int SHOW_GHOST_TIME = 7000;
 static const int LEVEL_CHANGE_TIME = 3000;
 static const int COUNT_OF_LIFES = 3;
 static const int COUNT_OF_GHOSTS = 4;
 static const int SCORE_STEP = 20;
 const QPair<const int, const int> PACMAN_DEFAULT_POS = {0, -60};
 const QPair <const int, const int> GHOST_DEFAULT_POS = {0, -100};
 const QVector<QPair<int, int>> BASIC_GHOST_TARGET = {{240,-280}, {-220,180}, {200,180},{-240,-280}};
 const QVector<QColor> GHOST_COLORS = {QColor(Qt::red), QColor(250, 125, 246), QColor(125, 250, 250), QColor(247, 179, 5)};
 const QColor deadModeColor = QColor(Qt::blue);

 game::PathLeeAlgorithm* algorithm;
 QVector<game::RouteStrategy*> ghostsStrategy;

 /* Timers */
 QTimer* trackActionGameTimer;
 QTimer* deadModeTimer;
 QTimer* ghostStartTimer;

 /* View's elements */
 HeroPacman* pacman;
 QVector<Ghost*> ghosts;
 QVector<SimpleFood*> simpleFoods;
 QVector <SuperFood*> superFoods;
 QVector <LabirintPart*> labirint;

 /* View's parts */
 QGraphicsScene* scene;
 Ui::GameWindow *ui;

 /* Game parametres */
 int MAP_MATRIX[WIDTH_MAP * HEIGHT_MAP];
 int generalCountFood;
 int countLifes;
 int scoreCounter;
 int foodCounter;
 bool isDeadMode;
public:
    GameWindow(std::string pathToMapFile,QWidget *parent = nullptr);
    ~GameWindow();

public slots:
    void slotGhostStartTimer();
    void slotCheckPacmanPosition();

private:
    void deleteGhosts();
    void setDeadColor();
    void recoverGhostColors();
    void recoverFoodMap();
    void finishDeadMode();
    void rebootGame();
    void startNewGame();
    void updateLabelLifesCounter();
    void updateLcdScoreCounter();
    void findPathForGhost();
    void initLabirintVector();
    void initMap();
};
#endif // GAMEWINDOW_H
