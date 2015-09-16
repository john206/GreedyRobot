#include "stdafx.h"
#include "Robot.h"
#include <iostream>
using namespace std;

Robot::Robot()
{
	robotCoordinates.first, robotCoordinates.second, treasureCoordinates.first, treasureCoordinates.second = 0;
}

Robot::Robot(pair<int, int> robotCoordinates, pair<int, int> treasureCoordinates)
{
	this->robotCoordinates.first = robotCoordinates.first;
	this->robotCoordinates.second = robotCoordinates.second;
	this->treasureCoordinates.first = treasureCoordinates.first;
	this->treasureCoordinates.second = treasureCoordinates.second;
}

Robot::~Robot()
{
}

pair<int, int> Robot::getRobotCoordinates() const
{
	return robotCoordinates;
}

pair<int, int> Robot::getTreasureCoordinates() const
{
	return treasureCoordinates;
}

void Robot::setRobotCoordinates(pair<int, int> robotCoordinates)
{
	this->robotCoordinates.first = robotCoordinates.first;
	this->robotCoordinates.second = robotCoordinates.second;
}

void Robot::setTreasureCoordinates(pair<int, int> treasureCoordinates)
{
	this->treasureCoordinates.first = treasureCoordinates.first;
	this->treasureCoordinates.second = treasureCoordinates.second;
}

void Robot::FindTreasure() const
{
	vector<string> pathsVector;
	int pathCount = 0;
	string path = "";
	
	FindPaths(robotCoordinates.first, robotCoordinates.second, treasureCoordinates.first, treasureCoordinates.second, pathsVector, pathCount, path);
	PrintPaths(pathsVector, pathCount);
}

void Robot::FindPaths(const int &x1, const int &y1, const int &x2, const int &y2, vector<string> &pathsVector, int &pathCount, const string &path) const
{
	if (x1 == x2 && y1 == y2) //Base Case
	{
		pathsVector.push_back(path);
		pathCount++;
	}

	if (y1 < y2) //Move North
	{
		FindPaths(x1, y1 + 1, x2, y2, pathsVector, pathCount, path + "N");
	}

	if (y1 > y2) //Move South
	{
		FindPaths(x1, y1 - 1, x2, y2, pathsVector, pathCount, path + "S");
	}

	if (x1 < x2) //Move East
	{
		FindPaths(x1 + 1, y1, x2, y2, pathsVector, pathCount, path + "E");
	}

	if (x1 > x2) //Move West
	{
		FindPaths(x1 - 1, y1, x2, y2, pathsVector, pathCount, path + "W");
	}
}

void Robot::PrintPaths(const vector<string> &pathsVector, const int &pathCount) const
{
	if (pathsVector[0] == "")
	{
		cout << "nowhere to go" << endl << endl;
		return;
	}
	
	cout << "number of paths: " << pathCount << endl << endl;

	int vectorSize = pathsVector.size();
	for (int i = 0; i < vectorSize; i++)
	{
		cout << pathsVector[i] << endl;
	}
	cout << endl;
}

