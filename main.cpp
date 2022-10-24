#include <GL/glut.h>
#include <GL/glut.h>
#include "game_1.h"
#include <stdlib.h>


#define COLUMNS 50
#define ROWS 50
#define FPS 10


extern short sDirection;
bool khelashash=false;

int score=0;

void timer_callback(int);
void display_callback();
void reshape_callback( int , int);
void keyboard_callback(int ,int ,int);


void init()

{
    glClearColor( 0.0,0.0,0.0,1.0);
    initGrid(COLUMNS,ROWS);
}

int main ( int argc , char**argv)
{
    glutInit(&argc , argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInitWindowSize(500 ,500);
    glutCreateWindow("Snake");
    glutDisplayFunc(display_callback);
    glutReshapeFunc(reshape_callback);
    glutTimerFunc( 0 , timer_callback , 0);
    glutSpecialFunc(keyboard_callback);
    init();
    glutMainLoop();
}



void display_callback()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    drawShaap();
    drawkhabar();
    glutSwapBuffers();
    if(khelashash)
    {
        char _score[10];
        itoa(score , _score , 10);
        char text[50] = " Your Point : ";
        strcat(text , _score);
        MessageBox(NULL ,text , "Khela Shash" , 0);
        exit(0);

    }
}

void reshape_callback( int w , int h)
{
    glViewport( 0 , 0 , (GLsizei)w , (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho( 0.0 , COLUMNS , 0.0 , ROWS , -1.0 , 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void timer_callback(int)
{
    glutPostRedisplay(); // gives openGL an urge to call display function ASAP//
    glutTimerFunc(1000/FPS ,timer_callback,0);
}

void keyboard_callback(int key , int ,int)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        if(sDirection != DOWN)
            sDirection=UP;
        break;

        case GLUT_KEY_DOWN:
        if(sDirection != UP)
            sDirection=DOWN;
        break;

        case GLUT_KEY_RIGHT:
        if(sDirection != LEFT)
            sDirection=RIGHT;
        break;

        case GLUT_KEY_LEFT:
        if(sDirection != RIGHT)
            sDirection=LEFT;
        break;
    }
}
