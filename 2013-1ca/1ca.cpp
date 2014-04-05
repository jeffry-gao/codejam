#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

bool debug=false;

bool isVow(char c){
	return c=='a'||c=='o'||c=='e'||c=='i'||
			c=='u';
}

int solveSmall(char* name, int N)
{
	char *p1,*p2,*pt;
	p1=name;
	p2=p1+N;
	int s = 0;
	int n = 0;
	while(*p1!=0){
		for(pt=p1;pt<p2;pt++){
			if(isVow(*pt)){
				if(n==N-1){
					s++;
					break;
				} else {
					if(debug)cout<<"+1"<<endl;
					n++;
				}
			} else {
					if(debug)cout<<"0"<<endl;
				n=0;
			}
		}
		if(*p2==0){
			p1++;
			p2=p1+N;
			if(*(p2-1)==0)
				break;
		}else{
			p2++;
		}
	}
	return s;
}

int solve(char* name, int N)
{
	cout<<name<<","<<N<<endl;
    char *p1 = name;
    char *p2 = p1;
    int status=0;
    while(*p1!=0){
		while(*p1!=0&&isVow(*p1))p1++;
		if(*p1==0)return status;
		if(debug)cout<<"p1:"<<p1-name<<endl;
		p2=p1;
		while(*p2!=0&&!isVow(*p2))p2++;
		if(debug)cout<<"p2:"<<p2-name<<endl;
		status += (p1-name)*(p2-p1-N+1);
		for(int i=p2-p1-N+1;i>0;i--)
			status += i;
		if(*p2==0)break;
		else p1=p2;
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
        int r = solveSmall(name,N);
        cout<<"Case #"<<c<<": "<<r<<endl;
    }
}

int main(int argc, char** args)
{
    if(argc>1)
        debug=true;
    make();
}

