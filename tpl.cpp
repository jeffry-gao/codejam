#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

bool debug=false;

long solveCase(string idt, int N, int* Ns)
{
	return 0;
}

void solve()
{
	int T;
	cin>>T;
	int c=0;
	while((++c)<=T){
		int N;
	 	cin>>N;
		int* Ns=new int[N];
		int i=-1;
		while((++i)<N)
			cin>>Ns[i];
		long r = solveCase("",N,Ns);
		delete Ns;
		cout<<"Case #"<<c<<": "<<r<<endl;
	}
}

int main(int argc, char** args)
{
	if(argc>1)
		debug=true;
    solve();
}

