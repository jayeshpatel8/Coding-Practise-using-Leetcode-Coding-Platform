class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        // [1,0,0,1,0,1], k = 2
        vector<int> iA;
        // index array [0,3,5]
        for (int i=0; i<nums.size(); i++) 
            if (nums[i]) iA.push_back(i);
        vector<long> pSum={0};
        int N = iA.size();
        // prefix Sum of iA [0,0,3,8]
        for (auto i : iA){
            pSum.push_back(i+pSum.back());
        }
        long res=INT_MAX;
        for (int i=k/2; i<N-(k-1)/2; i++){
            int n=k/2;
            long before = iA[i]*n - (pSum[i] - pSum[i-n]) - n*(n+1)/2;
            n=(k-1)/2;
            long after = (pSum[i+1+n] - pSum[i+1]) - iA[i]*n - n*(n+1)/2;
            res = min(res,before+after);
        }
        return res;
    }
};