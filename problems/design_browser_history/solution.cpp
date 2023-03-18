class BrowserHistory {
public:
vector<string> his;
int i=0,cur= 0;
    BrowserHistory(string homepage) {
        his.push_back(homepage);
        //i++;
    }
    
    void visit(string url) {
        i=cur;
        if (i+1>=his.size())
            his.push_back(url),i++;
        else
            his[++i]=url;
        cur = i;
    }
    
    string back(int steps) {
        cur = max(0,cur-steps);
        return his[cur];
    }
    
    string forward(int steps) {
        cur = min(i,cur+steps);
        return his[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */