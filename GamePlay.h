#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <GL/glut.h>
#include "table.h"
#include "shape.h"#define SUM_OF_COLOR 4
class GamePlay
{
    public:
        GamePlay(Table *ptable,Shape *pshape);
        virtual ~GamePlay();

        int  getRand(int from, int to);
        void createNewShape();
        bool isValidPos(int x,int y);
        void drawTable();
        void drawShape(int type,int stats,int x, int y);
        void rotationShape();
        void switchShapeType();
        int  getShapeType(){return this->shape->getTypeShape();};
        int  getShapeStatus(){return this->shape->getStatusShape();}
        void storeShape(int x,int y);
        bool checkMoveShape(int x,int y,int typeShape,int statusShape);
        int getX(){return this->x;};
        int getY(){return this->y;};
        int getTime(){return this->time;};
        void setTime(int t){this->time=t;};
        void moveXleft();
        void moveXright();
        bool isGameOver(){return this->table->isGameOver();};
        bool gamePlay();
        int getScore(){return this->table->getScore();};
        int getNextShapeType(){return this->nextShapeType;};
        int getNextShapeStatus(){return this->nextShapeStatus;};
        int getLevel(){return this->level;};
        void drawFrameTable(){this->table->drawFrameTable();};
        void setScore();

        private:
            Table *table;
            Shape *shape;
            bool gameOver;
            int nextX,nextY;
            int nextShapeType,nextShapeStatus;
            int x,y;
            int time;//speed game
            int level;
            int colorIndex;
};
#endif // GAMEPLAY_H
