// problem source: https://leetcode.com/problems/insert-delete-getrandom-o1/
// discussion reference: https://o-tantk.github.io/posts/randomized-array/
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int> data;
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it = find(data.begin(), data.end(), val);
        if (it != data.end())
            return false;
        else {
            data.push_back(val);
            return true;
        }
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = find(data.begin(), data.end(), val);
        if (it != data.end()) {
            cout << *it << endl;
            data.erase(it);
            return true;
        } else
            return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int range = data.size();
        int randomIndex = rand() % range;
        return data[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
