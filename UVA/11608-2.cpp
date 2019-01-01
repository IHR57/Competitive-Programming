#include <iostream>
using namespace std;

int main()
{
    int createdProblems[100], required[100], isProblem[100];
    int s, caseNo = 1;

    while(cin>>s){
        if(s < 0)  break;
        for(int i = 0; i < 12; i++){
            cin>>createdProblems[i];
        }
        for(int i = 0; i < 12; i++){
            cin>>required[i];
        }

        cout<<"Case "<<caseNo++<<":"<<endl;
        for(int i = 0; i < 12; i++){
            if(required[i] > s){
                cout<<"No problem. :("<<endl;
            }
            else{
                cout<<"No problem! :D"<<endl;
                s -= required[i];
            }
            s += createdProblems[i];
        }
    }

    return 0;
}
