class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n);
        // k=2 n =5
        // 1,5,4,3,2
        // k=3 n=5
        // 1,5,2,3,4
        int l=0,  i=1,j=n;
        while (l < k){
            ans[l++] = (l%2 == 0 ) ? i + l/2 : n - (l/2);
           // if (l & 1) ans[l++]=j--;
            //else ans[l++]=i++;
        }
        
        i = ans[l-1];
        if (l & 1){
            while(l<n)       ans[l++]=++i;            
        }
        else
            while(l<n)       ans[l++]=--i;            
        return ans;
    }
};