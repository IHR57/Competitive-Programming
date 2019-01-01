#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string temp1, temp2, str;
    int n, count1 = 0, count2 = 0;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>str;
        if(i == 0){
            temp1 = str;
            count1++;
        }
        else{
            if(str == temp1)
                count1++;
            else{
                temp2 = str;
                count2++;
            }
        }
    }

    if(count1 > count2)
        cout<<temp1<<endl;
    else
        cout<<temp2<<endl;

    return 0;
}
