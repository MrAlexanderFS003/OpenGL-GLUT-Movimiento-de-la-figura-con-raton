
/*
	Hecho por Max Flores Saldaña , Usando la programación orientada a Objetos en C++.
	Si desea ver la documentacion de GLUT: https://www.opengl.org/resources/libraries/glut/spec3/spec3.html
*/

#include "Cuadrado.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

// Variables que usaremos para calcular la posicion de raton y el tamaño de la ventana
#define ANCHO 800
#define ALTO 600

Cuadrado cuad;

//Variables usadas para almacenar los calculos obtenidos
float objX = 0.0f , objY = 0.0f, MobjX = 0.0f, MobjY = 0.0f;
int valor = 0;

void Iniciar() {
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-50, 50, -50, 50);
}

void Dibuja() {
	glClear(GL_COLOR_BUFFER_BIT);
	cuad.Dibuja();
	glutSwapBuffers();
}

// Cuando la tecla es presionada
void Tecla(unsigned char teclas, int x, int y) {
	switch (teclas) {
	case 27:
		exit(0); // Al precionar escape (Esc) se cierra el progrma 
		//Visita la pagina de codigo ASCII: https://elcodigoascii.com.ar/
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

//Posicion del raton
void Raton(int btn, int state, int x,int y) {
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		objX = (x - (ANCHO / 2)) * 100 / ANCHO;
		objY = ((ALTO / 2) - y) * 100 / ALTO;
		cuad.setPosX(objX);
		cuad.setPosY(objY);
		MobjX = objX;
		MobjY = objY;
		valor = state;
	}
}

//Movimiento de la figura en base al raton
void MoverRaton(int x, int y) {
	if (valor) {
		cuad.setPosX(MobjX);
		cuad.setPosY(MobjY);
	}
	MobjX = (x - (ANCHO / 2)) * 100 / ANCHO;
	MobjY = ((ALTO / 2) - y) * 100 / ALTO;
}

void Actualiza() {
	glutPostRedisplay();
}

int main() {
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(ANCHO, ALTO);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("CONTROL RATON 2D");

	Iniciar();
	glutDisplayFunc(Dibuja);
	glutIdleFunc(Actualiza);
	glutKeyboardFunc(Tecla);
	glutMouseFunc(Raton); // Posicion del raton
	glutMotionFunc(MoverRaton); // Movimiento del raton
	glutMainLoop();
	return 0;
}