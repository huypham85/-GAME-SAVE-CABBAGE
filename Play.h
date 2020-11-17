#pragma once
#include"State_Base.h"
#include "Player.h"
#include"Enemy.h"
#include"Animation.h"
#include"Heart.h"
#include"Collision.h"
#include"Shield.h"
#include<queue>
#include<vector>
#include"BackGround.h"
#include<SFML/Audio.hpp>
class Play : public State_Base
{
public:
	Play();
	~Play();

	void Exit();
	void Pause();
	void Resume();
	void Init();
	void Update(const float& deltaTime);
	void Draw(RenderTarget* Target);
private:
	//trap

	Animation trapAnimation;
	Sprite trapSprite;
	RectangleShape trap;
	Texture trapTex;

	BackGround* background = new BackGround[7];
	int currenIndex ;
	//BackGround* background[6];
	BackGround* currentBackGround;
	Collision* collision;
	bool hasCollision;
	Animation anim;;
	Player* player;
	Enemy* enemy;
	Heart* heart;
	Shield* shield;
	GameButton* button;
	Texture buttonTex;
	Texture scoreBoxTex;
	Sprite scoreBox;
	float TimeLeft;
	Vector2f BackPos;
	//sound
	SoundBuffer hitBuffer;
	Sound hitSound;
	SoundBuffer dingBuffer;
	Sound dingSound;
	SoundBuffer bloodBuffer;
	Sound bloodSound;
	SoundBuffer hurtBuffer;
	Sound hurtSound;
};

