#include <GL/freeglut.h>

#include <cmath>
#include "board.h"

#define PI atan(1) * 4

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;

bool drawEnemy = false;
bool drawPlayer = false;
int row = 0;
int col = 0;
int gridW = WIDTH / 3;
int gridH = HEIGHT / 3;

Board *board;
bool playerTurn = true;
bool win = false;
void resize(int w, int h)
{
	glViewport(0, 0, w, h);

	gluOrtho2D(0, w, 0,h);
	glutPostRedisplay();

}
void drawO(int x, int y){
	int rad = 100;
	glColor3f(1.0f, 0, 0);
	x = x * gridW + gridW / 2;
	y = HEIGHT - (y * gridH + gridH / 2);
	//cout << "draw O at " << x << "," << y << endl;
	glBegin(GL_POINTS);
	for (float theta = 0; theta <= 360; theta++){
		float angle = PI * theta / 180;
		float posX = cos(angle) * rad;
		float posY = sin(angle) * rad;
		glVertex2f(x + posX, y + posY);

	}
	glEnd();
}

void drawX(int x, int y){
	glColor3f(0.0f, 1, 0);
	x = x * gridW + gridW / 2;
	y = HEIGHT - (y * gridH + gridH / 2);
	int line_length = 200;
	//cout << "draw X at " << x << "," << y << endl;
	glLineWidth(2.0f);
	glBegin(GL_LINES);
	glVertex2f(x - line_length / 2, y - line_length / 2);
	glVertex2f(x + line_length / 2, y + line_length / 2);

	glVertex2f(x + line_length / 2, y - line_length / 2);
	glVertex2f(x - line_length / 2, y + line_length / 2);

	glEnd();
}

void mouseClick(int button, int state, int x, int y){	
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		//cout << "clicked at = " << x << "," << y << endl;
		row = y / gridH;
		col = x / gridW;
		//cout << "click at " << row << "," << col << endl;
		if (playerTurn)
			board->putX(row, col);
		else
			board->putO(row, col);
		//comment this to play 2 player
		board->runAI();
		//board->showBoard();
	
		int win = board->checkWin();
		//cout << "win = " << win << endl;
		if (win){
			if (win == 1)
				cout << "Player wins " << endl;
			else
				cout << "Enemy wins" << endl;
		}
		//uncomment this to play 2 player
		//playerTurn = !playerTurn;
		
		glutPostRedisplay();
	}
}
void render(){
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	glPointSize(2.0f);

	glBegin(GL_LINES);
	for (int i = 0; i < 3; i++){
		glVertex2f(0, i*(HEIGHT / 3));
		glVertex2f(WIDTH, i * (HEIGHT/3));
	}
	for (int i = 0; i < 3; i++){
		glVertex2f(i * (WIDTH / 3), 0);
		glVertex2f(i*(WIDTH/3), HEIGHT);
	}

	
	glEnd();

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (board->getAt(i, j) == 1){
				drawX(j, i);
			}
			else if (board->getAt(i, j) == 2){
				drawO(j, i);
			}
		}
	}
	glutSwapBuffers();
}
int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Tic Tac Toe");
	glutMouseFunc(mouseClick);
	glutDisplayFunc(render);
	glutReshapeFunc(resize);
	glutIdleFunc(render);
	board = new Board();
	glutMainLoop();
	delete board;

	return 0;
}