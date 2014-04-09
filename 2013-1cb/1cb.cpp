#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char** args)
{
	int T;
	cin>>T;
	int c=0;
	while((++c)<=T){
		int X,Y;
	 	cin>>X>>Y;
		string stepX = X>0?"WE":"EW";
		string stepY = Y>0?"SN":"NS";
		string path;
		if(X<0)X=-X;
		if(Y<0)Y=-Y;
		while(X-->0)path += stepX;
		while(Y-->0)path += stepY;
		cout<<"Case #"<<c<<": "<<path<<endl;
	}
}
