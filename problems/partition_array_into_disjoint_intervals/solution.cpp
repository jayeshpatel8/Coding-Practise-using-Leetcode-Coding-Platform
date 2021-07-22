class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int N =  nums.size(), leftmax, curmax, index=0;
        leftmax = curmax = nums[0];
        
        for (int i=1; i< N; i++){
            curmax  = max( curmax ,nums[i]);
            if (leftmax > nums[i])
                index = i, leftmax=curmax;            
        }
        return index + 1;
    }
/*
int partitionDisjoint(vector<int>& nums) {
        int N =  nums.size();
        int nmax[N+1], nmin[N+1];
        nmax[0]=nums[0];
        for ( int i=1; i< N; i++)
            nmax[i]  = max(nmax[i-1],nums[i]);
        nmin[N-1] = INT_MAX;
        for ( int i= N-2; i>=0; i--)
            nmin[i] = min(nmin[i+1],nums[i+1]);
        for ( int i=0; i< N; i++)
            if (nmax[i] <= nmin[i]) return i+1; 
        return 1;
    }
*/
};