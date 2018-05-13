//  Guillermo Barrientos González
//  A0332278
//
//
//  Computer Graphics. TC3022.
//  Basic TGA textures.
//  Displays a textured cube with vertices, normals and texture coordinates.
//


#pragma once
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include "freeglut.h"
#endif

#include "Camera.hpp"
#include "cPlanet.hpp"
#include "cSkybox.hpp"


// ==== CAMERA ====

int mouseCoords[2], mouseMotionType = 0;
Camera sceneCam, lightCam;
Camera *draggedCamera, *currentCamera;
float posX;
float posY;
float posZ;

// ==== SKYBOX ====

Skybox* skybox;

// ===== PLANET =====

Planet* sun;
Planet* mercury;
Planet* venus;
Planet* earth;
Planet* mars;
Planet* jupiter;
Planet* saturn;
Planet* uranus;
Planet* neptune;

GLfloat rotation;                                 // por borrar y pasarlo a planetas

// ==== MATERIAL ====

GLfloat* mat0_specular;
GLfloat* mat0_diffuse;
GLfloat* mat0_shininess;
GLfloat* light0_position;

// ==== OTHERS ====
bool play;
int velocity;


void init( void )
{
    // ==== OTHERS (INIT) ====
    
    play = false;
    velocity = 8;
    
    // ==== CAMERA (INIT) ====
    
    //glPopMatrix();
    
    //sceneCam.setPos(500, 100.0, -250);
    // sceneCam.setPos(0, 0, -2000000); // for real
    sceneCam.setPos(0, 0, -1400); // for ficticial
    sceneCam.setDirVec(0, 0, 1);
    sceneCam.setUpVec(0, -1, 0);
    sceneCam.setPivot(0,0,0);
    sceneCam.fov = 45;
    sceneCam.near_plane = 0.1;
    sceneCam.far_plane = 4000000.0f;
    
    posX = 0;
    posY = 0;
    posZ = -1400;
    lightCam.setPos(0, 0, -1400);
    lightCam.setDirVec(0, 0, 1);
    //lightCam.setPos(-3500, -2000, -1000);  // perspective
    //lightCam.setDirVec(1, 0.25, 0); // perspective
    lightCam.setPivot(0,0,0);
    lightCam.fov = 45;
    lightCam.setUpVec(0, -1, 0);
    lightCam.near_plane = 0.1;
    lightCam.far_plane = 4000000.0f;
    
    
    currentCamera = &lightCam; //    INITIAL CAMERA
    
    // ==== SKYBOX (INIT) =====
    
    skybox = new Skybox(4000000.0f);
    
    // ==== PLANET (INIT) ===
    
    sun = new Planet(0, 1, 0.1);
    mercury = new Planet(1, 40, 0.1);
    venus = new Planet(2, 40, 0.1);
    earth = new Planet(3, 40, 0.1);
    mars = new Planet(4, 40, 0.1);
    jupiter = new Planet(5, 40, 0.1);
    saturn = new Planet(6, 40, 0.1);
    uranus = new Planet(7, 40, 0.1);
    neptune = new Planet(8, 40, 0.1);
    
    
    glEnable(GL_TEXTURE_2D);                                    // pendiente por acomodar
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glShadeModel(GL_SMOOTH);
    
    // ==== MATERIAL (INIT) =====
    
    mat0_specular = new GLfloat[4];
    mat0_specular[0] = 1.0f; // S0r
    mat0_specular[1] = 1.0f; // S0g
    mat0_specular[2] = 1.0f; // S0b
    mat0_specular[3] = 1.0f; // S0a
    
    mat0_diffuse = new GLfloat[4];
    mat0_diffuse[0] = 1.0f; // D0r
    mat0_diffuse[1] = 0.0f; // D0g
    mat0_diffuse[2] = 0.0f; // D0b
    mat0_diffuse[3] = 1.0f; // D0a
    
    mat0_shininess = new GLfloat[1];
    mat0_shininess[0] = 60.0f;
    
    // ==== LIGTH (INIT) ====
    
    light0_position = new GLfloat[4];
    light0_position[0] = 1.0f; // L0x
    light0_position[1] = 1.0f; // L0y
    light0_position[2] = 1.0f; // L0z
    light0_position[3] = 0.0f; // L0w
    
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    
    rotation = 0.0f;                                          // por borrar y pasarlo a planetas
}

void mouse( int button, int state, int x, int y)              // POSIBLEMENTE POR BORRAR Y CAMBIAR POR TECLAS
{
    int mods;
    mouseCoords[0] = x;
    mouseCoords[1] = y;
    
    if(state == GLUT_DOWN){
        if(button == GLUT_LEFT_BUTTON){
            //draggedCamera = &sceneCam;
            draggedCamera = currentCamera;
        } else if(button == GLUT_RIGHT_BUTTON){
            //draggedCamera = &lightCam;
        } else {
            draggedCamera = 0;
        }
        mods = glutGetModifiers();
        if(mods & GLUT_ACTIVE_SHIFT){
            mouseMotionType = 2;
        } else if(mods & GLUT_ACTIVE_ALT){
            mouseMotionType = 3;
        } else if(mods & GLUT_ACTIVE_CTRL){
            mouseMotionType = 4;
        } else {
            mouseMotionType = 1;
        }
    } else {
        if(button == GLUT_LEFT_BUTTON)
            mouseMotionType = 0;
    }
}

void motion(int x, int y)                                   // CHECAR MOVIMIENTO DE LA CÁMARA
{
    if(!draggedCamera) return;
    if(mouseMotionType == 4) {
        //Type 4: Zoom
        draggedCamera->moveForward((mouseCoords[1] - y) * 0.05); // zTrans += (mouseCoords[1] - y) * 0.02;
        draggedCamera->rotate((mouseCoords[0] - x) * 0.2, 0, 1, 0);
        mouseCoords[0] = x;
        mouseCoords[1] = y;
    } else if(mouseMotionType == 2) {
        // Type 2: Translation on X / Y
        draggedCamera->rotate((mouseCoords[1] - y) * 0.1, 1, 0, 0); // xTrans += (x - mouseCoords[0]) * 0.02;
        draggedCamera->rotate((x - mouseCoords[0]) * 0.1, 0, 0, 1); // yTrans += (mouseCoords[1] - y) * 0.02;
        mouseCoords[0] = x;
        mouseCoords[1] = y;
    } else if(mouseMotionType == 3) {
        // Type 3: Tilt
        draggedCamera->moveUp((mouseCoords[1] - y) * 0.05);   // yTrans += (y - mouseCoords[1]) * 0.02;
        draggedCamera->moveLeft((mouseCoords[0] - x) * 0.05); // xTrans += (mouseCoords[0] - x) * 0.02;
        
        mouseCoords[0] = x;
        mouseCoords[1] = y;
    } else if(mouseMotionType == 1) {
        // Type 1: Rotate scene
        draggedCamera->moveAround((mouseCoords[1] - y) * 0.1, 1, 0, 0);   // yTrans += (y - mouseCoords[1]) * 0.02;
        draggedCamera->moveAround((mouseCoords[0] - x) * 0.1, 0, 1, 0); // xTrans += (mouseCoords[0] - x) * 0.02;
        
        mouseCoords[0] = x;
        mouseCoords[1] = y;
    }
}

void keys (unsigned char key, int x, int y)
{
    switch (key)
    {
            //  ==== CHANGE CAMERA ====
            
        case 'c':
            if(currentCamera == &sceneCam)
            {
                currentCamera = &lightCam;
            } else {
                currentCamera = &sceneCam;
            }
            break;
            
            //  ==== POSITION AND ZOM CAMERA ====
            
        case 'd':
            if(currentCamera == &lightCam){
                lightCam.moveRight(100);
            } else {
                sceneCam.moveRight(100);
            }
            break;
        case 'a':
            if(currentCamera == &lightCam){
                lightCam.moveLeft(100);
            } else {
                sceneCam.moveLeft(100);
            }
            break;
            /*
             case 'w':
             if(currentCamera == &lightCam){
             lightCam.moveUp(100);
             } else{
             sceneCam.moveUp(100);
             }
             break;
             case 's':
             if(currentCamera == &lightCam){
             lightCam.moveDown(100);
             } else {
             sceneCam.moveDown(100);
             }
             break;
             */
        case 'w':
            if(currentCamera == &lightCam){
                lightCam.moveForward(100);
            } else {
                sceneCam.moveForward(100);
            }
            break;
        case 's':
            if(currentCamera == &lightCam){
                lightCam.moveBackward(100);
            } else {
                sceneCam.moveBackward(100);
            }
            break;
            
            //  ==== PLAY AND PAUSE ====
            
        case 'p':
            if(play){
                play = false;
            } else {
                play = true;
            }
            break;
            
            //  ==== VELOCITY ====
            
        case '+':
            if(velocity > 2){
                velocity -= 2;
            }
            break;
        case '-':
            velocity += 2;
            break;
    }
}

void display( void )
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
    //glPopMatrix(); // RESET
    //glPopMatrix();
    
    // ==== MATERIAL (DISPLAY) ====
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat0_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat0_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat0_shininess);
    
    // ==== PLANET (DISPLAY) ====
    
    sun->draw();
    mercury->draw();
    venus->draw();
    earth->draw();
    mars->draw();
    jupiter->draw();
    saturn->draw();
    uranus->draw();
    neptune->draw();
    
    sceneCam.setPos(earth->pos[0], earth->pos[1], earth->pos[2]-800);
    
    // ==== CAMERA (DISPLAY) ====
    
    currentCamera->setView();
    //sceneCam.setPos(earth->pos[0], earth->pos[1], earth->pos[2]+200);
    //sceneCam.draw();
    
    // ==== SKYBOX (DISPLAY) ====
    
    skybox->draw();
    
    glutSwapBuffers();
}

void idle( void )
{
    if(play){
        sun->update(velocity);
        mercury->update(velocity);
        venus->update(velocity);
        earth->update(velocity);
        mars->update(velocity);
        jupiter->update(velocity);
        saturn->update(velocity);
        uranus->update(velocity);
        neptune->update(velocity);
    }
    glutPostRedisplay();
}

void reshape( int w, int h )
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w/h, 0.01f, 500.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    //camRatio = (float)w / h;
    //printf("%.3f\n",camRatio);
    currentCamera->setView();
}

int main( int argc, char** argv )
{
    //srand(time(NULL));
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (1100, 800);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Project Solar System");
    glutReshapeFunc (reshape);
    init ();
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keys);
    glutDisplayFunc(display);
    glutIdleFunc (idle);
    glutMainLoop();
    return 0;
}
