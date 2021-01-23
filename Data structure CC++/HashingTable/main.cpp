#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;
int isPrime(int x)
{
    if(x == 0 || x == 1)
           return 0;
    if(x == 2)
        return 1;
	if(x % 2 == 0)
		return 0;
	for(int i = 2; i < sqrt(x); i++)
		if(x / i * i == x)
			return 0;
	return 1;
}
int main()
{
	int N, M;
	cin >> M >> N;
	if(!isPrime(M))
		while(1)
			if(isPrime(++M))
				break;
	int a[M];
	for(int i = 0; i < M; i++)
		a[i] = 0;
	for(int i = 0; i < N; i++)
	{
		int tmp;
		int flag = 0;
		int location;
		cin >> tmp;
		for(int d = 0; d < M; d++)
        {
            if(a[(tmp + d * d) % M] == 0)
            {
                flag = 1;
                a[(tmp + d * d) % M] = tmp;
                location = (tmp + d * d) % M;
                break;
            }
        }
        if(i != N - 1)
            if(flag)
                cout << location << " ";
            else
                cout << "- ";
        else
            if(flag)
                cout << location;
            else
                cout << "-";
    }
    return 0;
}
