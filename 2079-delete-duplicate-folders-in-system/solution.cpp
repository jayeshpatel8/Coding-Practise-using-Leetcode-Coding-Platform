struct Trie{
    string name;
    map<string, Trie *> next;
    bool mark=0;
    
    Trie(string n = "") : name(n){}
};

class Solution {
public:
    unordered_map<string, Trie*> duplicate;
    vector<vector<string>> ans;
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Trie * root = new Trie();
        for (auto& path : paths) add(root,path);
        markDuplicate(root);
        vector<string> path;
        for (auto &[name, child] : root->next){
            dfs_NonMarked(child,path);
        }
        return ans;
    }
    void add(Trie * node, vector<string>& path){
        for (auto s : path){
            if (node->next.count(s) == 0)
                node->next[s] = new Trie(s);
            node = node->next[s];
        }
    }
    
    string markDuplicate(Trie * root){
        string path;
        for (auto &[name, child] : root->next){
            path += markDuplicate(child);
        }
        if (path.size()){
            if (duplicate.count(path))
                duplicate[path]->mark = root->mark=true;
            else
                duplicate[path]=root;
        }
        return root->name + "(" + path + ")" ;
    }
    void dfs_NonMarked(Trie* root, vector<string>& path){
        if (root->mark) return;
        
        path.push_back(root->name);
        ans.push_back(path);
        
        for (auto &[name, child] : root->next)
            dfs_NonMarked(child,path);
            
        path.pop_back();
    }
};
