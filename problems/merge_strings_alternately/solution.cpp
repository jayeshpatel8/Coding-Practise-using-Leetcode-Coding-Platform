class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,N1=word1.size(),N2=word2.size(),N=min(N1,N2);
        string s;
        while (i<N){
            s+=word1[i] ;s+= word2[i++];
        }
        while (i<N1)
            s+=word1[i++];
        while (i<N2)
            s+=word2[i++];
        return s;
    }
};