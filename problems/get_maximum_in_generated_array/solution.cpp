class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n<=2) return n!= 0;
        int arr[101]={} , ans = 1;
        arr[1]=1;
        for (int j=2, f= 1; j<=n;f++ ){
            arr[j++] = arr[f];
            if (j<=n)
                arr[j++] = arr[f]+arr[f+1];
            ans = max({ans,arr[j-2],arr[j-1]});
        }
        return ans;
    }
};