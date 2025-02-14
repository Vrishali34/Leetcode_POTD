import java.util.*;

class ProductOfNumbers {
    private List<Integer> list;

    public ProductOfNumbers() {
        list = new ArrayList<>();
        list.add(1);
    }

    public void add(int num) {
        if (num == 0) {
            list.clear();
            list.add(1);
        } else {
            list.add(list.get(list.size() - 1) * num);
        }
    }

    public int getProduct(int k) {
        int n = list.size();
        return n > k ? list.get(n - 1) / list.get(n - k - 1) : 0;
    }
}
