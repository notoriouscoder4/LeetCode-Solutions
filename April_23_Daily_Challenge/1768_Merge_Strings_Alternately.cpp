/*
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1.
If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.


Example 1:
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r

Example 2:
Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b
word2:    p   q   r   s
merged: a p b q   r   s

Example 3:
Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q
merged: a p b q c   d

Constraints:
    1 <= word1.length, word2.length <= 100
    word1 and word2 consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Intuition
    There are numerous ways in which we can combine the given strings. We've covered a few of them in this article.

    An intuitive method is to use two pointers to iterate over both strings. Assume we have two pointers, i and j, with i pointing to the first letter of word1 and j pointing to the first letter of word2. We also create an empty string results to store the outcome.

    We append the letter pointed to by pointer i i.e., word1[i], and increment i by 1 to point to the next letter of word1. Because we need to add the letters in alternating order, next we append word2[j] to results. We also increase j by 1.

    We continue iterating over the given strings until both are exhausted. We stop appending letters from word1 when i reaches the end of word1, and we stop appending letters from word2' when j reaches the end of word2.

Algorithm
    1. Create two variables, m and n, to store the length of word1 and word2.
    2. Create an empty string variable result to store the result of merged words.
    3. Create two pointers, i and j to point to indices of word1 and word2. We initialize both of them to 0.
    4. While i < m || j < n:
        4a. If i < m, it means that we have not completely traversed word1. As a result, we append word1[i] to result. We increment i to point to next index of words.
        4b. If j < n, it means that we have not completely traversed word2. As a result, we append word2[j] to result. We increment j to point to next index of words.
    5. Return results.

It is important to note how we form the result string in the following codes: - cpp:
The strings are mutable in cpp, which means they can be changed.
As a result, we used the string variable and performed all operations on it.
It takes constant time to append a character to the string. - java:
The String class is immutable in java. So we used the mutable StringBuilder to concatenate letters to result.
- python: Strings are immutable in python as well.
As a result, we used the list result to append letters and later joined the list with an empty string to return it as a string object.
The join operation takes linear time equal to the length of results to merge results with empty string.


Complexity Analysis
    Here, n is the length of word1 and m is the length of word2.

    Time complexity: O(m+n)
    We iterate over word1 and word2 once and push their letters into result. It would take O(m+n) time.

    Space complexity: O(1)
    Without considering the space consumed by the input strings (word1 and word2) and the output string (result), we do not use more than constant space.
*/
class Solution_2_pointer
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        string ans = "";
        int i = 0, j = 0;

        while (i < n && j < m)
        {
            ans.push_back(word1[i]);
            ans.push_back(word2[j]);
            i++;
            j++;
        }

        while (i < n)
        {
            ans.push_back(word1[i]);
            i++;
        }

        while (j < m)
        {
            ans.push_back(word2[j]);
            j++;
        }
        return ans;
    }
};

/*
Intuition
    To merge the given words, we can also use a single pointer.

    Let i be the pointer that we'll use. We begin with i = 0 and progress to the size of the longer word between word1 and word2, i.e., till i = max(word1.length(), word2.length()).

    As we progress to the size of a longer word, we check each time if i points to an index that is in bounds of the words or not. If i < word1.length(), we append word1[i] to results. Similarly if i < word2.length(), we append word2[i] to results.

    However, if i exceeds the length of any word, we don't have any letters to add from that word, so we ignore it and continue adding the letter from the longer word.

Algorithm
    1. Create two variables, m and n, to store the length of word1 and word2.
    2. Create an empty string variable result to store the result of merged words.
    3. Iterate over word1 and word2 using a loop running from i = 0 to i < max(m, n) and keep incrementing i by 1 after each iteration:
        3a. If i < m, it means that we have not completely traversed word1. As a result, we append word1[i] to result.
        3b. If i < n, it means that we have not completely traversed word2. As a result, we append word2[i] to result.
    Return results.

Complexity Analysis
    Here, n is the length of word1 and m is the length of word2.

    Time complexity: O(m+n)

    We iterate over word1 and word2 once pushing their letters into result. It would take O(m+n) time.
    Space complexity: O(1)

    Without considering the space consumed by the input strings (word1 and word2) and the output string (result), we do not use more than constant space.
*/
class Solution_1_pointer
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        string ans = "";
        int i = 0, j = 0;

        for (int i = 0; i < max(n, m); i++)
        {
            if (i < n)
                ans.push_back(word1[i]);
            if (i < m)
                ans.push_back(word2[i]);
        }
        return ans;
    }
};

int main()
{
    string word1 = "abc";
    string word2 = "pqr";

    Solution_2_pointer obj;
    auto ans = obj.mergeAlternately(word1, word2);
    cout << ans << "\n";

    return 0;
}