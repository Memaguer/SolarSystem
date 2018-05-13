//
//  cPlanet.cpp
//  Planet
//
//  Computer Graphics. TC3022.
//  Adapted by Guillermo Barrientos on 10/11/18.
//  REFERENCE[3]: This class was adapted from the "cCube" class provided by Professor Sergio Ruiz Loza
//
//  DATA PLANETS:
//  http://www.astronoo.com/en/articles/positions-of-the-planets.html
//

#include "cPlanet.hpp"


Planet::Planet(int planet, float planetScale, float orbitScale)
{
    glGenTextures(1, &targas.texID);
    glBindTexture(GL_TEXTURE_2D, targas.texID);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    // THIS DOESN'T USE MIPMAPS
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    // PLANET NUMBER
    planetNumber = planet;
    
    // DEFAULT POSITION
    pos[0] = 0.0f;
    pos[1] = 0.0f;
    pos[2] = 0.0f;
    
    bool real = true;
    
    // DEGRE
    degree = 0;
    
    currentDay = 0;
    
    
    switch(planet){
        case 0:
            LoadTGA(&targas, "/Users/MemoBG/Documents/ITC/8º semestre/Gráficas Computacionales/Proyectos/SolarSystem/SolarSystem/assets/sun.tga");
            // radius: 695,700 km
            // distance to the sun: 58,000,000km + sun radius
            // inclination: km
            // translation: 88 days
            // rotation: 59 days
            radius = 69.57;
            pos[0] = 0.0f;
            pos[1] = 0.0f;
            pos[2] = 0.0f;
            break;
        case 1:
            LoadTGA(&targas, "/Users/MemoBG/Documents/ITC/8º semestre/Gráficas Computacionales/Proyectos/SolarSystem/SolarSystem/assets/mercury.tga");
            // radius: 2,439 km
            // distance to the sun: 58,000,000 km
            // perihelion: 46,000,000 km
            // inclination: km
            // translation: 88 days
            // rotation: 59 days
            
            perihelion = (69.57 + 4600 + .24397) * orbitScale;
            pos[0] = (69.57 + 5800.0 + .24397) * orbitScale;
            pos[1] = 0.0f;
            pos[2] = 0.0f;
            radius = (.24397) * planetScale;
            translationDays = 88;
            break;
        case 2:
            LoadTGA(&targas, "/Users/MemoBG/Documents/ITC/8º semestre/Gráficas Computacionales/Proyectos/SolarSystem/SolarSystem/assets/venus.tga");
            // radius: 6052 km
            // distance to the sun: 108,000,000 km
            // perihelion: 107,000,000 km
            // inclination: km
            // translation: 255 days
            // rotation: 243 days
            // perihelion: 107,000,000 km
            
            perihelion = (69.57 + 10700 + .6052) * orbitScale;
            pos[0] = (69.57 + 10800.0 + .6052) * orbitScale;
            pos[1] = 0.0f;
            pos[2] = 0.0f;
            radius = (.6052) * planetScale;
            translationDays = 255;
            break;
        case 3:
            LoadTGA(&targas, "/Users/MemoBG/Documents/ITC/8º semestre/Gráficas Computacionales/Proyectos/SolarSystem/SolarSystem/assets/earth.tga");
            // radius: 6378.1 km
            // distance to the sun: 150,000,000 km
            // perihelion: 147,000,000 km
            // inclination: km
            // translation: 365 days
            // rotation: 1 days
            
            perihelion = (69.57 + 14700 + .63781) * orbitScale;
            pos[0] = (69.57 + 15000.0 + .63781) * orbitScale;
            pos[1] = 0.0f;
            pos[2] = 0.0f;
            radius = .63781 * planetScale;
            translationDays = 365;
            break;
        case 4:
            LoadTGA(&targas, "/Users/MemoBG/Documents/ITC/8º semestre/Gráficas Computacionales/Proyectos/SolarSystem/SolarSystem/assets/mars.tga");
            // radius: 3396.2 km
            // distance to the sun: 228,000,000 km
            // perihelion: 207,000,000 km
            // inclination: km
            // translation: 686.2 days
            // rotation: 1.03 days
            
            perihelion = (69.57 + 22800 + .33962) * orbitScale;
            pos[0] = (69.57 + 22800.0 + .33962) * orbitScale;
            pos[1] = 0.0f;
            pos[2] = 0.0f;
            radius = .33962 * planetScale;
            translationDays = 686.2;
            break;
        case 5:
            LoadTGA(&targas, "/Users/MemoBG/Documents/ITC/8º semestre/Gráficas Computacionales/Proyectos/SolarSystem/SolarSystem/assets/jupiter.tga");
            // radius: 71492 km
            // distance to the sun: 778,000,000 km
            // perihelion: 741,000,000 km
            // inclination: km
            // translation: 4,343.5 days
            // rotation: 0.4132 days
            
            perihelion = (69.57 + 74100 + 7.1492) * orbitScale;
            pos[0] = (69.57 + 77800.0 + 7.1492) * orbitScale;
            pos[1] = 0.0f;
            pos[2] = 0.0f;
            radius = 7.1492 * planetScale;
            translationDays = 4343.5;
            break;
        case 6:
            LoadTGA(&targas, "/Users/MemoBG/Documents/ITC/8º semestre/Gráficas Computacionales/Proyectos/SolarSystem/SolarSystem/assets/saturn.tga");
            // radius: 60268 km
            // distance to the sun: 1,427,000,000 km
            // perihelion: 1,350,000,000 km
            // inclination: km
            // translation: 10,585 days
            // rotation: 0.4375 days
            
            perihelion = (69.57 + 135000 + 6.0268) * orbitScale;
            pos[0] = (69.57 + 142700 + 6.0268) * orbitScale;
            pos[1] = 0.0f;
            pos[2] = 0.0f;
            radius = 6.0268 * planetScale;
            translationDays = 10585;
            break;
        case 7:
            LoadTGA(&targas, "/Users/MemoBG/Documents/ITC/8º semestre/Gráficas Computacionales/Proyectos/SolarSystem/SolarSystem/assets/uranus.tga");
            // radius: 25,559 km
            // distance to the sun: 2,870,000,000 km
            // perihelion: 2,730,000,000 km
            // inclination: km
            // translation: 30,660 days
            // rotation: 0.7187 days
            
            perihelion = (69.57 + 273000 + 2.5559) * orbitScale;
            pos[0] = (69.57 + 287000 + 2.5559) * orbitScale;
            pos[1] = 0.0f;
            pos[2] = 0.0f;
            radius = 2.5559 * planetScale;
            translationDays = 30660;
            break;
        case 8:
            LoadTGA(&targas, "/Users/MemoBG/Documents/ITC/8º semestre/Gráficas Computacionales/Proyectos/SolarSystem/SolarSystem/assets/neptune.tga");
            // radius: 24,041 km
            // distance to the sun: 4,500,000,000km
            // perihelion: 4,460,000,000 km
            // inclination: km
            // translation: 60,225 days
            // rotation: 0.701 days
            
            perihelion = (69.57 + 446000 + 2.4041) * orbitScale;
            pos[0] = (69.57 + 450000 + 2.4041) * orbitScale;
            pos[1] = 0.0f;
            pos[2] = 0.0f;
            radius = 2.4041 * planetScale;
            translationDays = 60225;
            break;
    }
    
    // ELLIPSE
    a = pos[0];
    b = sqrt((a * a) - ((a - perihelion) * (a - perihelion))); // b^2 = a^2 - c^2
    day = 360 / translationDays;
    
    // THIS DON'T USE MIPMAPS
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, targas.width, targas.height, 0, GL_RGB, GL_UNSIGNED_BYTE, targas.imageData);
    
    glBindTexture(GL_TEXTURE_2D, 0);
    
    
}

Planet::~Planet()
{
    glDeleteTextures( 1, &targas.texID );
}

void Planet::drawOrbit()
{
    //glPushMatrix();
    glColor3f(0, 0, 0);
    glLineWidth(0.5);
    glBegin(GL_LINE_LOOP);
    float x = 0;
    float z = 0;
    for (int i = 0; i < 360; i++)   {
        float radians = 2.0f * 3.1416f * i / 180.f;
        float xc = x + a * cosf(radians);
        float zc = z + b * sinf(radians);
        glVertex3f(xc, 0, zc);
    }
    glEnd();
    //glPopMatrix();
}

void Planet::getTranslationPosition(float t)
{
    float x = 0;
    float z = 0;
    float radians = 2.0f * 3.1416f * t / 180.f;
    pos[0] = x + a * cosf(radians);
    pos[2] = z + b * sinf(radians);
}

void Planet::draw()
{
    
    // ====== CITA [1] ======
    GLUquadric *qobj = gluNewQuadric();
    gluQuadricTexture(qobj,GL_TRUE);
    glBindTexture(GL_TEXTURE_2D,targas.texID);
    
    glPushMatrix();
    {
        drawOrbit();
        glTranslatef(pos[0], pos[1], pos[2]);
        glRotatef(90, 1, 0, 0);
        gluSphere(qobj,radius,50,50);
        gluDeleteQuadric(qobj);
        
    }
    glPopMatrix();
    
}

void Planet::update()
{
    // ====== TRANSLATION ======
    
    if(day < 360){
        currentDay = currentDay + day;
    } else {
        currentDay = 0;
    }
    float translation = translationDays * currentDay;
    getTranslationPosition(currentDay);
    
}
