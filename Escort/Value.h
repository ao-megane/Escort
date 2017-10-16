#ifndef VALUE_H
#define VALUE_H
#include"dxlib.h"

#define PI 3.1415926535

const int RED = GetColor(255, 0, 0);
const int GREEN = GetColor(0, 255, 0);
const int BLUE = GetColor(0, 0, 255);
const int BLACK = GetColor(0, 0, 0);
const int GRAY = GetColor(127, 127, 127);
const int WHITE = GetColor(255, 255, 255);
const int ORANGE = GetColor(243, 152, 0);

#define A (Key[0])
#define B (Key[1])
#define X (Key[2])
#define Y (Key[3])
#define RIGHT (Key[4])
#define LEFT (Key[5])
#define R_TRIG (Key[6]) //Trigから加算を始める
#define L_TRIG (Key[7]) //Trigから加算を始める
#define THUMB_Y (Key[8])//-100～+100 100が最大値
#define THUMB_X (Key[9]) //-100～+100 100が最大値

const int Trig = 200; //R2L2のカウントを始めるしきい値
const int ThumbTrig = 16383; //thumbの無視する範囲 ～32767

const int DISP_WIDTH = 2160;
const int DISP_HEIGHT = 1440;

const int P_WIDTH = 350;
const int P_HEIGHT = 480;

const int PRI_WIDTH = 350;
const int PRI_HEIGHT = 480;

#endif // !VALUE_H
