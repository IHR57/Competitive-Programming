#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    char string[1000000];
    char c;
    int i=0;

    do{
        c=cin.get();
        string[i]=c;  //store the character into string
        i++;
    }
    while(c!=EOF);
    string[i]='\0';     //assign null character at the end of the string
    int check=1;    //initialize the value of check;
    for(i=0; string[i]; i++){
        if(string[i]=='\"'){
            if(check%2!=0){
                cout<<"``";
                check++;    //the value of check will be 2
                continue;   //leave the rest of process
            }
            else if(check%2==0){
                cout<<"''";
                check--;    //decrement the value of check;
                continue;
            }
        }
        
        if(string[i]==EOF);
        else
            cout<<string[i];    //print the string
    }

    return 0;
}
