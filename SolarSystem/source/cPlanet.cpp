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
//  https://nssdc.gsfc.nasa.gov/planetary/factsheet/
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
    
    
    // OTHERS
    rotationAngle = 0;
    currentDay = 0;
    currentHour = 0;
    
    
    switch(planet){
        case 0:
            LoadTGA(&targas, "/Users/MemoBG/Documents/ITC/8º semestre/Gráficas Computacionales/Proyectos/SolarSystem/SolarSystem/assets/sun.tga");
            // radius: 695,700 km
            // distance to the sun: 58,000,000km + sun radius
            // rotation: 25 days = 600 hrs
            radius = 69.57;
            pos[0] = 0.0f;
            pos[1] = 0.0f;
            pos[2] = 0.0f;
            rotationHours = 600;
            break;
        case 1:
            LoadTGA(&targas, "/Users/MemoBG/Documents/ITC/8º semestre/Gráficas Computacionales/Proyectos/SolarSystem/SolarSystem/assets/mercury.tga");
            // radius: 2,439 km
            // distance to the sun: 58,000,000 km
            // perihelion: 46,000,000 km
            // eccentricity: 0.205
            // orbital inclination: 7.0 deg
            // obliquity: 0.034 deg
            // translation: 88 days
            // rotation: 59 days = 1416 hrs
            
            perihelion = (69.57 + 4600 + .24397) * orbitScale;
            pos[0] = (69.57 + 5800.0 + .24397) * orbitScale;
            pos[1] = 0.0f;
            pos[2] = 0.0f;
            radius = (.24397) * planetScale;
            translationDays = 88;
            rotationHours = 1416;
            eccentricity = 0.205;
            orbitalInclination = 7.0;
            obliquity = 0.034;
            break;
        case 2:
            LoadTGA(&targas, "/Users/MemoBG/Documents/ITC/8º semestre/Gráficas Computacionales/Proyectos/SolarSystem/SolarSystem/assets/venus.tga");
            // radius: 6052 km
            // distance to the sun: 108,000,000 km
            // perihelion: 107,000,000 km
            // eccentricity: 0.007
            // orbital inclination: 3.4 deg
            // obliquity: 177.4 deg
            // translation: 255 days
            // rotation: 243 days = 5832 hrs
            
            perihelion = (69.57 + 10700 + .6052) * orbitScale;
            pos[0] = (69.57 + 10800.0 + .6052) * orbitScale;
            pos[1] = 0.0f;
            pos[2] = 0.0f;
            radius = (.6052) * planetScale;
            translationDays = 255;
            rotationHours = 5832;
            eccentricity = 0.007;
            orbitalInclination = 3.4;
            obliquity = 177.4;
            break;
        case 3:
            LoadTGA(&targas, "/Users/MemoBG/Documents/ITC/8º semestre/Gráficas Computacionales/Proyectos/SolarSystem/SolarSystem/assets/earth.tga");
            // radius: 6378.1 km
            // distance to the sun: 150,000,000 km
            // perihelion: 147,000,000 km
            // eccentricity: 0.017
            // orbital inclination: 0.0 deg
            // obliquity: 23.4 deg
            // translation: 365 days
            // rotation: 1 days = 24 hrs
            
            perihelion = (69.57 + 14700 + .63781) * orbitScale;
            pos[0] = (69.57 + 15000.0 + .63781) * orbitScale;
            pos[1] = 0.0f;
            pos[2] = 0.0f;
            radius = .63781 * planetScale;
            translationDays = 365;
            rotationHours = 24;
            eccentricity = 0.017;
            orbitalInclination = 0.0;
            obliquity = 23.4;
            
            break;
        case 4:
            LoadTGA(&targas, "/Users/MemoBG/Documents/ITC/8º semestre/Gráficas Computacionales/Proyectos/SolarSystem/SolarSystem/assets/mars.tga");
            // radius: 3396.2 km
            // distance to the sun: 228,000,000 km
            // perihelion: 207,000,000 km
            // eccentricity: 0.094
            // orbital inclination: 1.9 deg
            // obliquity: 25.2 deg
            // translation: 686.2 days
            // rotation: 1.03 days = 24.72 hrs
            
            perihelion = (69.57 + 22800 + .33962) * orbitScale;
            pos[0] = (69.57 + 22800.0 + .33962) * orbitScale;
            pos[1] = 0.0f;
            pos[2] = 0.0f;
            radius = .33962 * planetScale;
            translationDays = 686.2;
            rotationHours = 25;
            eccentricity = 0.094;
            orbitalInclination = 1.9;
            obliquity = 25.2;
            break;
        case 5:
            LoadTGA(&targas, "/Users/MemoBG/Documents/ITC/8º semestre/Gráficas Computacionales/Proyectos/SolarSystem/SolarSystem/assets/jupiter.tga");
            // radius: 71492 km
            // distance to the sun: 778,000,000 km
            // perihelion: 741,000,000 km
            // eccentricity: 0.049
            // orbital inclination: 1.3 deg
            // obliquity: 3.1 deg
            // translation: 4,343.5 days
            // rotation: 0.4132 days = 11.3568 hrs
            
            perihelion = (69.57 + 74100 + 7.1492) * orbitScale;
            pos[0] = (69.57 + 77800.0 + 7.1492) * orbitScale;
            pos[1] = 0.0f;
            pos[2] = 0.0f;
            radius = 7.1492 * planetScale;
            translationDays = 4343.5;
            rotationHours = 12;
            eccentricity = 0.049;
            orbitalInclination = 1.3;
            obliquity = 3.1;
            break;
        case 6:
            LoadTGA(&targas, "/Users/MemoBG/Documents/ITC/8º semestre/Gráficas Computacionales/Proyectos/SolarSystem/SolarSystem/assets/saturn.tga");
            // radius: 60268 km
            // distance to the sun: 1,427,000,000 km
            // perihelion: 1,350,000,000 km
            // eccentricity: 0.057
            // orbital inclination: 2.5 deg
            // obliquity: 26.7 deg
            // translation: 10,585 days
            // rotation: 0.4375 days = 10.5 hrs
            
            perihelion = (69.57 + 135000 + 6.0268) * orbitScale;
            pos[0] = (69.57 + 142700 + 6.0268) * orbitScale;
            pos[1] = 0.0f;
            pos[2] = 0.0f;
            radius = 6.0268 * planetScale;
            translationDays = 10585;
            rotationHours = 11;
            eccentricity = 0.057;
            orbitalInclination = 2.5;
            obliquity = 26.7;
            break;
        case 7:
            LoadTGA(&targas, "/Users/MemoBG/Documents/ITC/8º semestre/Gráficas Computacionales/Proyectos/SolarSystem/SolarSystem/assets/uranus.tga");
            // radius: 25,559 km
            // distance to the sun: 2,870,000,000 km
            // perihelion: 2,730,000,000 km
            // eccentricity: 0.046
            // orbital inclination: 0.8 deg
            // obliquity: 97.8 deg
            // translation: 30,660 days
            // rotation: 0.7187 days = 17.2488 hrs
            
            perihelion = (69.57 + 273000 + 2.5559) * orbitScale;
            pos[0] = (69.57 + 287000 + 2.5559) * orbitScale;
            pos[1] = 0.0f;
            pos[2] = 0.0f;
            radius = 2.5559 * planetScale;
            translationDays = 30660;
            rotationHours = 17;
            eccentricity = 0.046;
            orbitalInclination = 0.8;
            obliquity = 97.8;
            break;
        case 8:
            LoadTGA(&targas, "/Users/MemoBG/Documents/ITC/8º semestre/Gráficas Computacionales/Proyectos/SolarSystem/SolarSystem/assets/neptune.tga");
            // radius: 24,041 km
            // distance to the sun: 4,500,000,000km
            // perihelion: 4,460,000,000 km
            // eccentricity: 0.011
            // orbital inclination: 1.8 deg
            // obliquity: 28.3 deg
            // translation: 60,225 days
            // rotation: 0.701 days = 16.824 hrs
            
            perihelion = (69.57 + 446000 + 2.4041) * orbitScale;
            pos[0] = (69.57 + 450000 + 2.4041) * orbitScale;
            pos[1] = 0.0f;
            pos[2] = 0.0f;
            radius = 2.4041 * planetScale;
            translationDays = 60225;
            rotationHours = 17;
            eccentricity = 0.011;
            orbitalInclination = 1.8;
            obliquity = 28.3;
            break;
        case 9:
            LoadTGA(&targas, "/Users/MemoBG/Documents/ITC/8º semestre/Gráficas Computacionales/Proyectos/SolarSystem/SolarSystem/assets/moon.tga");
            // radius: 1737.5 km
            // distance to the earth: 384,000 km
            // perihelion: 363,000 km
            // eccentricity: 0.055
            // orbital inclination: 5.1 deg
            // obliquity: 6.7 deg
            // translation: 27.3 days
            // rotation: 655.7 hrs
            
            perihelion = (.63781 + 36.3 + 0.1738) * orbitScale;
            pos[0] = (0.63781 + 38.4 + 0.1738) * orbitScale;
            pos[1] = 0.0f;
            pos[2] = 0.0f;
            radius = 0.1738 * planetScale;
            translationDays = 27;
            rotationHours = 656;
            eccentricity = 0.055;
            orbitalInclination = 5.1;
            obliquity = 6.7;
            break;
    }
    
    // ELLIPSE
    a = pos[0];
    b = sqrt((a * a) - ((eccentricity * a) * (eccentricity * a))); // b^2 = a^2 - c^2
    day = 360 / translationDays;
    
    hour = 360 / rotationHours;
    
    // THIS DON'T USE MIPMAPS
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, targas.width, targas.height, 0, GL_RGB, GL_UNSIGNED_BYTE, targas.imageData);
    
    glBindTexture(GL_TEXTURE_2D, 0);
    
    // ==== OTHER ATTRIBUTES ====
    if(planetNumber == 3){
        moon = new Planet(9, planetScale, 1);
    }
    
    if(planetNumber == 6){
        //  ###### RING #####
        glGenTextures(1, &targasRing.texID);
        glBindTexture(GL_TEXTURE_2D, targasRing.texID);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        // THIS DOESN'T USE MIPMAPS
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // ####### RINGS ########
        LoadTGA(&targasRing, "/Users/MemoBG/Documents/ITC/8º semestre/Gráficas Computacionales/Proyectos/SolarSystem/SolarSystem/assets/saturn-ring.tga");
        // THIS DON'T USE MIPMAPS
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, targasRing.width, targasRing.height, 0, GL_RGB, GL_UNSIGNED_BYTE, targasRing.imageData);
        
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    
    
    
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
    
    if(planetNumber != 0){
        glPushMatrix();
        {
            if(planetNumber == 9){
                glRotatef(90, 1, 0, 0);
            }
            glTranslatef(a - perihelion, 0, 0);   // PERIHELION
            glRotated(orbitalInclination, 0, 0, 1);  // ORBITAL INCLINATION
            drawOrbit();
            glTranslatef(pos[0], pos[1], pos[2]);
            glRotatef(90, 1, 0, 0);
            glRotatef(obliquity, 1, 0, 0);
            glRotatef(rotationAngle, 0, 0, 1);
            gluSphere(qobj, radius, 50, 50);
            gluDeleteQuadric(qobj);
            
            
            if(planetNumber == 6){
                GLUquadric *ring = gluNewQuadric();
                gluQuadricTexture(ring,GL_TRUE);
                glBindTexture(GL_TEXTURE_2D,targasRing.texID);
                //glutSolidTorus(490, 500, 2.4, 360);
                gluDisk(ring, 400, 600, 90, 10);
                gluDeleteQuadric(ring);
            }
            
            if(planetNumber == 3){
                moon->draw();
            }
            
            
        }
        glPopMatrix();
    }
    else{
        glPushMatrix();
        {
            glRotatef(90, 1, 0, 0);
            glRotatef(obliquity, 1, 0, 0);
            glRotatef(rotationAngle, 0, 0, 1);
            gluSphere(qobj,radius,50,50);
            gluDeleteQuadric(qobj);
        }
        glPopMatrix();
    }
    
    
}

void Planet::update(int velocity)
{
    // ====== TRANSLATION ======
    
    if(currentDay < 360){
        currentDay = currentDay + (day/velocity);
    } else {
        currentDay = 0;
    }
    getTranslationPosition(currentDay);
    
    // ====== ROTATION ======
    float h = 24 / velocity;
    
    if(currentHour < 360){
        currentHour = currentHour + hour * h;
    } else {
        currentHour = 0;
    }
    rotationAngle = currentHour;
    
    if(planetNumber == 3){
        moon->update(velocity);
    }
    
}
