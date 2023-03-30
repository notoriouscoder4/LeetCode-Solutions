/*
Implement the RandomizedSet class:

    1. RandomizedSet() Initializes the RandomizedSet object.
    2. bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
    3. bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
    4. int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called).
    Each element must have the same probability of being returned.

You must implement the functions of the class such that each function works in average O(1) time complexity.

Example 1:
Input
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
Output
[null, true, false, true, 2, true, false, 2]

Explanation
RandomizedSet randomizedSet = new RandomizedSet();
randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
randomizedSet.insert(2); // 2 was already in the set, so return false.
randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.

Constraints:
    -2^31 <= val <= 2^31 - 1
    At most 2 * 105 calls will be made to insert, remove, and getRandom.
    There will be at least one element in the data structure when getRandom is called.
*/

#include <bits/stdc++.h>
using namespace std;

class RandomizedSet
{
public:
    // Unordered Map does searching, insertion & deletion of element in average O(1) time
    // mp has num val as key and index of val in arr as value
    unordered_map<int, int> mp;

    // store the val in array, for finding random number in O(1)
    vector<int> arr;

    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        // if val has already present in map
        if (mp.count(val))
            return false;

        // if val is not present in map, push val in arr
        arr.push_back(val);

        // push val in map
        mp[val] = arr.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        // if val is present in map
        if (mp.count(val))
        {
            // find the index of val from map
            int idx = mp[val];

            // find the last value from array
            int last_val = arr.back();

            // put the last_val at idx
            arr[idx] = last_val;

            // remove the last element from array
            arr.pop_back();

            // update the value of last_val in map
            mp[last_val] = idx;

            // remove the val from map
            mp.erase(val);

            return true;
        }
        return false;
    }

    int getRandom()
    {
        // generate the random number from (0 to arr.size() - 1)
        int rand_idx = rand() % arr.size();
        return arr[rand_idx];
    }
};