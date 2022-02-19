class Solution {
public:
    vector<long long> maximumEvenSplit(long long cur) {
        if (cur & 1) return {};
        vector<long long> ans;
        
        long long i=2;
        for (; cur>i; i+=2){
            cur-=i;
            ans.push_back(i);
        }
        if (cur == i) ans.push_back(i);
        else
            ans.back() +=cur;
        return  ans;
    }
};