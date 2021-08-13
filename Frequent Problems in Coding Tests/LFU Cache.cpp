// problem source: https://leetcode.com/problems/lfu-cache/
// discussion reference: https://stackoverflow.com/questions/9370945/c-help-finding-the-max-value-in-a-map
class LFUCache { // LFU = LFU + LRU (same with count)
public:
    unordered_map<int, int> data;
    unordered_map<int, int> count;
    int cap;
    LFUCache(int capacity) {
        data.clear();
        count.clear();
        cap = capacity;
    }

    int get(int key) {
        count[key]++;
        return data[key];
    }

    void put(int key, int value) {
        if(cap > 0) {
            cap--;
            count[key]++;
            data[key] = value;
        } else if (cap == 0) {
            cout << "exceed" << endl;
            unordered_map<int, int>::iterator max_elem = std::max_element(count.begin(), count.end(), [] (const pair<int, int>& a, const pair<int, int>& b)->bool{ return a.second < b.second; } );
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
