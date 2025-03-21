class Solution {
    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        Map<String, List<String>> graph = new HashMap<>();
        Map<String, Integer> indegree = new HashMap<>();
        Set<String> supplySet = new HashSet<>(Arrays.asList(supplies));
        List<String> result = new ArrayList<>();

        // Step 1: Build graph and indegree
        for (int i = 0; i < recipes.length; i++) {
            String recipe = recipes[i];
            List<String> ingList = ingredients.get(i);
            for (String ing : ingList) {
                if (!supplySet.contains(ing)) {
                    graph.computeIfAbsent(ing, k -> new ArrayList<>()).add(recipe);
                    indegree.put(recipe, indegree.getOrDefault(recipe, 0) + 1);
                }
            }
            // If all ingredients are in supplies, indegree will be 0
            indegree.putIfAbsent(recipe, 0);
        }

        // Step 2: Topological Sort using queue
        Queue<String> queue = new LinkedList<>();
        for (String recipe : recipes) {
            if (indegree.get(recipe) == 0) {
                queue.offer(recipe);
            }
        }

        while (!queue.isEmpty()) {
            String cur = queue.poll();
            result.add(cur);
            supplySet.add(cur); //  it  can act as a supply

            if (graph.containsKey(cur)) {
                for (String dependent : graph.get(cur)) {
                    indegree.put(dependent, indegree.get(dependent) - 1);
                    if (indegree.get(dependent) == 0) {
                        queue.offer(dependent);
                    }
                }
            }
        }

        return result;
    }
}
