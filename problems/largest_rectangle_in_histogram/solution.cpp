class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
                
        int res=0, n = heights.size();
        if (n == 0) return 0;
        vector<int> L(n);
        vector<int> R(n);
        R[n-1]=n; L[0]=-1;
        for (int i=n-2; i>=0; i--){
            int next=i+1;
            while (next<n && heights[next]>=heights[i]) 
                next = R[next];
            R[i]=next;
        }        
        for (int i=1; i<n; i++){
            int next=i-1;
            while (next>=0 && heights[next]>=heights[i]) 
                next = L[next];
            L[i]=next;
            res = max( res, (R[i]-L[i] - 1)*heights[i]);
        }

        res = max( res, (R[0]-L[0] - 1)*heights[0]);
        return res;
    }
};