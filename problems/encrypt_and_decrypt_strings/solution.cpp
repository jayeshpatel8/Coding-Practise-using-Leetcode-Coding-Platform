class Encrypter {
public:
    unordered_map<char,string> M1;
    unordered_map<string,string> M2;
    vector<string> dict;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for (int i=0; i<keys.size(); i++)
            M1[keys[i]] = values[i], M2[values[i]]+=keys[i];
        dict = dictionary ;
        
    }

    string encrypt(string word1) {
        string s;
        for (auto c : word1){
            s += M1[c];            
        }
        return s;
    }
    
    int decrypt(string word2) {
        int ans=0;
        for (auto &w : dict)
            ans += (encrypt(w) ==word2);
       
        return ans;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */