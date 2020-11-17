#pragma once
#include"State_Base.h"
#include"GameButton.h"
#include"Player.h"
#include<fstream>
#include<iostream>
class EndGame : public State_Base
{
public:
	EndGame();
	~EndGame();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(const float& deltaTime);
	void Draw(RenderTarget* Target);
private:
	Texture deadTex;
	Sprite deadSprite;
	FILE* f;
	Player player;
	static bool isReplay;
	float currentTime;
	Sprite sprite;
	Texture texture;
	GameButton* button;
	GameButton* rankButton;
	Texture rankButtonTex;
	Texture buttonTex;
	Font font;
	Text uiText;
	Vector2f ReplayPos;
	Vector2f rankPos;
	unsigned currentPoint;
	unsigned highscore[5];
};

