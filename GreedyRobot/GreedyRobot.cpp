// GreedyRobot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Robot.h"
#include <iostream>
#include <utility>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{	
	while (true)
	{
		pair<int, int> robotCoordinates, treasureCoordinates;
		
		cout << "x1 y1 x2 y2: ";
		cin >> robotCoordinates.first >> robotCoordinates.second >> treasureCoordinates.first >> treasureCoordinates.second;
		cout << endl;

		Robot r1(robotCoordinates, treasureCoordinates);

		pair<int, int> testGetRobotCoords(r1.getRobotCoordinates());
		pair<int, int> testGetTreasureCoords(r1.getTreasureCoordinates());

		cout << "robot coordinates: \t(" << testGetRobotCoords.first << ", " << testGetRobotCoords.second << ")" << endl;
		cout << "treasure coordinates: \t(" << testGetTreasureCoords.first << ", " << testGetTreasureCoords.second << ")" << endl << endl;

		r1.FindTreasure();		
	}
	
	return 0;
}





