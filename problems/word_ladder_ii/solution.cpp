class Solution {
public:
    vector<vector<string>> res;
    vector<int> * parent;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        int n = wordList.size();
        // wordList len =0 or endWord not found
        if (n<1) return vector<vector<string>>();
        int endidx=-1,i;
        
        for ( i=0; i<n; i++)
        {
            //if (wordList[i][0] != endWord[0]) continue;
            if (wordList[i] != endWord)
                continue;
            else
            {endidx = i ; break;}
        }
        
        if (i==n) return res;
                
        wordList.push_back(beginWord); n++;
        
        vector<int>* graph = createGraph(  wordList);
       
        vector<int> vis(n);
        vis[n-1]=1;
        
       queue<int> bfs;
               
        bfs.push(n-1); 
        
        
        
        parent = new vector<int>[n];
        while(!bfs.empty()){
            int p = bfs.front();
            bfs.pop();
            if (p==endidx)
                break;
            for ( i=0; i<graph[p].size(); i++){
                int node = graph[p][i];
                if(vis[node] == 0){ //not visited
                   vis[node] = vis[p]+1;
                    parent[node].push_back(p);
                    bfs.push(node);
                }
                else if (vis[node] == vis[p]+1){
                    parent[node].push_back(p);
                }
            }
        }
        
        if (vis[endidx]==0) return res;
        vector<string> s{endWord};

         printParents(wordList,parent[endidx],s);
         return res;
            
        
    }

     vector<int>* createGraph( vector<string>& w){
         vector<int>* neib = new vector<int>[w.size()];
         
         for (int i=0; i<w.size();i++){             
             for (int j=i+1; j<w.size();j++)
                 if (isconnected(w[i],w[j]))
                 {
                     neib[i].push_back(j);
                     neib[j].push_back(i);
                 }
         }
         return neib;
     }
    void printParents(vector<string>& w, vector<int> &parent2,vector<string>& s){
        if (parent2.size()==0){
           vector<string> copy;
            //reverse_copy(s,s+(s.size()),copy.begin());
            for (auto it=s.cend()-1; it>=s.cbegin(); --it)
                copy.push_back(*it);
          //  reverse(copy.begin(),copy.end());
            res.push_back(copy); return;
        }
        
        for (int i=0; i< parent2.size();i++){
            s.push_back(w[parent2[i]]);
            printParents(w,parent[parent2[i]],s);
            s.pop_back();
        }
        
    }
    bool isconnected(string& a, string& b){
        
        int s=0,e = b.length(),cnt=0;;
        while(s<e){
            if(b[s]!=a[s])
                if (cnt++!=0)return false;
            s++;
                    
        }
        return true;        
    }
};