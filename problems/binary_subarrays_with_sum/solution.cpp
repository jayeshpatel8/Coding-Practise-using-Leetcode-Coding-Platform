class Solution {
public:
    int numSubarraysWithSum2(vector<int>& A, int goal) {
        int ans = 0,i=0,j=0,sum=0;
        unordered_map<int,int> map= {{0,1}};
        vector<int> psum(A.size()+1);
        for (; i<A.size(); i++){
            psum[i+1] +=A[i] + psum[i];
        }
        for (int i=0; i<A.size(); i++){
            ans += map[psum[i+1]-goal];
            map[psum[i+1]]++;
        }
        
        return ans;
    }
    int numSubarraysWithSum(vector<int>& A, int goal) {
        int ans = 0,i=0,j=0,sum=0;

        for (int zeros=0; i<A.size(); i++){
            sum += A[i];
            if (sum > goal){
                zeros=0;
                while (i> j && sum > goal ) sum -=A[j++];
            }
            if(sum ==  goal){
                ans++;
                while (j<i &&  A[j]==0) zeros++,j++;
                ans+=zeros;
                
            }            
            
                
        }
        
        return ans;
    }
};