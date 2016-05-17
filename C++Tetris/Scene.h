#pragma once

class CScene
{
public:
	CScene() {};
	~CScene() {};

	virtual bool Init() = 0;
	virtual void Release() = 0;
	virtual void Input() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	// �� �Լ����� ���� ���� �Լ��̹Ƿ� ��ӹ޴� 
	// Ŭ�������� ������ ���־�� ��.


};

