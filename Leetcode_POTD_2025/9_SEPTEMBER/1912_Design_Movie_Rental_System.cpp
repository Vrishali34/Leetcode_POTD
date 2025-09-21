class MovieRentingSystem {
    std::map<int, std::set<std::pair<int, int>>> available_movies;
    std::set<std::tuple<int, int, int>> rented_movies;
    std::map<std::pair<int, int>, int> prices;
public:
    MovieRentingSystem(int n, std::vector<std::vector<int>>& entries) {
        for (const auto& e : entries) {
            prices[{e[0], e[1]}] = e[2];
            available_movies[e[1]].insert({e[2], e[0]});
        }
    }
    std::vector<int> search(int movie) {
        std::vector<int> res;
        auto it = available_movies.find(movie);
        if (it != available_movies.end()) {
            for (const auto& p : it->second) {
                if (res.size() < 5) {
                    res.push_back(p.second);
                } else {
                    break;
                }
            }
        }
        return res;
    }
    void rent(int shop, int movie) {
        int price = prices.at({shop, movie});
        available_movies.at(movie).erase({price, shop});
        rented_movies.insert({price, shop, movie});
    }
    void drop(int shop, int movie) {
        int price = prices.at({shop, movie});
        rented_movies.erase({price, shop, movie});
        available_movies.at(movie).insert({price, shop});
    }
    std::vector<std::vector<int>> report() {
        std::vector<std::vector<int>> res;
        for (const auto& r : rented_movies) {
            if (res.size() < 5) {
                res.push_back({std::get<1>(r), std::get<2>(r)});
            } else {
                break;
            }
        }
        return res;
    }
};
