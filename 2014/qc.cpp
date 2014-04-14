#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

bool debug=false;

char mine[50][50];
int  mining[50][50];

void print(int R, int C){
	for(int j=0;j<R;j++){
		for(int k=0;k<C;k++){
			cout<<mine[j][k];
		}
		cout<<endl;
	}
	cout<<endl;
}

bool isSolvable(int R, int C, int M){
	if(debug)cout<<"checking"<<endl;
	memset(mining,-1,sizeof(mining));
	for(int i=0;i<R;i++){
		for( int j=0;j<C;j++){
			if(mine[i][j]!='*'&&
				(i==0||mine[i-1][j]!='*')&&
				(i==R-1||mine[i+1][j]!='*')&&
				(j==0||mine[i][j-1]!='*')&&
				(j==C-1||mine[i][j+1]!='*')&&
				(i==0&&j==0||mine[i-1][j-1]!='*')&&
				(i==0&&j==C-1||mine[i-1][j+1]!='*')&&
				(i==R-1&&j==0||mine[i+1][j-1]!='*')&&
				(i==R-1&&j==C-1||mine[i+1][j+1]!='*'))
			mining[i][j]=0;
		}
	}
	if(debug&&false){
		cout<<"mining:"<<endl;
		for(int i=0;i<R;i++){
			for( int j=0;j<C;j++)
				cout<<mining[i][j]<<" ";
			cout<<endl;
		}
	}

	for(int i=0;i<R;i++){
		for( int j=0;j<C;j++){
			if(mining[i][j]==0){
				if(i>0){
					mining[i-1][j]=0;
					if(j>0){
						mining[i-1][j-1]=0;
						mining[i][j-1]=0;
					}
					if(j<C-1){
						mining[i-1][j+1]=0;
						mining[i][j+1]=0;
					}
				}else if(i<R-1){
					mining[i+1][j]=0;
					if(j>0){
						mining[i+1][j-1]=0;
						mining[i][j-1]=0;
					}
					if(j<C-1){
						mining[i+1][j+1]=0;
						mining[i][j+1]=0;
					}
				}
			}
		}
	}
	if(debug&&false){
		cout<<"mining:"<<endl;
		for(int i=0;i<R;i++){
			for( int j=0;j<C;j++)
				cout<<mining[i][j]<<" ";
			cout<<endl;
		}
	}
	int countOpen=0;
	for(int i=0;i<R;i++)
		for( int j=0;j<C;j++)
			if(mining[i][j]==0)countOpen++;

	if(debug)cout<<"Open:"<<countOpen<<endl;
	return countOpen==R*C-M;
}

bool tryRearrange(int R, int C){
	bool moved=false;
	for(int i=R-1;i>1;i--){
		for(int j=0;j<C;j++){
			if(mine[i][j]=='.'&&mine[i-1][j+1]=='*'){
				int j2r=j;
				j++;
				if(debug)cout<<i<<","<<j<<endl;
				while(mine[i-1][j]=='*'&&j<C)
					j++;
				if(debug)cout<<j2r<<","<<j<<endl;
				if(i==R-2&&j-j2r>2){
					mine[i][j2r]='*';
					mine[i-1][j-2]='.';
					mine[i+1][j2r]='*';
					mine[i-1][j-1]='.';
					moved=true;
					break;
				} else if(i<R-2){
					mine[i][j2r]='*';
					mine[i-1][j-1]='.';
					moved=true;
					break;
				}
			}
		}
	}
	if(debug){
		cout<<"moved:"<<endl;
		print(R,C);
	}


	return moved;
}

void solve(int c)
{
	int R, C, M;
	cin>>R>>C>>M;
	memset(mine,'.',sizeof(mine));
	mine[R-1][C-1]='c';
	

	int m=M;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(m-->0)
				mine[i][j]='*';
			if(m==0)break;
		}
		if(m==0)break;
	}
	
	if(debug)print(R,C);
	bool solvable=true;
	while(!isSolvable(R,C,M)){
		if(!tryRearrange(R,C)){
			solvable=false;
			break;
		}
	}

	if(!solvable)
		cout<<"Case #"<<c<<": "<<endl<<"Impossible"<<endl;
	else{
		cout<<"Case #"<<c<<": "<<endl;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++)
				cout<<mine[i][j];
			cout<<endl;
		}
	}
		
}

int main(int argc, char** args)
{
	if(argc>1&&args[1][0]=='d'){
		debug=true;
		freopen("C-sample.in","r",stdin);
	}
	int T;
	cin>>T;
	int c=0;
	while((++c)<=T){
		solve(c);
	}
}
	
