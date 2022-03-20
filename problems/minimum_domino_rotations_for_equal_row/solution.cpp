class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int t[7] = {} , b[7]={};
        for (auto &i : tops) t[i]++;
        for (auto &i : bottoms) b[i]++;
        int ans=-1,sz = tops.size();
        for (int i=1 ; i<7; i++){
            if (t[i] == sz || b[i] == sz) return 0;
            
            if (t[i] + b[i] >= sz){
                int cnt1=0 ,cnt2=0, done=1;
                for (int j=0; j<sz; j++){
                    if (tops[j] != i && bottoms[j] != i){
                        done=0;break;
                    }
                    if (tops[j] == i ) cnt1++;
                    if (bottoms[j] == i ) cnt2++;
                }
                if (done) ans = max({ans, cnt1,cnt2});
            }
        }   
        return ans ==-1? -1: sz-ans;
    }
};