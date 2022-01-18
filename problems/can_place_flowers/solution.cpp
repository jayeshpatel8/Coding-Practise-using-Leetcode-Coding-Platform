class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int i=0, prev = 0,  next, cur=f[0];
        for ( ; n && i<f.size()-1; i++){
            next = f[i+1];
            if (!cur && !prev && !next)
                n--, cur=1;
            prev=cur; cur=next;
        }
        if (n && prev==0 && cur==0) n--;
        return n == 0;
    }
};