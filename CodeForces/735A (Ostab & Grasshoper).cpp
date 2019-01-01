//Problem ID: CodeForces Round 382 Division 2 - Problem A
//Programmer: IQBAL HOSSAIN
//Date: 27-11-16
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char str[120];
    int n, k, flag = 0;

    cin>>n>>k;
    cin>>str;

    int len = strlen(str);

    int index_g, index_t;

    for(int i=0; i<len; i++){
        if(str[i]=='G'){
            index_g = i;
        }
    }
    for(int i=0; i<len; i++){
        if(str[i]=='T'){
            index_t = i;
        }
    }

    //cout<<index_t<<" "<<index_g<<endl;

    if(index_t>index_g){
        for(int i=index_g; i<n; i = i+k){
            if(str[i]=='#'){
                flag = 0;
                break;
            }
            if(str[i]=='T'){
                flag = 1;
                break;
            }
        }
    }
    else if(index_t<index_g){
        for(int i=index_g; i>=0; i = i-k){
            if(str[i]=='#'){
                flag = 0;
                break;
            }
            if(str[i]=='T'){
                flag = 1;
                break;
            }
        }
    }

    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
