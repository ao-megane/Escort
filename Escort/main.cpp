#include "DxLib.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(2160, 1440, 32);
	//SetFontSize(40);
	{
	SetWindowSizeChangeEnableFlag(TRUE);
	SetWindowSizeExtendRate(0.8);
	ChangeWindowMode(TRUE);
	}


	
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	DrawPixel(320, 240, GetColor(255, 255, 255));	// �_��ł�

	WaitKey();				// �L�[���͑҂�

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}


//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow){
//
//	SetGraphMode(2160, 1440, 32);
//	//SetFontSize(40);
//	{
//	SetWindowSizeChangeEnableFlag(TRUE);
//	SetWindowSizeExtendRate(0.8);
//	ChangeWindowMode(TRUE);
//	}
//	DxLib_Init();
//	SetDrawScreen(DX_SCREEN_BACK);
//
//	XINPUT_STATE input;
//
//	int Key[10] = { 0 };
//
//	int flag = 0;
//	int level_flag = 0;
//	int count = 0;
//	int keep_count = 0;
//	InputInitialize();
//	Player.Initialize();
//	Princess.Initialize();
//	EnemyMngInitialize();
//	ChoreInitialize();
//	InputFile("koryosai2017.txt");
//
//	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {
//
//		GetJoypadXInputState(DX_INPUT_PAD1, &input);
//		InputUpdata(input, Key);
//		InputUpdata();
//		switch (flag){
//		case 0://OP
//			DrawOP();
//			if () {
//				if ();
//				level_flag = ;
//			}
//			if () {
//				if ();
//				level_flag = ;
//			}
//			break;
//		case 1://Loading
//			PlayerInitialize(level_flag);
//			PrincessInitialize(level_flag);
//			EnemyMngInitialize(level_flag);
//			ChoreInitialize(level_flag);
//			count = 0;
//			break;
//		case 2://playing
//			PlayerUpdata(count);
//			EnemyMngUpdata(count);
//			PrincessUpdata(count);
//			ChoreUpdata(count);
//
//			if (S_S_IsHit(Get_PriWeek(), Get_EnemyMng_Attack())) {
//
//			}
//			if (make) {
//				Set_ChoreLoser(level_flag,Get_ChoreLoser(level_flag)++);
//				flag = 3;
//			}
//			if (kati) {
//				Set_ChoreWiner(level_flag,Get_ChoreWiner(level_flag)++);
//				flag = 4;
//			}
//
//			DrawBackGround(count);
//			EnemyMngDraw();
//			PrincessDraw();
//			PyaerDraw();
//			break;
//		case 3://gameover
//			PrincessMotion_lose();
//			DrawLoseBord();
//			if () {
//				flag = 0;
//			}
//			break;
//		case 4://gameclear
//			DrawWinBord(level_flag);
//			if () {
//				flag = 0;
//			}
//			break;
//		default:
//			break;
//		}
//
//		count++;
//	}
//
//
//	UpdataFile("koryosai2017.txt");
//	DxLib_End();
//
//	// �\�t�g�̏I��
//	return 0;
//}