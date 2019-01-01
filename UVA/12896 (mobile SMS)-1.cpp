#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

int main()
{
    char str[10][10]={" ", ".,?\"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int number[110], press[110], length, test;

    cin>>test;

    while(test--){
        cin>>length;
        for(int i=0; i<length; i++){
            cin>>number[i];
        }
        for(int i=0; i<length; i++){
            cin>>press[i];
        }

        for(int i=0; i<length; i++){
            putchar(str[number[i]][press[i]-1]);
        }
        puts("");
    }

    return 0;
}
