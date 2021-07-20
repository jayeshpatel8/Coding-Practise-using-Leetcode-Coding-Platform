class Solution {
    vector<int> A;
    int N;

public:
    Solution(vector<int>& nums) {
        A = nums;
        N  = A.size();       
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {        
        return A;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> B(A);
        for (int i=N-1; i>=0; i--){
            int  j = (rand())%(i+1);
            swap(B[i],B[j]);     
        }      
       
        return B;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */