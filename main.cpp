#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include"gamePlay.h"
#include "table.h"
#include "shape.h"
#define HEIGHT 600
#define WIDTH 600
void key(unsigned char key,int s,int e);



GLfloat angle=0.0f;
float xc=0.0f,yc=0.0f,zc=0.0f;

Shape shape;
Table table(&shape);
GamePlay game(&table,&shape);
GLuint displayListIndex;//display list for frame table


void BitmapText(char *str, int wcx, int wcy)
{
	glRasterPos2i(wcx, wcy);
	for (int i=0; str[i] != '\0'; i++) {
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str[i]);
	}
}
void reshape(int w,int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,1.0f,1.0f,400);
    gluLookAt(/*eye*/20.0f,-70.0f,250.0f,/*centere*/20.0f,-70.0f,0.0f,/*upvector*/0.0f,1.0f,0.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void initDraw()
{
    glEnable(GL_DEPTH_TEST);
    displayListIndex = glGenLists(1);
    glNewList(displayListIndex, GL_COMPILE);
        game.drawFrameTable();
    glEndList();
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 0.0f, 1.0f );
    glPushMatrix();
        glRotatef(angle,0.0f,1.0f,0.0f);
        glTranslatef(xc,yc,zc);
        glCallList(displayListIndex);
        game.drawShape(game.getShapeType(),game.getShapeStatus(),game.getX(),game.getY());//current shape
        game.drawShape(game.getNextShapeType(),game.getNextShapeStatus(),-11,-4);//next shape
        char msg[50];
        int line=0;
        glColor3f(0.5f,1.0f,0.2f);
        for(int i=1;i<42;i++)
        {
            sprintf(msg,"%d",line);
            BitmapText(msg, -9, -(i*cubeSize*1.3));
            line++;
        }
        sprintf(msg, "Score: %d",game.getScore());
        BitmapText(msg, -50, 0);
        sprintf(msg, "Level: %d",game.getLevel());
        BitmapText(msg, -50, -8);
        game.drawTable();

    glPopMatrix();
    glutPostRedisplay();
    glutSwapBuffers();
}
void specialKey(int key,int s,int t)
{
    switch(key)
    {
        //move
        case GLUT_KEY_RIGHT:
            game.moveXright();
            break;
        case GLUT_KEY_LEFT:
            game.moveXleft();
            break;
        case GLUT_KEY_DOWN:
            game.gamePlay();
            break;
        case GLUT_KEY_END:
            while(game.gamePlay()==true);
            break;
    }
}
void key(unsigned char key,int s,int e)
{
    switch(key)
    {
        //exit
        case 27:
            exit(0);
        //PICES
        case 'z':
            game.switchShapeType();
            break;
        case 'x':
            game.rotationShape();
            break;
        case 'a':
            angle-=3.0f;
            break;
        case 'd':
            angle+=3.0f;
            break;
    }
}
void update(int time)
{
    if(!game.isGameOver())
        game.gamePlay();
    else
    {
        std::cout<<"&&&&&&&&&& GAME OVER &&&&&&&&&&&\n";
        exit(0);
    }
    glutTimerFunc(game.getTime(),update,0);
    glutPostRedisplay();
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowPosition(400,20);
    glutInitWindowSize(HEIGHT,WIDTH);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("Tetris");
    initDraw();
    glutReshapeFunc(reshape);
    glutDisplayFunc(draw);
    glutKeyboardFunc(key);
    glutSpecialFunc(specialKey);
    glutTimerFunc(0,update,0);
    glutMainLoop();
    return 0;
}
