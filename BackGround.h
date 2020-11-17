#pragma once
#include"State_Base.h"
#include "Player.h"
#include"Enemy.h"
#include"Animation.h"
#include"Heart.h"
#include"Collision.h"
#include<queue>
#include<vector>
class BackGround
{
private:
	vector<Sprite>BG_queue;
	string BGname;
	Texture back_ground;
	Sprite setBG;
	Sprite setBG2;
	

public:
	BackGround();
	~BackGround();
	void Init(string fileName);
	void Update(const float& deltaTime);
	void Draw(RenderTarget* Target);
};

