class Solution {
public:
    string minWindow(string s, string t) {
         int sz = s.size(), st = t.size();
        if (sz< st) return  "";
        int map[128]={}, start=-1,d=INT_MAX;
        for (auto c : t)  map[c]++;

        for (int l=0,r=0,cnt=st;  r<sz; r++){
            auto c = s[r];
            map[c]--;
            if (map[c] >= 0 ) cnt--;
            while (cnt==0 && l<=r){
                if (d > r-l+1){ d = r-l+1, start = l;}
                map[s[l]]++;
                if (map[s[l++]] > 0) cnt++;
            }
        }
        return start==-1? "" : s.substr(start,d);
    } 
};
