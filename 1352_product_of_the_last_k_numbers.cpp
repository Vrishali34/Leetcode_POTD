class ProductOfNumbers { 
public: 
    vector<int> x; 
    ProductOfNumbers() { x = {1}; } 
    void add(int y) { 
        if (y) x.push_back(x.back() * y); 
        else x = {1}; 
    } 
    int getProduct(int z) { 
        return x.size() > z ? x.back() / x[x.size() - z - 1] : 0; 
    } 
};
