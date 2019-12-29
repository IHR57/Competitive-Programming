#include <bits/stdc++.h>
#define MAX
using namespace std;

class ABBA
{
    public:
        string canObtain(string initial, string target)
        {
            string temp;
            int len1 = (int) initial.length();
            int len2 = (int) target.length();
            for(int i = len2 - 1; i >= len1; i--){
                if(target[i] == 'B'){
                    temp = target.substr(0, i);
                    cout<<temp<<endl;
                    reverse(temp.begin(), temp.end());
                    target = temp;
                }
                else{
                    temp = target.substr(0, i);
                    cout<<temp<<endl;
                    target = temp;
                }
            }

            if(target == initial)
                return "Possible";
            else
                return "Impossible";

        }

};

