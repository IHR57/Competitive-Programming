#include <iostream>
#include <stack>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    int test, cases = 1;
    string command, str, currentPage;

    scanf("%d", &test);

    while(test--){
        stack<string>Forward;
        stack<string>backward;

        currentPage = "http://www.lightoj.com/";

        cout<<"Case "<<cases++<<":"<<endl;
        while(cin>>command){
            if(command == "QUIT"){
                break;
            }

            if(command == "VISIT"){
                cin>>str;
                backward.push(currentPage);
                //printf("%s\n", str);
                cout<<str<<endl;
                currentPage = str;
                while(!Forward.empty())
                {
                    Forward.pop();
                }
            }

            else if(command == "BACK"){
                if(backward.empty()){
                    //printf("Ignored\n");
                    cout<<"Ignored"<<endl;
                }
                else{
                    Forward.push(currentPage);
                    currentPage = backward.top();
                    backward.pop();
                    cout<<currentPage<<endl;
                    //printf("%s\n", currentPage);
                }
            }

            else if(command == "FORWARD"){
                if(Forward.empty()){
                    cout<<"Ignored"<<endl;
                }
                else{
                    backward.push(currentPage);
                    currentPage = Forward.top();
                    Forward.pop();
                    cout<<currentPage<<endl;
                }
            }
        }
    }

    return 0;
}
