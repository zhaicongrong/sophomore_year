#include <iostream>
#include <cstdio>
#include <string>
#include <map>
//无语了，我脑子有坑，怎么写也写不出来
using namespace std;
int main()
{
    string s1, s2, s3, s4;
    string match;
    map<char, int> hour;
    for(int i = 0; i < 10; i++)
        hour.insert(pair<char, int>(i + '0', i));
    for(int i = 0; i < 13; i++)
        hour.insert(pair<char, int>(i + 'A', i + 10));
    int a[3], point = 0;
    cin >> s1 >> s2 >> s3 >> s4;
    for(int i = 0; i < s1.length(); i++)
        for(int j = 0; j < s2.length(); j++)
        {
            if(s1[i] == s2[j])
                match.push_back(s1[i]); 
        }
    for(int i = 0; i < match.size(); i++)
    {
        if(isalpha(match[i]) == 1)
        {
            if(i == 0)
            {
                a[0] = match[0] - 'A' + 1;
                a[1] = hour.at(match[1]); 
                break;
            }
            else
            {
                a[0] = match[i] - 'A' + 1;
                a[1] = hour.at(match[0]);
                break;
            }
                   
        }
    }
    
    for(int i = 0; i < s3.length(); i++)
        for(int j = 0; j < s4.length(); j++)
        {
            if(s3[i] == s4[j])
            {
                a[2] = i;
                break;
            }
        }
    switch (a[0])
    {
        case 1: printf("MON");break;
        case 2: printf("TUE");break;
        case 3: printf("WED");break;
        case 4: printf("THU");break;
        case 5: printf("FRI");break;
        case 6: printf("SAT");break;
        case 7: printf("SUN");break;
    }
    if(a[1] < 10)
        printf(" 0%d", a[1]);
    else
        printf(" %d", a[1]);
    if(a[2] < 10)
        printf(":0%d", a[2]);
    else
        printf(":%d", a[2]);
    printf("\n****************\n");
    printf("%d %d %d", a[0], a[1], a[2]);
}