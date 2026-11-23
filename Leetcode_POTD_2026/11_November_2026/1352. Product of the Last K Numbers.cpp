class ProductOfNumbers {
    vector<int> pref_prod;
public:
    ProductOfNumbers() : pref_prod(1, 1) {}

    void add(int num) {
        if (num == 0) pref_prod.assign(1, 1);
        else pref_prod.push_back(pref_prod.back() * num);
    }

    int getProduct(int k) {
        int len = pref_prod.size();
        return k >= len ? 0 : pref_prod.back() / pref_prod[len - 1 - k];
    }
};
