#pragma once
#include"State_Base.h"
#include"Animation.h"
class Info : public State_Base
{
public:
	Info();
	~Info();
	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(const float& deltaTime);
	void Draw(RenderTarget* Target);
private:
	Animation animation;
	float currentTime;
	Font font;
	Text uiText;
	Texture texture;
	Sprite sprite;
};

