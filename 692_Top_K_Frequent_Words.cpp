/*
Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest.
Sort the words with the same frequency by their lexicographical order.

Example 1:
Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:
Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.

Constraints:
1 <= words.length <= 500
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
k is in the range [1, The number of unique words[i]]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
      static bool cmp(pair<string, int> &a, pair<string, int> &b)
      {
            // here second stores the frequency and if the frequency equals then sort lexicographically
            if (a.second == b.second)
            {
                  // this is comparing string lexicographically and if val<0 it means first string is smaller than second string
                  int val = a.first.compare(b.first);
                  if (val < 0)
                        return a.second;
            }
            // if the frequency does not equal then sort according to frequency from highest to lowest
            return a.second > b.second;
      }

public:
      vector<string> topKFrequent(vector<string> &words, int k)
      {
            unordered_map<string, int> mp;
            for (auto word : words)
                  mp[word]++;

            // sort according to value i.e. frequency
            vector<pair<string, int>> temp;
            for (auto &it : mp)
                  temp.push_back(it);
            sort(temp.begin(), temp.end(), cmp);

            vector<string> result;
            for (int i = 0; i < k; ++i)
                  result.push_back(temp[i].first);
            return result;
      }
};