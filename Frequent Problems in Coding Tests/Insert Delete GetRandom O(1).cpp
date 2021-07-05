// problem source: https://leetcode.com/problems/insert-delete-getrandom-o1/
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int> data;
    RandomizedSet() {
        // vector or map?
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        data.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = std::remove(data.begin(), data.end(), val);
        data.resize(it - data.begin());
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return 0;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
