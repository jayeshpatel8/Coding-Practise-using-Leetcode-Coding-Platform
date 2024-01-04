class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> f;
        for (auto i : nums) f[i]++;
        int ans=0;
        for (auto &[k,v] : f){
            if (v %3 == 0 ) ans += v/3;
            else{
                if (v>2 && ((v-2)%3 == 0)){
                    ans += 1 + (v-2)/3;
                }
                else if (v > 4 && ((v-4)%3 == 0)){
                    ans += 2 + (v-4)/3;
                }
                else if (v <5){
                    if (v==1) return -1;
                    else ans += v/2;
                }
                else return -1;
            }
        }
        return ans;
    }
};
