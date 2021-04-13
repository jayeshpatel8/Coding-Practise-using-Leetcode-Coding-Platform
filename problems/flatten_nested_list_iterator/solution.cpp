/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<int> v;
    
    int n,c;
public:
    void init(vector<NestedInteger> & l, vector<int> & v){
        for (int j=0; j< l.size(); j++){
            if (l[j].isInteger()){
                v.push_back(l[j].getInteger());
            }
            else{
                init(l[j].getList(), v);
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList)  {    
        init(nestedList,v);
        n= v.size();
        c=0;
        
    }
    //[[1,1],2,[1,1]]
    int next() {
        // fetch next
        int ans=0;
        if (c<n) ans = v[c++];        
        return ans;
    }
    
    bool hasNext() {
        return c<n;   
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */