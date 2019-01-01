#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main()
{
    char str[500];
    int i, j, k;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    while(cin.getline(str, sizeof(str))){
        int sum=0;
        for(i=0; str[i]; i++){
            //int sum=0;
            int k;
            if(str[i]>='1' && str[i]<='9'){
                j=str[i]-48;
                sum+=j;
                continue;
            }
            k=sum;
            int m=k;
            if(str[i]>='A' && str[i]<='Z'){
                //k=sum;
                for(j=0; j<m; j++){
                    cout<<str[i];
                }
                sum=0;
                continue;
            }
            else if(str[i]=='b'){
                for(j=0; j<m; j++)
                    cout<<" ";
                sum=0;
                continue;
            }
            else if(str[i]=='*'){
                for(j=0; j<m; j++)
                    cout<<'*';
                sum=0;
                continue;
            }
            else if(str[i]=='!' || str[i]=='\0'){
                cout<<endl;
                continue;
            }
        }
        cout<<endl;
    }

    return 0;
}
