#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include <vector>
using namespace std;
using namespace sf;

class Animation
{
private:
	vector<Texture>listTexture;
	float deltaTime;
	float currentFrame = 0;
public:
	Animation() {}
	Animation(int from, int imageCount, float deltaTime, string fileName);
	void Update();
	void setTexture(Sprite& sprite);
};

