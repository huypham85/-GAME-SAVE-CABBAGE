#pragma once
#include<SFML/Graphics.hpp>
#include<sstream>
using namespace std;
using namespace sf;
class GameButton : public sf::Sprite
{
public:
	GameButton();
	~GameButton();
	void SetOnClick(void(*Click)());
	void CatchEvent(float x, float y, float posX, float posY, string buttonName, RenderWindow* window);
	bool IsCatch();
	void Update(const float& deltaTime);
	void Draw(RenderTarget* Target);
private:
	Text buttonText;
	Font font;
	void (*Click)();
	bool isCatch;
	float timerMax;
	float timer;
	bool mouseHeld;
	int dem = 5;
};

