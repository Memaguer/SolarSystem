//
//  cTexture.hpp
//  Texture
//
//  Computer Graphics. TC3022.
//  Created by Sergio Ruiz Loza.
//  REFERENCE[2]: This class was provided by Professor Sergio Ruiz Loza.
//

#pragma once
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include "freeglut.h"
#endif

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#ifndef __TGA_HEADER__
#define __TGA_HEADER__

typedef struct
{
    GLubyte * imageData;
    GLuint bpp;
    GLuint width;
    GLuint height;
    GLuint texID;
    GLuint type;
} Texture;

typedef struct
{
    GLubyte Header[12];
} TGAHeader;

typedef struct
{
    GLubyte header[6];
    GLuint bytesPerPixel;
    GLuint imageSize;
    GLuint temp;
    GLuint type;
    GLuint Height;
    GLuint Width;
    GLuint Bpp;
} TGA;

bool LoadTGA(Texture * texture, char * filename);
bool LoadCompressedTGA(Texture * texture, char * filename, FILE * fTGA);
bool LoadUncompressedTGA(Texture * texture, char * filename, FILE * fTGA);
#endif

