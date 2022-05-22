class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rocks, int arocks) {
        long long sum = 0;
        for (int i=0; i<cap.size(); i++){
            cap[i] -= rocks[i];
            sum +=cap[i];
    
        }
    
        if (arocks >= sum) return rocks.size();
        sort(begin(cap), end(cap));
        int ans = 0;
        for (int i=0; i<cap.size() && arocks >0; i++){
            if (cap[i] >= 0){
                if (cap[i] <= arocks){
                    arocks -= cap[i];
                    ans++;
                }
                else{
                    break;
                    arocks = 0;
                }
            }                          
        }
        return ans;
    }
};