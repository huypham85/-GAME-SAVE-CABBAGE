#include "Enemy.h"

Enemy::Enemy()
{
	current = Animation(1, 8, 1.0f, "enemy_0");
	current.setTexture(sprite);
	enemy.setSize((Vector2f)sprite.getTexture()->getSize());
	enemyTimer = 0;
	enemyTimerMax = 80;
	maxEnemies = 10000;
	currentTime = 0;
}

Enemy::~Enemy()
{
}

void Enemy::Move(Vector2f movement, float Timer, int direct)
{
	if (Timer > 0 ) {
		if (direct == 3) {
			currentTime += 1.f / 100.f;
			//printf("%f\n", currentTime);
			Vector2f v(800.f, 800.f * cos(10.f * currentTime) + 10.f);
			tmp.x = tmp.y = 0;
			tmp.x = v.x;
			tmp.y = v.y;
			//printf("%f %f\n", enemy.getPosition().x, enemy.getPosition().y);
			sprite.move(tmp * 1.f / 50.f);
			enemy.setPosition(sprite.getPosition());
		}
		if (direct == 4) {
			currentTime += 1.f / 100.f;
			//printf("%f\n", currentTime);
			Vector2f v(-800.f, 800.f * sin(10.f * currentTime) + 10.f);
			tmp.x = tmp.y = 0;
			tmp.x = v.x;
			tmp.y = v.y;
			//printf("%f %f\n", enemy.getPosition().x, enemy.getPosition().y);
			sprite.move(tmp * 1.f / 50.f);
			enemy.setPosition(sprite.getPosition());
		}
		if (direct != 3 && direct !=4) {
			//tmp = tmp * scale;
			sprite.move(tmp);
			enemy.setPosition(sprite.getPosition());
		}
	}
	else {
		currentTime = 0;
		int minn = 10;
		int maxx = 20;
		if (direct == 0) {
			tmp.x = tmp.y = 0;
			tmp.x = rand() % maxx - minn;
			tmp.y = rand() % (maxx-minn+1)+minn;
			//sprite.move(tmp);
			
		}
		if (direct == 1) {
			tmp.x = tmp.y = 0;
			tmp.x = rand() % (maxx - minn + 1) + minn;
			tmp.y = rand() % maxx - minn;
			//sprite.move(tmp);
			//enemy.setPosition(sprite.getPosition());
		}
		if (direct == 2) {
			tmp.x = tmp.y = 0;
			tmp.x = rand() % 40 - 40;
			tmp.y = rand() % maxx - minn;
			//sprite.move(tmp);
			//enemy.setPosition(sprite.getPosition());
		}
		/*if (direct == 3) {
			printf("%f\n", currentTime);
			Vector2f v(100.f, 1000.f * cos(10.f * currentTime) + 10.f);
			tmp.x = tmp.y = 0;
			tmp.x = v.x;
			tmp.y = v.y;
			/*tmp.x = rand() % (maxx - minn + 1) + minn;
			tmp.y = rand() % maxx - minn;*/

			//sprite.move(tmp);
			//enemy.setPosition(sprite.getPosition());
		//}
		
		//if (direct == 3) tmp = tmp / 100.f;
		if (direct != 3 && direct != 4) {
			tmp = tmp * scale;
			sprite.move(tmp);
			enemy.setPosition(sprite.getPosition());
		}
		
	}
}

void Enemy::SpawnEnemy()
{
	int enemy_skin = rand() % 4;
	if (enemy_skin == 0) {
		current = Animation(1, 8, 1.0f, "enemy_0");
		current.setTexture(sprite);
		enemy.setSize((Vector2f)sprite.getTexture()->getSize());
	}
	else if (enemy_skin == 1) {
		current = Animation(1, 4, 1.0f, "enemy1_0");
		current.setTexture(sprite);
		enemy.setSize((Vector2f)sprite.getTexture()->getSize());
	}
	else if (enemy_skin == 2) {
		current = Animation(1, 4, 1.0f, "enemy2_0");
		current.setTexture(sprite);
		enemy.setSize((Vector2f)sprite.getTexture()->getSize());
	}
	else if (enemy_skin == 3) {
		current = Animation(1, 4, 1.0f, "enemy3_0");
		current.setTexture(sprite);
		enemy.setSize((Vector2f)sprite.getTexture()->getSize());
	}
	Vector2f pos;
	choice = rand() % 5;
	if (choice == 0) {
		// bay tu tren xuong
		pos.x = rand() % 799;
		pos.y = 0;
	}
	else if(choice==1)
	{
		// bay tu trai qua
		pos.x = 0;
		pos.y = rand() % 500;
	}
	else if(choice == 2)
	{
		// bay tu phai qua
		pos.x = 799;
		pos.y = rand() % 500;
	}
	else if (choice == 3)
	{
		printf("cos is created\n");
		currentTime = 0;
		// bay tu trai qua theo duong hinh sin
		pos.x = 0;
		pos.y = rand() % 500;
	}
	else if (choice == 4)
	{
		printf("sin is created\n");
		currentTime = 0;
		// bay tu phai qua theo hinh sin
		pos.x = 799;
		pos.y = rand() % 400;
	}
	sprite.setPosition(pos);
	enemy.setPosition(pos);
}



void Enemy::Update()
{
	currentTime += 1 / 100;
	current.Update();
	current.setTexture(sprite);
		if (enemyTimer >= enemyTimerMax) {
			SpawnEnemy();
			enemyTimer = 0;
		}
		else this->enemyTimer += 1.f;
	Move(this->movement, enemyTimer, choice);
}

Sprite Enemy::getEnemy()
{
	return sprite;
}

void Enemy::Draw(RenderTarget* Target)
{
	Target->draw(sprite);
}