class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(begin(strs),end(strs),[&](auto& s1, auto & s2){return s1.size()>s2.size();});
        int N = strs.size();
        for ( int i= 0; i<  N; i++){
            int j=-1;
            while(++j<N) {
                if (j!=i && isSubSeq(strs[i],strs[j])) break;
            }
            if (j==N) return strs[i].size();
        }
        return -1;
    }
    bool isSubSeq(string & s2, string & s1){
        int i = 0,j=0;
        while (i<s1.size() && j<s2.size()){
            if(s1[i] == s2[j]) j++;
            i++;
        }
        return j == s2.size();
    }
};