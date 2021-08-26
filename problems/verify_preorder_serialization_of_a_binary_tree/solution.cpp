class Solution {
public:
    int j=0, N;
    bool isValidSerialization(string s) {
        N = s.size();
        preorder(s);
        return j == s.size()-1;
    }
    void preorder(string &s){
        
        if (j>=N) return;
        if (s[j] == '#') {  
            return ;
        }
        while ( j < N && s[j] != ',') j++;
        j++;
        preorder(s);
        while ( j < N && s[j] != ',') j++;
        j++;
        preorder(s);
    }
};