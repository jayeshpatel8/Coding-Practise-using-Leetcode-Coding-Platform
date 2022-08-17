class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> map={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> set;
        for (auto &w : words){
            string s;
            for (auto c : w)
                s += map[c-'a'];
            
            set.insert(s);
        }
        
        return set.size();
    }
};