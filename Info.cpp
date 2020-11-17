#include "Info.h"

Info::Info()
{
}

Info::~Info()
{
}

void Info::Exit()
{
}

void Info::Pause()
{
}

void Info::Resume()
{
}

void Info::Init()
{
	animation = Animation(1, 4, 0.08f, "info");
	animation.setTexture(sprite);
	//texture.loadFromFile("info.png");
	//sprite.setTexture(texture);
}

void Info::Update(const float& deltaTime)
{
	animation.Update();
	animation.setTexture(sprite);
	if(Keyboard::isKeyPressed(Keyboard::Space)) State_Machine::GetInstance()->ChangeState(StateTypes::STATE_Intro);
}

void Info::Draw(RenderTarget* Target)
{
	Target->draw(sprite);
}
