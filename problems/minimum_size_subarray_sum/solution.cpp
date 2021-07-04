class Solution {
public:
    int minSubArrayLen(int T, vector<int>& A) {
        int len=INT_MAX,sum=0;
        for (int i=0,j=0; j<A.size(); j++){
            sum+=A[j];
            
            while(i<=j && sum >= T){
                len = min(len,j-i+1);
                sum-= A[i++];
            }
        }
        return len==INT_MAX ? 0 : len;
    }
};