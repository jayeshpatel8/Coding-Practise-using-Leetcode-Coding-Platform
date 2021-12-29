class Solution {
public:
    bool isSelfCrossing(vector<int>& d) {


        d.insert(begin(d),4,0);
        int l=d.size();
        int i=4;
        // check outer spiral
        for (; i<l && d[i] > d[i-2]; i++) ;
            
        if (i==l) return false;
        
        if (d[i] >= d[i-2]-d[i-4])
            d[i-1]-=d[i-3];
        for (++i; i<l && d[i] < d[i-2]; i++);
        return i != l;
        
    }
};