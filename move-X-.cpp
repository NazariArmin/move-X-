//============================================================================
// Name        : movement.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <vector>
using namespace std;
int x = 1 , y = 1;
vector<int> xPoint;
vector<int> yPoint; //point that print 'o'
int speed = 2;
void savePointOfXY()
{
	bool flag = true;
	for (int i=xPoint.size()-1 ; i>=0; i--)
	{
		if(x == xPoint[i] && y == yPoint[i])
		{
			flag = false;
		}
	}
	if(flag == true)
	{
		xPoint.push_back(x);
		yPoint.push_back(y);
	}
}
void checkBack(bool & xBack , bool & yBack)
{
	if(x == 29)
		xBack = true;
	if(x == 1)
		xBack = false;
	if(y == 59)
		yBack = true;
	if(y == 1)
		yBack = false;

}
void printo(int i , int j , bool& flag)
{
	if(i == x && j == y)
	{
		cout<<"X";
		flag = true;
	}


	for(int k = 0; k <= xPoint.size() ; k++)
	{
		if((i == xPoint[k] && j == yPoint[k])&& ( xPoint[k] != x || yPoint[k] != y ))
		{
				cout << "o";
				flag = true;
		}

	}



}
void print()
{
	usleep(100000 / speed);
	system("clear");

	for(int i = 0 ; i < 60 ; i++)
		cout << "-";
	cout << endl;
	for(int i = 1 ; i<30; i++)
	{
		for(int j = 0 ; j < 61 ; j++)
		{
			bool flag = false;
			printo(i ,j ,flag);

			if(j == 0 || j == 60)
				cout << "|";
			else if(flag== false)
				cout << " ";

		}
		cout << endl;
	}
	for (int i = 0 ; i < 60 ; i++)
		cout << "-";


		cout << endl;
}
int main()
{
	bool xBack = false;
	bool yBack = false;
	xPoint.push_back(-1);
	yPoint.push_back(-1);

	while(true)
	{

		savePointOfXY();

		checkBack(xBack, yBack);
		if(xBack == false)
			x++;
		else
			x--;
		if(yBack == false)
			y++;
		else
			y--;
		print();
	}
}
