#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int n, data[200], sum = 0, visited[200]= {0};

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>data[i];
        sum += data[i];
    }

    int value = 2 * sum / n;


    for(int i = 0; i <= n; i++){
        if(!visited[i]){
            for(int j = i+1; j < n; j++){
                if(!visited[j] && data[i] + data[j] == value){
                    cout<<i+1<<" "<<j+1<<endl;
                    visited[i] = visited[j] = 1;
                    break;
                }
            }
        }
    }


    return 0;
}
