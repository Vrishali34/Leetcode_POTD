from collections import defaultdict, deque

class Solution(object):
    def findAllRecipes(self, recipes, ingredients, supplies):
        graph = defaultdict(list)
        indegree = defaultdict(int)
        supply_set = set(supplies)
        result = []

        for i, r in enumerate(recipes):
            for ing in ingredients[i]:
                if ing not in supply_set:
                    graph[ing].append(r)
                    indegree[r] += 1
            indegree[r] = indegree.get(r, 0)

        queue = deque([r for r in recipes if indegree[r] == 0])

        while queue:
            curr = queue.popleft()
            result.append(curr)
            supply_set.add(curr)
            for nei in graph[curr]:
                indegree[nei] -= 1
                if indegree[nei] == 0:
                    queue.append(nei)

        return result
