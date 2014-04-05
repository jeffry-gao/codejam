#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

bool debug=false;

int solve(char* name, int N)
{
	char *p1 = name;
	char *p2 = p1;
	int status=0;
	while(*p1!=0){
		while(*p1!=0&&(*p1=='a'||*p1=='e'||*p1=='i'||*p1=='o'||*p1=='u')){
			p1++;
			p2++;
		}	
		if(*p1==0)break;
		while(*p2!=0&&(*p2!='a'||*p2!='e'||*p2!='i'||*p2!='o'||*p2!='u'))
			p2++;
		if(debug)cout<<"p1:"<<p1-name<<"; p2:"<<p2-name<<endl;
		if(p2-p1>=N){
			if(p1==name){
				for(int i=p2-p1-N+1;i>0;i--){
					status += i;
					if(debug)cout<<"add "<<i<<endl;
				}
			} else {
				status += (p1-name)*(p2-p1-N);
				if(debug)cout<<"add "<<(p1-name)*(p2-p1-N)<<endl;
			}
		}
		if(*p2==0){
			break;
		}else{
			p1=p2;
		}
	}
	return status;
}

void make()
{
	int T;
	cin>>T;
	int c=0;
	while((++c)<=T){
		int N;
		char name[1000000];
		memset(name,0,sizeof(name));
	 	cin>>name>>N;
		int r = solve(name,N);
		cout<<"Case #"<<c<<": "<<r<<endl;
	}
}

int main(int argc, char** args)
{
	if(argc>1)
		debug=true;
    make();
}

