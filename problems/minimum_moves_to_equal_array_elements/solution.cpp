class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        long N= nums.size();
        // m = moves , x  = final equal number , N = nums.size()
        // sum - m * (N-1) = x * N
        // x = minNum + m
        //  sum - m * (N-1) = (minNum + m) * N
        // m = sum - minNum * N 
        long sum = accumulate(begin(nums),end(nums),0) ;
        return sum - *min_element(begin(nums),end(nums)) * N;
    }
    int minMoves2(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int N= nums.size();
        long ans = 0, start = nums[0] ;
        for (int i=0, j = N-1; i<j; j--){
            
            while (i<j && start == nums[i+1]) i++;
            if (i >= j ) break;
            long diff = (nums[j] + ans) - start;
            start +=  diff;
            ans += diff;            
        }
        return ans;
    }
};