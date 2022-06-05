class TextEditor {
public:
    string bef, aft;
    //int cur=0 ,sz = 0;
    TextEditor() {
        
    }
    
    void addText(string text) {
        bef.insert(end(bef),begin(text),end(text));
    }
    
    int deleteText(int k) {
        int del =  min<int>( bef.size() , k);
        bef.resize(bef.size()  - del);
        return del;
    }
    
    string cursorLeft(int k) {
        while (k-- && !bef.empty()){
            aft.push_back(bef.back());
            bef.pop_back();
        }
        return bef.substr(bef.size() - min<int>(10,bef.size()));
    }
    
    string cursorRight(int k) {
        while (k-- && !aft.empty()){
            bef.push_back(aft.back());
            aft.pop_back();
        }
        return bef.substr(bef.size() - min<int>(10,bef.size()));
    }
};

/*
class TextEditor {
public:
    string s;
    int cur=0 ,sz = 0;
    TextEditor() {
        
    }
    
    void addText(string text) {
        int t = text.size();
        if (sz == cur)
            s += text;
        else
            s.insert(cur,text,0,t);
        cur += t;
        sz += t;
    }
    
    int deleteText(int k) {
        int ncur = max(0, cur - k);
        int del = min(k, cur);
        s.erase(ncur,del);
        cur = ncur;
        sz -= del;
        return del;
    }
    
    string cursorLeft(int k) {
        cur = max(0, cur-k);
        if (cur == 0) return "";
        else{
            if (cur <= 10)
                return s.substr(0,cur);
            else{
                return s.substr(cur-10,10);
            }
        }
    }
    
    string cursorRight(int k) {
        cur = min<int>(sz, cur + k);
            if (cur <= 10)
                return s.substr(0,cur);
            else{
                return s.substr(cur-10,10);
            }        
    }
};
*/
/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */