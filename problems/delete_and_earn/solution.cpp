class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {        
        vector<int> freq(10001);
        for (auto i: nums)  freq[i]+=i;
        int one_back=freq[1], two_back=0;
        for (int i = 2; i<10001; i++){
            int t = max(one_back, two_back + freq[i]);
            two_back=one_back; one_back = t;
        }
        return one_back;
    }

};