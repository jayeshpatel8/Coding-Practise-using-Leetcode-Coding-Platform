class Solution {
public:
    int isPrefixOfWord(string sentence, string sw) {
        istringstream ss(sentence);
        string w;
        int i=1;
        while (ss >> w){
            if ( w.length() >= sw.length() && w.compare(0,sw.length(),sw)==0 ){
                return i;
            }
            i++;
        }
        return -1;
    }
};
