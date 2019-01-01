#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    char str[200];
    int count = 0;

    cin>>str;

    int len = strlen(str);

    int i = 0;
    while(i < len){
        if(str[i] == 'D'){
            if(str[i+1] == 'a' && str[i+2] == 'n' && str[i+3] == 'i' && str[i+4] == 'l'  && i + 4 < len){
                count++;
                i = i + 4;
            }
        }
        else if(str[i] == 'O'){
            if(str[i+1] == 'l' && str[i+2] == 'y' && str[i+3] == 'a' && i + 3 < len){
                count++;
                i = i + 3;
            }
        }
        else if(str[i] == 'S'){
            if(str[i+1] == 'l' && str[i+2] == 'a' && str[i+3] == 'v' && str[i+4] == 'a'  && i + 4 < len){
                count++;
                i = i + 4;
            }
        }
        else if(str[i] == 'A'){
            if(str[i+1] == 'n' && str[i+2] == 'n' && i + 2 < len){
                count++;
                i = i + 2;
            }
        }
        else if(str[i] == 'N'){
            if(str[i+1] == 'i' && str[i+2] == 'k' && str[i+3] == 'i' && str[i+4] == 't'  && str[i+5] == 'a' && i + 5 < len){
                count++;
                i = i + 5;
            }
        }
        i = i + 1;
    }

    if(count == 1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
