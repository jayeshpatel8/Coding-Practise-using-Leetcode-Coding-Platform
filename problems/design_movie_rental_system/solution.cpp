class MovieRentingSystem {
public:
    set<array<int,3>> rented;  // price,shop,movie
    
    set<pair<int,int>> dropped[10001]; //  price, shop  
    unordered_map<int,int> shops[300001];  // movie,shop = price
    
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
            
        for (auto & e : entries){
            dropped[e[1]].insert({e[2],e[0]});
            shops[e[0]][e[1]]=e[2];
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        
        for (auto &[price,shop] : dropped[movie])
            if (ans.size() < 5) ans.push_back( shop);
            else break;
        return ans;
    }
    
    void rent(int shop, int movie) {
        int price = shops[shop][movie];
        dropped[movie].erase(dropped[movie].find({price,shop}));
        rented.insert({price,shop,movie});
    }
    
    void drop(int shop, int movie) {
        int price = shops[shop][movie];
        rented.erase(rented.find({price,shop,movie}));
        dropped[movie].insert({price,shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        for (auto &[price,shop,movie] : rented){
            if (ans.size() < 5) ans.push_back({shop,movie});   
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */