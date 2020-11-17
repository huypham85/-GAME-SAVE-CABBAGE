#pragma once
#include"State_Base.h"
#include"GameButton.h"
#include "GameConfiger.h"

class Transform_Character : public State_Base
{
public:
	Transform_Character();
	~Transform_Character();

	void Exit();
	void Pause();
	void Resume();
	const int& getCharacter() const ;
	void Init();
	void Update(const float& deltaTime);
	void Draw(RenderTarget* Target);
private:
	static bool isChoosen;
	static char character;
	float currentTime;
	Sprite sprite;
	Texture texture;
	GameButton* button;
	GameButton* button2;
	GameButton* button1;
	GameButton* button3;
	GameButton* button4;
	Texture buttonTex;
	Texture button1Tex;
	Texture button2Tex;
	Texture button3Tex;
	Texture button4Tex;
	Texture frame1Tex;
	Texture frame2Tex;
	Texture frame3Tex;
	Texture frame4Tex;
	Sprite frame1Sprite;
	Sprite frame2Sprite;
	Sprite frame3Sprite;
	Sprite frame4Sprite;
	Vector2f BackPos;
	Vector2f button1Pos;
	Vector2f button2Pos;
	Vector2f button3Pos;
	Vector2f button4Pos;
	Font font;
	Text uiText;
};

