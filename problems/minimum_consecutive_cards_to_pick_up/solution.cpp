class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
        vector<int> freq(1e6+1);
        int ans = 1e6;
        for (int i=0,j=0;i<cards.size(); i++){
            if (freq[cards[i]]){
                ans = min (ans, i-freq[cards[i]]+2);
                
            }
            freq[cards[i]]=i+1;
        }
        return ans ==1e6 ?-1 : ans;
    }
};