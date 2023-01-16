#include "Cuadrado.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

void Cuadrado::Dibuja() {
	glPushMatrix();
	glPointSize(20);
	glColor3ub(82, 190, 128);
	glTranslatef(posX,posY,0);
	glBegin(GL_POINTS);
	glVertex2f(0,0);
	glEnd();
	glPopMatrix();
}

void Cuadrado::Actualiza() {
	glutPostRedisplay();
}