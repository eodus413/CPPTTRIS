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

	// 위 함수들은 순수 가상 함수이므로 상속받는 
	// 클래스에서 재정의 해주어야 함.


};

