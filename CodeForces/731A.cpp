#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

int main()
{
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char str[200];
    int Forward, Backward, sum = 0;

    cin>>str;

    int len = strlen(str);

    int prev = 1, curr;

    for(int i = 0; i < len; i++){
        for(int j = 0; j < 26; j++){
            if(str[i] == alphabet[j]){
                curr = j + 1;
            }
        }
        Forward = abs(curr - prev);
        Backward = 26 - Forward;

        if(Forward <= Backward)
            sum += Forward;
        else
            sum += Backward;
        prev = curr;
    }

    cout<<sum<<endl;

    return 0;
}
