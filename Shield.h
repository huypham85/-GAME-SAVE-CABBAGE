#pragma once
#include "Animation.h"
class Shield
{
private:
	RectangleShape heart;
	Texture shieldTex;
	Sprite shieldSprite;
	//Animation heartAnim;
	float shieldTimer;
	float shieldTimerMax;
	static bool hasShield;
	float useTime;
	static bool isUseTime;
public:
	Shield ();
	~Shield();
	void SpawnShield();
	Sprite getShield();
	void setShieldTimer(float timer);
	float getShieldTimer();
	void setHasShield(bool option);
	bool getHasShield();
	float getUseTime();
	void setUseTime(float time);
	bool getIsUseTime();
	void setIsUseTime(bool option);

	void Update();
	void Draw(RenderTarget* Target);
};

