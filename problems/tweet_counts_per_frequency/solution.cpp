class TweetCounts {
public:
    unordered_map<string, map<int,int>> map;
    
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        map[tweetName][time]++;    
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int st, int en) {
        int f = freq == "minute" ? 60 : (freq == "hour" ? 3600 : 86400);

        vector<int> ans((en-st) / f + 1);
        auto &t = map[tweetName];
        auto end = t.upper_bound(en);
        for (auto it = t.lower_bound(st);it != end; it++ ){
            int time = it->first;
            if (st <= time && time <=en)
                ans[ (time -st) /f ]+=it->second;
        }
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */