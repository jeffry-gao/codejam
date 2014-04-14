#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

bool debug=false;

int R, C, M;
char mine[50][50];
int  flags[50][50];

void print(){
    for(int j=0;j<R;j++){
        for(int k=0;k<C;k++){
            cout<<mine[j][k];
        }
        cout<<endl;
    }
}

bool isSolvable(){
    // special case
    if(R*C-M==1) return true;
    memset(flags,0,sizeof(flags));
    for(int i=0;i<R;i++){
        for( int j=0;j<C;j++){
            flags[i][j]=1;
            for(int m=i-1;m<=i+1;m++)
                for(int n=j-1;n<=j+1;n++)
                    if(0<=m&&m<R&&0<=n&&n<C&&mine[m][n]=='*')flags[i][j]=0;
        }
    }

    for(int i=0;i<R;i++){
        for( int j=0;j<C;j++){
            if(flags[i][j]==1){
                for(int m=i-1;m<=i+1;m++)
                    for(int n=j-1;n<=j+1;n++)
                        if(0<=m&&m<R&&0<=n&&n<C&&flags[m][n]!=1)flags[m][n]=2;
            }
        }
    }

    int countClose=0;
    for(int i=0;i<R;i++)
        for( int j=0;j<C;j++)
            if(flags[i][j]==0)countClose++;

    return countClose==M;
}

bool transform(){
    bool moved=false;
    for(int i=R-1;i>0;i--){
        for(int j=0;j<C;j++){
            if(mine[i][j]=='.'&&mine[i-1][j+1]=='*'){
                int j2r=j;
                j++;
                while(mine[i-1][j]=='*'&&j<C)
                    j++;
                if(i==R-2){
                    if((j2r==0||mine[i+1][j2r-1]=='*')&&j-j2r>2){
                        mine[i][j2r]='*';
                        mine[i+1][j2r]='*';
                        mine[i-1][j-1]='.';
                        mine[i-1][j-2]='.';
                        moved=true;
                        break;
                    } else if(j2r>0&&mine[i+1][j2r-1]=='.'&&j-j2r>3){
                        mine[i][j2r]='*';
                        mine[i+1][j2r-1]='*';
                        mine[i+1][j2r]='*';
                        mine[i-1][j-1]='.';
                        mine[i-1][j-2]='.';
                        mine[i-1][j-3]='.';
                        moved=true;
                        break;
                    }
                } else {
                    mine[i][j2r]='*';
                    mine[i-1][j-1]='.';
                    moved=true;
                    break;
                }
            }
        }
        if(moved)break;
    }
    if(debug){
        cout<<"moved:"<<endl;
        print();
    }


    return moved;
}

void solve(int c)
{
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
    
    if(debug)print();
    bool solvable=true;
    while(!isSolvable()){
        if(!transform()){
            solvable=false;
            break;
        }
    }

    if(!solvable)
        cout<<"Case #"<<c<<": "<<endl<<"Impossible"<<endl;
    else{
        cout<<"Case #"<<c<<": "<<endl;
        print();
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
    

