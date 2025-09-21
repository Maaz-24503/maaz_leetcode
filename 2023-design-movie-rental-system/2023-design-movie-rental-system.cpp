class MovieRentingSystem {
private:
    struct PriceShopCompare {
        bool operator()(const pair<int,int> &a, const pair<int,int> &b) const {
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        }
    };

    struct PriceShopMovieCompare {
        bool operator()(const tuple<int,int,int> &a, const tuple<int,int,int> &b) const {
            if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
            if (get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
            return get<2>(a) < get<2>(b);
        }
    };

    unordered_map<long long,int> priceMap;                        
    unordered_map<int, set<pair<int,int>, PriceShopCompare>> movieMap; 
    set<tuple<int,int,int>, PriceShopMovieCompare> rentedSet;          

    long long makeKey(int shop, int movie) {
        return (static_cast<long long>(shop) << 32) | static_cast<unsigned int>(movie);
    }

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            priceMap[makeKey(shop, movie)] = price;
            movieMap[movie].insert({price, shop});
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        auto &s = movieMap[movie];
        int count = 0;
        for (auto it = s.begin(); it != s.end() && count < 5; ++it, ++count) {
            res.push_back(it->second);
        }
        return res;
    }

    void rent(int shop, int movie) {
        int price = priceMap[makeKey(shop, movie)];
        movieMap[movie].erase({price, shop});
        rentedSet.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        int price = priceMap[makeKey(shop, movie)];
        movieMap[movie].insert({price, shop});
        rentedSet.erase({price, shop, movie});
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;
        int count = 0;
        for (auto it = rentedSet.begin(); it != rentedSet.end() && count < 5; ++it, ++count) {
            res.push_back({get<1>(*it), get<2>(*it)});
        }
        return res;
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