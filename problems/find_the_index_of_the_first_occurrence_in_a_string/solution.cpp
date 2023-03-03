class Solution {
public:
    int strStr(string haystack, string needle) {
        
        for (int i=0; i<haystack.size(); i++){
            if (haystack[i] != needle[0])  continue;
            int j=0, k=i;
            for (; j<needle.size() && k<haystack.size(); j++ ,k++)
            {
                if (haystack[k] != needle[j])  break;
            }
            if (j == needle.size()) return i;
        }
        return -1;
    }
};