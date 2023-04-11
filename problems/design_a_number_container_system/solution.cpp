class NumberContainers {
public:
unordered_map<int, set<int>> map;
unordered_map<int,int> map2;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        
        
        if (map2.count(index))
        {
            map[map2[index]].erase(index);
        }
        map2[index]=number;
        map[number].insert(index);
    }
    
    int find(int number) {
        
        if (map.count(number) && !map[number].empty()){
            return *begin(map[number]);
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */