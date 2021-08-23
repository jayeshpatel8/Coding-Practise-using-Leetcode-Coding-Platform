class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> s;
        for (auto i :  nums)
            s.insert(i);
                   
        for ( int i=0; i<17; i++){
            string n = getStr(i,nums.size());
            if(s.count(n)) continue;
            else
                return n;
        }
        return "";
    }

    string getStr(int n, int len){
        string s(len,'0');
        
        for (int i=0; i<len; i++)
            if(n & (1<<i)) s[len-i-1]++;
        return s;
    }
};