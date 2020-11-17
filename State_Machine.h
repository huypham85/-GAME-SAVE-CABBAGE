#pragma once
#include<list>
#include"Singleton.h"
using namespace std;
class State_Base;

enum  StateTypes
{
	STATE_INVALID = 0,
	STATE_Info,
	STATE_Intro,
	STATE_Menu,
	STATE_Play,
	STATE_EndGame,
	STATE_Transform,
	STATE_Rank,
};
class State_Machine:public CSingleton<State_Machine>
{
public:
	State_Machine();
	~State_Machine();
public:
	void CleanUp();
	void ChangState(State_Base* state);
	void ChangeState(StateTypes stt);
	void PushState(StateTypes stt);
	void PopState();
	inline State_Base* CurrentState()const {
		return ActiveState;
	}
	inline bool NeedToChangeState()const {
		return (NextState!=nullptr);
	}
	inline bool HasState() {
		
		return StackStates.size()>0;
	
	}

	bool isRunning() { return running; }
	void Quit() { running = false; }
	void PerformStateChange();

	inline void setNameChar(char name)
	{
		nameChar = name;
	}
	char getNameChar()
	{
		return nameChar;
	}
	bool isChangedCharacter()
	{
		return isChangedChar;
	}
	void DontChange()
	{
		isChangedChar = false;
	}

private:
	list<State_Base*> StackStates;
	State_Base* ActiveState;
	State_Base* NextState;
	bool running;
	
	bool isChangedChar;
	char nameChar;
};

