#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <string>
#include <sstream>
#define MAX 30
using namespace std;

int main()
{
    string str;
    set<string> s;

    while(getline(cin, str)){
        int len = (int) str.length();
        for(int i = 0; i < len; i++){
            if(isalpha(str[i]))
                str[i] = tolower(str[i]);
            else
                str[i] = ' ';
        }
        istringstream iS(str);
        string w;
        while(iS >> w){
            s.insert(w);
        }
    }

    for(set<string>::const_iterator it = s.begin(); it != s.end(); it++){
        cout<<*it<<endl;
    }

    return 0;
}
