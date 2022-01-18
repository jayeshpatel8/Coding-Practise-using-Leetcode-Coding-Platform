class Solution {
public:
    char slowestKey(vector<int>& rt, string kp) {
        int t[26]={0};
        t[kp[0]-'a']=rt[0];
        for (int i=1;i<rt.size(); i++){
            t[kp[i]-'a']=max(t[kp[i]-'a'], rt[i]-rt[i-1]);
        }
        int m =0, a;
        for ( int i=0; i<26; i++){            
            if (m <= t[i] ) m = t[i], a = i;
        }

        return 'a'+a;
    }
};