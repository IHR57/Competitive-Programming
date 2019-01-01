#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

bool flag[MAX];
int counter[MAX];

int convert(char ch1, char ch2)
{
    return ((ch1 - 48) * 10 + (ch2 - 48));
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str, ans;

    map<string, int> myMap;

    int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    cin>>str, ans;

    int len = (int) str.length();
    int idx = 0;

    int cnt = 0, id = 0, Max = -1;

    for(int i = 0; i <= len - 10; i++){
        string temp = str.substr(i, 10);
        if(temp[2] != '-' || temp[5] != '-')
            continue;
        if(!isdigit(temp[0]))
            continue;
        if(!isdigit(temp[1]))
            continue;
        if(!isdigit(temp[3]))
            continue;
        if(!isdigit(temp[4]))
            continue;
        if(temp[6] != '2' || temp[7] != '0' || temp[8] != '1')
            continue;
        if(temp[9] < '3' || temp[9] > '5')
            continue;
        int day = convert(temp[0], temp[1]);
        int m = convert(temp[3], temp[4]);
        if(m > 12 || m <= 0)
            continue;
        if(day > month[m] || day <= 0)
            continue;
        if(myMap.find(temp) == myMap.end()){
            myMap[temp] = idx++;
        }
        int x = myMap[temp];
        counter[x]++;
        if(counter[x] > Max){
            Max = counter[x];
            ans = temp;
        }
    }

    cout<<ans<<endl;

    return 0;
}
