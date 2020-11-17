#include "BackGround.h"

BackGround::BackGround()
{
}

BackGround::~BackGround()
{
}

void BackGround::Init(string fileName)
{
    
    back_ground.loadFromFile(fileName);
    setBG.setTexture(back_ground);
    setBG2.setTexture(back_ground);
    setBG2.setPosition(0, -800);
    setBG.setTextureRect(IntRect(0, 634, 800, 800));
    setBG2.setTextureRect(IntRect(0, 634, 800, 800));
    BG_queue.push_back(setBG);
    BG_queue.push_back(setBG);
}

void BackGround::Update(const float& deltaTime)
{
    
    // BG movement
    setBG.move(Vector2f(0.f, 4.f / 4.f));
    setBG2.move(Vector2f(0.f, 4.f / 4.f));
    if (setBG.getPosition().y > 800) {
        setBG.setPosition(0, -798);
    }
    if (setBG2.getPosition().y >= 800) {
        setBG2.setPosition(0, -798);
    }
}

void BackGround::Draw(RenderTarget* Target)
{
    Target->draw(setBG);
    Target->draw(setBG2);
    
}
