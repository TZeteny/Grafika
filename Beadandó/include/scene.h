#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"
#include "utils.h"
#include "model.h"

#include <obj/model.h>

typedef struct Scene {
    //check if necessary size
    Model model[15];

    Material material;
    Material sky_material;
    Material grass_material;

    //check if necessary size
    GLuint textures[18];

    float rotation;
} Scene;

//use the txt files to load in the correct models and textures
void object_reader(Scene* scene);
void texture_reader(Scene* scene);

//Initialize the scene by loading models
void init_scene(Scene* scene);

//Set the lighting of the scene
void set_lighting();

//Set the current material
void set_material(const Material* material);

//Draw and update the scene objects
void update_scene(Scene* scene, double time);

//Draw the scene objects
void draw_scene(const Scene* scene);

#endif
