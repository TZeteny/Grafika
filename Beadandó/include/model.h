#ifndef OBJ_MODEL_H
#define OBJ_MODEL_H

#define TRUE 1
#define FALSE 0

#define INVALID_VERTEX_INDEX 0

//3D vertex
typedef struct Vertex {
    double x;
    double y;
    double z;
} Vertex;

//2D texture vetex
typedef struct TextureVertex {
    double u;
    double v;
} TextureVertex;

//Point of the face
typedef struct FacePoint {
    int vertex_index;
    int texture_index;
    int normal_index;
} FacePoint;

//Triangle as facepoint triplet
typedef struct Triangle {
    struct FacePoint points[3];
} Triangle;

//3D model with texture
typedef struct Model {
    int n_vertices;
    int n_texture_vertices;
    int n_normals;
    int n_triangles;
    Vertex* vertices;
    TextureVertex* texture_vertices;
    Vertex* normals;
    Triangle* triangles;
} Model;

//Types of the considered elements
typedef enum {
    NONE,
    VERTEX,
    TEXTURE_VERTEX,
    NORMAL,
    FACE
} ElementType;

//Initialize the model structure
void init_model(Model* model);

//Allocate memory for model
void allocate_model(Model* model);

//Release the allocated memory of the model
void free_model(Model* model);

#endif
