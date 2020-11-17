#include "Player.h"
#include "GameConfiger.h"

void Player::applyGravity()
{
	movement.y += gravity * 1 / 20;
}

Player::Player()
{
	//shield

	// init UI
	cout << "---Player is created\n";
	this->hpMax = 10;
	this->hp = this->hpMax;
	hpBoxTex.loadFromFile("heartbox.png");
	hpBox.setTexture(hpBoxTex);
	hpBox.setScale(0.4, 0.4);
	hpBox.setPosition(5, 730);
	HpBar.setSize(Vector2f(180.0f, 30.0f));
	HpBar.setFillColor(Color::Red);
	HpBar.setPosition(Vector2f(74.0f, 745.0f));
	font.loadFromFile("yoshi.ttf");
	uiPointText.setFont(font);
	uiPointText.setCharacterSize(30);
	uiPointText.setFillColor(Color::Red);
	uiPointText.setString("NONE");
	uiPointText.setPosition(690.0f, 740.0f);

	//animation
	fileName = "player";
	fileName += State_Machine::GetInstance()->getNameChar();
	fileName += '_';
	//cout << tmp << endl;
	current = Animation(1, 12, 0.5f, fileName);
	current.setTexture(sprite);


	//player
	body.setSize((Vector2f)sprite.getTexture()->getSize());
	sprite.setScale(Vector2f(2.0f, 2.0f));
	sprite.setPosition(200, 200);
	pressable = true;
	movement.x = movement.y = 0;
	isEndGame = false;
	isCollision = false;
}

void Player::Init()
{
	fileName = "player";
	fileName += State_Machine::GetInstance()->getNameChar();
	fileName += '_';
	//cout << tmp << endl;
	current = Animation(1, 12, 0.5f, fileName);
	current.setTexture(sprite);
	
	//player
	body.setSize((Vector2f)sprite.getTexture()->getSize());
	sprite.setScale(Vector2f(2.0f, 2.0f));
	//sprite.setOrigin((Vector2f)sprite.getTexture()->getSize() * 0.5f);
	sprite.setPosition(200, 200);
	pressable = true;
	movement.x = movement.y = 0;
	isEndGame = false;
}

void Player::initBox()
{
	boxAnim = Animation(1, 4, 0.2f, "cabbage");
	boxAnim.setTexture(box);
	boxShape.setSize((Vector2f)box.getTexture()->getSize());
	//tmp.loadFromFile("box.png");
	//box.setTexture(tmp);
	//box.setScale(0.9f, 0.9f);
	Vector2f getPos;
	getPos = sprite.getPosition();
	getPos.y += 33;
	getPos.x -= 8;
	box.setPosition(getPos);
	boxShape.setPosition(getPos);
}

Sprite Player::getBox()
{
	return box;
}

Sprite Player::getPlayer()
{
	return sprite;
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}

const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

float Player::getHpSize()
{
	return HpBar.getSize().x;
}

bool Player::getPressable()
{
	return pressable;
}

void Player::setPoint(unsigned point)
{
	this->point = point;
}

unsigned Player::getPoints()
{
	return this->point;
}

void Player::SetHp(const int hp)
{
	this->hp = hp;
}

void Player::LoseHp(const int value)
{
	if (this->hp < value) this->hp = 0;
	else this->hp -= value;
}

void Player::GainHp(const int value)
{
	if (this->hp <= 5) {
		this->hp += value;
	}
	else this->hp += (10 - this->hp);
}

void Player::Flip()
{
	Vector2f scale=sprite.getScale();
	Vector2f boxScale = box.getScale();
	boxScale.x *= -1;
	scale.x *= -1;
	faceRight = !faceRight;
	sprite.setScale(scale);
	//box.setScale(boxScale);
}

void Player::Move(Vector2f movement)
{
	sprite.move(movement);
	body.setPosition(sprite.getPosition());
}

void Player::UpdateBox()
{
	Vector2f getPos;
	getPos = sprite.getPosition();
	getPos.y += 33;
	getPos.x -= 8;
	box.setPosition(getPos);
	boxShape.setPosition(getPos);
}

void Player::UpdateWindowCollision(RenderTarget *Target, Vector2f opposite)
{
	// window collision
	//left
	if (this->getBounds().left < 0.f  && isCollision == false) {
		//cout << this->getBounds().left << endl;
		movement.x = - opposite.x;
		movement.y =  opposite.y;
		isCollision = true;
		//printf("%f %f\n", movement.x, movement.y);
	}
	//right
	else if ((this->getBounds().left + this->getBounds().width >= Target->getSize().x)&&isCollision==false) {
		// cout << player.getBounds().left << endl;
		movement.x = -opposite.x;
		movement.y = opposite.y;
		isCollision = true;
	//	printf("%f %f\n", opposite.x, opposite.y);
	}
	//top
	if (this->getBounds().top < 0.f && isCollision==false) {
		//cout << player.getBounds().top << endl; 
		movement.x = opposite.x;
		movement.y = -opposite.y;
		isCollision = true;
		//printf("%f %f\n", opposite.x, opposite.y);

	}

	//bottom
	else if (this->getBounds().top + this->getBounds().height >= Target->getSize().x) {
		//cout << player.getBounds().left << endl;
		//this->DeadAnim();
		pressable = false;
		if (pressable == false) TimeLeft += 1.f/100.f;
		if (TimeLeft >= 1.f) State_Machine::GetInstance()->ChangeState(StateTypes::STATE_EndGame);
	}
	if (isCollision == true) {
		//printf("is moving\n");
		Move(this->movement);
		isCollision = false;
	}
	//movement.x = 0;
}

void Player::Update(RenderTarget* Target)
{
	if(pressable==true) point += 1;
	stringstream ss;
	ss << this->point;
	uiPointText.setString(ss.str());

	//update movementx
	applyGravity();
	
	current.Update();
	current.setTexture(sprite);
	boxAnim.Update();
	//printf("%f %f\n", box.getPosition().x, box.getPosition().y);
	boxAnim.setTexture(box);
	if (pressable == true) {
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			this->movement.y = -5;
		}
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			this->movement.x = -10;
			if (faceRight) Flip();
		}
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			this->movement.x = 10;
			if (!faceRight) Flip();
		}
	}
	UpdateWindowCollision(Target, movement);
	UpdateBox();
	Move(this->movement);
	movement.x = 0;
}



void Player::UpdateGUI()
{
	float hpPercent = ((float)hp) / ((float)hpMax);
	HpBar.setSize(Vector2f(180.0f * hpPercent, HpBar.getSize().y));
}

void Player::DeadAnim()
{
	pressable = false;
	deadFileName = "fall";
	deadFileName += State_Machine::GetInstance()->getNameChar();
	deadFileName += '_';
	current= Animation(1, 6, 0.3f, deadFileName);
	current.setTexture(sprite);
	//cout << pressable << endl;
}

void Player::Draw(RenderTarget* Target)
{
	Target->draw(box);
	Target->draw(sprite);
	Target->draw(uiPointText);
	Target->draw(hpBox);
	Target->draw(HpBar);
}

