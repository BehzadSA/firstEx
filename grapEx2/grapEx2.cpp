// grapEx2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <glut.h>
#include<math.h>

float tr[3][3] = { { 0,0,.5 },{ .5,0,0 },{ 1,1,1 } };
//float tr[3][3] = { { -.3,.4,1 },{ .3,.4,1 },{ -.4,.2,1 } };
float scale[3][3] = { { .5,0,0 },{ 0,1,0 },{ 0,0,1 } };
//float scale[3][3] = { { .5,0,0 },{ 0,1,0 },{ 0,0,1 } };
float trans[3][3] = { { 1,0,0 },{ 0,1,.2 },{ 0,0,1 } };
float rotate[3][3] = { { cos(3.14 / 4),-sin(3.14 / 4),0 },{ sin(3.14 / 4),cos(3.14 / 4),0 },{ 0,0,1 } };
float r[3][3];
float rc[3][3];
void copy(float **a)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			rc[i][j] = a[i][j];
		}
	}
}
float ** multy(float a[][3] , float b[][3] )
{
	float **tr1;
	tr1 = new float*[3];
	tr1[0] = new float[3];
	tr1[1] = new float[3];
	tr1[2] = new float[3];
	for (int l = 0; l < 3; l++)
	{
		for (int p = 0; p < 3; p++)
		{
			tr1[l][p] = 0;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				tr1[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return tr1;
}
void init()
{
	glClearColor(1, 1, 1, 0);
	glShadeModel(GL_FLAT);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	// display
	float **t1;


	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(tr[0][0],tr[1][0]);
	glVertex2f(tr[0][1], tr[1][1]);
	glVertex2f(tr[0][2], tr[1][2]);
	glColor3f(0, 0, 1);
	t1 = multy( scale,tr);
	copy(t1);
	t1 = multy( trans,rc);
	copy(t1);
	t1 = multy( rotate,rc);
	glVertex2f(t1[0][0],t1[1][0]);
	glVertex2f(t1[0][1], t1[1][1]);
	glVertex2f(t1[0][2], t1[1][2]);
	glEnd();
	//
	glutSwapBuffers();

}



void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("my first program");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}

