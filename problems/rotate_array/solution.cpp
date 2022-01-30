class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int  N = nums.size();
        k = k%N;
        if (k==0) return;
        for(int i=0, j = 0, total = 0; i<N && total < N; i++){
            j = i;
            int temp = nums[i];
            do {
                j = (j + k) % N;
                swap(temp,nums[j]);
                total++;
            }while (i!= j);
        }
    }
    void rotate1(vector<int>& nums, int k) {
        int  N= nums.size();
        k = k%N;
        if (k==0) return;
        
        vector<int> t(begin(nums) +N-k, end(nums));
        
        for(int i=N-k-1, j = N-1; i>=0; i--,j--)
            nums[j] = nums[i];
        for(int i=0; i<k;i++)
            nums[i] = t[i];
    }
};