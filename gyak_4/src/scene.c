#include "scene.h"

#include <GL/gl.h>
//#include <GL/glut.h>

void init_scene(Scene* scene)
{
}

void update_scene(Scene* scene)
{
}

void render_scene(const Scene* scene)
{
    draw_origin();
}

void draw_origin()
{
    //Lines of the cube
    glBegin(GL_LINES);

    //X
    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    //Y
    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    //Z
    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    //X's parallel on X,Y plane
    glColor3f(0.5, 0, 0);
    glVertex3f(0, 1, 0);
    glVertex3f(1, 1, 0);

    //Y's parallel on X,Y plane
    glColor3f(0, 0.5, 0);
    glVertex3f(1, 0, 0);
    glVertex3f(1, 1, 0);

    //Square at Z = 1
    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 1);
    glVertex3f(1, 0, 1);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 1);
    glVertex3f(0, 1, 1);

    glColor3f(0.5, 0, 0);
    glVertex3f(0, 1, 1);
    glVertex3f(1, 1, 1);

    glColor3f(0, 0.5, 0);
    glVertex3f(1, 0, 1);
    glVertex3f(1, 1, 1);

    //Z's parallel's, vertical edges of the cube
    glColor3f(1, 0, 1);
    glVertex3f(1, 0, 0);
    glVertex3f(1, 0, 1);

    glColor3f(0, 1, 1);
    glVertex3f(0, 1, 0);
    glVertex3f(0, 1, 1);

    glColor3f(0, 0, 0.5);
    glVertex3f(1, 1, 0);
    glVertex3f(1, 1, 1);

    glEnd();

    //Triangle in the cube
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 1);
    glVertex3f(0, 0, 0);
    glColor3f(0, 1, 1);
    glVertex3f(1, 1, 0);
    glColor3f(1, 1, 0);
    glVertex3f(0.5, 0.5, 1);
    glEnd();

    GLUquadric *quad;
    quad = gluNewQuadric();
    gluQuadricDrawStyle(quad, GLU_FILL);

    glColor3f(2,1.65, 0);
    glPushMatrix();
    gluSphere(quad, 1, 20, 20);
    glPopMatrix();

}
