#ifndef SHAPE_H
#define SHAPE_H
#include <GL/glut.h>
#define cubeSize 3.0f
#define postionZ 0.0f
#define SHIFT_CUBE 1.0f
#define SRART_SHAPES 7
typedef enum {QUAD, STICK, L, MIRRIR_L, S, MIRROR_S, FLIP_K} typeShape;
typedef enum {SKIP=6,PIVOT=0,BREAK=8,END=9} blockType;
class Shape
{
    public:
        Shape();
        friend void cube(GLfloat x,GLfloat y);
        GLbyte checkBlock(int type,int stats,int x, int y);
        int getTypeShape(){return this->type;};
        int getStatusShape(){return this->status;};
        void setTypeShape(int ntype){this->type=ntype;};
        void setStatusShape(int nstatus){this->status=nstatus;};
    private:
        int type;
        int status;
};
#endif // SHAPE_H
