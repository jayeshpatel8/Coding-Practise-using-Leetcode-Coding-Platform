class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>s.size()/2) return false;
        const int mask = (1 << k)-1;
        bool bnum[1<<k];
        for (int i=0; i<1<<k; i++) bnum[i]=0;
        int num = stoi(s.substr(0,k),0,2);        
        bnum[num]=true;
        for (int i=k; i< s.size(); i++)
            bnum[num = ((num << 1 ) & mask) + (s[i]-'0') ]=true;
        
        for (int i=0; i<1<<k; i++) 
            if (bnum[i]==0) return false;
        
        return true;
    }
};