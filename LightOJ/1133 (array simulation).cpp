#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int test, m, n, a, b, i, j, k, l, p=1;

    cin>>test;
    while(test--){
        int  value[110], rev[110];
        char ch[30];
        cin>>n>>m;
        for(i=0; i<n; i++){
            cin>>value[i];
        }
        for(j=1; j<=m; j++){
            scanf("%s", &ch);
            if(ch[0]=='P'){
                cin>>a>>b;
                swap(value[a], value[b]);
            }
            else if(ch[0]=='S'){
                cin>>k;
                for(i=0; i<n; i++){
                    value[i]=value[i]+k;
                }
            }
            else if(ch[0]=='M'){
                cin>>k;
                for(i=0; i<n; i++){
                    value[i]=value[i]*k;
                }
            }
            else if(ch[0]=='D'){
                cin>>k;
                for(i=0; i<n; i++){
                    value[i]=value[i]/k;
                }
            }
            else if(ch[0]=='R'){
                for(i=n-1, l=0; i>=0; i--, l++){
                    rev[l]=value[i];
                }
                for(i=0; i<n; i++){
                    value[i]=rev[i];
                }
            }
        }
        cout<<"Case "<<p++<<": "<<endl;
        for(i=0; i<n-1; i++){
            cout<<value[i]<<" ";
        }
        cout<<value[n-1];
        cout<<endl;
    }

    return 0;
}
