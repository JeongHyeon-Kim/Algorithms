// problem source: https://leetcode.com/problems/time-based-key-value-store/
class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<unordered_map<string, string>, int time> data;
    int time_stamp = 0;
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        unordered_map<string, string> temp;
        temp[key] = value;
        data[temp] = timestamp;
    }

    string get(string key, int timestamp) {

    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
