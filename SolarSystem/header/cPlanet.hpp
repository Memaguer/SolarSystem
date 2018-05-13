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
    void update(int velocity);
    void drawOrbit();
    void getTranslationPosition(float t);
    float pos[3];
    
private:
    Texture targas;
    Texture targasRing;
    Planet* moon;
    int planetNumber;
    float perihelion;
    float eccentricity;
    float orbitalInclination;
    float radius;
    float day; // ellipse
    float hour;
    float currentDay; // ellipse
    float currentHour;
    float b; // ellipse
    float a; // ellipse (averageDistance)
    float obliquity;
    float rotationAngle;
    float translationDays;
    float rotationHours;
};

#endif __PLANET

