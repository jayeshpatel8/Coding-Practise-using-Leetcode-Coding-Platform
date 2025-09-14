class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> match;
        unordered_map<string,string> low_match;
        const string vowel = "aeiou";
        vector<string> ans(queries.size());
        for(auto &s : wordlist){
            match.insert(s);
            string sl =s;
            transform(sl.begin(), sl.end(), sl.begin(),[](char c){return tolower(c);});
            if (0 == low_match.count(sl)) low_match[sl]=s;
            
            for(int i=0; i<sl.size(); i++)
                if (vowel.find(sl[i])!= string::npos)       sl[i]='0';                    
            
            if (0 == low_match.count(sl)) low_match[sl]=s;
        }
        for(int i=0; i<queries.size() ; i++){
            if(match.count(queries[i])) { ans[i]= queries[i]; continue;}

                string sl =queries[i];
                transform(sl.begin(), sl.end(), sl.begin(),[](char c){return tolower(c);});
                if(low_match.count(sl)) { ans[i]= low_match[sl]; continue;}
                
                transform(sl.begin(), sl.end(), sl.begin(),[&](char c){
                    if (vowel.find(c)!= string::npos)   return '0';
                    return c;});
                
                if (low_match.count(sl)) ans[i]=low_match[sl];                            
        }
        return ans;
    }
};
