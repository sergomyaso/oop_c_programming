#include "gamewindow.h"
#include "ui_gamewindow.h"

void GameWindow::initLabirintVector() {
    for (size_t i = 0; i < WIDTH_MAP * HEIGHT_MAP; i++) {
        if (MAP_MATRIX[i] == -BLANK_OF_LABIRINT)
            this->labirint.push_back(new LabirintPart(false));
        else
            this->labirint.push_back(new LabirintPart(true));
    }
}

void GameWindow::updateLabelLifesCounter() {
    this->ui->lablelLifes->setText(QString::number(this->countLifes));
    countLifes--;
}

void GameWindow::recoverFoodMap() {
    for (auto item : simpleFoods) {
        scene->addItem(item);
    }
    for (auto item : this->superFoods) {
        scene->addItem(item);
    }
}

void GameWindow::initMap() {
    initLabirintVector();
    generalCountFood = 0;
    for (int i = X_OF_BOUNDING__RECT_SCENE; i < X_OF_BOUNDING__RECT_SCENE + WIDTH_OF_BOUNDING__RECT_SCENE; i += LabirintPart::WIDTH_OF_BOUNDING_RECT) {
        size_t indexOfRow = (WIDTH_OF_BOUNDING__RECT_SCENE / 2 + i) / LabirintPart::WIDTH_OF_BOUNDING_RECT;
        for (int j = Y_OF_BOUNDING__RECT_SCENE; j < Y_OF_BOUNDING__RECT_SCENE + HEIGHT_OF_BOUNDING__RECT_SCENE; j += LabirintPart::HEIGHT_OF_BOUNDING_RECT) {
            size_t indexOfColumn = (HEIGHT_OF_BOUNDING__RECT_SCENE / 2 + j) / LabirintPart::HEIGHT_OF_BOUNDING_RECT;
            if (labirint[indexOfRow * WIDTH_MAP + indexOfColumn]->isBlocked()) {
                scene->addItem(labirint[indexOfRow * WIDTH_MAP + indexOfColumn]);
                labirint[indexOfRow * WIDTH_MAP + indexOfColumn]->setPos(j, i);
            }
            else {
                generalCountFood++;
                simpleFoods.push_back(new SimpleFood());
                simpleFoods[simpleFoods.size() - 1]->setPos(j, i);
            }
        }
    }

    for (int i = 0; i < COUNT_OF_GHOSTS; i++) {
        superFoods.push_back(new SuperFood());
        superFoods[superFoods.size() - 1]->setPos(BASIC_GHOST_TARGET[i].first, BASIC_GHOST_TARGET[i].second);
    }
}

void GameWindow::setDeadColor() {
    for (auto ghost : ghosts) {
        ghost->setColor(deadModeColor);
    }
}

void GameWindow::slotCheckPacmanPosition() {
    QList<QGraphicsItem*> colliding = scene->collidingItems(pacman);
    for (QGraphicsItem* item : colliding) {
        if (dynamic_cast<LabirintPart*> (item)) {
            pacman->isStay = true;
            pacman->setPos(pacman->mapToParent(0, 2 * HeroPacman::STEP));
        }
        if (dynamic_cast<Ghost*> (item)) {
            if (isDeadMode) {
                item->setPos(GHOST_DEFAULT_POS.first, GHOST_DEFAULT_POS.second);
                for (int i = 0; i < ghosts.size(); i++) {
                        ghosts[i]->cleanPathToTarget();
                }
            }
            else {
                this->trackActionGameTimer->stop();
                this->deadModeTimer->stop();
                this->ghostStartTimer->stop();
                if (countLifes > 0) {
                    rebootGame();
                    updateLabelLifesCounter();
                }
                else {
                    startNewGame();
                }
                if (foodCounter == simpleFoods.size()) {
                    int tempScoreRsults = scoreCounter;
                    startNewGame();
                    scoreCounter = tempScoreRsults;
                }
            }
        }
        if (dynamic_cast<SimpleFood*> (item)) {
            scene->removeItem(item);
            this->scoreCounter += SCORE_STEP;
            this->foodCounter++;
        }
        if (dynamic_cast<SuperFood*> (item)) {
            isDeadMode = true;
            setDeadColor();
            for (int i = 0; i < ghostsStrategy.size(); i++) {
                 ghostsStrategy[i]->swithDeadMode();
             }
            deadModeTimer->start(DEAD_MODE_TIME);
            scene->removeItem(item);
        }
    }
}

void GameWindow::updateLcdScoreCounter() {
    this->ui->lcdScoreCounter->display((int)this->scoreCounter);
}

void GameWindow::finishDeadMode() {
    recoverGhostColors();
    this->isDeadMode = false;
    for (int i = 0; i < ghosts.size(); i++) {
        ghostsStrategy[i]->swithDeadMode();
     }
    deadModeTimer->stop();
}

void GameWindow::findPathForGhost() {
   for (int i = 0; i < ghosts.size(); i++) {
        ghosts[i]->slotWalkTimer();
    }
}

void GameWindow::recoverGhostColors() {
    for (int i = 0; i < this->ghosts.size(); i++) {
        ghosts[i]->setColor(GHOST_COLORS[i]);
    }
}

void GameWindow::slotGhostStartTimer() {
    if (ghosts.size() == COUNT_OF_GHOSTS) {
        ghostStartTimer->stop();
        return;
    }
    ghosts.push_back(new Ghost(ghostsStrategy[ghosts.size()], GHOST_COLORS[ghosts.size()]));
    scene->addItem(ghosts[ghosts.size() - 1]);
    ghosts[ghosts.size() - 1]->setPos(GHOST_DEFAULT_POS.first, GHOST_DEFAULT_POS.second);
}

void GameWindow::rebootGame() {
    deleteGhosts();
    pacman->setPos(PACMAN_DEFAULT_POS.first, PACMAN_DEFAULT_POS.second);
    Sleep(LEVEL_CHANGE_TIME);
    trackActionGameTimer->start(STEP_TIME);
    slotGhostStartTimer();
    ghostStartTimer->start(SHOW_GHOST_TIME);
}

void GameWindow::deleteGhosts() {
    for (auto item : ghosts) {
        delete item;
    }
    ghosts.clear();
}

void GameWindow::startNewGame() {
    recoverFoodMap();
    isDeadMode = false;
    scoreCounter = 0;
    foodCounter = 0;
    countLifes = COUNT_OF_LIFES;
    rebootGame();
    updateLabelLifesCounter();
}

GameWindow::GameWindow(std::string pathToMapFile, QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setBackgroundBrush(QBrush(Qt::black));
    this->scene = new QGraphicsScene();
    this->scene->setSceneRect(X_OF_BOUNDING__RECT_SCENE, Y_OF_BOUNDING__RECT_SCENE, WIDTH_OF_BOUNDING__RECT_SCENE, HEIGHT_OF_BOUNDING__RECT_SCENE);
    ui->graphicsView->setScene(scene);

    try {
        game::MapLoader mapLoader(pathToMapFile, MAP_MATRIX);
        mapLoader.loadMap();
    }   catch(game::OpenFileException& exe){
        exe.showProblem();
        return;
    }
    pacman = new HeroPacman(&this->labirint);
    scene->addItem(pacman);
    ghostsStrategy = {new game::BlinkyStrategy(new game::PathLeeAlgorithm(MAP_MATRIX),BASIC_GHOST_TARGET[0], pacman, &foodCounter,&generalCountFood), new game::PinkyStrategy(new game::PathLeeAlgorithm(MAP_MATRIX),BASIC_GHOST_TARGET[1],pacman), new game::InkyStrategy(new game::PathLeeAlgorithm(MAP_MATRIX),BASIC_GHOST_TARGET[2], BASIC_GHOST_TARGET), new game::PockeyStrategy(new game::PathLeeAlgorithm(MAP_MATRIX),BASIC_GHOST_TARGET[3], pacman)};
    trackActionGameTimer = new QTimer();
    connect(trackActionGameTimer, &QTimer::timeout, pacman, &HeroPacman::slotTrackKeyTimer);
    connect(trackActionGameTimer, &QTimer::timeout, this, &GameWindow::slotCheckPacmanPosition);
    connect(trackActionGameTimer, &QTimer::timeout, this, &GameWindow::updateLcdScoreCounter);
    connect(trackActionGameTimer, &QTimer::timeout, this, &GameWindow::findPathForGhost);
    ghostStartTimer = new QTimer();
    connect(ghostStartTimer, &QTimer::timeout, this, &GameWindow::slotGhostStartTimer);
    deadModeTimer = new QTimer();
    connect(deadModeTimer, &QTimer::timeout, this, &GameWindow::finishDeadMode);
    initMap();
    startNewGame();
}

GameWindow::~GameWindow()
{
    delete ui;
}
