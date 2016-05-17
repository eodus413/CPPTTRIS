#pragma once
#include "LinkedList.h"
#include "Scene.h"
#include "Screen.h"
#include "Button.h"
class CMain : public CScene
{
private:
	Screen screen;
	Button game_start;
	Button game_end;

	int select_button_number;
public:
	
	CMain();
	~CMain() {};

	virtual bool Init() ;
	virtual void Release();
	virtual void Input();
	virtual void Update();
	virtual void Draw();

	// �� �Լ����� ���� ���� �Լ��̹Ƿ� ��ӹ޴� 
	// Ŭ�������� ������ ���־�� ��.


};

