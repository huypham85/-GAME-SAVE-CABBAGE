#include "State_Base.h"
#include"Intro.h"
#include"Play.h"
#include"EndGame.h"
#include"Transform_Character.h"
#include"Rank.h"
#include"Info.h"
State_Base* State_Base::CreateState(StateTypes stt)
{
	State_Base* gs = nullptr;
	switch (stt)
	{
	case STATE_INVALID:
		break;
	case STATE_Intro:
		gs = new Intro();
		break;
	case STATE_Menu:
		break;
	case STATE_Play:
		gs = new Play();
		break;
	case STATE_EndGame:
		gs = new EndGame();
		break;
	case STATE_Transform:
		gs = new Transform_Character();
		break;
	case STATE_Rank:
		gs = new Rank();
		break;
	case STATE_Info:
		gs = new Info();
		break;
	default:
		break;
	}
	return gs;
}

State_Base::State_Base()
{
}

State_Base::~State_Base()
{
}

