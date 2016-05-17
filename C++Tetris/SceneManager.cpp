#pragma once
#include "GameManager.h"
#include "SceneManager.h"
#include "Console.h"
CSceneManager::CSceneManager()
{
	m_CurrentScene = nullptr;
}

CSceneManager::~CSceneManager()
{
	this->Release();
}

bool CSceneManager::ChangeScene(CScene * NewScene)
{
	this->Release();		// 현재의 씬을 해제한다.

	if (NewScene->Init() == false)
	{
		return false;
	}
	m_CurrentScene = NewScene;

	Rect rt = { 0,0,20,20 };
	CNL()->Erase(rt);

	return true;
}
void CSceneManager::Input()
{
	m_CurrentScene->Input();
}

void CSceneManager::Release()
{
	if (m_CurrentScene != nullptr)
	{
		m_CurrentScene->Release();

		delete m_CurrentScene;
		m_CurrentScene = nullptr;
	}
}

void  CSceneManager::Update()
{
	m_CurrentScene->Update();
}

void CSceneManager::Draw()
{
	m_CurrentScene->Draw();
}