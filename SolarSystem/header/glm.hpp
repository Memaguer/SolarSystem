//
//  glm.hpp
//  glm
//
//  Computer Graphics. TC3022.
//  Created by Sergio Ruiz Loza.
//  REFERENCE[2]: This class was provided by Professor Sergio Ruiz Loza.
//
//  -------------------------------------------------------------------------
//  Nate Robins, 1997, 2000
//  nate@pobox.com, http://www.pobox.com/~nate
//
//  Wavefront OBJ model file format reader/writer/manipulator.
//
//  Includes routines for generating smooth normals with
//  preservation of edges, welding redundant vertices & texture
//  coordinate generation (spheremap and planar projections) + more.
//
//  Improved version:
//  Tudor Carean - April 2008 - added texture support
//  --------------------------------------------------------------------------

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include "freeglut.h"
#endif

#ifndef M_PI
#define M_PI 3.14159265f
#endif

#define GLM_NONE     (0)
#define GLM_FLAT     (1 << 0)
#define GLM_SMOOTH   (1 << 1)
#define GLM_TEXTURE  (1 << 2)
#define GLM_COLOR    (1 << 3)
#define GLM_MATERIAL (1 << 4)

typedef struct _GLMmaterial
{
    char* name;
    GLfloat diffuse[4];
    GLfloat ambient[4];
    GLfloat specular[4];
    GLfloat emmissive[4];
    GLfloat shininess;
    GLuint IDTextura;
} GLMmaterial;

typedef struct _GLMtriangle {
    GLuint vindices[3];
    GLuint nindices[3];
    GLuint tindices[3];
    GLuint findex;
    GLuint vecini[3];
    bool visible;
} GLMtriangle;


typedef struct _GLMtexture {
    char *name;
    GLuint id;
    GLfloat width;
    GLfloat height;
} GLMtexture;

typedef struct _GLMgroup {
    char*             name;
    GLuint            numtriangles;
    GLuint*           triangles;
    GLuint            material;
    struct _GLMgroup* next;
} GLMgroup;

typedef struct _GLMmodel {
    char*    pathname;
    char*    mtllibname;
    
    GLuint   numvertices;
    GLfloat* vertices;
    
    GLuint   numnormals;
    GLfloat* normals;
    
    GLuint   numtexcoords;
    GLfloat* texcoords;
    
    GLuint   numfacetnorms;
    GLfloat* facetnorms;
    
    GLuint       numtriangles;
    GLMtriangle* triangles;
    
    GLuint       nummaterials;
    GLMmaterial* materials;
    
    GLuint       numgroups;
    GLMgroup*    groups;
    GLuint       numtextures;
    GLMtexture*  textures;
    
    GLfloat position[3];
    
} GLMmodel;

struct mycallback
{
    void (*loadcallback)(int,char *);
    int start;
    int end;
    char *text;
};

GLvoid glmDraw(GLMmodel* model, GLuint mode,char *drawonly);

GLfloat glmDot(GLfloat* u, GLfloat* v);

GLfloat
glmUnitize(GLMmodel* model);

GLvoid
glmDimensions(GLMmodel* model, GLfloat* dimensions);

GLvoid
glmScale(GLMmodel* model, GLfloat scale);

GLvoid
glmReverseWinding(GLMmodel* model);

GLvoid
glmFacetNormals(GLMmodel* model);

GLvoid
glmVertexNormals(GLMmodel* model, GLfloat angle);

GLvoid
glmLinearTexture(GLMmodel* model);

GLvoid
glmSpheremapTexture(GLMmodel* model);

GLvoid
glmDelete(GLMmodel* model);

GLMmodel* glmReadOBJ(char* filename);
GLMmodel* glmReadOBJ(char* filename,mycallback *call);

GLvoid
glmWriteOBJ(GLMmodel* model, char* filename, GLuint mode);

GLvoid
glmDraw(GLMmodel* model, GLuint mode);

GLuint
glmList(GLMmodel* model, GLuint mode);

GLvoid
glmWeld(GLMmodel* model, GLfloat epsilon);

GLubyte*
glmReadPPM(char* filename, int* width, int* height);

GLMgroup*
glmFindGroup(GLMmodel* model, char* name);

