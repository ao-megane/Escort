#include"DxLib.h"
#include"Value.h"
//#include"math.h"

#pragma(push)
#pragma warning ( disable : 4789 )
// unused code that generates compiler warning C4789
#pragma(pop)

void InputInitialize(int key[]) {
	for (int i = 0; i < 20; i++)
		key[i] = 0;
}

void InputUpdata(XINPUT_STATE input, int Key[]) {

	GetJoypadXInputState(DX_INPUT_PAD1, &input);
	if (input.Buttons[12]) A++; else A = 0;
	if (input.Buttons[13]) B++; else B = 0;
	if (input.Buttons[14]) X++; else X = 0;
	if (input.Buttons[15]) Y++; else Y = 0;
	if (input.Buttons[9]) RIGHT++; else RIGHT = 0;
	if (input.Buttons[8]) LEFT++; else LEFT = 0;
	if (input.Buttons[4]) PAUSE++; else PAUSE = 0;
	if (input.LeftTrigger > Trig) L_TRIG++; else L_TRIG = 0;
	if (input.RightTrigger > Trig) R_TRIG++; else R_TRIG = 0;

	if ((input.ThumbLY * input.ThumbLY + input.ThumbLX * input.ThumbLX) < ThumbTrig * ThumbTrig) {
		THUMB_Y = 0;
		THUMB_X = 0;
	}
	else {
		THUMB_Y = (-1) * input.ThumbLY / 32767.0 * 100;
		THUMB_X = input.ThumbLX / 32767.0 * 100;
	}

}

void InputUpdata(int Key[]) {

		 if (CheckHitKey(KEY_INPUT_RIGHT) && CheckHitKey(KEY_INPUT_RSHIFT)) THUMB_X = 100; 
	else if (CheckHitKey(KEY_INPUT_RIGHT)) THUMB_X = 55;
	else if (CheckHitKey(KEY_INPUT_LEFT) && CheckHitKey(KEY_INPUT_RSHIFT)) THUMB_X = -100;
	else if (CheckHitKey(KEY_INPUT_LEFT)) THUMB_X = -55;
	else THUMB_X = 0;
		 if (CheckHitKey(KEY_INPUT_UP)) THUMB_Y = -80;
	else if (CheckHitKey(KEY_INPUT_DOWN)) THUMB_Y = 80;
	else THUMB_Y = 0;
	if (CheckHitKey(KEY_INPUT_D)) B++; else B = 0;
	if (CheckHitKey(KEY_INPUT_S)) A++; else A = 0;
	if (CheckHitKey(KEY_INPUT_W)) Y++; else Y = 0;
	if (CheckHitKey(KEY_INPUT_A)) X++; else X = 0;

	if (CheckHitKey(KEY_INPUT_P)) PAUSE++; else PAUSE = 0;
	
}

void PrintInput(int Key[]) {

	DrawFormatString(0, 0, WHITE, "A:%d", A);
	DrawFormatString(0, 40, WHITE, "B:%d", B);
	DrawFormatString(0, 80, WHITE, "X:%d", X);
	DrawFormatString(0, 120, WHITE, "Y:%d", Y);
	DrawFormatString(0, 160, WHITE, "R1:%d", RIGHT);
	DrawFormatString(0, 200, WHITE, "L1:%d", LEFT);
	DrawFormatString(0, 240, WHITE, "R_TRIG:%d", R_TRIG);
	DrawFormatString(0, 280, WHITE, "L_TRIG:%d", L_TRIG);
	DrawFormatString(0, 320, WHITE, "RATIO_X:%d", THUMB_X);
	DrawFormatString(0, 360, WHITE, "RATIO_Y:%d", THUMB_Y);
	DrawFormatString(0, 400, WHITE, "1:%d", Key[10]);
	DrawFormatString(0, 440, WHITE, "2:%d", Key[11]);
	DrawFormatString(0, 480, WHITE, "3:%d", Key[12]);
	DrawFormatString(0, 520, WHITE, "4:%d", Key[13]);
	DrawFormatString(0, 560, WHITE, "5:%d", Key[14]);
	DrawFormatString(0, 600, WHITE, "6:%d", Key[15]);
	DrawFormatString(0, 640, WHITE, "7:%d", Key[16]);
	DrawFormatString(0, 680, WHITE, "8:%d", Key[17]);
	DrawFormatString(0, 720, WHITE, "9:%d", Key[18]);
	DrawFormatString(0, 760, WHITE, "10:%d", Key[19]);

}