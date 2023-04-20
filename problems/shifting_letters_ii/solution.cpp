class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> f(s.size()+1);
        for (auto &s : shifts){
            f[s[0]] += s[2]? 1 : -1;
            f[s[1]+1] += s[2]? -1 : 1;
        }

        
        for (int i=0, psum=0; i<s.size(); i++){
            psum +=f[i];
            int c = (s[i] - 'a' + psum )%26;
            c = (c+26)%26;
            s[i] = 'a'+ c; 
        }
        return s;
    }
};