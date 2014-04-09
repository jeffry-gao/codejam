#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

string solveCase(string idt, int X, int Y)
{
	string stepX = X>0?"WE":"EW";
	string stepY = Y>0?"SN":"NS";
	string path;
	X = abs(X);
	Y = abs(Y);
	while(X-->0)path += stepX;
	while(Y-->0)path += stepY;

	return path;
}

void solve()
{
	int T;
	cin>>T;
	int c=0;
	while((++c)<=T){
		int X,Y;
	 	cin>>X>>Y;
		string r = solveCase("",X,Y);
		cout<<"Case #"<<c<<": "<<r<<endl;
	}
}

int main(int argc, char** args)
{
    solve();
}

