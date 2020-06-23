class Solution {
public:
    vector<vector<string>> res;
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        int n = wordList.size();
        unordered_set<string> wset(wordList.begin(),wordList.end());
        // wordList len =0 or endWord not found
        if (wset.count(endWord)==0) return    vector<vector<string>>();     
        
        unordered_set<string> firstset{beginWord},endset{endWord};
        bool flag=false, end=false;
        unordered_map<string,vector<string>> dic;
        int len=1;
        
        while(!firstset.empty() && !endset.empty() && !flag)
        {
            unordered_set<string> temp;            
            if(firstset.size()>endset.size()){
                firstset.swap(endset);
                end = !end;
            }
            
            for (const auto & s : firstset ) wset.erase(s);
            for (const auto & s : endset ) wset.erase(s);
            
            for( auto s : firstset){                      
                
                 //cout << "[" <<s<<"]=";
                string cur=s;
                for (int i = 0; i<s.length(); i++)
                {
                    char old = s[i];
                    for (char c = 'a'; c<='z'; c++)
                    {
                        s[i] = c;                    
                        //if(wset.count(s)>0)
                        {
                            
                            if (endset.count(s)){
                            const string* parent = &cur;
                            const string* child = &s;

                            if(end) swap(parent, child);                                
                                flag=true;
                                dic[*parent].push_back(*child);
                                //cout << "END - " << cur << ":" << old << "-"<< s << ", ";
                            }                            
                            else if (wset.count(s) && !flag)
                            {
                                
                                temp.insert(s);
                            const string* parent = &cur;
                            const string* child = &s;

                            if(end) swap(parent, child);
									 dic[*parent].push_back(*child);
                                //cout <<  s << ", ";
                            }                            
                        }                                        
                    }
                    s[i]=old;                
                }
            }
            
            firstset.swap(temp);
            len++;
        }
        /*
        for (auto s: dic){
            cout << "dic[" << s.first<< "] = "<< s.second.size() <<"[ ";
            for (auto t : s.second)
                cout << t << " ";
            cout << "] ";
        }*/
        if (flag){
           vector<string> s{beginWord};
            dfs(dic,beginWord,endWord,s);
            
        }
        return res;                    
    }
void dfs(const unordered_map<string,vector<string>>& dic, const string & beginWord,const string & endWord, vector<string>& s){
         if (beginWord==endWord )
        {
           
                res.push_back(s); 
            return;
        }
        
        const auto it = dic.find(beginWord);
        if(it == dic.cend()) return;
         for(const string& child : it->second){
            s.push_back(child);
            dfs(dic,child,endWord,s);
            s.pop_back();
        }
    }
   
};