//Problem ID: CodeForces - 474C (Captain Marmot)
//Programmer: IQBAL HOSSAIN     Description: Geometry
//Date: 08/01/19
//Needed help to solve this one
#include <bits/stdc++.h>
#define MAX 100005
#define EPS 1e-8
#define PI acos(-1.0)
using namespace std;

double d[50];
const int inf = 1<<28;

bool dcmp(double i, double j)
{
    return fabs(i - j) <= EPS;
}

struct point
{
    double x, y;
};

bool compare(const point& i, const point& j){
    if(!dcmp(i.x, j.x)){
        return i.x < j.x;
    }
    return i.y < j.y;
}

bool isEqual(const point& i, const point&j)
{
    return dcmp(i.x, j.x) && dcmp(i.y, j.y);
}

point turnLeft(const point& i, const point& j, double a)
{
    point temp;
    temp.x = (i.x - j.x) * cos(a) - (i.y - j.y) * sin(a) + j.x;
    temp.y = (i.x - j.x) * sin(a) + (i.y - j.y) * cos(a) + j.y;

    return temp;
}

double dist(point i, point j)
{
    return ((i.x - j.x) * (i.x - j.x)) + ((i.y - j.y) * (i.y - j.y));
}

bool check(point i, point j, point k, point l)
{
    point arr[4];
    arr[0] = i, arr[1] = j, arr[2] = k, arr[3] = l;
    int idx = 0;

    for(int i = 0; i < 4; i++){
        for(int j = i + 1; j < 4; j++){
            d[idx++] = dist(arr[i], arr[j]);
        }
    }
    sort(d, d + idx);

    if (dcmp(d[0], d[3]) && !dcmp(d[0], 0) && dcmp(d[4], d[5]) && dcmp(d[0] * 2, d[4])) {
        return true;
    } else
        return false;
}

int main()
{
    point a[20], b[20];
    int n;

    scanf("%d", &n);

    while(n--){
        for(int i = 0; i < 4; i++){
            scanf("%lf %lf %lf %lf", &a[i].x, &a[i].y, &b[i].x, &b[i].y);
        }

        int ans = inf;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                for(int k = 0; k < 4; k++){
                    for(int l = 0; l < 4; l++){
                        if(check(turnLeft(a[0], b[0], i * PI / 2), turnLeft(a[1], b[1], j * PI / 2),
                            turnLeft(a[2], b[2], k * PI / 2), turnLeft(a[3], b[3], l * PI / 2))){

                            ans = min(ans, i + j + k + l);
                        }
                    }
                }
            }
        }
        if(ans == inf)
            ans = -1;

        printf("%d\n", ans);
    }

    return 0;
}
