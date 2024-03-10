#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>


//player position

float playerx; // Player X axis
float playery; // Player Y axis



void drawPlayer(){
	glColor3f(0,1,0);
	glPointSize(8);
	glBegin(GL_POINTS);
	glVertex2i(playerx,playery);
	glEnd();
}







void display()
{
 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 	drawPlayer();
 	glutSwapBuffers();
}

void buttons(unsigned char key,int x,int y){
	if(key=='a'){ playerx-+5;}
	if(key=='d'){ playerx+=5;}
	if(key=='w'){ playery-=5;}
	if(key=='s'){ playery+=5;}
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