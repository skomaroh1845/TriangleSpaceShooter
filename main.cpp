#include <iostream>
#include <vector>

#include "C:\Users\Skomaroh\Desktop\Primitives\Primitives.h"
#include "SpaceShip.h"
#include "bullets.cpp"
#include "Wall.h"
#include <glut.h>
#include <Windows.h>

vector<Wall> walls;
SpaceShip S('d', 'w', T(10, 10), 1, 1, 1);
bullet A[6];

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // Очистка экрана
    glLoadIdentity(); // Сброс просмотра
    glOrtho(0, 192, 0, 108, -1, 1);
    
    //draw grids 
    line L1(T(0, 0), T(192, 0)); // T = Vector2D
    line L2(T(0, 0), T(0, 108));
    L1.setWidth(2);
    L2.setWidth(2);
    L1.print();
    L2.print();
    for (int i = 0; i < 192; ++i) {
        line L3(T(i, 0), T(i, 1));
        L3.print();
    }
    for (int i = 0; i < 108; ++i) {
        line L3(T(0, i), T(1, i));
        L3.print();
    };
    //WALLS
    for (auto it = walls.begin(); it != walls.end(); ++it) {
        it->print();
    }
    //

    //ShipControl
    S.CanMove(walls);
    S.moveForward();    
    if (GetAsyncKeyState((unsigned short)'D') & 0x8000) {
        S.rotate(2);
    };
    S.print();
    for (int i = 0; i < 6; ++i) {
        A[i].print();
        A[i].moveForward(0.5);
    }
    //

    glutSwapBuffers();
}

void timer(int = 0)
{
    display();

    glutTimerFunc(10, timer, 0);
}

void changeWinSize(int w, int h)
{
    if (h == 0)
        h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float ratio = (float)w / (float)h;
    if (w <= h)
        glOrtho(-1, 1, -1 / ratio, 1 / ratio, 1, -1);
    else
        glOrtho(-1 * ratio, 1 * ratio, -1, 1, 1, -1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyFunc(unsigned char key, int x, int y) {
    //ShipControl
    if (key == 'w') {
        if (S.getBullets() > 0) {
            S.fire();
            for (int i = 0; i < 6; ++i)
                if (A[i].getCenter().getX() <= 0) {
                    A[i] = bullet(S.getDirectional(), S.getCenter()); break;
                }

        }
    }
    //
}

int main(int argc, char** argv) {
    std::cout << "Game start" << std::endl;
    walls.resize(4);
    walls[0].setWall(T(0, 54), 54, 'V');
    walls[1].setWall(T(96, 108), 96, 'H');
    walls[2].setWall(T(192, 54), 54, 'V');
    walls[3].setWall(T(96, 0), 96, 'H'); 

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 450);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Primitives");

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glutKeyboardFunc(keyFunc);
    glutDisplayFunc(display);
  //  glutReshapeFunc(changeWinSize);
    timer(0);

    glutMainLoop();
    return 0;
};