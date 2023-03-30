/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings.
There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

1. Trie() Initializes the trie object.
2. void insert(String word) Inserts the string word into the trie.
3. boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
4. boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

Example 1:
    Input
    ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
    [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
    Output
    [null, null, true, false, true, null, true]

    Explanation
    Trie trie = new Trie();
    trie.insert("apple");
    trie.search("apple");   // return True
    trie.search("app");     // return False
    trie.startsWith("app"); // return True
    trie.insert("app");
    trie.search("app");     // return True

Constraints:
    1 <= word.length, prefix.length <= 2000
    word and prefix consist only of lowercase English letters.
    At most 3 * 10^4 calls in total will be made to insert, search, and startsWith.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Implement trie (store/retrieve keys in dataset of strings)

    Each node contains pointer to next letter & is word flag

    Time: O(n) insert, O(n) search, O(n) startsWith
    Space: O(n) insert, O(1) search, O(1) startsWith
*/

class Trie
{
public:
    struct TrieNode
    {
        bool isEnd;
        unordered_map<char, TrieNode *> hm;
    };

    TrieNode *root;

    Trie()
    {
        root = getNode();
    }

    TrieNode *getNode()
    {
        TrieNode *node = new TrieNode();
        node->isEnd = false;
        return node;
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); ++i)
        {
            char ch = word[i];
            if (curr->hm.find(ch) == curr->hm.end())
            {
                curr->hm[ch] = getNode();
                curr = curr->hm[ch];
            }
            else
            {
                curr = curr->hm[ch];
            }
        }
        curr->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        if (root == nullptr)
            return false;

        TrieNode *curr = root;
        for (int i = 0; i < word.size(); ++i)
        {
            char ch = word[i];
            if (curr->hm.count(ch) == 0)
                return false;
            curr = curr->hm[ch];
        }
        return curr->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        if (root == nullptr)
            return false;

        TrieNode *curr = root;
        for (int i = 0; i < prefix.size(); ++i)
        {
            char ch = prefix[i];
            if (curr->hm.count(ch) == 0)
                return false;
            curr = curr->hm[ch];
        }
        return true;
    }
};