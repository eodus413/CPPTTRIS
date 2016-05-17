#pragma once
#include "Singleton.h"
#include"Scene.h"



class CSceneManager :public Singleton<CSceneManager>
{
private:
	CScene* m_CurrentScene;		// ÇöÀçÀÇ ¾À
public:
	CSceneManager();
	~CSceneManager();

	bool ChangeScene(CScene* NewScene);
	virtual void Input();
	virtual void Release();
	virtual void Update();
	virtual void Draw();


};

#define SceneManager() Singleton<CSceneManager>::InstancePtr()
