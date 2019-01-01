#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    char str[100], revstr[100], revpalin[100], str1[100];
    int i, j, count;
    bool flag;

    while(cin.getline(str, sizeof(str))){
        count=0;
        int len=strlen(str);
        for(i=len-1, j=0; i>=0; i--, j++){
            revstr[j]=str[i];
        }
        revstr[j]='\0';
        if(strcmp(str, revstr)==0){
            for(i=0; str[i]; i++){
                if(str[i]=='A' || str[i]=='H' || str[i]=='I' || str[i]=='M' || str[i]=='O' || str[i]=='T' || str[i]=='U' || str[i]=='V' || str[i]=='W' || str[i]=='X' || str[i]=='Y' || str[i]=='1' || str[i]=='8'){
                    count++;
                }
            }
            if(count==len)
                cout<<str<<" -- is a mirrored palindrome."<<endl<<endl;
            else
                cout<<str<<" -- is a regular palindrome."<<endl<<endl;
        }
        else{
            strcpy(str1, str);
            for(i=0; str[i]; i++){
                if(str[i]=='3')
                    str[i]='E';
                else if(str[i]=='J')
                    str[i]='L';
                else if(str[i]=='5')
                    str[i]='Z';
                else if(str[i]=='2')
                    str[i]='S';
            }
            for(i=len-1, j=0; i>=0; i--, j++){
                revpalin[j]=str[i];
            }
            revpalin[j]='\0';
            if(strcmp(str, revpalin)==0)
                cout<<str1<<" -- is a mirrored string."<<endl<<endl;
            else
                cout<<str1<<" -- is not a palindrome."<<endl<<endl;
        }
    }

    return 0;
}
