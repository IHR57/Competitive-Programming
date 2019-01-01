#include <bits//stdc++.h>
using namespace std;

int main()
{
    string serial, str, final_str[60];
    int n, visited[60];
    int count, index;

    while(cin>>n && n != 0){

        memset(visited, 0, sizeof(visited));
        index = 1;

        int sum = 0;
        for(int i = 1; i <= n; i++){
            cin>>serial>>str;
            int len = str.size();
            //sum = (sum + len)%(n+1);

            count = 0;
            for(int j = index; j <= n; ){
                if(visited[j] == 0){
                    count++;
                }
                if(count == len){
                    index = j;
                    break;
                }
                j = (j+1) % (n+1);
                if(j == 0)
                    j = 1;
            }
            visited[index] = 1;
            final_str[index] = serial;
        }

        for(int i = 1; i < n; i++){
            cout<<final_str[i]<<" ";
        }
        cout<<final_str[n]<<endl;
    }

    return 0;
}
