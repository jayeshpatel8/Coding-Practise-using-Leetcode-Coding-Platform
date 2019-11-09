class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
         int len=s.length();
         unordered_set<char> set;
        int idx=0,max_size=0,b_idx=0;
        while(idx < len)
        {
           if (set.find(s[idx]) != set.end())
           {
               if (max_size < (idx-b_idx))
                    max_size = (idx-b_idx);
               set.erase(s[b_idx++]);
               
           }
        else
           set.insert(s[idx++]);      
        }
       if (max_size < set.size())
            max_size = set.size();
        return max_size;
    }
};