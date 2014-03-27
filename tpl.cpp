#include<iostream>
#include <algorithm>

using namespace std;

bool debug=false;

int solve(string idt,int E,int R, int N, int* Ns)
{
	return 0;
}

void make()
{
	int T;
	cin>>T;
	int c=0;
	while((++c)<=T){
		int E,R, N;
	 	cin>>E>>R>>N;
		int* Ns=new int[N];
		int i=-1;
		while((++i)<N)
			cin>>Ns[i];
		int steps = solve("",E,R,N,Ns);
		cout<<"Case #"<<c<<": "<<steps<<endl;
	}
}

int main(int argc, char** args)
{
	if(argc>1)
		debug=true;
    make();
}

