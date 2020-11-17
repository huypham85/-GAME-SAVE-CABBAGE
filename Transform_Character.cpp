#include "Transform_Character.h"
#include<iostream>
#include<sstream>
Transform_Character::Transform_Character()
{
	currentTime = 0;
	
}

Transform_Character::~Transform_Character()
{
}

void Transform_Character::Exit()
{
}

void Transform_Character::Pause()
{
}

void Transform_Character::Resume()
{
}

const int& Transform_Character::getCharacter() const
{
	return character;
}

void Transform_Character::Init()
{
	printf("state transform is created\n");
	// init UI
	font.loadFromFile("GameFont.ttf");
	uiText.setFont(font);
	uiText.setCharacterSize(60);
	uiText.setFillColor(Color::Red);
	stringstream ss;
	ss << "CHOOSE YOUR HERO" << endl;
	uiText.setString(ss.str());
	uiText.setPosition(120.0f, 50.0f);
	uiText.setOutlineThickness(0.15f);
	uiText.setOutlineColor(Color::Red);

	//init Background
	texture.loadFromFile("Layer2.png");
	sprite.setTexture(texture);
	//sprite.setScale(13.0f, 13.0f);    
	sprite.setTextureRect(IntRect(0, 634, 800, 800));

	button = new GameButton();
	buttonTex.loadFromFile("Back.png");
	button->setTexture(buttonTex);
	button->setPosition(0.0f, 0.0f);
	BackPos = button->getPosition();
	button->setScale(3.0f, 3.0f);
	button->SetOnClick([]() {
		State_Machine::GetInstance()->PopState();
		});

	// init player button
	button1 = new GameButton();
	button1Tex.loadFromFile("player1_1.png");
	button1->setTexture(button1Tex);
	button1->setPosition(80.0f, 300.0f);
	button1Pos = button1->getPosition();
	button1->setScale(3.0f, 3.0f);
	button1->SetOnClick([]() {
		//State_Machine::GetInstance()->PopState();
		character = '1';
		isChoosen = true;
		std::cout << "character: " << character << std::endl;
		});
	button2 = new GameButton();
	button2Tex.loadFromFile("player2_1.png");
	button2->setTexture(button2Tex);
	button2->setPosition(260.0f, 300.0f);
	button2Pos = button2->getPosition();
	button2->setScale(3.0f, 3.0f);
	button2->SetOnClick([]() {
		//State_Machine::GetInstance()->PopState();
		character = '2';
		isChoosen = true;
		std::cout << "character: " << character << std::endl;
		});
	button3 = new GameButton();
	button3Tex.loadFromFile("player3_1.png");
	button3->setTexture(button3Tex);
	button3->setPosition(450.0f, 300.0f);
	button3Pos = button3->getPosition();
	button3->setScale(3.0f, 3.0f);
	button3->SetOnClick([]() {
		//State_Machine::GetInstance()->PopState();
		character = '3';
		isChoosen = true;
		std::cout << "character: " << character << std::endl;
		});
	button4 = new GameButton();
	button4Tex.loadFromFile("player4_1.png");
	button4->setTexture(button4Tex);
	button4->setPosition(620.0f, 300.0f);
	button4Pos = button4->getPosition();
	button4->setScale(3.0f, 3.0f);
	button4->SetOnClick([]() {
		isChoosen = true;
		character = '4';
		});
	
	// init character frame
	frame1Tex.loadFromFile("frame_character.png");
	frame2Tex.loadFromFile("frame_character.png");
	frame3Tex.loadFromFile("frame_character.png");
	frame4Tex.loadFromFile("frame_character.png");
	frame1Sprite.setTexture(frame1Tex);
	frame2Sprite.setTexture(frame2Tex);
	frame3Sprite.setTexture(frame3Tex);
	frame4Sprite.setTexture(frame4Tex);
	frame1Sprite.setScale(0.25f, 0.25f);
	frame2Sprite.setScale(0.25f, 0.25f);
	frame3Sprite.setScale(0.25f, 0.25f);
	frame4Sprite.setScale(0.25f, 0.25f);
	frame1Sprite.setPosition(50, 250);
	frame2Sprite.setPosition(230,250);
	frame3Sprite.setPosition(410,250);
	frame4Sprite.setPosition(580,250);

}

void Transform_Character::Update(const float& deltaTime)
{
	if (isChoosen == true) {
		State_Machine::GetInstance()->setNameChar(character);
		State_Machine::GetInstance()->PopState();
		isChoosen = false;
	}
	//printf("transform is updating\n");
	currentTime += deltaTime;
	button->CatchEvent(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y, BackPos.x, BackPos.y,"Back", window );
	button->Update(deltaTime);
	button1->CatchEvent(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y, button1Pos.x, button1Pos.y, "Pink Man", window);
	button1->Update(deltaTime);
	button2->CatchEvent(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y, button2Pos.x, button2Pos.y, "Virtual Guy", window);
	button2->Update(deltaTime);
	button3->CatchEvent(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y, button3Pos.x, button3Pos.y, "Mask Dude", window);
	button3->Update(deltaTime);
	button4->CatchEvent(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y, button4Pos.x, button4Pos.y, "Ninja Frog", window);
	button4->Update(deltaTime);
}

void Transform_Character::Draw(RenderTarget* Target)
{
	//printf("transform is draw\n");
	Target->draw(sprite);
	Target->draw(*button);
	Target->draw(*button1);
	Target->draw(*button2);
	Target->draw(*button3);
	Target->draw(*button4);
	Target->draw(uiText);
	Target->draw(frame1Sprite);
	Target->draw(frame2Sprite);
	Target->draw(frame3Sprite);
	Target->draw(frame4Sprite);
	button->Draw(Target);
	button1->Draw(Target);
	button2->Draw(Target);
	button3->Draw(Target);
	button4->Draw(Target);

}
char Transform_Character::character = '3';
bool Transform_Character::isChoosen = false;
