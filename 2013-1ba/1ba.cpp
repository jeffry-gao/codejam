#include<iostream>
#include <algorithm>

using namespace std;

bool debug=false;

int solve(string idt,int A, int N, int* Ns)
{
	idt += "  ";
	if(debug){
		cout<<endl;
		cout<<idt<<"[in]A:"<<A<<";N="<<N<<";Ns[0]:"<<Ns[0]<<endl<<idt;
		for(int i=0;i<N;i++)
			cout<<Ns[i]<<" ";
		cout<<endl;
	}

	if(A==1)
		return N;
	int steps=0;
	if(A<=Ns[0]){
		if(1==N){
			steps++;
		}else{
			// compare the step to add or digits to remove
			int sa = 0;
			while(A<=Ns[0]){
				if(debug)
					cout<<idt<<"try to add "<<A-1<<endl;
				A = 2*A -1;
				sa++;
			}	
			if(debug)
				cout<<idt<<"sa:"<<sa<<"; N:"<<N<<endl;
			sa += solve(idt,A, N, Ns);
			steps = min(sa,N);
		}
	} else { 
		if(N>1)
			steps = solve(idt,A+Ns[0],N-1,Ns+1);
	}
	if(debug){
		cout<<idt<<"[out]steps:"<<steps<<endl;
	}
	return steps;
}

void make()
{
	int T;
	cin>>T;
	int c=0;
	while((++c)<=T){
		int A, N;
	 	cin>>A>>N;
		int* Ns=new int[N];
		int i=-1;
		while((++i)<N)
			cin>>Ns[i];
		sort(Ns, Ns+N);
		int steps = solve("",A,N,Ns);
		cout<<"Case #"<<c<<": "<<steps<<endl;
	}
}

int main(int argc, char** args)
{
	if(argc>1)
		debug=true;
    make();
}

