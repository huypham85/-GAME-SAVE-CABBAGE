#pragma once
#include"SFML//Graphics.hpp"
#include"State_Machine.h"
using namespace sf;
class State_Base
{
public:
	State_Base();
	virtual ~State_Base();

	virtual void Exit() = 0;
	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void Init() = 0;
	virtual void Update(const float& deltaTime) = 0;
	virtual void Draw(RenderTarget* Target) = 0;
	static State_Base* CreateState(StateTypes stt);
	static RenderWindow* window;
};

