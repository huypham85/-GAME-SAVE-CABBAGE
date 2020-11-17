#pragma once
#include<SFML/Graphics.hpp>
#include"Animation.h"
using namespace sf;
class Collision
{
private:
	RectangleShape collisionShape;
	Animation collisionAnim;
	Sprite collisionSprite;
	float timer;
	float timerMax;
public:
	Collision();
	~Collision();
	void SetCollisionAnim();
	float getTimer();
	void Update(float x, float y);
	void Draw(RenderTarget* Target);
};

