#include<iostream>
#include <algorithm>

using namespace std;
//Manage your Energy

bool debug=false;

int maxE=0;
int regain=0;

int solve(string idt,int E, int N, int* Ns)
{
	idt += "  ";
	if(debug)
		cout<<idt<<"[in]E:"<<E<<"; N:"<<N<<"; Ns[0]:"<<Ns[0]<<endl;

	int maxGain=0;
	if(N==1)
		return Ns[0]*E;
	else{
		int maxGainIdx=0;
		for(int i=0;i<=E;i++){
		 	int gainNext = solve(idt,min(maxE,E-i+regain),N-1,Ns+1);
			int gainTry = i*Ns[0];
			if(debug)
				cout<<idt<<"Enegy used:"<<i<<"; Gain now:"<<gainTry<<"; Gain next:"<<gainNext<<endl;
			gainTry += gainNext;
			if(gainTry>maxGain){
				maxGain=gainTry;
				maxGainIdx=i;
			}
		}
		
		if(debug)
			cout<<idt<<"[max]Enegy used:"<<maxGainIdx<<"; Gain:"<<maxGain<<endl;
		
	}
	return maxGain;
}

void make()
{
	int T;
	cin>>T;
	int c=0;
	while((++c)<=T){
		int E,R, N;
	 	cin>>E>>R>>N;
		maxE=E;
		regain=R;
		int* Ns=new int[N];
		int i=-1;
		while((++i)<N)
			cin>>Ns[i];
		int gain = solve("",E,N,Ns);
		cout<<"Case #"<<c<<": "<<gain<<endl;
	}
}

int main(int argc, char** args)
{
	if(argc>1)
		debug=true;
    make();
}

