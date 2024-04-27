//
//  Head.h
//  AnimalHockey
//
//

#ifndef Head_h
#define Head_h

#include <stdio.h>

//色

static const GLfloat red[] = { 1.0, 0.0, 0.0, 1.0 };
static const GLfloat yellow[] = { 1.0, 0.85, 0.0, 1.0 };
static const GLfloat blue[] = { 0.0, 0.32, 0.4, 1.0 };
static const GLfloat rightblue[] = { 0.2, 0.8, 0.8, 1.0 };
static const GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
static const GLfloat white1[] = { 0.8, 0.8, 0.8, 1.0 };
static const GLfloat black[] = { .1, .1, .1, 1.0 };
static const GLfloat beige[] = { 0.8, 0.7, 0.4, 1.0 };
static const GLfloat gray[] = { 0.1, 0.1, 0.1, 1.0 };
static const GLfloat green[] = { 0.0, 1.0, 0.0, 1.0 };
static const GLfloat dgreen[] = { 0.5, 1.0, 0.5, 1.0 };
static const GLfloat grey[] = { 0.5, 0.5, 0.5, 1.0 };
static const GLfloat dgrey[] = { 0.4, 0.4, 0.4, 1.0 };

//
static const GLfloat pos[] = {0, 5000, 0, 1};
static const GLfloat pos0[] = { -500.0, 500.0, 0, 1 };
static const GLfloat pos1[] = { 0.0, 0.0, 5.0, 1.0 };

//関数
void drawField(void);//フィールドの描画
void drawPuck(double x, double y, double z);//パックの描画
void drawHandle(double x, double y, double z);

//変数
static int rightscore=0;     //右のプレイヤーの得点
static int leftscore=0;     //左のプレイヤーの得点
static char  score1[256];

extern double px;     //パックの位置
extern double py;     //パックの位置
extern double pz;     //パックの位置
extern double pvx;     //パックの速度
extern double pvy;     //パックの速度
extern int pucknumber;     //パックの種類を指定する数字

extern double hx1;
extern double hy1;
extern double hz1;

extern double hx2;
extern double hy2;
extern double hz2;


//定数
static const int width = 300;     //フィールドの幅
static const int length = 400;     //フィールドの長さ
static const int height = 50;     //壁の高さ
static const int goalwidth = 100;     //ゴールの幅

static const double px0 = 0;     //パックの初期位置
static const double py0 = 0;     //パックの位置
static const double pz0 = 0;     //パックの位置
static const double pvx0 = 0.8;     //パックの速度
static const double pvy0 = 1;     //パックの速度

static const double hx10 = 0;
static const double hy10 = -100;
static const double hz10 = 0;

static const double hx20 = 0;
static const double hy20 = 100;
static const double hz20 = 0;


#endif /* Head_h */
