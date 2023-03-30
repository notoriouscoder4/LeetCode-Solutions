/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

Constraints:
    1 <= haystack.length, needle.length <= 10^4
    haystack and needle consist of only lowercase English characters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    Single hash:
        using a hash function to calculate the hash values of the pattern and the substrings,
        we can quickly compare these values and eliminate substrings that do not match.
        This reduces the number of comparisons needed, making the algorithm faster than the brute-force approach
        eg: helloworld and world.

        world = 22 + 14 + 17 + 11 + 3 = 67
        hello = 7 + 4 + 11 + 11 + 14 = 47
        as they don't match no need to compare.
        The next step dont recompute the hash for entire ellow instead - h + w = 47-7+22= 62

        But using the above formula still leads to more matches hence use a more complicated formula hash = s[0]*p^0 + s[1]*p^1 + s[2]*p^2 + ... + s[n-1]*p^(n-1) where p is prime
    */
    int strStr(string haystack, string needle)
    {
        int n = haystack.length();
        int m = needle.length();
        if (m > n)
            return -1;

        int prime = 31;
        int MOD = 1e9 + 7;
        int needleHash = 0;
        int haystackHash = 0;
        int power = 1;

        // compute hash value of needle(substring)
        for (int i = 0; i < m; i++)
        {
            needleHash = (1LL * needleHash * prime % MOD + needle[i] - 'a' + 1) % MOD;
            haystackHash = (1LL * haystackHash * prime % MOD + haystack[i] - 'a' + 1) % MOD;
            if (i < m - 1)
                power = 1LL * power * prime % MOD;
        }

        // check if needle(subtsring) is found in haystack(string)
        for (int i = 0; i < n - m + 1; i++)
        {
            if (needleHash == haystackHash && haystack.substr(i, m) == needle)
                return i;
            if (i < n - m)
                haystackHash = ((haystackHash - (1LL * (haystack[i] - 'a' + 1) * power % MOD) % MOD + MOD) % MOD * prime % MOD + (haystack[i + m] = 'a' + 1)) % MOD;
        }
        return -1;
    }

    /*
    Intuition of this Problem:
        Using string matching algorithm - Knuth Morris Pratt

    Approach for this Problem:
    1. Initialize variables n and m to store the lengths of the input strings haystack and needle respectively.
    2. If the length of the needle is 0, return 0.
    3. Initialize a vector pi of length m to store the prefix function values.
    4. Initialize variables j and i to 0 and 1 respectively.
    5. Iterate through the needle string from index 1 to m-1.
    6. If needle[j] is not equal to needle[i] and j is greater than 0, set j to pi[j-1].
    7. If needle[j] is equal to needle[i], increment j by 1.
    8. Set pi[i] to the value of j.
    9. Initialize variable j to 0.
    10. Iterate through the haystack string from index 0 to n-1.
    11. If needle[j] is not equal to haystack[i] and j is greater than 0, set j to pi[j-1].
    12. If needle[j] is equal to haystack[i], increment j by 1.
    13. If j is equal to m, return i-m+1.
    14. Return -1 as no match has been found.
    */

    /*
    Time Complexity and Space Complexity:
        Time complexity: O(n+m), where n is the length of the text and m is the length of the pattern. 
        This is because we perform a linear scan of the text and the pattern, and the time spent computing the pi array is also O(m).
        
        Space complexity: O(m), as we need to store the pi array, which has length m.
    */
    int strStr(string haystack, string needle)
    {
        int n = haystack.length();
        int m = needle.length();
        if (m == 0)
            return 0;
        // In the KMP algorithm, the pi vector (short for prefix function) is used to store the length of the longest proper prefix of the pattern (needle) that is also a suffix of a substring of the pattern.

        // The purpose of the pi vector is to avoid unnecessary comparisons when searching for the pattern in the text (haystack).
        // When a mismatch occurs between the pattern and the text, the pi vector tells us the length of the longest prefix of the pattern that matches a suffix of the pattern up to the mismatch position.
        // We can then shift the pattern to the right by this length and continue the search from there instead of starting over from the beginning of the pattern.

        // For example, consider the pattern ABCDABD. If we have matched the first four characters ABCD with the text but the next character in the text is X, which does not match the next character A in the pattern, we can shift the pattern to the right by pi[3] = 0 characters and start comparing the next character in the text with the first character A in the shifted pattern (DABD).
        // Without the pi vector, we would have to start over from the beginning of the pattern (ABCDABD).
        vector<int> pi(m);
        pi[0] = 0;
        int j = 0;
        for (int i = 1; i < m; i++)
        {
            // while (j > 0 && needle[j] != needle[i]) { j = pi[j - 1]; }: This statement is used to update the value of j (the length of the longest proper prefix of the pattern that is also a suffix of a substring of the pattern) when a mismatch is found between the characters of the pattern at positions j and i.
            // The idea here is to use the pi values computed so far to find the longest proper prefix of the pattern that is also a suffix of a substring of the pattern that matches the characters of the pattern up to position i.
            // We do this by using the value of pi[j-1], which represents the length of the longest proper prefix of the pattern that is also a suffix of a substring of the pattern up to position j-1.
            // We update j to this value and continue the loop until we find a proper prefix that matches a suffix of the pattern up to position i or we reach the beginning of the pattern (j = 0).
            while (j > 0 && needle[j] != needle[i])
            {
                j = pi[j - 1];
            }
            // if (needle[j] == needle[i]) { j++; }: This statement is used to update the value of j when a match is found between the characters of the pattern at positions j and i.
            // If the characters match, we increment j by 1, indicating that we have found a new character that matches the longest proper prefix of the pattern that is also a suffix of a substring of the pattern up to position i.
            if (needle[j] == needle[i])
            {
                j++;
            }
            // pi[i] = j;: This statement is used to store the value of j in the pi vector at position i. This represents the length of the longest proper prefix of the pattern that is also a suffix of a substring of the pattern up to position i.
            // By computing the pi vector in this way, we can use it in the KMP algorithm to avoid unnecessary comparisons when searching for the pattern in the text.
            pi[i] = j;
        }
        j = 0;
        for (int i = 0; i < n; i++)
        {
            // while (j > 0 && needle[j] != haystack[i]) { j = pi[j - 1]; }: This statement is used to update the value of j (the length of the longest proper prefix of the pattern that is also a suffix of a substring of the pattern) when a mismatch is found between the characters of the pattern and the text.
            // This works similarly to the prefix function algorithm used to compute the pi vector, as explained in my previous answer.
            // We use the pi values computed so far to find the longest proper prefix of the pattern that is also a suffix of a substring of the pattern that matches the characters of the text up to position i.
            // If a mismatch is found between the characters of the pattern and the text at position j and i, we update j to the pi value at position j-1 and continue the loop until we find a proper prefix that matches a suffix of the pattern up to position i or we reach the beginning of the pattern (j = 0).

            while (j > 0 && needle[j] != haystack[i])
            {
                j = pi[j - 1];
            }
            // if (needle[j] == haystack[i]) { j++; }: This statement is used to update the value of j when a match is found between the characters of the pattern and the text.
            // If the characters match, we increment j by 1, indicating that we have found a new character that matches the longest proper prefix of the pattern that is also a suffix of a substring of the pattern up to position i.
            if (needle[j] == haystack[i])
            {
                j++;
            }
            // if (j == m) { return i - m + 1; }: This statement is used to check if we have found a complete match of the pattern in the text.
            // If j is equal to the length of the pattern m, then we have found a complete match, and we return the starting index of the match in the text (i - m + 1).
            if (j == m)
            {
                return i - m + 1;
            }
        }
        return -1;
    }
};