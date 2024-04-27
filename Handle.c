//
//  Handle.c
//  AnimalHockey
//
//  天野さん
//

#include <stdio.h>
#include <math.h>
#include <GLUT/GLUT.h>
#include <Opengl/opengl.h>
//#include <GL/glut.h>
#include "Head.h"

void Handle(void) {
    int rad = 40;
    float height = 40;
    int size_r = 50;
    double pi = 3.1415;
    GLfloat color[4];
    double radius[30] = {0};
    double h_before, h_after;
    double rad_c = 2 * pow(3,0.5) * height / 18;
    for(int j=1; j<27; j++){
//        glMaterialfv(GL_FRONT, GL_DIFFUSE, white1);
        glMaterialfv(GL_FRONT, GL_AMBIENT, color);
//        glMaterialfv(GL_FRONT, GL_SPECULAR, white1);
        glMaterialf(GL_FRONT, GL_SHININESS, 10.0);
        glBegin(GL_QUAD_STRIP);
        for(double i=0;i<=size_r;i=i+1){
            double t = i*2*pi/size_r;
            if(j == 1){
                radius[j] = 0.5 * rad;
                h_before = 0;
                h_after = 0;
                for(int k=0; k<4; k++){color[k] = red[k];}
                glNormal3f(0.0, -1.0, 0.0);
            }
            else if(j == 2){
                radius[j] = 0.5 * rad;
                h_before = 0;
                h_after = 0.3 * height;
                for(int k=0; k<4; k++){color[k] = red[k];}
                glNormal3f((GLfloat)cos(t),0.0,(GLfloat)sin(t));
            }
            else if(j == 3){
                radius[j] = 0.45 * rad;
                h_before = 0.3 * height;
                h_after = 0.3 * height;
                for(int k=0; k<4; k++){color[k] = red[k];}
                glNormal3f(0.0, 1.0, 0.0);
            }
            else if(j == 4){
                radius[j] = 0.45 * rad;
                h_before = 0.3 * height;
                h_after = 0.05 * height;
                for(int k=0; k<4; k++){color[k] = red[k];}
                glNormal3f(-(GLfloat)cos(t),0.0,-(GLfloat)sin(t));
            }
            else if(j == 5){
                radius[j] = rad_c;
                h_before = 0.05 * height;
                h_after = 0.05 * height;
                for(int k=0; k<4; k++){color[k] = red[k];}
                glNormal3f(0.0, 1.0, 0.0);
            }
            else if(j == 6){
                radius[j] = rad_c;
                h_before = 0.05 * height;
                h_after = height / 3;
                for(int k=0; k<4; k++){color[k] = red[k];}
                glNormal3f((GLfloat)cos(t),0.0,(GLfloat)sin(t));
            }
            else {
                radius[j] = rad_c + 0.5 * rad_c * pow((j - 7), 2) / pow(19, 2);
                h_before = height / 3 + height*(j-7)/114;
                h_after = height / 3 + height*(j-6)/114;
                for(int k=0; k<4; k++){color[k] = red[k];}
                glNormal3f((GLfloat)cos(t),0.0,(GLfloat)sin(t));
            }
            //glNormal3f((GLfloat)cos(t),0.0,(GLfloat)sin(t));
            
            glVertex3f((GLfloat)(radius[j-1]*cos(t)), h_before, (GLfloat)(radius[j-1]*sin(t)));
            glVertex3f((GLfloat)(radius[j]*cos(t)), h_after, (GLfloat)(radius[j]*sin(t)));
        }
        glEnd();
    }
    
    glTranslatef(0, 2 * height / 3, 0);
    glutSolidSphere(height / 3, 100, 100);
}

void drawHandle(double x, double y, double z) {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glPushMatrix();
    glTranslated(x, y, z);
    glRotatef(90, 1, 0, 0);
    Handle();
    glPopMatrix();
//    glutSwapBuffers();
}
