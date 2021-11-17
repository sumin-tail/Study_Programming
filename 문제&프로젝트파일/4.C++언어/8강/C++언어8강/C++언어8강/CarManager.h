#pragma once
#include "Car.h"
#include "List"

#define MAKE 5000
#define SPACEBAR 32

class CarManager
{
	list<Car> carList;
	list<Car>::iterator iter;
   public:
	   void Start();
	   void CarMake();
};

