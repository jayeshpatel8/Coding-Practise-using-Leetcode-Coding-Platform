class Solution {
public:
    int N;
    int splitArray(vector<int>& nums, int m) {
        int l= *max_element(begin(nums), end(nums));
         N= nums.size();
        if (m == N) return l;
        int r = accumulate(begin(nums), end(nums),0);   
        while (l<r){
            int mid = l +(r-l)/2;
            if (partition(nums,mid,m)  )
                r=mid;
            else 
                l=mid+1;
        }
        return l;
    }
    bool partition(vector<int>& nums, int size, int m){
        int i=0, sum=0;
        while (m > 0){
            m--,sum=0;
            while (i < N && sum + nums[i] <= size)
                sum += nums[i++];
        }
        return i == N;
    }
   
};