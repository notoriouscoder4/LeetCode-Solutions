/*
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

1. WordDictionary() Initializes the object.
2. void addWord(word) Adds word to the data structure, it can be matched later.
3. bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise.
word may contain dots '.' where dots can be matched with any letter.

Example:
    Input
    ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
    [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
    Output
    [null,null,null,null,false,true,true,true]

    Explanation
    WordDictionary wordDictionary = new WordDictionary();
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    wordDictionary.search("pad"); // return False
    wordDictionary.search("bad"); // return True
    wordDictionary.search(".ad"); // return True
    wordDictionary.search("b.."); // return True

Constraints:
    1 <= word.length <= 25
    word in addWord consists of lowercase English letters.
    word in search consist of '.' or lowercase English letters.
    There will be at most 3 dots in word for search queries.
    At most 104 calls will be made to addWord and search.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Design add & search words data structure

    Implement trie, handle wildcards: traverse all children & search substrings

    Time: O(m x 26^n) -> m = # of words, n = length of words
    Space: O(n)
*/

class TrieNode
{
public:
    TrieNode *children[26];
    bool isEnd;

    TrieNode()
    {
        // for (int i = 0; i < 26; ++i)
        // {
        //     children[i] = NULL;
        // }
        memset(children, NULL, sizeof(children));
        isEnd = false;
    }
};

class WordDictionary
{
public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
    {
        TrieNode *node = root;
        int curr = 0;

        for (int i = 0; i < word.size(); ++i)
        {
            curr = word[i] - 'a';
            if (node->children[curr] == NULL)
            {
                node->children[curr] = new TrieNode();
            }
            node = node->children[curr];
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        TrieNode *node = root;
        return searchInNode(word.c_str(), node);
    }

    bool searchInNode(const char *word, TrieNode *node)
    {
        for (int i = 0; word[i] && node; i++)
        {
            if (word[i] != '.')
            {
                node = node->children[word[i] - 'a'];
            }
            else
            {
                TrieNode *tmp = node;
                for (int j = 0; j < 26; j++)
                {
                    node = tmp->children[j];
                    if (searchInNode(word + i + 1, node))
                    {
                        return true;
                    }
                }
            }
        }
        return node && node->isEnd;
    }

private:
    TrieNode *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */