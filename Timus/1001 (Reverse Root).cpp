#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double number;
    vector<double>ob;

    while(cin>>number){
        ob.push_back(number);
    }

    for(int i=ob.size()-1; i>=0; i--){
        cout<<setiosflags(ios::fixed)<<setprecision(4);
        cout<<sqrt(ob[i])<<endl;
    }

    return 0;
}
