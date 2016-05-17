#pragma once
#include "Header.h"
#include "UserHeader.h"
#include "Scene.h"
class Button
{
private:
	Position pos;
	Color color;
	string name;
	Square box[3][10];
	bool select;

	CScene* _scene;
public:
	void Init();
	void Input(int key);
	void Update();
	void Draw();
	
	void Copy(const Button& bt);
	
	void set_select(bool s);

	Button();
	Button(Position p_pos,string p_name, CScene* scene);

	~Button();
};

