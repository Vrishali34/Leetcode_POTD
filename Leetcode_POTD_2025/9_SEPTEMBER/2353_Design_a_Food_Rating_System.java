import java.util.*;

class FoodRatings {
    private Map<String, Integer> foodToRating;
    private Map<String, String> foodToCuisine;
    private Map<String, PriorityQueue<Food>> cuisineToFoods;

    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        foodToRating = new HashMap<>();
        foodToCuisine = new HashMap<>();
        cuisineToFoods = new HashMap<>();

        for (int i = 0; i < foods.length; i++) {
            String food = foods[i];
            String cuisine = cuisines[i];
            int rating = ratings[i];

            foodToRating.put(food, rating);
            foodToCuisine.put(food, cuisine);

            cuisineToFoods.computeIfAbsent(cuisine, k -> new PriorityQueue<>((a, b) -> {
                int ratingDiff = b.rating - a.rating;
                if (ratingDiff != 0) {
                    return ratingDiff;
                }
                return a.name.compareTo(b.name);
            })).add(new Food(food, rating));
        }
    }

    public void changeRating(String food, int newRating) {
        foodToRating.put(food, newRating);
        String cuisine = foodToCuisine.get(food);
        cuisineToFoods.get(cuisine).add(new Food(food, newRating));
    }

    public String highestRated(String cuisine) {
        PriorityQueue<Food> pq = cuisineToFoods.get(cuisine);
        while (true) {
            Food top = pq.peek();
            if (foodToRating.get(top.name) == top.rating) {
                return top.name;
            }
            pq.poll();
        }
    }

    private class Food {
        String name;
        int rating;

        public Food(String name, int rating) {
            this.name = name;
            this.rating = rating;
        }
    }
}
