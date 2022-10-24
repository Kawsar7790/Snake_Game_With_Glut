#include <GL/glut.h>
#include <GL/glut.h>
#include <ctime>
#include "game_1.h"

// to draw grids //

// one unit square = one unit of co-ordinates //
extern int score;

int gridX , gridY;
int shaap_length=5;
BOOL khabar=true;
int khabarX, khabarY;
short sDirection= RIGHT;
extern bool khelashash;

int posX[60] = {20 , 20 , 20 , 20 ,20 }, posY[60] = {20 , 19 , 18 , 17 , 16};

void initGrid( int x , int y)   // a function to initialize the co-ordinates of the grid //
{
    gridX=x;
    gridY=y;

}

void unit(int , int);

void drawGrid()
{
    for (int x=0 ; x<gridX ; x++)           // draw the whole grid ( 0 ,0 ) to ( 0, 49)//
    {
        for ( int y=0 ; y<gridY ; y++)
        {
            unit (x,y);
        }
    }

}

void unit( int x , int y)  //code of the color management of the whole program //
{

   if (x==0 || y==0 || x==gridX-1 || y==gridY-1)
   {
       glLineWidth( 1.5);
       glColor3f(1.0 , 0.0 , 0.0);
   }
   else


   {
       glLineWidth(1.5);
       glColor3f(1.0 , 1.0 , 1.0);
   }




    glBegin(GL_LINE_LOOP);

    glVertex2f(x , y);
    glVertex2f(x+1,y);
    glVertex2f(x+1,y+1);
    glVertex2f(x,y+1);

    glEnd();
}

void drawkhabar()
{
    if(khabar)
       ultapalta(khabarX , khabarY);
    khabar=false;
    glColor3f( 1.0 , 0.0 , 0.6);
    glRectf(khabarX , khabarY , khabarX+1 , khabarY+1);
}


void drawShaap()
{
    for (int i=shaap_length-1 ; i > 0 ; i--)
    {
        posX[i] = posX[i-1];
        posY[i] = posY[i-1];
    }

    if(sDirection==UP)
        posY[0]++;

    if(sDirection==DOWN)
        posY[0]--;

    if(sDirection==RIGHT)
        posX[0]++;

    if(sDirection==LEFT)
        posX[0]--;

        for (int i=0 ; i< shaap_length ; i++)
        {
            if(i == 0)
                glColor3f(1.0 , 1.0  , 0.0);
            else
                glColor3f(0.5 , 0.0  , 0.78);

            glRectd(posX[i] ,posY[i] , posX[i]+1 ,posY[i]+1);
        }




    if( posX[0]==0 || posX[0]==gridX-1 || posY[0]==0 || posY[0]==gridY-1)
        khelashash=true;

        if( posX[0]==khabarX && posY[0]==khabarY)

        {
               score++;
              shaap_length++;

              if ( shaap_length > MAX)
                    shaap_length=MAX;

             khabar=true;
        }

}

void ultapalta(int &x ,int &y)
{
    int _min=1;
    int _maxX =gridX-2;
    int _maxY =gridY-2;
    srand(time(NULL));
    x=_min+rand() % (_maxX-_min);
    y=_min+rand() % (_maxY-_min);
}
