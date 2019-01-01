#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    char c;
    char string[500];
    int i=0;


   while(cin>>string){

        for(i=0; string[i]!=0; i++){
            string[i]=(char)(string[i]-7);
        }
        string[i]='\0';

        cout<<string;

        cout<<endl;
   }

    return 0;
}
