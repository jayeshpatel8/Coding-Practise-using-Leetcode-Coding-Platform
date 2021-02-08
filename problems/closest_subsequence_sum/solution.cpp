
class Solution {
public:
    vector<int> subset[2] ;
    vector<int> Arr;
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        Arr=nums;
        subset_sum(subset[0],0, n/2, 0);

        subset_sum(subset[1], n/2, n,0);

        sort(subset[1].begin(), subset[1].end());
        
        int ans = INT_MAX;
        for (int i=0; i< subset[0].size(); i++){
            int sum1 = subset[0][i];
            auto it = upper_bound(subset[1].begin(), subset[1].end(), goal-sum1);
            
            if (it != subset[1].end()){ // higher
                ans = min (ans, abs (goal - sum1 - *(it)));
            }
            if (it != subset[1].begin()){ // same or lower
                ans = min (ans, abs(goal - sum1 - *(--it) ));
            }
        }
        return ans;
    }
    void subset_sum(vector<int>& s, int start, int end, int sum){
       
        if(start>=end) {s.push_back(sum); return;}
        subset_sum(s,start+1,end,sum+Arr[start]);
        subset_sum(s,start+1,end,sum);
    }
};
