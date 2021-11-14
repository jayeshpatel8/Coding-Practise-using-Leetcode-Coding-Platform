class CombinationIterator {
public:
    int len , N;
    string s;
    vector<int> idx;
    CombinationIterator(string characters, int combinationLength) {
        s = characters;
        len = combinationLength;
        N = s.size();
        for (int i=0; i<len; i++) idx.push_back(i);
        idx[len-1]--;
    }
    
    string next() {
        if (idx.back() +1< N ) idx.back()++;
        else{
            int i = len-1, j = 1;
         
            while(i>0 && idx[i] + j >= N ){
                i--,j++;
            }
            
            j = ++idx[i++];
            while(i<len)
                idx[i++] = ++j;            
        }
        return getstr();
    }
    string getstr(){
        string ans;
        for (auto i : idx)
            ans += s[i];
        return ans;
    }
    bool hasNext() {
        return (idx.back() != N-1 || N-(idx[0]+1 ) >= len );
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */