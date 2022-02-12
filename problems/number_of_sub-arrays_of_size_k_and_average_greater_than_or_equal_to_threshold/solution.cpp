class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int th) {
        int sum=0, asum = k* th, ans=  0;
        for (int i=0,K=k-1;i<arr.size(); i++){
            sum += arr[i];
            if (i>=K){
                ans+=(sum>= asum);
                sum -=arr[i-K];
            }
        }
        return ans;
    }
};