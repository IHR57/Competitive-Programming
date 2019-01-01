#include <iostream>
using namespace std;
int main(){int r,t,a,n,s[101][101]={0};cin>>t;while(t--){cin>>n;r=0;for(int i=1;i<=n;i++){for(int j=1;j<=i;j++){cin>>a;s[i][j]=max(s[i-1][j],s[i-1][j-1])+a;r=max(s[i][j],r);}}cout<<r<<endl;}return 0;}
