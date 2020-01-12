#include "table.h"
#include <iostream>
//constructor
Table::Table(Shape *s)
{
    /*
    for(int i=0;i<HEIGHT_TABLE;i++)
    {
        for(int j=0;j<WIDTH_TABLE;j++)
            this->table[i][j]=EMPTY;
    }*/
    for(int i=HEIGHT_TABLE-1;i>10;i--)
    {
        for(int j=0;j<WIDTH_TABLE-1;j++)
            this->table[i][j]=FILED;
    }
    this->shape=s;
    this->heightTable=0;
    this->score=0;
    this->gameOver=false;
}
void Table::drawFrameTable()
{
    //front
    glColor3f(1.0f,0.0f,1.0f);
    glBegin(GL_LINES);
        //top
        glVertex3f(0.0f,0.0f,GLfloat(postionZ+cubeSize));
        glVertex3f(GLfloat( (WIDTH_TABLE*(cubeSize+SHIFT_CUBE)-SHIFT_CUBE)),0.0f,GLfloat(postionZ+cubeSize));
        //button
        glVertex3f(0.0f, GLfloat(-(HEIGHT_TABLE*(cubeSize+SHIFT_CUBE)-SHIFT_CUBE)), GLfloat(postionZ+cubeSize));
        glVertex3f(GLfloat((WIDTH_TABLE*(cubeSize+SHIFT_CUBE)-SHIFT_CUBE)), GLfloat(-(HEIGHT_TABLE*(cubeSize+SHIFT_CUBE)-SHIFT_CUBE)), GLfloat(postionZ+cubeSize));
        //left
        glVertex3f(0.0f, 0.0f, GLfloat(postionZ+cubeSize));
        glVertex3f(0.0f, GLfloat(-(HEIGHT_TABLE*(cubeSize+SHIFT_CUBE)-SHIFT_CUBE)), GLfloat(postionZ+cubeSize));
        //right
        glVertex3f(GLfloat((WIDTH_TABLE*(cubeSize+SHIFT_CUBE)-SHIFT_CUBE)), 0.0f, GLfloat(postionZ+cubeSize));
        glVertex3f(GLfloat((WIDTH_TABLE*(cubeSize+SHIFT_CUBE)-SHIFT_CUBE)), GLfloat(-(HEIGHT_TABLE*(cubeSize+SHIFT_CUBE)-SHIFT_CUBE)), GLfloat(postionZ+cubeSize));
    glEnd();
    //back
    glColor3f(0,0,0);
    glBegin(GL_LINES);
        //top
        glVertex3f(0.0f,0.0f,GLfloat(postionZ));
        glVertex3f(GLfloat( (WIDTH_TABLE*(cubeSize+SHIFT_CUBE)-SHIFT_CUBE)),0.0f,GLfloat(postionZ));
        //button
        glVertex3f(0.0f, GLfloat(-(HEIGHT_TABLE*(cubeSize+SHIFT_CUBE)-SHIFT_CUBE)), GLfloat(postionZ));
        glVertex3f(GLfloat((WIDTH_TABLE*(cubeSize+SHIFT_CUBE)-SHIFT_CUBE)), GLfloat(-(HEIGHT_TABLE*(cubeSize+SHIFT_CUBE)-SHIFT_CUBE)), GLfloat(postionZ));
        //left
        glVertex3f(0.0f, 0.0f, GLfloat(postionZ));
        glVertex3f(0.0f, GLfloat(-(HEIGHT_TABLE*(cubeSize+SHIFT_CUBE)-SHIFT_CUBE)), GLfloat(postionZ));
        //right
        glVertex3f(GLfloat((WIDTH_TABLE*(cubeSize+SHIFT_CUBE)-SHIFT_CUBE)), 0.0f, GLfloat(postionZ));
        glVertex3f(GLfloat((WIDTH_TABLE*(cubeSize+SHIFT_CUBE)-SHIFT_CUBE)), GLfloat(-(HEIGHT_TABLE*(cubeSize+SHIFT_CUBE)-SHIFT_CUBE)), GLfloat(postionZ));
    glEnd();
}

void Table::restartTable()
{
    for(int i=0;i<HEIGHT_TABLE;i++)
    {
        for(int j=0;j<WIDTH_TABLE;j++)
            this->table[i][j]=EMPTY;
    }
}
void cube(GLfloat x,GLfloat y);
void Table::drawShape(int type,int stats,int x, int y)
{
    int tmpx=x*(cubeSize+SHIFT_CUBE);
    int tmpy=y*(cubeSize+SHIFT_CUBE)-cubeSize;
    int posX=0;
    int posY=0;
    bool flagEnd=false;
    for(int i=0;i<5;i++)
    {
        posY=shape->checkBlock(type,stats,0,i); // get the positions y;
        for(int j=1;j<5;j++)
        {
            if(shape->checkBlock(type,stats,j,i)==BREAK)
                break;
            else if(shape->checkBlock(type,stats,j,i)==END)
            {
                flagEnd=true;
                break;
            }
            else if((posX=shape->checkBlock(type,stats,j,i))!=SKIP)
                cube(GLfloat(tmpx+(posX*(cubeSize+SHIFT_CUBE))),GLfloat(tmpy-(posY*(cubeSize+SHIFT_CUBE))));
        }
        if(flagEnd)
            break;
    }
}
void Table::drawTable()
{
    glColor3f(0.0f,0.0f,0.0f);
    for(int i=0,y=-cubeSize;i<HEIGHT_TABLE;i++,y-=(cubeSize+SHIFT_CUBE))
    {
        for(int j=0,x=0.0f;j<WIDTH_TABLE;j++,x+=(cubeSize+SHIFT_CUBE))
        {
            if(this->table[i][j]==FILED)
            {
                cube(GLfloat(x),GLfloat(y));
            }
        }
    }
}
void Table::setCube(int x,int y)
{
    if(isValidPos(x,y))
        this->table[int(y)][int(x)]=FILED;
    if(this->table[0][5]==FILED || this->table[0][6]==FILED || this->table[0][7]==FILED)
    {
        std::cout<<"game over\n";
        this->gameOver=true;
    }
}

bool Table::isValidPos(int x,int y)
{
    if(x>=WIDTH_TABLE || x<0 || y>=HEIGHT_TABLE)
        return false;
    if(this->table[y][x]==FILED)
        return false;
    return true;
}
bool Table::checkLine(int line)
{
    if(line<0 || line>=HEIGHT_TABLE)
        return false;
    for(int i=0;i<WIDTH_TABLE;i++)
        if(this->table[line][i]==EMPTY)
            return false;
    return true;
}

void Table::copyLine(int line,int numOfLine)
{
    int countDeleteLines=0;
    if(line<0 || line>=HEIGHT_TABLE)
        return;
    for(int i=line;i>=0;i--)
    {
        for(int j=0;j<WIDTH_TABLE;j++)
        {
            if(i-(numOfLine)<0)
                break;
            this->table[i][j]=this->table[i-(numOfLine)][j];
        }
        countDeleteLines++;
    }
}
void Table::deleteLines()
{
    int countLines=0;
    int line=this->heightTable;
    while(line<HEIGHT_TABLE)
    {
        if(checkLine(line))
            countLines++;
        else if(countLines>0)
            break;
        line++;
    }
    if(countLines>0)
    {
        score+=(POINTS*countLines);
        copyLine(line-1,countLines);
    }
}
