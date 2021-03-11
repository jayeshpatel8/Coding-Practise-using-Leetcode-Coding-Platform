class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long sum =0;
        for (auto i : nums) sum +=i;
        int cnt=0;
        long d =abs(goal - sum);
        while(d !=0){
            
            if (d>= limit){
                 cnt += d/limit;
                 d = d%limit;
            }
            else{
                cnt++;
                break;
            }
        }
        return cnt;
    }
};