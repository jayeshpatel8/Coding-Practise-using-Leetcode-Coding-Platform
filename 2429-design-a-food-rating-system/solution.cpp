class FoodRatings {
public:
unordered_map<string,string> f;
unordered_map<string,int> r;
unordered_map<string, set<pair<int,string>>> c;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i=0; i<foods.size(); i++){
            f[foods[i]]=cuisines[i];
            r[foods[i]]=ratings[i];
            c[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        c[f[food]].erase({-r[food], food});
        r[food] = newRating;
        c[f[food]].insert({-newRating, food});

    }
    
    string highestRated(string cuisine) {
        return (begin(c[cuisine]))->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
