//Problem ID: CodeForces - 849B (Tell your World)
//Programmer: IQBAL HOSSAIN     Description: Brute Force / Geometry
//Date: 14/05/19
#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

double x[MAX], y[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>y[i];
        x[i] = i * 1.0;
    }

    set<double> s;
    for(int i = 2; i <= n; i++){
        double m = (y[i] - y[1]) / (x[i] - x[1]);
        s.clear();
        for(int j = 1; j <= n; j++){
            double c = (y[j] - m * x[j]);
            s.insert(c);
            if(s.size() > 2){
                break;
            }
        }
        if(s.size() == 2){
            cout<<"Yes"<<endl;
            return 0;
        }
        s.clear();
    }
    for(int i = 3; i <= n; i++){
        double m = (y[i] - y[2]) / (x[i] - x[2]);
        s.clear();
        for(int j = 1; j <= n; j++){
            double c = (y[j] - m * x[j]);
            s.insert(c);
            if(s.size() > 2)
                break;
        }
        if(s.size() == 2){
            cout<<"Yes"<<endl;
            return 0;
        }
        s.clear();
    }

    cout<<"No"<<endl;

    return 0;
}
