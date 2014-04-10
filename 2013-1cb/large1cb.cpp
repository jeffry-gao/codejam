#include <iostream>
#include <string.h>

using namespace std;

string solve(int X, int Y)
{
	string path;
	int Xabs = X<0?-X:X;
	int Yabs = Y<0?-Y:Y;
	int s = 1;
	while(((s+1)*s)/2<Xabs+Yabs)
		s++;
	int back = ((s+1)*s/2-Xabs-Yabs)/2;
	
}

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
		cout<<"Case #"<<c<<": "
			<<solve(X,Y)<<endl;
	}
}
