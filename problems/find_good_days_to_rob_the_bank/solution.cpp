class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& sec, int time) {
        int N = sec.size();
        vector<int> inc(N,1),dec(N,1),ans;
        for (int i=1; i<N; i++){
            if(sec[i-1] >= sec[i])
                inc[i] += inc[i-1];
        }
        for (int i=N-2; i>=0; i--){
            if(sec[i] <= sec[i+1])
                dec[i] += dec[i+1];
        }      
        for (int i=time; i<N-time; i++){
            
            if (inc[i]>time && dec[i]>time)
                ans.push_back(i);
        }
        return ans;
    }
};