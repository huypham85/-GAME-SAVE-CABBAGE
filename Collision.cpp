#include "Collision.h"

Collision::Collision()
{
	timer = 0;
	timerMax = 8;
	
}

Collision::~Collision()
{

}

void Collision::SetCollisionAnim()
{
	collisionAnim = Animation(1, 8, 1.f, "frame");
	collisionAnim.setTexture(collisionSprite);
	collisionShape.setSize((Vector2f)collisionSprite.getTexture()->getSize());
}

float Collision::getTimer()
{
	return timer;
}

void Collision::Update(float x, float y)
{
	collisionAnim.Update();
	collisionAnim.setTexture(collisionSprite);
	collisionSprite.setPosition(x ,y);
	collisionShape.setPosition(x, y);
	timer += 1.f;
}

void Collision::Draw(RenderTarget* Target)
{
	Target->draw(collisionSprite);
}
