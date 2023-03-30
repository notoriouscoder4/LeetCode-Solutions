/*

*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int sign = 1, base = 0, i = 0;
        while (s[i] == ' ') // ignore the whitespaces
            i++;
        if (s[i] == '-' || s[i] == '+') // sign of number
            sign = 1 - 2 * (s[i++] == '-');

        while (s[i] >= '0' && s[i] <= '9')
        { // checking for valid input
            // handling overflow
            if (base > INT_MAX / 10 || (base == INT_MAX / 10 && s[i] - '0' > 7))
            {
                if (sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            base = 10 * base + (s[i++] - '0');
        }
        return sign * base;
    }
};

int main()
{
    string s = "42";

    Solution obj;
    auto ans = obj.myAtoi(s);
    cout << ans << "\n";

    return 0;
}