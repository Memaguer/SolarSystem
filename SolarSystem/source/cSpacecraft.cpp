//
//  cSpacecraft.cpp
//  Spacecraft
//
//  Computer Graphics. TC3022.
//  Adapted by Guillermo Barrientos on 10/11/18.
//  REFERENCE[3]: This class was adapted from the "cCar" class provided by Professor Sergio Ruiz Loza
//

#include "cSpacecraft.hpp"

Spacecraft::Spacecraft()
{
    pos[0] = 200;
    pos[1] = 100;
    pos[2] = -100;
    vertical = false;
    horizontal = false;
    angleH = 0;
    angleV = 0;
    
    spacecraft = glmReadOBJ("/Users/MemoBG/Documents/ITC/8º semestre/Gráficas Computacionales/Proyectos/SolarSystem/SolarSystem/assets/spacecraft.obj");
    glmScale(spacecraft, 0.20);
    glmFacetNormals(spacecraft);
    glmVertexNormals(spacecraft, 45.0f);
}

void Spacecraft::draw(){
    //glRotatef(180, 0, 0, 1);
    if(horizontal){
        glTranslatef(pos[0], pos[1], pos[2]);
        glRotatef(angleH, 0, 1, 0);
        glRotatef(angleV, 1, 0, 0);
        horizontal = false;
    } else if(vertical){
        glTranslatef(pos[0], pos[1], pos[2]);
        glRotatef(angleH, 0, 1, 0);
        glRotatef(angleV, 1, 0, 0);
        vertical = false;
    }
    else{
        // ==== HORIZONTAL ====
        pos[0] = pos[0] + sin(angleH*3.14159/180);
        pos[1] = pos[1] - sin(angleV*3.14159/180);
        pos[2] = pos[2] + cos(angleH*3.14159/180);
        
        // ==== DRAW ====
        glTranslatef(pos[0], pos[1], pos[2]);
        glRotatef(angleH, 0, 1, 0);
        glRotatef(angleV, 1, 0, 0);
    }
    glmDraw(spacecraft, GLM_SMOOTH | GLM_MATERIAL);
}

Spacecraft::~Spacecraft()
{
    delete spacecraft;
}
