#include "scene.h"
#include "callbacks.h"
#include "camera.h"

#include <GL/glut.h>
#include <math.h>
#include <obj/load.h>
#include <obj/draw.h>
#include <string.h>

double pendulum_swing;

void object_reader(Scene* scene) {
    int i = 0;
    FILE *fp;
    char str[10000];
    char* filename = "assets/objects/objloader.txt";
    char name[2000];
    char *names;
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Could not open file %s",filename);
    }

    while (fgets(str, sizeof name, fp) != NULL){
        names = strtok(str," ");

        while( names != NULL ) {
            load_model(&(scene->model[i]), (char*)names);
            names = strtok(NULL, " ");
            i++;
        }
    }

    fclose(fp);
}

void texture_reader(Scene* scene) {
    int i = 0;
    FILE *fp;
    char str[10000];
    char* filename = "assets/textures/texturesloader.txt";
    char name[2000];
    char *names;
    fp = fopen(filename, "r");

    if (fp == NULL){
        printf("Could not open file %s",filename);
    }

    while (fgets(str, sizeof name, fp) != NULL){
        names = strtok(str," ");

        while( names != NULL ) {
            scene->textures[i] = load_texture((char*)names);
            names = strtok(NULL, " ");
            i++;
        }
    }

    fclose(fp);
}

void init_scene(Scene* scene) {
    object_reader(scene);
    texture_reader(scene);

    //sky
    scene->sky_material.ambient.red = 0.5;
    scene->sky_material.ambient.green = 0.5;
    scene->sky_material.ambient.blue = 0.5;

    scene->sky_material.diffuse.red = 0.5;
    scene->sky_material.diffuse.green = 0.5;
    scene->sky_material.diffuse.blue = 0.5;

    scene->sky_material.specular.red = 0.0;
    scene->sky_material.specular.green = 0.0;
    scene->sky_material.specular.blue = 0.0;

    scene->sky_material.shininess = 0.0;

    //grass
    scene->grass_material.ambient.red = 0.2;
    scene->grass_material.ambient.green = 0.2;
    scene->grass_material.ambient.blue = 0.2;

    scene->grass_material.diffuse.red = 0.2;
    scene->grass_material.diffuse.green = 0.2;
    scene->grass_material.diffuse.blue = 0.2;

    scene->grass_material.specular.red = 0.0;
    scene->grass_material.specular.green = 0.0;
    scene->grass_material.specular.blue = 0.0;

    scene->grass_material.shininess = 0.0;
}

void draw_scene(const Scene* scene) {
    glEnable(GL_TEXTURE_2D);
    set_material(&(scene->material));
    set_lighting();

    //sky
    set_material(&(scene->sky_material));
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glRotatef(180, 0, 1, 1);
    glBindTexture(GL_TEXTURE_2D, scene->textures[0]);
    draw_model(&(scene->model[0]));
    glPopMatrix();

    //grass
    set_material(&(scene->grass_material));
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glRotatef(180, 0, 1, 1);
    glBindTexture(GL_TEXTURE_2D, scene->textures[1]);
    draw_model(&(scene->model[1]));
    glPopMatrix();

    //house
    glPushMatrix();
    glTranslatef(0, 0, 0.3);
    glRotatef(180, 0, 1, 1);
    glBindTexture(GL_TEXTURE_2D, scene->textures[2]);
    draw_model(&(scene->model[2]));
    glPopMatrix();

    //raptor
    glPushMatrix();
    glTranslatef(1.75, 4, 0.5);
    glRotatef(scene->rotation, 0, 1, 1);
    glBindTexture(GL_TEXTURE_2D, scene->textures[3]);
    draw_model(&(scene->model[3]));
    glPopMatrix();

    //clock
    //main body
    glPushMatrix();
    glScalef(0.2, 0.2, 0.2);
    glTranslatef(0, -7.5, 0);
    glRotatef(90, 1, 0, 0);
    glRotatef(180, 0, 1, 0);
    glBindTexture(GL_TEXTURE_2D, scene->textures[5]);
    draw_model(&(scene->model[4]));
    glPopMatrix();
    //pendulum
    glPushMatrix();
    glScalef(0.2, 0.2, 0.2);
    glTranslatef(0, -6.4, 0);
    glRotatef(90, 1, 0, 0);
    //glRotatef(pendulum_swing, 0, 0, 1);
    //glRotatef(scene->rotation, 0, 0, 1);
    glBindTexture(GL_TEXTURE_2D, scene->textures[6]);
    draw_model(&(scene->model[5]));
    glPopMatrix();
    //hand
    glPushMatrix();
    //glScalef(0.2, 0.2, 0.2);
    glTranslatef(0, -0.45, -5.5);
    glRotatef(90, 1, 0, 0);
    glBindTexture(GL_TEXTURE_2D, scene->textures[7]);
    draw_model(&(scene->model[6]));
    glPopMatrix();
}

void draw_help(int texture) {
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glMatrixMode(GL_MODELVIEW);

    glBindTexture(GL_TEXTURE_2D, texture);
    glLoadIdentity();
    glColor3f(1, 1, 1);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(-1.99, 1.5, -3);
    glTexCoord2f(1, 0);
    glVertex3f(1.99, 1.5, -3);
    glTexCoord2f(1, 1);
    glVertex3f(1.99, -1.5, -3);
    glTexCoord2f(0, 1);
    glVertex3f(-1.99, -1.5, -3);
    glEnd();

    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
}

void update_scene(Scene* scene, double time) {
    int i = 0;
    pendulum_swing = 0;

    scene->rotation += 60 * time;
    /*if ((int)time % 2 == 0) {
        pendulum_swing += scene->rotation;
    }
    else {
        pendulum_swing += -1 * (scene->rotation);
    }*/
}


void set_lighting() {
    float diffuse_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float specular_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float position[] = { 0.0f, 0.0f, 8.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    float position_fire[] = { 0.0f, -1.25f, 0.3f, 1.0f };
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT1, GL_POSITION, position_fire);
}

void set_material(const Material* material) {
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}
