#include <iostream>
#include <algorithm>
using namespace std;
void solve(int c)
{
    int N;
    cin>>N;
    double Naomi[1000],Ken[1000];
    for(int i=0;i<N;i++)cin>>Naomi[i];
    for(int i=0;i<N;i++)cin>>Ken[i];
    sort(Naomi,Naomi+N);
    sort(Ken,Ken+N);
    int y=0,z=N;
    for(int i=0,j=0;i<N;i++){
        if(Naomi[i]>Ken[j]){
            y++;
            j++;
        }
    }
    for(int i=0,j=0;j<N;i++,j++){
        while(j<N&&Ken[j]<Naomi[i])j++;
        if(j<N)z--;
    }
    cout<<"Case #"<<c<<": "<<y<<" "<<z<<endl;
}

int main(int argc, char** args)
{
    int T;
    cin>>T;
    int c=0;
    while((++c)<=T){
        solve(c);
    }
}
