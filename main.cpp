#include "C:\Users\Skomaroh\Desktop\Primitives\Primitives.h"
#include "SpaceShip.h"
#include "bullets.cpp"
#include <glut.h>
#include <Windows.h>

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
    S.moveForward(0.3);
    if (GetAsyncKeyState((unsigned short)'D') & 0x8000) {
        S.rotate(2);
    };
    S.print();
    for (int i = 0; i < 6; ++i) {
        A[i].print();
        A[i].moveForward(0.5);
    }
    

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
    if (key == 'w') {
        if (S.getBullets() > 0) {
            S.fire();
            for (int i = 0; i < 6; ++i)
                if (A[i].getCenter().getX() <= 0) {
                    A[i] = bullet(S.getDirectional(), S.getCenter()); break;
                }

        }
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
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