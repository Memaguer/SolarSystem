//
//  cSpacecraft.hpp
//  Spacecraft
//
//  Computer Graphics. TC3022.
//  Adapted by Guillermo Barrientos on 10/11/18.
//  REFERENCE[3]: This class was adapted from the "cCar" class provided by Professor Sergio Ruiz Loza
//

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include "freeglut.h"
#endif

#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "glm.hpp"

#ifndef cSpacecraft_hpp
#define cSpacecraft_hpp

#include <stdio.h>

#endif /* cSpacecraft_hpp */

class Spacecraft{
public:
    Spacecraft();
    ~Spacecraft();
    void draw();
    void assign(int pos);
    float angleH;
    float angleV;
    float pos[3];
    bool vertical;
    bool horizontal;
    GLMmodel * spacecraft;
};

