#include <iostream>
#include <string.h>
#include <vector>
#define MAX 200
using namespace std;

char home[MAX], str[MAX], first[MAX], second[MAX];

int main()
{
    int n;

    cin>>n;

    cin>>home;

   // int a = getId(home);
    int left = 0, right = 0;
    for(int i = 0; i < n; i++){
        cin>>str;
        int k = 0;
        for(int j = 0; j < 3; j++){
            first[k++] = str[j];
        }
        first[k++] = '\0';

        int len = strlen(str);

        int l = 0;
        for(int j = 5; j < len; j++){
            second[l++] = str[j];
        }
        second[l++] = '\0';

        //cout<<first<<" "<<second<<endl;

        if(strcmp(first, home) == 0){
            left++;
        }
        else if(strcmp(second, home) == 0)
            right++;

        //cout<<"ID: "<<b<<" "<<c<<endl
    }
    if(left == right)
        cout<<"home"<<endl;
    else
        cout<<"contest"<<endl;


    return 0;
}
