#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    char str[110];
    int G, length, n, i, j, k;

    while(G!=0){

        cin>>G;
        if(G==0)//if group=0
            break;
        cin>>str;

        length=strlen(str);
        n=length/G;  //number of groups

        //Reversing  the word in groupwise
        j=n-1;
        k=0;
        while(j<length){
            for(i=j; i>=k; i--){
                cout<<str[i];
            }
            j=j+n;
            k=k+n;
        }
        cout<<endl;
    }

    return 0;
}
