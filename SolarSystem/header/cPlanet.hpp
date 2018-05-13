//
//  cPlanet.hpp
//  Planet
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

#ifndef __PLANET
#define __PLANET

class Planet
{
public:
    Planet (int planet, float planetScale, float orbitScale);
    ~Planet ();
    void draw();
    void update();
    void drawOrbit();
    void getTranslationPosition(float t);
    float pos[3];
    
private:
    Texture targas;
    int planetNumber;
    float perihelion;
    float radius;
    float day; // ellipse
    float currentDay; // ellipse
    float b; // ellipse
    float a; // ellipse (averageDistance)
    float degree;
    float translationDays;
};

#endif __PLANET

