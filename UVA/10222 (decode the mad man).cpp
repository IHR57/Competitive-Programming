//Problem ID: 10222
//Programmer: IQBAL HOSSAIN
//credit Md. Mahmud Ahsan

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[]="`1234567890-=qwertyuiop[]asdfghjkl;'\zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}ASDFGHJKL:\"|ZXCVBNM<>?";
    char input[10000];
    int i, j;
    int flag;

    while(cin.getline(input, sizeof(input))){
        for(i=0; input[i]!='\0'; i++){
            flag=0; //checking if input character is found
            for(j=0; str[j]!='\0'; j++){
                if(input[i]==str[j]){
                    cout<<str[j-2];
                    flag=1; //if input character is found
                    break;
                }
            }
            if(flag==0)
                cout<<input[i]; //if input character is not found show the str[] character
        }
        cout<<endl;
    }

    return 0;
}
