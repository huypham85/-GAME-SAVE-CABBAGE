#include "Intro.h"
#include<sstream>
using namespace std;
Intro::Intro()
{
	currentTime = 0;
}

Intro::~Intro()
{
}

void Intro::Exit()
{
}

void Intro::Pause()
{
}

void Intro::Resume()
{
}

void Intro::Init()
{
	animation = Animation(1, 5, 0.15f, "intro_anim");
	animation.setTexture(animSprite);
	animSprite.setScale(3, 3);
	animSprite.setPosition(350, 200);
	titleTex.loadFromFile("title_intro.png");
	titleSprite.setTexture(titleTex);	
	titleSprite.setPosition(110, 70);
	titleSprite.setScale(0.15, 0.15);
	//init Background
	texture.loadFromFile("Layer6.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 634, 800, 800));
	//sprite.setScale(13.0f, 13.0f);

	// init Button
	button = new GameButton();
	//printf("state Intro is created\n");
	buttonTex.loadFromFile("PlayBtn.png");
	button->setTexture(buttonTex);
	button->setPosition(330.0f, 350.0f);
	PlayPos = button->getPosition();
	button->setScale(0.1, 0.1);
	button->SetOnClick([]() {
		State_Machine::GetInstance()->ChangeState(StateTypes::STATE_Play);
		});

	// init Trans_Button
	transButton = new GameButton();
	transButtonTex.loadFromFile("menuBtn.png");
	transButton->setTexture(transButtonTex);
	transButton->setPosition(330.0f, 530.0f);
	TransPos = transButton->getPosition();
	transButton->setScale(0.6, 0.6);
	transButton->SetOnClick([]() {
		State_Machine::GetInstance()->ChangeState(StateTypes::STATE_Transform);
		});
}

void Intro::Update(const float& deltaTime)
{
	animation.Update();
	animation.setTexture(animSprite);
	currentTime += deltaTime;
	button->CatchEvent(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y,PlayPos.x, PlayPos.y, "Play", window);
	button->Update(deltaTime);

	transButton->CatchEvent(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y,TransPos.x, TransPos.y, "Character", window);
	transButton->Update(deltaTime);
}

void Intro::Draw(RenderTarget* Target)
{
	Target->draw(sprite);
	Target->draw(*button);
	//Target->draw(uiText);
	Target->draw(titleSprite);
	Target->draw(*transButton);
	button->Draw(Target);
	transButton->Draw(Target);
	Target->draw(animSprite);
	
}