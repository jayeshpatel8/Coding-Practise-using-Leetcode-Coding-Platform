class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n =arr.size(), sum = 0;
        for (int i=0; i<n; i++){
            auto l = i, r = n - i - 1;
            sum += arr[i] * ((l/2 +1 ) * (r/2+1));
            sum += arr[i] * (((l+1)/2  ) * ((r+1)/2));
        }
        return sum;
    }
};