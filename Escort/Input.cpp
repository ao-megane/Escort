#include"DxLib.h"
#include"Value.h"
//#include"math.h"

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
	if (CheckHitKey(KEY_INPUT_D)) B++; else B = 0;


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

}