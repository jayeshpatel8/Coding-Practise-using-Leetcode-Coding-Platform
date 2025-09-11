class Solution {
public:
    string sortVowels(string s) {
        vector<char> ch;
        string v= "aeiouAEIOU";
        for (auto & c :s){
            if (v.find(c) != string::npos){
                ch.push_back(c);
                c=1;
            }
        }
        sort(begin(ch),end(ch));

        int i=0;
        for (auto & c :s){
            if (c == 1) 
                c=ch[i++];
        }
        return s;
    }
};
