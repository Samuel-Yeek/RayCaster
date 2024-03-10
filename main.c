#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#define PI 3.1415926535


//player position

float playerx; // Player X axis
float playery; // Player Y axis
float pdx,pdy; //player delta x and y
float playerangle; //playerangle


void drawPlayer(){
	glColor3f(0,1,0);
	glPointSize(8);
	glBegin(GL_POINTS);
	glVertex2i(playerx,playery);
	glEnd();
}

//The map

int mapX=8,mapY=8,mapS=64; // map X length, map Y length, and cube size
int map[]=
{
	1,1,1,1,1,0,1,1,
	1,0,0,0,1,0,0,1,
	1,0,0,0,1,0,0,1,
	1,0,0,0,1,0,1,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,
};


void drawMiniMap(){
	int x,y,xo,yo;
	for(y=0;y<mapY;y++)
	{
		for (x=0;x<mapX;x++)
		{
			if(map[y*mapX+x]==1){ glColor3f(1,1,1);} else{ glColor3f(0,0,0);}
			xo=x*mapS; yo=y*mapS;
			glBegin(GL_QUADS);
			glVertex2i(xo+1     ,yo     +1);
			glVertex2i(xo+1     ,yo+mapS-1);
			glVertex2i(xo-1+mapS,yo+mapS-1);
			glVertex2i(xo-1+mapS,yo     +1);
			glEnd();
			}
		}	
}




void display()
{
 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 	drawMiniMap();
 	drawPlayer();
 	glutSwapBuffers();
}

void buttons(unsigned char key,int x,int y){
	if(key=='a'){ playerangle-=0.1; if(playerangle<0){playerangle+=2*PI;} pdx=cos(playerangle)*5; pdy=sin(playerangle)*5;}
	if(key=='d'){ playerangle+=0.1; if(playerangle>2*PI){playerangle-=2*PI;} pdx=cos(playerangle)*5; pdy=sin(playerangle)*5;} //turn based on a hardcoded amount, will be adjustable later
	if(key=='w'){ playerx+=pdx; playery+=pdy;}
	if(key=='s'){ playerx-=pdx; playery-=pdy;}
	glutPostRedisplay();
}





//Initialize 

void init()
{
	glClearColor(0.3,0.3,0,0);
	gluOrtho2D(0,1024,512,0);
	playerx = 300;
	playery = 300;
	
}





int main(int argc, char** argv)
{ 
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1024,512);
	glutCreateWindow("RayCaster");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(buttons);
	glutMainLoop();
}