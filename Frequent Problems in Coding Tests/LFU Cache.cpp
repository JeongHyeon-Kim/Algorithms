// problem source: https://leetcode.com/problems/lfu-cache/
// discussion reference: https://stackoverflow.com/questions/9370945/c-help-finding-the-max-value-in-a-map
// discussion reference2: https://leetcode.com/problems/lfu-cache/discuss/1302793/C%2B%2B-or-Using-Maps
class LFUCache { // LFU = LFU + LRU (same with count)
public:
    struct KeyInfo {
        int value;
        int frequency;
        list<int>::iterator position;
    };

    map<int, KeyInfo> data;
    map<int, list<int>> key_frequency;
    int cap;
    int minimal_frequency;

    LFUCache(int capacity) {
        data.clear();
        key_frequency.clear();
        cap = capacity;
    }

    void update_frequency(int key) {
        key_frequency[data[key].frequency].erase(data[key].position);

        if (key_frequency[data[key].frequency].empty()) { // empty, size() == 0
            key_frequency.erase(data[key].frequency);
            if (data[key]. frequency == minimal_frequency)
                minimal_frequency++;
        }

        data[key].frequency++;
        key_frequency[data[key].frequency].push_back(key); // list insert
        data[key].position = prev(key_frequency[data[key].frequency].end()); // last
    }

    int get(int key) {
        if (data.find(key) == data.end()) return -1;
        update_frequency(key);
        return data[key].value; // KeyInfo's value
    }

    void put(int key, int value) {
        if (cap == 0) return;
        auto it = data.find(key);

        if (it == data.end()) { // not found
            if (data.size() == cap) { // reached full
                data.erase(key_frequency[minimal_frequency].front());
                key_frequency[minimal_frequency].pop_front();

                if (minimal_frequency != 1 && key_frequency[minimal_frequency].empty())
                    key_frequency.erase(minimal_frequency);
            }
            KeyInfo information;
            information.value = value;
            information.frequency = 1;
            data[key] = information;
            key_frequency[information.frequency].push_back(key);
            data[key].position = prev(key_frequency[information.frequency].end());
            minimal_frequency = 1;
        } else {
            data[key].value = value;
            update_frequency(key);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
