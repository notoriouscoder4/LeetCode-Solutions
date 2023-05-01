/*
You are given an array of unique integers salary where salary[i] is the salary of the ith employee.

Return the average salary of employees excluding the minimum and maximum salary.
Answers within 10^-5 of the actual answer will be accepted.

Example 1:
Input: salary = [4000,3000,1000,2000]
Output: 2500.00000
Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500

Example 2:
Input: salary = [1000,2000,3000]
Output: 2000.00000
Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.
Average salary excluding minimum and maximum salary is (2000) / 1 = 2000

Constraints:
    3 <= salary.length <= 100
    1000 <= salary[i] <= 106
    All the integers of salary are unique.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution_sorting
{
public:
    double average(vector<int> &salary)
    {
        sort(salary.begin(), salary.end());
        int n = salary.size(), cnt = 0, total_salary = 0;

        for (int i = 1; i < n - 1; i++)
        {
            cnt++;
            total_salary += salary[i];
        }

        return (double)total_salary / (double)cnt;
    }
};

class Solution
{
public:
    double average(vector<int> &salaries)
    {
        int minSalary = INT_MAX;
        int maxSalary = INT_MIN;
        int sum = 0;

        for (int salary : salaries)
        {
            // Sum of all the salaries.
            sum += salary;
            // Update the minimum salary.
            minSalary = min(minSalary, salary);
            // Update the maximum salary.
            maxSalary = max(maxSalary, salary);
        }

        // Divide the sum by total size - 2, as we exclude minimum and maximum values.
        return (double)(sum - minSalary - maxSalary) / (double)(salaries.size() - 2);
    }
};

int main()
{
    vector<int> salary = {4000, 3000, 1000, 2000};

    Solution obj;
    auto ans = obj.average(salary);
    cout << ans << endl;

    return 0;
}