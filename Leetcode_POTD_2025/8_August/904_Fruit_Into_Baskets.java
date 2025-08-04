class Solution {
    public int totalFruit(int[] fruits) {
        int max_fruits = 0;
        int last_fruit_type = -1;
        int second_last_fruit_type = -1;
        int last_fruit_count = 0;
        int current_fruits = 0;

        for (int fruit_type : fruits) {
            if (fruit_type == last_fruit_type || fruit_type == second_last_fruit_type) {
                current_fruits++;
            } else {
                current_fruits = last_fruit_count + 1;
            }
            if (fruit_type == last_fruit_type) {
                last_fruit_count++;
            } else {
                last_fruit_count = 1;
                second_last_fruit_type = last_fruit_type;
                last_fruit_type = fruit_type;
            }
            max_fruits = Math.max(max_fruits, current_fruits);
        }
        return max_fruits;
    }
}
