#include <GL/glut.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstdio>

const int width = 800;
const int height = 600;
const int NUM_ORBS = 100;

struct Orb {
    float x, y;
    float radius;
    float dx, dy;
    float r, g, b, a;
    float da;
};

Orb orbs[NUM_ORBS];
bool paused = false;
float speedMultiplier = 1.0f;  // Default speed

void initOrbs() {
    for (int i = 0; i < NUM_ORBS; ++i) {
        orbs[i].x = rand() % width;
        orbs[i].y = rand() % height;
        orbs[i].radius = 10 + rand() % 30;
        orbs[i].dx = ((rand() % 100) / 500.0f) - 0.1f;
        orbs[i].dy = ((rand() % 100) / 500.0f) - 0.1f;
        orbs[i].r = (rand() % 100) / 100.0f;
        orbs[i].g = (rand() % 100) / 100.0f;
        orbs[i].b = (rand() % 100) / 100.0f;
        orbs[i].a = 0.0f;
        orbs[i].da = 0.002f + (rand() % 5) / 1000.0f;
    }
}

void drawCircle(float x, float y, float radius, float r, float g, float b, float a) {
    glColor4f(r, g, b, a);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 360; ++i) {
        float angle = i * 3.14159f / 180;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}

void updateOrbs() {
    for (int i = 0; i < NUM_ORBS; ++i) {
        orbs[i].x += orbs[i].dx * speedMultiplier;
        orbs[i].y += orbs[i].dy * speedMultiplier;

        orbs[i].a += orbs[i].da;
        if (orbs[i].a > 1.0f || orbs[i].a < 0.0f)
            orbs[i].da *= -1;

        // Wrap around screen
        if (orbs[i].x < -50) orbs[i].x = width + 50;
        if (orbs[i].x > width + 50) orbs[i].x = -50;
        if (orbs[i].y < -50) orbs[i].y = height + 50;
        if (orbs[i].y > height + 50) orbs[i].y = -50;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = 0; i < NUM_ORBS; ++i) {
        drawCircle(orbs[i].x, orbs[i].y, orbs[i].radius,
                   orbs[i].r, orbs[i].g, orbs[i].b, orbs[i].a);
    }

    glutSwapBuffers();
}

void timer(int) {
    if (!paused) {
        updateOrbs();
        glutPostRedisplay();
    }
    glutTimerFunc(16, timer, 0);  // ~60 FPS
}

void handleMouse(int button, int state, int x, int y) {
    if (state == GLUT_DOWN) {
        exit(0); // Exit on mouse click
    }
}

void handleKeyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'q':
        case 27:  // Escape key
            exit(0);
            break;
        case 'r':
            initOrbs();
            break;
        case 'd':
            printf("Orb[0] -> x: %.2f, y: %.2f, radius: %.2f, color: (%.2f, %.2f, %.2f), alpha: %.2f\n",
                   orbs[0].x, orbs[0].y, orbs[0].radius, orbs[0].r, orbs[0].g, orbs[0].b, orbs[0].a);
            break;
        case 'p':
            paused = !paused;
            break;
        case 's':  // Speed toggle with more range
            if (speedMultiplier == 1.0f)
                speedMultiplier = 2.0f;
            else if (speedMultiplier == 2.0f)
                speedMultiplier = 4.0f;
            else if (speedMultiplier == 4.0f)
                speedMultiplier = 0.5f;
            else
                speedMultiplier = 1.0f;

            printf("Speed multiplier set to %.1fx\n", speedMultiplier);
            break;
    }
}


void init() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.0, 0.0, 0.05, 1.0); // dark background
    gluOrtho2D(0, width, 0, height);
    srand(time(0));
    initOrbs();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(width, height);
    glutCreateWindow("Colorful Floating Orbs Screensaver");

    init();
    glutDisplayFunc(display);
    glutMouseFunc(handleMouse);        // Register mouse click handler
    glutKeyboardFunc(handleKeyboard);  // Register key press handler
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
