/*
Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

    1. void add(key) Inserts the value key into the HashSet.
    2. bool contains(key) Returns whether the value key exists in the HashSet or not.
    3. void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.

Example 1:

Input
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
Output
[null, null, null, true, false, null, true, null, false]

Explanation
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // return True
myHashSet.contains(3); // return False, (not found)
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // return True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // return False, (already removed)

Constraints:
    0 <= key <= 10^6
    At most 104 calls will be made to add, remove, and contains.
*/

#include <bits/stdc++.h>
using namespace std;

class MyHashSet
{
public:
    bitset<1000001> table;
    MyHashSet()
    {
        table.reset();
    }

    void add(int key)
    {
        table.set(key);
    }

    void remove(int key)
    {
        table.set(key, 0);
    }

    bool contains(int key)
    {
        return table[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */