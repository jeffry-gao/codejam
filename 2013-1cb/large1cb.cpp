#include <iostream>
#include <string.h>

using namespace std;

#define addup(s) ((s)+1)*(s)/2

string solve(int X, int Y)
{
    string path;
    int Xabs = X<0?-X:X;
    int Yabs = Y<0?-Y:Y;
    int s = 1;
    while(addup(s)<Xabs+Yabs||(addup(s)-Xabs-Yabs)%2==1)s++;
    int b1 = (addup(s)-Xabs-Yabs)/2;
    int b2 = (b1>s)?b1-s:0;
    b1 = b1 - b2;

    for(int i=s;i>0;i--) {
        // i.e. (-2,0) X forward 1, X forward 3, X backward 2
        if(Y==0)
            path.insert(0,1, (i==b1||(b2!=0&&b2==i))?(X>0?'W':'E'):(X>0?'E':'W') );
        else
            // not all the case can be solved by the method below, so the case Y==0 above is necessary
            if(i!=b1&&(b2==0||i!=b2)&&Xabs>=i){
                Xabs -= i;
                path.insert(0,1,(X>0?'E':'W'));
            } else
                path.insert(0,1, (i==b1||(b2!=0&&b2==i))?(Y>0?'S':'N'):(Y>0?'N':'S'));
    }

    return path;
}

int main(int argc, char** args)
{
    int T,X,Y;
    cin>>T;
    int c=0;
    while((++c)<=T){
        cin>>X>>Y;
        cout<<"Case #"<<c<<": "<<solve(X,Y)<<endl;
    }
}
