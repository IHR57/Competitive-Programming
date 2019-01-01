#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int number, result;
    char str1[20], str2[20];

    cin>>number>>str1>>str2;

    if(strcmp(str2, "week") == 0){
        if(number == 5 || number == 6){
            result = 53;
        }
        else
            result = 52;
    }

    else if(strcmp(str2, "month") == 0){
        if(number <= 29){
            result = 12;
        }
        else if(number == 30)
            result = 11;
        else if(number == 31)
            result = 7;
    }

    cout<<result<<endl;

    return 0;
}
