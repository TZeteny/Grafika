#include "callbacks.h"
#include "init.h"

#include <windows.h>
#include <mmsystem.h>
#include <GL/glut.h>
#include <stdio.h>

//Set the callbacks for GLUT
void set_callbacks();

int main(int argc, char* argv[]) {
    int window;

    int windowsize_w = 1024;
    int windowsize_h = 768;

    PlaySound("music.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

    glutInit(&argc, argv);
    glutInitWindowSize(windowsize_w, windowsize_h);

    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-windowsize_w)/2,
    (glutGet(GLUT_SCREEN_HEIGHT)-windowsize_h)/2);

    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

    window = glutCreateWindow("Grafika beadando");
    glutSetWindow(window);

    init_opengl();
    init_scene(&scene);
    init_camera(&camera);
    set_callbacks();
    glutMainLoop();

    return 0;
}

void set_callbacks() {
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(SpecialKeyHandler);
    glutKeyboardUpFunc(keyboard_up);
    glutIdleFunc(idle);
}
