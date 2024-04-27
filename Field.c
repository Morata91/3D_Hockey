//
//  Field.c
//  AnimalHockey
//
//  村田担当分
//

#include <stdio.h>
#include <GLUT/GLUT.h>
#include <Opengl/opengl.h>
//#include <GL/glut.h>
#include "Head.h"

void drawField(void){
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, rightblue);
    glBegin(GL_POLYGON);
    glVertex3d(width/2, length/2, 0);
    glVertex3d(-width/2, length/2, 0);
    glVertex3d(-width/2, -length/2, 0);
    glVertex3d(width/2, -length/2, 0);
    glEnd();
    
    //
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, blue);
    glBegin(GL_POLYGON);
    glVertex3d(width/2, length/2, 0);
    glVertex3d(width/2, length/2, height);
    glVertex3d(goalwidth/2, length/2, height);
    glVertex3d(goalwidth/2, length/2, 0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3d(-goalwidth/2, length/2, 0);
    glVertex3d(-goalwidth/2, length/2, height);
    glVertex3d(-width/2, length/2, height);
    glVertex3d(-width/2, length/2, 0);
    glEnd();
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, blue);
    glBegin(GL_POLYGON);
    glVertex3d(goalwidth/2, length/2, 0);
    glVertex3d(goalwidth/2, length/2, height);
    glVertex3d(width/2, length/2, height);
    glVertex3d(width/2, length/2, 0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3d(-width/2, length/2, 0);
    glVertex3d(-width/2, length/2, height);
    glVertex3d(-goalwidth/2, length/2, height);
    glVertex3d(-goalwidth/2, length/2, 0);
    glEnd();
    //
    
    glBegin(GL_POLYGON);
    glVertex3d(width/2, -length/2, 0);
    glVertex3d(goalwidth/2, -length/2, 0);
    glVertex3d(goalwidth/2, -length/2, height);
    glVertex3d(width/2, -length/2, height);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3d(-goalwidth/2, -length/2, 0);
    glVertex3d(-width/2, -length/2, 0);
    glVertex3d(-width/2, -length/2, height);
    glVertex3d(-goalwidth/2, -length/2, height);
    glEnd();
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, blue);
    glBegin(GL_POLYGON);
    glVertex3d(width/2, -length/2, 0);
    glVertex3d(width/2, -length/2, height);
    glVertex3d(goalwidth/2, -length/2, height);
    glVertex3d(goalwidth/2, -length/2, 0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3d(-goalwidth/2, -length/2, 0);
    glVertex3d(-goalwidth/2, -length/2, height);
    glVertex3d(-width/2, -length/2, height);
    glVertex3d(-width/2, -length/2, 0);
    glEnd();
    //
    
    glBegin(GL_POLYGON);
    glVertex3d(width/2, length/2, height);
    glVertex3d(width/2, length/2, 0);
    glVertex3d(width/2, -length/2, 0);
    glVertex3d(width/2, -length/2, height);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3d(-width/2, -length/2, height);
    glVertex3d(-width/2, -length/2, 0);
    glVertex3d(-width/2, length/2, 0);
    glVertex3d(-width/2, length/2, height);
    
    glEnd();
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, black);
    glBegin(GL_LINES);
    glVertex3d(width/2, 0, 1);
    glVertex3d(-width/2, 0, 1);
    glEnd();
    
}
