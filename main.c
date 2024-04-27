//
//  main.c
//  AnimalHockey
//  戸叶さん、園さん

#include <stdio.h>
#include <math.h>
#include <GLUT/GLUT.h>
#include <Opengl/opengl.h>
//#include <GL/glut.h>
#include "Head.h"

double px = px0;     //パックの位置
double py = py0;     //パックの位置
double pz = pz0;     //パックの位置
double pvx= pvx0;     //パックの速度
double pvy= pvy0;     //パックの速度

double hx1 = hx10;
double hy1 = hy10;
double hz1 = hz10;
double hx2 = hx20;
double hy2 = hy20;
double hz2 = hz20;

int pucknumber = 2;

int mySpecialValue1 = 0;
int mySpecialValue2 = 0;

int crashFrag1 = 0;
int crashFrag2 = 0;

int startFrag = 0;

void display(void){
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    //    glScalef(0.5, 0.5, 0.5);
    drawPuck(px, py, pz);
    glPopMatrix();
    
    
    
    drawField();
    
    glPushMatrix();
    drawHandle(hx1, hy1, hz1);
    glPopMatrix();
    glPushMatrix();
    drawHandle(hx2, hy2, hz2);
    glPopMatrix();
    //glutSwapBuffers();
}

void myKeyboardFunc(unsigned char key, int x, int y){     //パックの変更、Handle1を動かす
    switch(key){
        case '1':     //Pucknumberの増加(increase)
            pucknumber = 1;
            break;
        case '2':     //Pucknumberの減少(decrease)
            pucknumber=2;
            break;
            
        case 'w':
            mySpecialValue1 |= 1 << 0;
            break;
        case 'a':
            mySpecialValue1 |= 1 << 1;
            break;
        case 'd':
            mySpecialValue1 |= 1 << 2;
            break;
        case 's':
            mySpecialValue1 |= 1 << 3;
            break;
            
        case ' ':
            startFrag = 1;
            break;
            
        case 'p':
            startFrag = 0;
            break;
            
        default:
            break;
            
    }
    
}

void myKeyboardUpFunc(int key, int x, int y)
{
    switch (key)
    {
        case 'w':
            mySpecialValue1 &= ~(1 << 0);//mySpecialValueの1bit目を0にする
            break;
        case 'a':
            mySpecialValue1 &= ~(1 << 1);//mySpecialValueの2bit目を0にする
            break;
        case 'd':
            mySpecialValue1 &= ~(1 << 2);//mySpecialValueの3bit目を0にする
            break;
        case 's':
            mySpecialValue1 &= ~(1 << 3);//mySpecialValueの4bit目を0にする
            break;
        default:
            break;
    }
    
}

void mySpecialFunc(unsigned char key, int x, int y){     //Handle2を動かす
    switch(key){
            
        case GLUT_KEY_UP:
            mySpecialValue2 |= 1 << 0;
            break;
        case GLUT_KEY_LEFT:
            mySpecialValue2 |= 1 << 1;
            break;
        case GLUT_KEY_RIGHT:
            mySpecialValue2 |= 1 << 2;
            break;
        case GLUT_KEY_DOWN:
            mySpecialValue2 |= 1 << 3;
            break;
            
        default:
            break;
    }
}

void mySpcialUpFunc(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_UP:
            mySpecialValue2 &= ~(1 << 0);//mySpecialValueの1bit目を0にする
            break;
        case GLUT_KEY_LEFT:
            mySpecialValue2 &= ~(1 << 1);//mySpecialValueの2bit目を0にする
            break;
        case GLUT_KEY_RIGHT:
            mySpecialValue2 &= ~(1 << 2);//mySpecialValueの3bit目を0にする
            break;
        case GLUT_KEY_DOWN:
            mySpecialValue2 &= ~(1 << 3);//mySpecialValueの4bit目を0にする
            break;
        default:
            break;
    }
    
}

void myTimerFunc(int value){
    
    if(startFrag) {
        
        glLoadIdentity();
        gluLookAt(-200, 0, 300.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
        if(px<-(width/2.0)+30 || px>(width/2.0)-30) pvx=-pvx;     //壁での反射
        if(py<-(length/2.0)+30 || py>(length/2.0)-30) pvy=-pvy;     //壁での反射
        
        
        
        
        
        if(hx1-40<px && px<hx1+40 && hy1-40<py && py<hy1+40) {//Handle1での反射
            if (!crashFrag1) {
                crashFrag1 = 1;
                if (fabs(px-hx1) <= fabs(py-hy1)) {
                    pvy = -pvy;
                } else {
                    pvx = -pvx;
                }
                
            }
        } else {
            crashFrag1 = 0;
        }
        
        if(hx2-40<px && px<hx2+40 && hy2-40<py && py<hy2+40) {//Handle2での反射
            if (!crashFrag2) {
                crashFrag2 = 1;
                if (fabs(px-hx2) <= fabs(py-hy2)) {
                    pvy = -pvy;
                } else {
                    pvx = -pvx;
                }
                
            }
        } else {
            crashFrag2 = 0;
        }
        
        
        
        
        
        if((px>=-goalwidth/2.0 && px<=goalwidth/2.0) && (py<=-(length/2.0)+40 && py>=-(length/2.0)+30)) {   //右のプレイヤーの得点時
            px=0;
            py=0;
            pvx=-pvx;
            rightscore++;
            startFrag = 0;
        }
        if((px>=-goalwidth/2.0 && px<=goalwidth/2.0) && (py>=(length/2.0)-40 && py<=(length/2.0)-30)) {    //左のプレイヤーの得点時
            
            px=0;
            py=0;
            pvx=-pvx;
            leftscore++;
            startFrag = 0;
        }
        
        px+=pvx;     //パックの移動
        py+=pvy;
        
        
        if (mySpecialValue1 == 1 && hy1<-20)hy1+=1;//ここを変更
        if (mySpecialValue1 == 2 && hx1>-width/2+20)hx1-=1;//ここを変更
        if (mySpecialValue1 == 4 && hx1<width/2-20)hx1+=1;//ここを変更
        if (mySpecialValue1 == 8 && hy1>-length/2+20)hy1-=1;//ここを変更
        if (mySpecialValue1 == 3 && hy1<-20 && hx1>-width/2+20){
            hx1-=1;
            hy1+=1;
        }
        if (mySpecialValue1 == 5 && hy1<-20 && hx1<width/2-20){
            hx1+=1;
            hy1+=1;
        }
        if (mySpecialValue1 == 10 && hy1>-length/2+20 && hx1>-width/2+20){
            hx1-=1;
            hy1-=1;
        }
        if (mySpecialValue1 == 12 && hy1>-length/2+20 && hx1<width/2-20){
            hx1+=1;
            hy1-=1;
        }
        
        
        //
        if (mySpecialValue2 == 1 && hy2>20)hy2-=1;//ここを変更
        if (mySpecialValue2 == 2 && hx2<width/2-20)hx2+=1;//ここを変更
        if (mySpecialValue2 == 4 && hx2>-width/2+20)hx2-=1;//ここを変更
        if (mySpecialValue2 == 8 && hy2<length/2-20)hy2+=1;//ここを変更
        if (mySpecialValue2 == 3 && hy2>20 && hx2<width/2-20){
            hx2+=1;
            hy2-=1;
        }
        if (mySpecialValue2 == 5 && hy2>20 && hx2>-width/2+20){
            hx2-=1;
            hy2-=1;
        }
        if (mySpecialValue2 == 10 && hy2<length/2-20 && hx2<width/2-20){
            hx2+=1;
            hy2+=1;
        }
        if (mySpecialValue2 == 12 && hy2<length/2-20 && hx2>-width/2+20){
            hx2-=1;
            hy2+=1;
        }
        
    }
    
    if(startFrag) glutTimerFunc(10, myTimerFunc, 0);
}

void idle(void){
    glutPostRedisplay();
}

void init(void){
    
    
    
    glClearColor(0.0, 0.8, 0.4, 0.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    
    glutKeyboardFunc(myKeyboardFunc);
    glutKeyboardUpFunc(myKeyboardUpFunc);
    glutSpecialFunc(mySpecialFunc);
    glutSpecialUpFunc(mySpcialUpFunc);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    

        glLightfv(GL_LIGHT0, GL_AMBIENT, white1);

    
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1, 1.0, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    gluLookAt(-200, 0, 300.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    
    if(startFrag) myTimerFunc(0);
}

void drawBitmapString(void* font, char* string){
    glPushAttrib(GL_CURRENT_BIT);
    
    /* ビットマップ文字列の描画 */
    while (*string)
        glutBitmapCharacter(font, *string++);
    
    glPopAttrib();
}


void visudisplay(void) {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //glRasterPos2f(0.0, -0.9);
    sprintf(score1, "Score is %d - %d", leftscore, rightscore);
    
    drawBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,score1);
    
    
    gluLookAt(0.0, -(length/2.0)+150, 100.0, 0.0, 0.0, 1.5, -1.0, 0.0, 0.0);
    //    glLightfv(GL_LIGHT1, GL_POSITION, pos1);
    //    glLightfv(GL_LIGHT0, GL_AMBIENT, white);
    glViewport(50, 150, 500, 500);
    
    //    glPushMatrix();
    //    drawField();
    //    drawPuck();
    //    glPopMatrix();
    display();
    
    init();
    
    
    gluLookAt(0.0, (length/2.0)-150, 100, 0.0, 0.0, 1.5, 1.0, 0.0, 0.0);
    //    glLightfv(GL_LIGHT1, GL_POSITION, pos1);
    //    glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
    glViewport(650, 150, 500, 500);
    //    drawField();
    //    drawPuck();
    
    display();
    init();
    
    
    glutIdleFunc(idle);
    
    glutSwapBuffers();
    
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1200, 800);
    glutCreateWindow("C Dev");
    
    glutDisplayFunc(visudisplay);
    
    glutMainLoop();
    return 0;
}
