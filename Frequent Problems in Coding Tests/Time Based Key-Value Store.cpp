// problem source: https://leetcode.com/problems/time-based-key-value-store/
class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<int, unordered_map<string, string>> data;
    int time_stamp = 0;
    int last_time = 0;
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        unordered_map<string, string> temp;
        temp[key] = value;
        data[timestamp] = temp;
        last_time = timestamp;
    }

    string get(string key, int timestamp) {
        bool not_found = true;
        unordered_map<string, string> temp;
        for (auto it = data.begin(); it != data.end(); it++) {
            if (it->first == timestamp) {
                temp = it->second;
                not_found = false;
            }
        }
        if (not_found) {
            temp = data[last_time];
            return temp[key];
        } else
            return temp[key];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
