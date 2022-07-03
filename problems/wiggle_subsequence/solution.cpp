class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int N = nums.size(),  sign[2]={1,1};
        for (int i=1; i<N; i++){
            int diff = nums[i-1] - nums[i] ;
            if (diff != 0){
                bool pos = diff > 0;
                sign[pos] = sign[!pos] + 1;        
            }
        }
        return max(sign[0],sign[1]);
    }    
    /*
    int wiggleMaxLength2(vector<int>& nums) {
        int N = nums.size();
        vector<int> pos(N+1), neg(N+1);
        for (int i=1; i<N; i++){
            int diff = nums[i-1] - nums[i];
            if (diff == 0){
                pos[i] = pos[i-1];
                neg[i] = neg[i-1];
            }
            else if (diff > 0){
                pos[i] = neg[i-1]+1;
                neg[i] = neg[i-1];
            }
            else{
                neg[i] = pos[i-1] + 1;
                pos[i] = pos[i-1];
            }
        }
        return max(pos[N-1],neg[N-1])+1;
    }
    */
};