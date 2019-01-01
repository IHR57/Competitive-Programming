#include <bits//stdc++.h>
using namespace std;

int main()
{
    int Size, command, test, n, value, cases=1;
    char str[50];

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &Size, &command);
        deque<int>dq;

        int index=0;

        printf("Case %d:\n", cases++);

        for(int i=0; i<command; i++){
            scanf("%s", str);
            if(strcmp(str, "pushLeft")==0){
                scanf("%d", &n);
                if(dq.size()!=Size){
                    dq.push_front(n);
                    printf("Pushed in left: %d\n", n);
                }
                else
                    printf("The queue is full\n");
            }
            else if(strcmp(str, "pushRight")==0){
                scanf("%d", &n);
                if(dq.size()!=Size){
                    dq.push_back(n);
                    printf("Pushed in right: %d\n", n);
                }
                else
                    printf("The queue is full\n");
            }
            else if(strcmp(str, "popLeft")==0){
                if(dq.size()!=0){
                    value = dq.front();
                    dq.pop_front();
                    printf("Popped from left: %d\n", value);
                }
                else
                    printf("The queue is empty\n");
            }
            else if(strcmp(str, "popRight")==0){
                if(dq.size()!=0){
                    value = dq.back();
                    dq.pop_back();
                    printf("Popped from right: %d\n", value);
                }
                else
                    printf("The queue is empty\n");
            }
        }
    }

    return 0;
}
