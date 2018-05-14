//
//  cSkybox.cpp
//  Skybox
//
//  Computer Graphics. TC3022.
//  Adapted by Guillermo Barrientos on 10/11/18.
//  REFERENCE[3]: This class was adapted from the "cCube" class provided by Professor Sergio Ruiz Loza
//


#include "cSkybox.hpp"


Skybox::Skybox(float side)
{
    this->side = side;
    hside = side / 2.0f;
    
    glGenTextures(1, &targas.texID);
    glBindTexture(GL_TEXTURE_2D, targas.texID);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    LoadTGA(&targas, "/Users/MemoBG/Documents/ITC/8º semestre/Gráficas Computacionales/Proyectos/SolarSystem/SolarSystem/assets/starts.tga");
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, targas.width, targas.height, 0, GL_RGB, GL_UNSIGNED_BYTE, targas.imageData);
    //glBindTexture(GL_TEXTURE_2D, 0);
}

Skybox::~Skybox(void)
{
    glDeleteTextures(1, &targas.texID);
}

void Skybox::draw(void)
{
    //===== FRONT ====
    glBindTexture(GL_TEXTURE_2D, targas.texID);
    glBegin(GL_QUADS);
    
    glNormal3f(0.0f, 0.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-hside, -hside, hside);
    
    glNormal3f(0.0f, 0.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(hside, -hside, hside);
    
    glNormal3f(0.0f, 0.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(hside, hside, hside);
    
    glNormal3f(0.0f, 0.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-hside, hside, hside);
    
    glEnd();
    glBindTexture(GL_TEXTURE_2D, NULL);
    
    
    //===== RIGHT ====
    glBindTexture(GL_TEXTURE_2D, targas.texID);
    glBegin(GL_QUADS);
    
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(hside, hside, hside);
    
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(hside, hside, -hside);
    
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(hside, -hside, -hside);
    
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(hside, -hside, hside);
    
    //===== LEFT ====
    glBindTexture(GL_TEXTURE_2D, targas.texID);
    glBegin(GL_QUADS);
    
    glNormal3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-hside, hside, hside);
    
    glNormal3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-hside, hside, -hside);
    
    glNormal3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-hside, -hside, -hside);
    
    glNormal3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-hside, -hside, hside);
    
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, NULL);
    
    // ===== BACK ====
    glBindTexture(GL_TEXTURE_2D, targas.texID);
    glBegin(GL_QUADS);
    
    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-hside, -hside, -hside);
    
    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(hside, -hside, -hside);
    
    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(hside, hside, -hside);
    
    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-hside, hside, -hside);
    
    glEnd();
    glBindTexture(GL_TEXTURE_2D, NULL);
    
    // ===== TOP ====
    glBindTexture(GL_TEXTURE_2D, targas.texID);
    glBegin(GL_QUADS);
    
    glNormal3f(0.0f, -1.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-hside, hside, hside);
    
    glNormal3f(0.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-hside, hside, -hside);
    
    glNormal3f(0.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(hside, hside, -hside);
    
    glNormal3f(0.0f, -1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(hside, hside, hside);
    
    glEnd();
    glBindTexture(GL_TEXTURE_2D, NULL);
    
    // ===== BOTTOM ====
    glBindTexture(GL_TEXTURE_2D, targas.texID);
    glBegin(GL_QUADS);
    
    glNormal3f(0.0f, 1.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-hside, -hside, hside);
    
    glNormal3f(0.0f, 1.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(hside, -hside, hside);
    
    glNormal3f(0.0f, 1.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(hside, -hside, -hside);
    
    glNormal3f(0.0f, 1.0f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-hside, -hside, -hside);
    
    glEnd();
    glBindTexture(GL_TEXTURE_2D, NULL);
}
