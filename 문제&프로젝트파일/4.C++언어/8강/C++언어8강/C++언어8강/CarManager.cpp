#include "CarManager.h"

void CarManager::CarMake()
{
	Car add;
	carList.push_back(add);
}

void CarManager::Start()
{
	int CurClock;
	int MakeClock;
	MakeClock = clock();
	CarMake();

	while (1)
	{
		CurClock = clock();
		if (CurClock - MakeClock >= MAKE)
		{
			CarMake();
			MakeClock = CurClock;
		}

		for (iter = carList.begin(); iter != carList.end(); iter++)
		{
			iter->Drive();

			if (iter->EndCheck())
			{
				carList.erase(iter);
				break;
			}

		}

		//Ű���� �Է��� ���Դٸ�
		if (_kbhit())
		{
			if (SPACEBAR == _getch())
			{
				for (iter = carList.begin(); iter != carList.end(); iter++)
				{
					iter->Boster();
				}
			}
		}
	}
}