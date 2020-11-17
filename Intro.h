#pragma once
#include"State_Base.h"
#include"GameButton.h"
#include"Animation.h"
class Intro: public State_Base
{
public:
	Intro();
	~Intro();

	void Exit() ;
	void Pause() ;
	void Resume() ;

	void Init() ;
	void Update(const float& deltaTime) ;
	void Draw(RenderTarget* Target) ;
private:
	
	Animation animation;
	Sprite animSprite;
	float currentTime;
	Sprite sprite;
	Sprite titleSprite;
	Texture titleTex;
	Texture texture;
	GameButton* button;
	GameButton* transButton;
	Texture transButtonTex;
	Texture buttonTex;
	Font font;
	Text uiText;
	Vector2f PlayPos;
	Vector2f TransPos;
};

