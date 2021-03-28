class Solution {
public:
    int reinitializePermutation(int n) {
        int arr[n];
        for (int i=0; i<n; i++) arr[i]=i;
        
        int pos=n/2,cnt=1, mid = n/2;
        while(pos!=1){
            if (pos %2)
                pos  = mid + (pos - 1)/2;
            else 
                pos /=2;
            cnt++;
        }
        return cnt;
    }
};