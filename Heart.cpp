#include "Heart.h"

Heart::Heart()
{
	heartTimer = 0;
	heartTimerMax = 1000;
	heartSprite.setScale(2, 2);
}

Heart::~Heart()
{
}

void Heart::SpawnHeart()
{
	hasHeart = true;
	cout << "heart is spawned" << endl;
	heartAnim = Animation(1, 5, 0.2f, "heart");
	heartAnim.setTexture(heartSprite);
	heart.setSize((Vector2f)heartSprite.getTexture()->getSize());
	Vector2f pos;
	pos.x = rand() % (750 - 20 + 1) + 20;
	pos.y = rand() % (750 - 20 + 1) + 20;
	heartSprite.setPosition(pos);
	heart.setPosition(pos);
}

Sprite Heart::getHeart()
{
	return heartSprite;
}

void Heart::setHeartTimer(float timer)
{
	this->heartTimer = timer;
}

float Heart::getHeartTimer()
{
	return heartTimer;
}

void Heart::setHasHeart(bool option)
{
	this->hasHeart = option;
}

bool Heart::getHasHeart()
{
	return this->hasHeart;
}

void Heart::Update()
{
	if (hasHeart == true) {
		heartAnim.Update();
		heartAnim.setTexture(heartSprite);
	}
	if (heartTimer >= heartTimerMax) {
		SpawnHeart();
		heartTimer = 0;
	}
	else this->heartTimer += 1.f;
}

void Heart::Draw(RenderTarget* Target)
{
	Target->draw(heartSprite);
}
