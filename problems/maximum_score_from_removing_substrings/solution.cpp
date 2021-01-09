class Solution {
public:


    unordered_map<string,int> M;
    int maximumGain(string s, int x, int y) {
        string a = "ab", b = "ba";
        if (x < y) swap(a, b), swap(x, y);
        //return maxGain(s, a, x) + maxGain(s, b, y);
        return x*maxGain(s, a[0], a[1]) + y*maxGain(s, b[0], b[1]);
    }
    int maxGain(string& s, string s1, int x) {
        int sum=0,idx=0;
        int n = s.size();
        for (int i=0; i<n; i++){
            s[idx++]=s[i];
            
            if (idx>1 && s[idx-2]==s1[0] && s[idx-1]==s1[1]) {
                idx -=2; sum+=x;
            }
        }
        s.resize(idx);
        return sum;
    }
    int maxGain(string &s, char c1, char c2){
        string o={"."};
        int sum=0;
        for (auto c : s){
            if (o.back() == c1 && c==c2)
                sum++,o.pop_back();
            else 
                o.push_back(c);
        }
        s=o;
        return sum;
    }
   
};