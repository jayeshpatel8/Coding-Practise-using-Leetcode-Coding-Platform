class Solution {
public:
    int longestBeautifulSubstring(string word) {
     int v[128]={}; 
        v['a']=1;v['e']=2;v['i']=3;v['o']=4;v['u']=5;;
        
        int ans=0,n= word.size(), len=1,d=1;
        for(int i=1; i< n; i++){
            if (word[i]==word[i-1]) len++;
            else if (word[i]>word[i-1]) len++, d++;
            else d=len=1;
            if (d==5) ans =max(ans,len);
        }
        return ans;
    }
};