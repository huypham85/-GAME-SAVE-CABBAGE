#include "State_Machine.h"
#include"State_Base.h"

RenderWindow* State_Base::window = nullptr;
State_Machine::State_Machine()
{
	isChangedChar = false;
	nameChar = '1';
}

State_Machine::~State_Machine()
{
}

void State_Machine::CleanUp()
{
	while (!StackStates.empty()) {
		StackStates.back()->Exit();
		StackStates.pop_back();
	}
}

void State_Machine::ChangState(State_Base* state)
{
	NextState = state;
}

void State_Machine::ChangeState(StateTypes stt)
{
	State_Base* gs = State_Base::CreateState(stt);
	NextState = gs;
}

void State_Machine::PushState(StateTypes stt)
{
	State_Base* state = State_Base::CreateState(stt);
	if (!StackStates.empty()) {
		StackStates.back()->Pause();
	}

	NextState = state;
}

void State_Machine::PopState()
{
	if (!StackStates.empty()) {
		StackStates.back()->Exit();
		StackStates.pop_back();
		
	}
	if (!StackStates.empty()) {
		StackStates.back()->Resume();

	}
	ActiveState = StackStates.back();
}

void State_Machine::PerformStateChange()
{
	if (NextState != nullptr) {
		if (!StackStates.empty()) {
			StackStates.back()->Exit();
		}
		StackStates.push_back(NextState);
		StackStates.back()->Init();
		ActiveState = NextState;
	}
	NextState = nullptr;

}
