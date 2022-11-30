class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = start , next=ans;
        for (int i=1; i<n; i++){
            ans ^= (next+= 2);
        }
        return ans;
    }
};