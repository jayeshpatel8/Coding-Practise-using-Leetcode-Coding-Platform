class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        long  j=0;
        if (k==1 || nums.size()<=2)
        {
            for (auto i : nums) j +=i;
            return j;
        }
        int i=0,N=nums.size();
        //j=nums[i];
        for (; i<N; ){
            j+=nums[i];
            
            int next = i+1,l=i+1;
            // [1,-1,-2,4,-7,3], k = 2
            while (l<=i+k && l<N && nums[l]<0) {                            
              if(nums[next] < nums[l])
                next = l;                
              l++;
            }
            
            if (l>i+k){
                if(l>=N || next == N-1) { j+=nums[N-1];break;}
                i =next;                
            }
            else if (l >=N-1){
                j +=nums[N-1]; break;
            }else{
                i=l;
            }            
        }
        return j;
    }
};