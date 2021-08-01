// prboelm source: https://leetcode.com/problems/find-median-from-data-stream/
// discussion reference: https://leetcode.com/problems/find-median-from-data-stream/discuss/1358711/C%2B%2B-Code-oror-Max-heap-and-Min-heap
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> max_data; // max -> min
    priority_queue<int, vector<int>, greater<int>> min_data; // min -> max
    MedianFinder() {}

    void addNum(int num) {
        if (max_data.empty() || (!max_data.empty() && num <= max_data.top()))
            max_data.push(num);
        else
            min_data.push(num);
        while (max_data.size() > min_data.size() + 1) {
            int max_top = max_data.top();
            max_data.pop();
            min_data.push(max_top);
        }
        while (min_data.size() > max_data.size() + 1) {
            int min_top = min_data.top();
            min_data.pop();
            max_data.push(min_top);
        }
    }

    double findMedian() {
        priority_queue<int> search_data = max_data;
        priority_queue<int, vector<int>, greater<int>> search_data2 = min_data;
        while (!search_data.empty()) {
            cout << search_data.top() << " ";
            search_data.pop();
        }
        cout << endl;
        while (!search_data2.empty()) {
            cout << search_data2.top() << " ";
            search_data2.pop();
        }
        cout << endl;
        if (max_data.size() == min_data.size()) // even size
            return (max_data.top() + min_data.top()) / 2.0f;
        if (max_data.size() > min_data.size()) // odd size
            return max_data.top();
        return min_data.top(); // odd size
    }


    // Wrong Answer with ["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
    // [[],[1],[3],[],[2],[]]
    // unordered_map<int, int> data;
    // MedianFinder() {}
    //
    // void addNum(int num) { data[data.size()] = num; }
    //
    // double findMedian() {
    //     int data_size = data.size();
    //     vector<pair<int, int>> map_to_vect(data.begin(), data.end());
    //     sort(map_to_vect.begin(), map_to_vect.end());
    //     if (data_size % 2 == 1)
    //         return data[data_size / 2];
    //     else
    //         return (data[data_size / 2 - 1] + data[data_size / 2]) / 2.0f;
    // }

    // Time Limit Exceeded
    // vector<int> data;
    // MedianFinder() {}
    //
    // void addNum(int num) { data.push_back(num); }
    //
    // double findMedian() {
    //     int data_size = data.size();
    //     sort(data.begin(), data.end());
    //     if (data_size % 2 == 1)
    //         return data[data_size / 2];
    //     else
    //         return (data[data_size / 2 - 1] + data[data_size / 2]) / 2.0f;
    // }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
