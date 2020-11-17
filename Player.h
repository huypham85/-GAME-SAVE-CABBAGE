#pragma once
#include"Animation.h"
#include"GameButton.h"
#include"Transform_Character.h"
#include<sstream>
using namespace std;
class Player
{
private:
	CircleShape circle;
	Transform_Character skin;
	string fileName;
	string deadFileName;
	RectangleShape body;
	RectangleShape boxShape;
	Sprite sprite;
	Vector2f size;
	Animation current;
	Animation boxAnim;
	Vector2f movement;
	Vector2f collisionMovement;
	bool isCollision;
	unsigned hp;
	unsigned hpMax;
	static unsigned point;
	float gravity = 9.8f;
	float TimeLeft = 0.f;
	bool faceRight = true;
	void applyGravity();
	Sprite box;
	Texture boxTex;
	bool pressable;
	RectangleShape HpBar;
	Texture hpBoxTex;
	Sprite hpBox;
	Font font;
	Text uiPointText;

	bool isEndGame;
public:
	Player();
	void Init();
	void initBox();
	Sprite getBox();
	Sprite getPlayer();
	const int& getHp() const;
	const int& getHpMax() const;
	const sf::FloatRect getBounds() const;
	float getHpSize();
	bool getPressable();
	void setPoint(unsigned point);
	unsigned getPoints();
	void SetHp(const int hp);
	void LoseHp(const int value);
	void GainHp(const int value);
	void Flip();
	void Move(Vector2f movement);
	void UpdateBox();
	void Update(RenderTarget* Target);
	void UpdateWindowCollision(RenderTarget * Target, Vector2f opposite);
	void UpdateGUI();
	void DeadAnim();
	void Draw(RenderTarget* Target);
	
};

