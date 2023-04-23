class LUPrefix {
public:
vector<bool> vis;
int ans = 0;
    LUPrefix(int n) {
        vis.resize(n+2);
    }
    
    void upload(int video) {
        vis[video]=true;
        while(vis[ans+1]) ans++;
    }
    
    int longest() {
        return ans;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */