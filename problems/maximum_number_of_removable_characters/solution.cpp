class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& remv) {
       vector<int> map(s.size(), INT_MAX);
        for (int i = 0; i<remv.size(); i++)
        {            
            map[remv[i]] = i;
        }
        
        int l = 0, r = remv.size()-1, m, ans=-1;
        int psize = p.size(), ssize = s.size();
        while(l <= r){
            m = (l + r) /2;
            int i=0,j=0;
            for (; i<ssize && j<psize; i++){
                if (map[i] > m && s[i] == p[j]) j++;
            }
            if (j ==psize) {l = m + 1; ans = m;}
            else r = m - 1;
        }
        return r+1;
    }
};