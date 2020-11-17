#pragma once
#include"State_Base.h"
#include"GameButton.h"
#include"Player.h"
#include<fstream>
#include<iostream>
#include<algorithm>
#include<sstream>
class Rank : public State_Base
{
public:
	Rank();
	~Rank();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(const float& deltaTime);
	void Draw(RenderTarget* Target);
private:
	FILE* f;
	Player player;
	float currentTime;
	Sprite sprite;
	Sprite title;
	Texture titleTex;
	Texture texture;
	GameButton* button;
	Texture buttonTex;
	Font font;
	Text ui1Text;
	Text ui2Text;
	Text ui3Text;
	Text ui4Text;
	Text ui5Text;
	Vector2f BackPos;
	unsigned currentPoint;
	unsigned highscore[5];
	Texture rank1Tex;
	Texture rank2Tex;
	Texture rank3Tex;
	Texture rank4Tex;
	Texture rank5Tex;
	Sprite rank1Sprite;
	Sprite rank2Sprite;
	Sprite rank3Sprite;
	Sprite rank4Sprite;
	Sprite rank5Sprite;
};

