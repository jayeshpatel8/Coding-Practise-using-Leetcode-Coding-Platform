class SORTracker {
public:

    set<pair<int,string>> s;
    set<pair<int,string>>::iterator it = end(s); // point to ith highest
    
    SORTracker() {
        
    }
    
    void add(string name, int score) {
        auto itn = s.insert({-score, name}).first; // score coverted to -ve to avoid custome comparator
        if (it == end(s) || *itn < *it)
            it--; // decrement if higher number inserted than current to point to higher number
    }
    
    string get() {
        
        return (it++)->second; // increment to point next lower number
    }
};
/*
class SORTracker {
public:
    struct Comp{
      bool operator()(const pair<int,string> &i, const pair<int,string> &j) const{
          return (i.first == j.first ? (i.second < j.second) : i.first > j.first);
      }  
    };

    set<pair<int,string>, Comp> minQ,maxQ;    
    
    SORTracker() {
        
    }
    
    void add(string name, int score) {
        minQ.insert({score,name});
        if (!maxQ.empty())
        {
            auto i = maxQ.rbegin();
            
            minQ.insert(*i);
            maxQ.erase(*i);
            auto j = minQ.begin();
            maxQ.insert(*j);
            minQ.erase(*j);
        }
        
    }
    
    string get() {
        auto i = minQ.begin();
        auto ans = *i;
        maxQ.insert(*i);
        minQ.erase(*i);
        
        return ans.second;
    }
};
*/
/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */