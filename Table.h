#ifndef TABLE_H
#define TABLE_H
#include <GL/glut.h>
#include "shape.h"
#define WIDTH_TABLE 16
#define HEIGHT_TABLE 40
#define POINTS 40
typedef enum{EMPTY,FILED} statusBlockTable;
class Table
{
    public:
        Table(Shape *s);
        void drawFrameTable();
        void restartTable();
        void drawTable();
        void drawShape(int type,int stats,int x, int y);
        void setCube(int x,int y);
        bool isValidPos(int x,int y);
        bool isGameOver(){return this->gameOver;};
        void deleteLines();
        int getScore(){return this->score;};
    private:
        Shape *shape;
        int heightTable;
        int score;
        bool gameOver;
        GLbyte table[HEIGHT_TABLE][WIDTH_TABLE];
        bool checkLine(int line);
        void copyLine(int line,int numOfLine);
};
#endif // TABLE_H
