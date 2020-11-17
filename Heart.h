#pragma once
#include"Animation.h"
class Heart
{
private:
	RectangleShape heart;
	Sprite heartSprite;
	Animation heartAnim;
	float heartTimer;
	float heartTimerMax;
	static bool hasHeart;
public:
	Heart();
	~Heart();
	void SpawnHeart();
	Sprite getHeart();
	void setHeartTimer(float timer);
	float getHeartTimer();
	void setHasHeart(bool option);
	bool getHasHeart();
	void Update();
	void Draw(RenderTarget* Target);
};

