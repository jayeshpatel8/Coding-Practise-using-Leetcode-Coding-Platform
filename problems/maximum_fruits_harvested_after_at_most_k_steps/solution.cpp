class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int pos, int k) {
        auto left = upper_bound(begin(fruits), end(fruits), vector<int>{pos-k});
        int ans=0, sum=0;
        for (auto right = left; right != end(fruits) && (*right)[0]-pos <=k; right++){            
            sum += (*right)[1];
            
            while(min(pos-(*left)[0]+(*right)[0]-(*left)[0], (*right)[0]-pos+(*right)[0]-(*left)[0]) > k)
                sum -= (*left++)[1];
            ans = max(ans, sum);
        }
        return ans;
    }
    /*
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size(), N = fruits[n-1][0];
        vector<int> psum (max(N, startPos+k)+2);
        int j=0;
        for  (auto i : fruits){
            while(j<i[0])
                psum[j + 1] = psum[j],j++;            
            psum[j+1] = psum[j] + i[1];
            j++;
        }
        while (j<startPos+k) psum[j + 1] = psum[j],j++;            
        int l = max(0, startPos-k), r= min(N,startPos+k);
        int ans = max( psum[startPos+1] - psum[l],  psum[r+1] - psum[startPos]);
        
        for(int i=0;i<=k/2;++i) {// to left
            int l=max(0,startPos-i);
            int r=min(N+1,startPos+k-2*i);
            ans=max(ans,psum[r+1] - (l==0? 0 : psum[l]));
            r=min(N+1,startPos+i);
            l=max(0,startPos-(k-2*i));
            ans=max(ans,psum[r+1] - (l==0? 0 : psum[l]));
        }
        return ans;
    }*/
};