#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char key[]={"`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./"};
    char str[1000];
    int flag;

    while(cin.getline(str, sizeof(str))){
        int len = strlen(str);

        for(int i=0; i<len; i++){
            flag = 0;
            for(int j=0; key[j]!='\0'; j++){        //input don't contain (Q, A, Z, `)
                if(str[i]==key[j]){
                    cout<<key[j-1];
                    flag = 1;
                    break;
                }
            }
            if(!flag)       //if character not found in the key just print the character
                cout<<str[i];
        }
        cout<<endl;
    }

    return 0;
}
