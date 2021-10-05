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
                    chunk_unit = 60;
                else if (freq == "hour")
                    chunk_unit = 3600;
                else // freq == "day"
                    chunk_unit = 864000;


                for (int j = startTime; j <= endTime; j += chunk_unit) {
                    if (recording[i].second >= startTime && recording[i].second <= endTime)
                        middle_solution[j / chunk_unit]++;
                }
            }
        }
        for (int i = startTime; i <= endTime; i += chunk_unit) {
            if (middle_solution[i / chunk_unit] != 0)
                result.push_back(middle_solution[i]);
            else
                result.push_back(0);
        }
        // for (int i = 0; i < 10001; i++) {
        //     if (middle_solution[i] != 0)
        //         result.push_back(middle_solution[i]);
        // }
        // if (result.empty())
        //     result.push_back(0);
        return result;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
