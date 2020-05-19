#include <iostream>
#include <vector>
#include <fstream>

#include "C:\Users\Skomaroh\Desktop\Primitives\Primitives.h"
#include "SpaceShip.h"
#include "bullets.cpp"
#include "Wall.h"
#include <glut.h>
#include <Windows.h>

using namespace std;

vector<Wall> walls;
vector<SpaceShip> S;
bullet bull[20];

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
    for (int i = 0; i < S.size(); i++) {
        S[i].CanMove(walls);
        S[i].moveForward();    
        if (GetAsyncKeyState((unsigned short)'D') & 0x8000) {
            S[i].rotate(2);
        };
        S[i].print();
    }
    //
    //bullets
    for (int i = 0; i < 20; ++i) {
        bull[i].print();
        bull[i].hit(S, walls);
        bull[i].moveForward(0.62);
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
    if (key == S[0].getKeyAction()) {
        if (S[0].getBullets() > 0) {
            S[0].fire();
            //bullets
            for (int i = 0; i < 20; ++i)
                if (bull[i] .getCenter().getX() < 0) {
                    bull[i] = bullet(S[0].getDirectional() - S[0].getCenter(), S[0].getCenter());
                    break;
                }
        }
    }
    if (key == ' ') S[0].UpSpeed();
    //
}

void GameInit() {
    string fname;
    std::cout << "Game start" << std::endl;
    walls.resize(4);
    walls[0].setWall(T(0, 54), 54, 'V');
    walls[1].setWall(T(96, 108), 96, 'H');
    walls[2].setWall(T(192, 54), 54, 'V');
    walls[3].setWall(T(96, 0), 96, 'H'); 
    walls.push_back(Wall(T(40, 20), 15, 'H'));
  //  walls.push_back(Wall(T(55, 20), 1, 'V'));
  /*  while (true) {
        std::cout << "Input map name: ";
        std::cin >> fname;
        ifstream ifile(fname);
        ifile.open(fname);
        if (ifile.is_open()) {
            std::cout << "file error" << std::endl;
        }
        else {
            std::cout << "Map loading..." << std::endl;
            int x = 0, y, size, rotation, n; // 0 = hor, 1 = vert
            //ifile >> n;
            for (int i = 0; i < 2; i++) {
                //ifile >> x >> y >> size >> rotation;
                char a;
                ifile.get(a);
                cout << a << endl;
               // std::cout << x << y << size << rotation << std::endl;
             /*   if (rotation == 0) 
                    walls.push_back(Wall(T(x, y), size, 'H'));
                else 
                    walls.push_back(Wall(T(x, y), size, 'V')); *
            }                    
            ifile.close();
        }
    } */
    std::cout << "Input num players: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        S.push_back(SpaceShip('d', 'w', T(15*(i+1), 10), 1, 0.5, 1));
    }
    for (int i = 0; i < 20; i++) {
        bull[i] = bullet();
    }
}

int main(int argc, char** argv) {
    GameInit();
    
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