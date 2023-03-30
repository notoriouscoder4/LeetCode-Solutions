/*
RandomizedCollection is a data structure that contains a collection of numbers, possibly duplicates (i.e., a multiset).
It should support inserting and removing specific elements and also removing a random element.

Implement the RandomizedCollection class:

    1. RandomizedCollection() Initializes the empty RandomizedCollection object.
    2. bool insert(int val) Inserts an item val into the multiset, even if the item is already present. Returns true if the item is not present, false otherwise.
    3. bool remove(int val) Removes an item val from the multiset if present. Returns true if the item is present, false otherwise.
    Note that if val has multiple occurrences in the multiset, we only remove one of them.
    4. int getRandom() Returns a random element from the current multiset of elements.
    The probability of each element being returned is linearly related to the number of same values the multiset contains.

You must implement the functions of the class such that each function works on average O(1) time complexity.

Note: The test cases are generated such that getRandom will only be called if there is at least one item in the RandomizedCollection.

Example 1:
Input
["RandomizedCollection", "insert", "insert", "insert", "getRandom", "remove", "getRandom"]
[[], [1], [1], [2], [], [1], []]
Output
[null, true, false, true, 2, true, 1]

Explanation
RandomizedCollection randomizedCollection = new RandomizedCollection();
randomizedCollection.insert(1);   // return true since the collection does not contain 1.
                                  // Inserts 1 into the collection.
randomizedCollection.insert(1);   // return false since the collection contains 1.
                                  // Inserts another 1 into the collection. Collection now contains [1,1].
randomizedCollection.insert(2);   // return true since the collection does not contain 2.
                                  // Inserts 2 into the collection. Collection now contains [1,1,2].
randomizedCollection.getRandom(); // getRandom should:
                                  // - return 1 with probability 2/3, or
                                  // - return 2 with probability 1/3.
randomizedCollection.remove(1);   // return true since the collection contains 1.
                                  // Removes 1 from the collection. Collection now contains [1,2].
randomizedCollection.getRandom(); // getRandom should return 1 or 2, both equally likely.


Constraints:
    -2^31 <= val <= 2^31 - 1
    At most 2 * 105 calls in total will be made to insert, remove, and getRandom.
    There will be at least one element in the data structure when getRandom is called.
*/

#include <bits/stdc++.h>
using namespace std;

class RandomizedCollection
{
public:
    // Unordered Map does searching, insertion & deletion of element in average O(1) time
    // mp has num val as key and index of val in arr as value
    unordered_map<int, int> mp;

    // store the val in array, for finding random number in O(1)
    vector<int> arr;

    RandomizedCollection()
    {
    }

    bool insert(int val)
    {
        if (mp[val] == 0) // the element is not present yet in the vector or map
        {
            arr.push_back(val);
            mp[val]++; // due to the reason of duplicate
            return true;
        }
        else if (mp[val] > 0) // it is present in the vector or mp
        {
            arr.push_back(val);
            mp[val]++;
            return false;
        }
        return false; // this will not get encounterd
    }

    bool remove(int val)
    {
        if (mp[val] > 0) // the element is present
        {
            auto it = find(arr.begin(), arr.end(), val);
            arr.erase(it);
            mp[val]--;
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