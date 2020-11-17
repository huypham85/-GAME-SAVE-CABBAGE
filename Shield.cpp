#include "Shield.h"

Shield::Shield()
{
	shieldTimer = 0;
	shieldTimerMax = 500;
	useTime = 0;
}

Shield::~Shield()
{
}

void Shield::SpawnShield()
{
	shieldTex.loadFromFile("shield.png");
	shieldSprite.setTexture(shieldTex);
	shieldSprite.setScale(0.6f, 0.6f);
	hasShield = true;
	cout << "shield is spawned" << endl;
	Vector2f pos;
	pos.x = rand() % (750 - 20 + 1) + 20;
	pos.y = rand() % (750 - 20 + 1) + 20;
	shieldSprite.setPosition(pos);
	shieldSprite.setPosition(pos);
}

Sprite Shield::getShield()
{
	return shieldSprite;
}

void Shield::setShieldTimer(float timer)
{
	this->shieldTimer = timer;
}

float Shield::getShieldTimer()
{
	return shieldTimer;
}

void Shield::setHasShield(bool option)
{
	this->hasShield = option;
}

bool Shield::getHasShield()
{
	return this->hasShield;
}

float Shield::getUseTime()
{
	return this->useTime;
}

void Shield::setUseTime(float time)
{
	this->useTime = time;
}

bool Shield::getIsUseTime()
{
	return isUseTime;
}

void Shield::setIsUseTime(bool option)
{
	this->isUseTime = option;
}

void Shield::Update()
{
	if (isUseTime == true) {
		useTime += 1.f;
		if (useTime >= 150.f) {
			isUseTime = false;
			useTime = 0;
		}
	}
	if (shieldTimer >= shieldTimerMax) {
		SpawnShield();
		shieldTimer = 0;
	}
	else this->shieldTimer += 1.f;
}

void Shield::Draw(RenderTarget* Target)
{
	Target->draw(shieldSprite);
}
