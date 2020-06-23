class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> nodeList(wordList.begin(),wordList.end());
        if (nodeList.count(endWord)==0) return 0;
        
        unordered_set<string> s1{beginWord},s2{endWord};
        
        bool found=false;
        int len=1,loop=2;
         while(!s1.empty() && !s2.empty())
         {
             
             if (s1.size()>s2.size()) {s1.swap(s2);}
             
             for (auto & s : s1) nodeList.erase(s);
             for (auto s : s2) nodeList.erase(s);
             unordered_set<string> temp;
             for (const auto & s : s1)
             {
                 string  cur = s;
                 for (int i=0; i<s.size(); i++)
                 {
                     char t = cur[i];
                     for (char c='a'; c <='z'; c++)
                     {
                         cur[i] = c;
                         if (s2.count(cur))
                         {
                            return ++len;
                            //else return 2;
                        }
                                                  
                         else if (nodeList.count(cur)){
                            temp.insert(cur);
                         }
                     }
                     cur[i]=t;
                 }
             }
             s1.swap(temp);
             len++;
         }
        
        return 0;
    }
};