#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

bool debug=false;

void u2(){
	char s[]="abcd";
	int   l=strlen(s);
	
	vector<string> sl,temp;
	string tt;
	tt += (s[0]);
	sl.push_back(tt);
    for(int i=1;i<l;i++){
		cout<<sl.size()<<endl;
		temp=sl;
		sl.clear();
		for(int j=0;j<temp.size();j++){
			for(int k=0;k<temp[j].size();k++){
				tt=temp[j];
				sl.push_back(tt.insert(k,1,s[i]));
			}
			sl.push_back(temp[j]+s[i]);
		}
	}
	for(int i=0;i<sl.size();i++)
		cout<<"["<<i<<"]"<<sl[i]<<endl;
}

void u1(){
	char s[]="abcd";
	int   l=strlen(s);
    for(int i=0;i<1<<l;i++){
		cout<<i<<":";
		for(int j=0;j<l;j++){
			if(i&(1<<j))
				cout<<s[j];
		}
		cout<<endl;
	}
}

int solve(string idt,int N, int* Ns)
{
	if(N==0)
		return 0;
	else if(N==1){
		return Ns[0];
	}else{
		return Ns[0]+solve(idt,N-1,Ns+1);
	}
	return 0;
}

void make()
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
		int r = solve("",N,Ns);
		delete Ns;
		cout<<"Case #"<<c<<": "<<r<<endl;
	}
}

int main(int argc, char** args)
{
	if(argc>1)
		debug=true;
//    make();
	u2();
}

