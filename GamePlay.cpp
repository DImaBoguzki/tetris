#include "GamePlay.h"
#include <iostream>//color vectors
GLfloat color[SUM_OF_COLOR][3]={
                        {1.0f,0.0f,0.0f},   //red
                        {0.0f,1.0f,0.0f},   //green
                        {0.0f,0.0f,1.0f},   //blue
                        {0.0f,0.0f,0.0f}    //black
                    };

GamePlay::GamePlay(Table *ptable,Shape *pshape){
    this->table=ptable;
    this->shape=pshape;
    this->x=6;
    this->y=-1;
    this->nextX=6;
    this->nextY=0;
    this->shape->setTypeShape(0);
    this->shape->setStatusShape(1);
    this->nextShapeType=getRand(0,6);
    this->nextShapeStatus=getRand(0,3);
    this->gameOver=false;
    this->time=500;
    this->level=1;
    this->colorIndex=getRand(0,SUM_OF_COLOR);
}
GamePlay::~GamePlay()
{
    //dtor
}
int GamePlay::getRand(int from, int to)
{
	return rand() % (to - from +1) +from;
}
void GamePlay::createNewShape()
{
    this->x=this->nextX;
    this->y=this->nextY;
    this->shape->setTypeShape(this->nextShapeType);
    this->shape->setStatusShape(this->nextShapeStatus);
    this->nextX=6;
    this->nextY=-1;
    this->colorIndex=getRand(0,3);
    this->nextShapeType=getRand(0,6);
    this->nextShapeStatus=getRand(0,SUM_OF_COLOR);
}
void GamePlay::drawShape(int type,int stats,int x,int y)
{
    glColor3fv(color[this->colorIndex]);
    this->table->drawShape(type,stats,x,y);
}
void GamePlay::drawTable()
{
    this->table->drawTable();
}
void GamePlay::rotationShape()
{
    int tmp=getShapeStatus();
    if((tmp+1)==4)
    {
        if(checkMoveShape(x,y,getShapeType(),0)==true)
            this->shape->setStatusShape(0);
    }
    else
        if(checkMoveShape(x,y,getShapeType(),(tmp+1))==true)
            this->shape->setStatusShape(tmp+1);
}
void GamePlay::storeShape(int x,int y)
{
    int posX=0;
    int posY=0;

    bool flagEnd=false;
    for(int i=0;i<5;i++)
    {
        posY=shape->checkBlock(shape->getTypeShape(),shape->getStatusShape(),0,i); // get the positions y;
        for(int j=1;j<5;j++)
        {
            if(shape->checkBlock(shape->getTypeShape(),shape->getStatusShape(),j,i)==BREAK)
                break;
            else if(shape->checkBlock(shape->getTypeShape(),shape->getStatusShape(),j,i)==END)
            {
                flagEnd=true;
                break;
            }
            else if(shape->checkBlock(shape->getTypeShape(),shape->getStatusShape(),j,i)!=SKIP)
            {
                posX=shape->checkBlock(shape->getTypeShape(),shape->getStatusShape(),j,i);
                this->table->setCube(x+posX,(y*(-1))+posY);
            }
        }
        if(flagEnd)
            break;
    }
    createNewShape();
}
//valid positions on table
bool GamePlay::isValidPos(int x,int y)
{
    if(this->table->isValidPos(x,y)==true)
        return true;
    return false;
}
bool GamePlay::checkMoveShape(int x,int y,int typeShape,int statusShape)
{
    int posX=0;
    int posY=0;
    bool flagEnd=false;
    for(int i=0;i<5;i++)
    {
        posY=(shape->checkBlock(typeShape,statusShape,0,i)); // get the positions y;
        for(int j=1;j<5;j++)
        {
            if(shape->checkBlock(typeShape,statusShape,j,i)==BREAK)
                break;
            else if(shape->checkBlock(typeShape,statusShape,j,i)==END)
            {
                flagEnd=true;
                break;
            }
            else if(shape->checkBlock(typeShape,statusShape,j,i)!=SKIP)
            {
                posX=(shape->checkBlock(typeShape,statusShape,j,i));
                if(isValidPos(x+posX,(y*(-1))+posY)==false)
                    return false;
            }
        }
        if(flagEnd)
            break;
    }
    return true;
}
void GamePlay::moveXleft()
{
    if(checkMoveShape(this->x-1,this->y,getShapeType(),getShapeStatus()))
        this->x--;
}
void GamePlay::moveXright()
{
    if(checkMoveShape(this->x+1,this->y,getShapeType(),getShapeStatus()))
        this->x++;
}
bool GamePlay::gamePlay()
{
    if(checkMoveShape(this->x,this->y-1,getShapeType(),getShapeStatus()))
    {
        this->y--;
        return true;
    }
    else
    {
        std::cout<<"flag ";
        storeShape(this->x,this->y);
        table->deleteLines();
        setScore();
        return false;
    }
}
void GamePlay::switchShapeType()
{
    int tmp=getShapeType();
    if((tmp+1)==7)
        this->shape->setTypeShape(0);
    else
        this->shape->setTypeShape((tmp+1));
}
void GamePlay::setScore()
{
    if(getScore()>=160 && this->level==1)
    {
        //level 2
        this->level++;
        this->time-=150;
    }
    else if(getScore()>=460 && this->level==2)
    {
        //level 3
        std::cout<<level<<"\n";
        this->level++;
        this->time-=150;
    }
    else if(getScore()>=1000 && this->level==3)
    {
        //level 4
        std::cout<<level<<"\n";
        this->level++;
        this->time-=150;
    }

}
