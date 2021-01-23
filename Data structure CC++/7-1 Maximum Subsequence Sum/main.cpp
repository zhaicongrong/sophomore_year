#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> nums;
    for(int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    int sum = INT_MIN;
    int tmpsum = nums[0];
    for(int i = 1; i < N; i++)
    {
        tmpsum += nums[i];
        if(tmpsum > sum)
            sum = tmpsum;
        else
            if(tmpsum < 0)
                tmpsum = 0;
    }
    cout << sum;
    return 0;
}
