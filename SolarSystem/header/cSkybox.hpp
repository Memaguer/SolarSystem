//
//  cSkybox.hpp
//  Skybox
//
//  Computer Graphics. TC3022.
//  Adapted by Guillermo Barrientos on 10/11/18.
//  REFERENCE[3]: This class was adapted from the "cCube" class provided by Professor Sergio Ruiz Loza
//

#pragma once
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include "freeglut.h"
#endif
#include "cTexture.hpp"

#ifndef __SKYBOX
#define __SKYBOX

class Skybox
{
public:
    Skybox (float side);
    ~Skybox (void);
    void draw(void);
    
private:
    float side;
    float hside;
    Texture targas;
};

#endif __SKYBOX


