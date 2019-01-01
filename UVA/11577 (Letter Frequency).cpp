#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main()
{
    int test, counter[50], i;
    char alphabet[] = {"abcdefghijklmnopqrstuvwxyz"};
    char str[300];

    cin>>test;
    getchar();

    while(test--){
        gets(str);
        int len = strlen(str);

        for(i=0; i<len; i++){
            str[i] = tolower(str[i]);   //converting UpperCase to LowerCase
        }
        str[i] = '\0';

        for(i=0; i<26; i++){
            counter[i] = 0;         //initialize all counter equal to zero
        }

        for(i=0; i<len; i++){
            for(int j=0; j<26; j++){
                if(str[i]==alphabet[j]){
                    counter[j]++;
                }
            }
        }

        int Max = 0;

        for(i=0; i<26; i++){
            if(counter[i]>Max)
                Max = counter[i];       //find the maximum occuring number
        }

        for(i=0; i<26; i++){
            if(counter[i]==Max)
                cout<<alphabet[i];
        }
        cout<<endl;
    }

    return 0;
}
