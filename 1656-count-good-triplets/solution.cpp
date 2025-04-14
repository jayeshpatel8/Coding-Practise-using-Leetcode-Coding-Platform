class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int ans = 0;
        for (int i=0, N=arr.size(); i<N; i++){
            for (int j=i+1; j<N; j++){
                for (int k=j+1; k<N; k++){
                    if (abs(arr[i]-arr[j]) <=a && abs(arr[i]-arr[k]) <=c && abs(arr[k]-arr[j]) <=b)
                        ans++;
                }
            }
        }
        return ans;
    }
};
