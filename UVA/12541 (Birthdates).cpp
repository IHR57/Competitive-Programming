#include <iostream>
using namespace std;

int main()
{
    int month, day, year, n;
    string name;

    cin>>n;

    cin>>name>>day>>month>>year;

    int Max_year = year;
    int Max_month = month;
    int Max_day = day;
    string id = name;

    int Min_year = year;
    int Min_month = month;
    int Min_day = day;
    string id_min = name;

    for(int i = 1; i < n; i++){
        cin>>name>>day>>month>>year;
        if(year > Max_year){
            Max_year = year;
            Max_month = month;
            Max_day = day;
            id = name;
        }
        else if(year == Max_year){
            if(month > Max_month){
                Max_year = year;
                Max_month = month;
                Max_day = day;
                id = name;
            }
            else if(month == Max_month){
                if(day > Max_day){
                    Max_year = year;
                    Max_month = month;
                    Max_day = day;
                    id = name;
                }
                else if(day == Max_day){
                    Max_year = year;
                    Max_month = month;
                    Max_day = day;
                    id = name;
                }
            }
        }

         if(year < Min_year){
            Min_year = year;
            Min_month = month;
            Min_day = day;
            id_min = name;
        }
        else if(year == Min_year){
            if(month < Min_month){
                Min_year = year;
                Min_month = month;
                Min_day = day;
                id_min = name;
            }
            else if(month == Min_month){
                if(day < Min_day){
                    Min_year = year;
                    Min_month = month;
                    Min_day = day;
                    id_min = name;
                }
                else if(day == Min_day){
                    Min_year = year;
                    Min_month = month;
                    Min_day = day;
                    id_min = name;
                }
            }
        }
    }

    cout<<id<<endl;
    cout<<id_min<<endl;

    return 0;
}
