#include "shape.h"
//THE FIRST COLUMNS IS INDEX OF SHIFT Y,BREAK LOOP(X)==8,BREAK BOTH LOOPS==9,SKIP==6, PIVOT==0(THE ACTUAL X,Y)
// ANY OTHER NUMBERS IN OTHERS COLUMNS IS THE SHIFT OF X
const GLbyte shapeType [7][4][5][5]=
{
    {       // quads 0
        {
            { 0,-1, 0, 8, 6},//PIVOT
            { 1,-1, 0, 9, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6}
        },
        {
            { 0,-1, 0, 8, 6},//PIVOT
            { 1,-1, 0, 9, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6}
        },
        {
            { 0,-1, 0, 8, 6},//PIVOT
            { 1,-1, 0, 9, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6}
        },
        {
            { 0,-1, 0, 8, 6},//PIVOT
            { 1,-1, 0, 9, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6}
        }
    }, // end quads
    {
        {   //stick 1
            {-1, 0, 8, 6, 6},
            { 0, 0, 8, 6, 6},//PIVOT
            { 1, 0, 8, 6, 6},
            { 2, 0, 9, 6, 6},
            { 6, 6, 6, 6, 6}
        },
        {
            { 0,-1, 0, 1, 2},//PIVOT
            { 9, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6}
        },
        {
            {-1, 0, 8, 6, 6},
            { 0, 0, 8, 6, 6},//PIVOT
            { 1, 0, 8, 6, 6},
            { 2, 0, 9, 6, 6},
            { 6, 6, 6, 6, 6}
        },
        {
            { 0,-1, 0, 1, 2},//PIVOT
            { 9, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6}
        }
    },   // end stick
    {
        {   // L 2
            {-1, 0, 8, 6, 6},
            { 0, 0, 6, 6, 6},//PIVOT
            { 1, 0, 1, 9, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6}
        },
        {
            { 0,-1, 0, 1, 8},
            { 1,-1, 9, 6, 6},//PIVOT
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6}
        },
        {
            {-1,-1, 0, 8, 6},
            { 0, 6, 0, 8, 6},//PIVOT
            { 1, 6, 0, 9, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6}
        },
        {
            {-1,-1, 8, 6, 6},
            { 0,-1, 0, 1, 9},//PIVOT
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6}
        }   //end L
    },
    {
        {   //mirror L 3
            {-1, 6, 0, 8, 6},
            { 0, 6, 0, 8, 6},//PIVOT
            { 1,-1, 0, 9, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6}
        },
        {
            {-1,-1, 8, 6, 6},
            { 0,-1, 0, 1, 9},//PIVOT
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6}
        },
        {
            {-1, 0, 1, 8, 6},
            { 0, 0, 8, 6, 6},//PIVOT
            { 1, 0, 9, 6, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6}
        },
        {
            { 0,-1, 0, 1, 6},//PIVOT
            { 1, 6, 6, 1, 9},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6}
        }
    },  //end mirror L
    {
        {   // S 4
            { 0, 6, 0, 1, 8},//PIVOT
            { 1,-1, 0, 9, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6}
        },
        {
            {-1,-1, 8, 6, 6},
            { 0,-1, 0, 8, 6},//PIVOT
            { 1, 6, 0, 9, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6}
        },
        {
            { 0, 6, 0, 1, 8},//PIVOT
            { 1,-1, 0, 9, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6}
        },
        {
            {-1,-1, 8, 6, 6},
            { 0,-1, 0, 8, 6},//PIVOT
            { 1, 6, 0, 9, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6}
        }
    },  //END S
    {
        {   // mirror S 5
            { 0,-1, 0, 8, 6},//PIVOT
            { 1, 6, 0, 1, 9},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6}
        },
        {
            {-1, 6, 1, 8, 6},
            { 0, 0, 1, 8, 6},//PIVOT
            { 1, 0, 9, 6, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6}
        },
        {
            { 0,-1, 0, 8, 6},//PIVOT
            { 1, 6, 0, 1, 9},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6}
        },
        {
            {-1, 6, 1, 8, 6},
            { 0, 0, 1, 8, 6},//PIVOT
            { 1, 0, 9, 6, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6}
        }   //end mirror S
    },
    {
        {   //flip K
            {-1 ,6, 0, 8, 6},
            { 0,-1, 0, 1, 9},//PIVOT
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6}
        },
        {
            {-1, 0, 8, 6, 6},
            { 0, 0, 1, 8, 6},
            { 1, 0, 9, 6, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6}
        },
        {
            { 0,-1, 0, 1, 8},
            { 1, 6, 0, 9, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6}
        },
        {
            {-1, 6, 0, 8, 6},
            { 0,-1, 0, 8, 6},
            { 1, 6, 0, 9, 6},
            { 6, 6, 6, 6, 6},
            { 6, 6, 6, 6, 6}
        }
    }
};

Shape::Shape()
{
    this->type=0;
    this->status=0;
}
GLbyte Shape::checkBlock(int type,int stats,int x, int y)
{
    if(shapeType[type][stats][y][x]==SKIP)
        return SKIP;
    else if(shapeType[type][stats][y][x]==BREAK)
        return BREAK;
    else if(shapeType[type][stats][y][x]==PIVOT)
        return PIVOT;
    return shapeType[type][stats][y][x];
}
void cube(GLfloat x,GLfloat y)
{
                glBegin(GL_QUADS);
                    glVertex3f(x,y,postionZ);
                    glVertex3f(x,y+cubeSize,postionZ);
                    glVertex3f(x+cubeSize,y+cubeSize,postionZ);
                    glVertex3f(x+cubeSize,y,postionZ);
                glEnd();
                glBegin(GL_QUADS);
                    glVertex3f(x,y,postionZ+cubeSize);
                    glVertex3f(x,y+cubeSize,postionZ+cubeSize);
                    glVertex3f(x+cubeSize,y+cubeSize,postionZ+cubeSize);
                    glVertex3f(x+cubeSize,y,postionZ+cubeSize);
                glEnd();
                glBegin(GL_QUADS);
                    glVertex3f(x,y,postionZ);
                    glVertex3f(x,y,postionZ+cubeSize);
                    glVertex3f(x+cubeSize,y,postionZ+cubeSize);
                    glVertex3f(x+cubeSize,y,postionZ);
                glEnd();
                glBegin(GL_QUADS);
                    glVertex3f(x,y+cubeSize,postionZ);
                    glVertex3f(x,y+cubeSize,postionZ+cubeSize);
                    glVertex3f(x+cubeSize,y+cubeSize,postionZ+cubeSize);
                    glVertex3f(x+cubeSize,y+cubeSize,postionZ);
                glEnd();
                glBegin(GL_QUADS);
                    glVertex3f(x,y,postionZ);
                    glVertex3f(x,y,postionZ+cubeSize);
                    glVertex3f(x,y+cubeSize,postionZ+cubeSize);
                    glVertex3f(x,y+cubeSize,postionZ);
                glEnd();
                glBegin(GL_QUADS);
                    glVertex3f(x+cubeSize,y,postionZ);
                    glVertex3f(x+cubeSize,y,postionZ+cubeSize);
                    glVertex3f(x+cubeSize,y+cubeSize,postionZ+cubeSize);
                    glVertex3f(x+cubeSize,y+cubeSize,postionZ);
                glEnd();
}
