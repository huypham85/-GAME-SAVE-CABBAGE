#include "GameButton.h"
#include<iostream>
//using namespace sf;
//using namespace std;

GameButton::GameButton()
{
	Click = nullptr;
	isCatch = false;
	timerMax = 0.5f;
	timer = 0.0f;
	mouseHeld = false;
	this->setPosition(200, 350);
	font.loadFromFile("GameFont.ttf");
	buttonText.setFont(font);
	buttonText.setCharacterSize(30);
	buttonText.setFillColor(Color::Red);
	buttonText.setOutlineThickness(0.1);
	buttonText.setOutlineColor(Color::Red);
	buttonText.setString("NONE");
	buttonText.setPosition(300.f, 740.0f);
}

GameButton::~GameButton()
{
}

void GameButton::SetOnClick(void(*Click)())
{
	this->Click = Click;
}

void GameButton::CatchEvent(float x, float y, float posX, float posY, string buttonName, RenderWindow* window)
{
	isCatch = false;
	sf::FloatRect rectMouse(x, y, 0.0001f, 0.0001f);
	if (this->getGlobalBounds().intersects(rectMouse)) {
		isCatch = true;
		this->setPosition(posX, posY - 10.f);
		stringstream ss;
		ss << buttonName;
		buttonText.setString(ss.str());
	}
	else this->setPosition(posX, posY);
	//std::cout << this->getGlobalBounds().intersects(rectMouse) <<"x: "<<x<<" "<<"y: "<<y << std::endl;
}

bool GameButton::IsCatch()
{
	return isCatch;
}

void GameButton::Update(const float& deltaTime)
{
	timer += deltaTime;
	
	if (timer >= timerMax) {
		//mouseHeld = false;
		timer -= timerMax;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && isCatch) {
		dem--;
		Click();
		mouseHeld = true;
	}
}

void GameButton::Draw(RenderTarget* Target)
{
	if (isCatch == true) Target->draw(buttonText);
}
