#pragma once
#include <string>
#include "Singleton.h"

class ChangeChar:
	public CSingleton< ChangeChar>
{
public:
	ChangeChar()
	{}
	~ChangeChar()
	{
	}
	
};
