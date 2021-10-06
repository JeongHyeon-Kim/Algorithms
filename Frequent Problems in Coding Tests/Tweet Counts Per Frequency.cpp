// problem source: https://leetcode.com/problems/tweet-counts-per-frequency/
class TweetCounts {
public:
    vector<int> result;
    vector<pair<string, int>> recording;
    TweetCounts() { }

    void recordTweet(string tweetName, int time) {
        recording.push_back(make_pair(tweetName, time));
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int recording_size = recording.size();
        int middle_solution[10001] = {0, };
        int chunk_unit = 0;
        result.clear();

        for (int i = 0; i < recording_size; i++) {
            if (recording[i].first == tweetName) {
                if (freq == "minute")
                    chunk_unit = 59;
                else if (freq == "hour")
                    chunk_unit = 3599;
                else // freq == "day"
                    chunk_unit = 86399;
                if (recording[i].second >= startTime && recording[i].second <= endTime)
                    middle_solution[recording[i].second / chunk_unit]++;
            }
        }

        cout << startTime << " " << endTime << endl;
        int count = 0;
        for (int i = startTime; i <= endTime; i += chunk_unit) {
            if (middle_solution[i / chunk_unit] != 0)
                result.push_back(middle_solution[i / chunk_unit]);
            else
                result.push_back(0);
            count++;
        }
        cout << count << endl;
        return result;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
