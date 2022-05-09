class Solution {
public:

    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> pq;
        int k = nums.size();
        vector<int> size(k);
        int max_ = INT_MIN;
        int d = INT_MAX, start=-1;
        for (int i=0; i<k; i++){
            pq.push({nums[i][0],i,0});
            max_ =max(max_ , nums[i][0]);
            size[i] = nums[i].size();           
        }
        while (1){
            auto [s,i,j] = pq.top(); pq.pop();
            int dist =  max_ - s ;

            if (dist < d)
                d = dist, start = s;
            else if(d== dist && start>s)
                    start= s;
            if (++j >= size[i] ) break;
            max_ =max(max_ , nums[i][j]);
            pq.push({nums[i][j], i, j});
        }
        return {start, start+d};
    }
};