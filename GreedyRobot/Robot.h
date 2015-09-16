#pragma once
#include<string>
#include<vector>
#include<utility>
using namespace std;

class Robot
{
public:
	Robot();
	Robot(pair<int, int> robotCoordinates, pair<int, int> treasureCoordinates);
	~Robot();

	pair<int, int> getRobotCoordinates() const;
	pair<int, int> getTreasureCoordinates() const;

	void setRobotCoordinates(pair<int, int> robotCoordinates);
	void setTreasureCoordinates(pair<int, int> treasureCoordinates);

	void FindTreasure() const;

private:
	pair<int, int> robotCoordinates, treasureCoordinates;
	
	void FindPaths(const int &x1, const int &y1, const int &x2, const int &y2, vector<string> &pathsVector, int &pathCount, const string &path) const;
	void PrintPaths(const vector<string> &pathsVector, const int &pathCount) const;
};

