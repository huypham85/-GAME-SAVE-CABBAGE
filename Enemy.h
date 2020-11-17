#pragma once
#include"Animation.h"
using namespace std;
class Enemy
{
private:
	RectangleShape enemy;

	Sprite sprite;
	Vector2f size;
	Animation current;
	Vector2f movement;
	float enemyTimer;
	float enemyTimerMax;
	int maxEnemies;
	Vector2f tmp; // enemy's movement
	int choice;
	float currentTime ;
	float scale = 1.5f;
public:
	Enemy();
	~Enemy();
	void Move(Vector2f movement, float Timer, int direct);
	void SpawnEnemy();
	void Update();
	Sprite getEnemy();
	void Draw(RenderTarget* Target);
	
};

