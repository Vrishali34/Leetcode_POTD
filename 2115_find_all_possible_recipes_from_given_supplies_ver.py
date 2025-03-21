class Solution(object):
    def findAllRecipes(self, recipes, ingredients, supplies):
        can_make = set(supplies)
        recipe_map = dict(zip(recipes, ingredients))
        memo = {}
        
        def dfs(r):
            if r in can_make:
                return True
            if r not in recipe_map or r in memo:
                return False
            memo[r] = False  
            for ing in recipe_map[r]:
                if not dfs(ing):
                    return False
            can_make.add(r)
            return True

        return [r for r in recipes if dfs(r)]
