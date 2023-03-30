/*
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

Example 1:
Input: pattern = "abba", s = "dog cat cat dog"
Output: true

Example 2:
Input: pattern = "abba", s = "dog cat cat fish"
Output: false

Example 3:
Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false

Constraints:
    1 <= pattern.length <= 300
    pattern contains only lower-case English letters.
    1 <= s.length <= 3000
    s contains only lowercase English letters and spaces ' '.
    s does not contain any leading or trailing spaces.
    All the words in s are separated by a single space.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> mp;
        unordered_map<string, bool> visited;

        vector<string> wordList;

        // Breaking input into word using string stream
        // Used for breaking words
        stringstream st(s);

        // To store individual words
        string word;
        int count = 0;

        while (st >> word)
        {
            count++;
            wordList.push_back(word);
        }

        if (pattern.size() != count)
        {
            return false;
        }
        else
        {
            for (int i = 0; i < pattern.size(); ++i)
            {
                char c = pattern[i];

                // case1. if not visted for new letter eg: abba s[dog,dog,dog,dog] so dog is already assinged to 'a' so "dog" will be visited before it comes to the letter b.
                if (mp[c] == "" && visited[wordList[i]] == true)
                {
                    return false;
                }

                // case 2 .if not visited we will make it visited and assign value as v[i]
                else if (mp[c] == "")
                {
                    mp[c] = wordList[i];
                    visited[wordList[i]] = true;
                }
                // case 3. if value is already assigned so not equal to the v[i].
                else
                {
                    if (mp[c] != wordList[i])
                        return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    string pattern = "abba";
    string s = "dog cat cat dog";

    Solution obj;
    auto ans = obj.wordPattern(pattern, s);
    cout << ans << "\n";

    return 0;
}