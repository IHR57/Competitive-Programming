#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    char s1[40], s2[40], s3[40], s4[40], str1[1005][20], str2[1005][20];

    cin>>s1>>s2;

    strcpy(str1[0], s1);
    strcpy(str2[0], s2);

    int j = 1;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>s3>>s4;

        if(strcmp(s1, s3) == 0){
            strcpy(s1, s4);
            strcpy(str1[j], s1);
            strcpy(str2[j], s2);
            j++;
        }
        else if(strcmp(s2, s3) == 0){
            //strcpy(s1, s4);
            strcpy(s2, s4);
            strcpy(str1[j], s1);
            strcpy(str2[j], s2);
            j++;
        }
    }

    for(int i = 0; i <= n; i++){
        cout<<str1[i]<<" "<<str2[i]<<endl;
    }

    return 0;
}
