/*

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    struct TrieNode
    {
        /* isEndOfWord is true if the node represents end of a word */
        bool isEndOfWord;

        /* nodes store a map to child node */
        TrieNode *children[26];

        TrieNode()
        {
            for (int i = 0; i < 26; ++i)
                children[i] = NULL;
            isEndOfWord = false;
        }
    };

    // Function to insert new words in trie
    void addWord(const string &word, TrieNode *root)
    {
        TrieNode *temp = root;

        for (int i = 0; i < word.length(); ++i)
        {
            int idx = word[i] - 'a';
            if (temp->children[idx] == NULL)
                temp->children[idx] = new TrieNode;

            temp = temp->children[idx];
        }
        temp->isEndOfWord = true;
    }
    /*function to search in trie*/
    bool wordPresent(string word, TrieNode *root, int index, int count)
    {
        if (index >= word.length())
            return count > 1;

        TrieNode *current = root;
        for (int i = index; i < word.length(); ++i)
        {
            int idx = word[i] - 'a';
            if (current->children[idx] == NULL)
                return false;

            current = current->children[idx];

            if (current->isEndOfWord)
            {
                if (wordPresent(word, root, i + 1, count + 1))
                    return true;
            }
        }
        return false;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        TrieNode *root = new TrieNode;
        for (int i = 0; i < words.size(); ++i)
            addWord(words[i], root);

        vector<string> ans;
        for (string &word : words)
        {
            /* find if word is present or not, if yes then add in the answer*/
            if (wordPresent(word, root, 0, 0))
                ans.push_back(word);
        }
        return ans;
    }
};