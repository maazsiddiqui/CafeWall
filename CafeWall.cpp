#include "stdafx.h"
#include <gl/glut.h>

int width = 800;
int height = 500;

void oneQuadLine(int x, int y) {
	for(int countCol = 0; countCol < 7; countCol++) {
		glVertex2i(x, y);			// Top Left
		glVertex2i(x + 35, y);		// Top Right
		glVertex2i(x + 35, y - 35);	// Bottom Right
		glVertex2i(x, y - 35);		// Bottom Left
		x += 75;
	}
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	
	int x = 160;
	int y = 425;

	oneQuadLine(x, y);
	oneQuadLine(x-15, y-(36*1));
	oneQuadLine(x-30, y-(36 * 2));
	oneQuadLine(x-15, y-(36 * 3));
	oneQuadLine(x, y-(36 * 4));
	oneQuadLine(x - 15, y - (36 * 5));
	oneQuadLine(x - 30, y - (36 * 6));
	oneQuadLine(x - 15, y - (36 * 7));
	oneQuadLine(x, y - (36 * 8));
	
	glEnd();
	
	glColor3f(0.7, 0.7, 0.7);
	glLineWidth(2);
	glBegin(GL_LINES);

	for (int i = 0; i < 10; i++) {
		glVertex2i(75, y - (36 * i));
		glVertex2i(700, y - (36 * i));
	}

	glEnd();
	glFlush();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("Cafe Wall Illusion");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (double)width, 0.0, (double)height);
	glutDisplayFunc(display);
	glutMainLoop();
}
