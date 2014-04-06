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
	if(debug)cout<<name<<","<<N<<endl;
	char *p1,*p2,*pt;
	p1=name;
	p2=p1+N;
	int s = 0;
	int n = 0;
	while(*p1!=0){
		n=0;
		for(pt=p1;pt<p2;pt++){
			if(!isVow(*pt)){
				if(n==N-1){
					s++;
					break;
				} else {
					n++;
					if(debug)printf("%ld-%ld\n",p1-name,p2-name);
				}
			} else {
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
	char *p3=NULL, *p4=NULL;
    int status=0;
    while(*p1!=0){
		while(*p1!=0&&isVow(*p1))p1++;
		if(debug)cout<<"p1:"<<p1-name<<endl;
		if(*p1==0){
			if(debug)cout<<"break with *p1==0"<<endl;
			break;
		}
		p2=p1;
		while(*p2!=0&&!isVow(*p2))p2++;
		if(debug)cout<<"p2:"<<p2-name<<endl;

		if(!*p2==0){
			p3=p2;
			while(*p3!=0&&isVow(*p3))p3++;
			if(debug)
				cout<<"p3:"<<p3-name<<endl;
			if(*p3==0){
				if(debug)
				cout<<"*p3==0"<<endl;
			}
			p4=p3;
			while(*p4!=0&&!isVow(*p4))
				p4++;
			if(debug)
				cout<<"p4:"<<p4-name<<endl;
			if(p4-p3>N)
				p4=p3+N;	
		}else{
			p4=p2;
		}
		if(debug)cout<<"cal("<<p1-home<<","
							<<p2-home<<","
							<<p4-home<<endl;
		
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
