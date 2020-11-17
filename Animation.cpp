#include "Animation.h"

Animation::Animation(int from, int imageCount, float deltaTime,string fileName)
{
	for (int i = from; i <= imageCount; i++) {
		Texture textture;
		textture.loadFromFile(fileName + to_string(i) + ".png");	
		listTexture.push_back(textture);
	}
	this->deltaTime = deltaTime;
}

void Animation::Update()
{
	currentFrame += deltaTime;
	if (currentFrame > listTexture.size() - 1)
 		currentFrame = 0;
}

void Animation::setTexture(Sprite& sprite)
{
	sprite.setTexture(listTexture[currentFrame]);
}

