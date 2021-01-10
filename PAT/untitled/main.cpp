#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int maxlength = 0;
        int end = 0, start = 0;
        for(int k = 0; k < s.size(); k++)
        {
            auto k1 = expand(s, k, k);
            auto k2 = expand(s, k, k + 1);
            if(k1.second - k1.first > k2.second - k2.first)
            {
                if(k1.second - k1.first + 1 > maxlength)
                {
                    maxlength = k1.second - k1.first + 1;
                    start = k1.first;
                    end = k2.second;
                }
            }
            else
            {
                if(k2.second - k2.first + 1 > maxlength)
                {
                    maxlength = k2.second - k2.first + 1;
                    start = k2.first;
                    end = k2.second;
                }
            }
        }
        return s.substr(start, maxlength);
    }
    pair<int, int> expand(string s, int mid1, int mid2)
    {
        if(mid2 == s.size() || s[mid1] != s[mid2])
            return {mid1, mid1};
        int left = mid1;
        int right = mid2;
        while(left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return {left + 1, right - 1};
    }
};
int main()
{

    string a;
    cin >> a;
    Solution s;
    string Result = s.longestPalindrome(a);
    cout << Result;
    return 0;
}
