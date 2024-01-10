#include<windows.h>
#include <GL/glut.h>
#include <math.h>

float p=-0.005;
float s=-0.005;
float u=-0.005;
float triangleScale = 1.0;

void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx,cy);
    for(int i=0; i<100; i++)
    {
        float angle = 4.0f * 3.1416f * i/100;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f((x+cx),(y+cy));
    }
    glEnd();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            p -= 0.01;
            triangleScale -= 0.05; // Scale down
            break;
        case GLUT_KEY_RIGHT:
            p += 0.01;
            triangleScale += 0.05; // Scale up
            break;
    }
    glutPostRedisplay();
}

void mydisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);

//green color part on the background
    glColor3f (0.204,0.51,0.204);
    glVertex3f(-0.05f, 0.0f, 0.0f);
    glVertex3f(-0.05f, 0.20f, 0.0f);
    glVertex3f(0.85f, 0.20f, 0.0f);
    glVertex3f(0.85f, 0.00f, 0.0f);

//Sky
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f(-0.05f, 0.20f, 0.0f);
    glVertex3f(-0.05f, 0.40f, 0.0f);
    glVertex3f(0.85f, 0.40f, 0.0f);
    glVertex3f(0.85f, 0.20f, 0.0f);
    glEnd();

//loop for moon
    if(s<=0.95)
        s=s+.00002;
    else
        s=-0.000000005;

    if(u<=0.40)
        u=u+.000002;
    else
        u=-0.00000005;
    glutPostRedisplay();

    glColor3f(1.0, 1.0, 1.0);
    circle(0.04,0.03,s-0.05, u+0.25);


    glBegin(GL_QUADS);
    //black font Road here
    glColor3f (0.4, 0.4, 0.4);
    glVertex3f(-0.05f, -0.05f, 0.0f);
    glVertex3f(-0.05f, 0.03f, 0.0f);
    glVertex3f(0.90f, 0.03f, 0.0f);
    glVertex3f(0.90f, -0.05f, 0.0f);

    // road devider1
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f(-0.05f, -0.01f, 0.0f);
    glVertex3f(-0.05f, 0.0f, 0.0f);
    glVertex3f(-0.02f, 0.0f, 0.0f);
    glVertex3f(-0.02f, -0.01f, 0.0f);
// road devider2
    glVertex3f(0.03f, 0.0f, 0.0f);
    glVertex3f(0.03f, -0.01f, 0.0f);
    glVertex3f(0.08f, -0.01f, 0.0f);
    glVertex3f(0.08f, 0.0f, 0.0f);

// road devider3
    glVertex3f(0.13f, 0.0f, 0.0f);
    glVertex3f(0.13f, -0.01f, 0.0f);
    glVertex3f(0.18f, -0.01f, 0.0f);
    glVertex3f(0.18f, 0.0f, 0.0f);

// road devider3
    glVertex3f(0.23f, 0.0f, 0.0f);
    glVertex3f(0.23f, -0.01f, 0.0f);
    glVertex3f(0.28f, -0.01f, 0.0f);
    glVertex3f(0.28f, 0.0f, 0.0f);

// road devider4
    glVertex3f(0.33f, 0.0f, 0.0f);
    glVertex3f(0.33f, -0.01f, 0.0f);
    glVertex3f(0.38f, -0.01f, 0.0f);
    glVertex3f(0.38f, 0.0f, 0.0f);
// road devider5
    glVertex3f(0.43f, 0.0f, 0.0f);
    glVertex3f(0.43f, -0.01f, 0.0f);
    glVertex3f(0.48f, -0.01f, 0.0f);
    glVertex3f(0.48f, 0.0f, 0.0f);

// road devider3
    glVertex3f(0.53f, 0.0f, 0.0f);
    glVertex3f(0.53f, -0.01f, 0.0f);
    glVertex3f(0.58f, -0.01f, 0.0f);
    glVertex3f(0.58f, 0.0f, 0.0f);

// road devider3
    glVertex3f(0.63f, 0.0f, 0.0f);
    glVertex3f(0.63f, -0.01f, 0.0f);
    glVertex3f(0.68f, -0.01f, 0.0f);
    glVertex3f(0.68f, 0.0f, 0.0f);

// road devider3
    glVertex3f(0.73f, 0.0f, 0.0f);
    glVertex3f(0.73f, -0.01f, 0.0f);
    glVertex3f(0.78f, -0.01f, 0.0f);
    glVertex3f(0.78f, 0.0f, 0.0f);

// road devider3
    glVertex3f(0.83f, 0.0f, 0.0f);
    glVertex3f(0.83f, -0.01f, 0.0f);
    glVertex3f(0.88f, -0.01f, 0.0f);
    glVertex3f(0.88f, 0.00f, 0.0f);
    glEnd();

    glBegin(GL_QUADS); //upper body
    glColor3f(0.0,0.0,1.0);
    glVertex3f(p+0.01,0.06,0);
    glVertex3f(p+0.01,0.02,0);
    glVertex3f(p+0.10,0.02,0);
    glVertex3f(p+0.10,0.06,0);
    glEnd();
    glBegin(GL_QUADS); // lower body
    glColor3f(0.0,0.0,1.0);
    glVertex3f(p-0.05,-0.015,0);
    glVertex3f(p-0.05,0.025,0);
    glVertex3f(p+0.16,0.025,0);
    glVertex3f(p+0.16,-0.015,0);
    glEnd();
    //first car body in back side
    glBegin(GL_TRIANGLES);
    glVertex3f(p+0.01,0.02,0);
    glVertex3f(p+0.01,0.06,0);
    glVertex3f(p-0.01,0.02,0);

    glVertex3f(p+0.10,0.02,0);
    glVertex3f(p+0.10,0.06,0);
    glVertex3f(p+0.125,0.02,0);
    glEnd();

    glBegin(GL_QUADS);
    //window 1
    glColor3f(0.0, 0.1, 0.1);
    glVertex3f(p+0.01,0.03,0);
    glVertex3f(p+0.025,0.05,0);
    glVertex3f(p+0.05,0.05,0);
    glVertex3f(p+0.05,0.03,0);
    //windows 2
    glVertex3f(p+0.06,0.03,0);
    glVertex3f(p+0.06,0.05,0);
    glVertex3f(p+0.08,0.05,0);
    glVertex3f(p+0.095,0.03,0);
    glEnd();

    glColor3f(0.0,0.0,0);
    circle(0.02,0.02,p+0.0, -0.01); //tier 1
    circle(0.02,0.02,p+0.10, -0.01); //tier 2

    glPushMatrix();
    glColor3f(0.0, 1.0, 1.0);
    glTranslatef(0.45f, 0.18f, 0.0f); // Translate to the middle of the window
    glScalef(triangleScale, triangleScale, 1.0); // Apply scaling
    glRotatef(90, 0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.015, -0.015, 0);
    glVertex3f(-0.015, 0.015, 0);
    glVertex3f(0.015, 0.0, 0);
    glEnd();
    glPopMatrix();

    glFlush();
}

void init ()
{
    glClearColor (1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-0.05, 0.85, -0.05, 0.40, 0.0, 10.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1200, 720);
    glutInitWindowPosition (70, 80);
    glutCreateWindow ("Move the car");
    init();
    glutDisplayFunc(mydisplay);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}
