#pragma once
#include "Card.h"
#include "string"
#include <iostream>
using namespace std;
class IFormattable {
public:
	string Format();
	virtual void Prettyprint() = 0;
};