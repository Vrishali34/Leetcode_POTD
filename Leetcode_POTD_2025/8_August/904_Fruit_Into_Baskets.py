class Solution(object):
    def totalFruit(self, fruits):
        """
        :type fruits: List[int]
        :rtype: int
        """
        max_fruits = 0
        last_fruit_type = -1
        second_last_fruit_type = -1
        last_fruit_count = 0
        current_fruits = 0

        for fruit_type in fruits:
            if fruit_type == last_fruit_type or fruit_type == second_last_fruit_type:
                current_fruits += 1
            else:
                current_fruits = last_fruit_count + 1

            if fruit_type == last_fruit_type:
                last_fruit_count += 1
            else:
                last_fruit_count = 1
                second_last_fruit_type = last_fruit_type
                last_fruit_type = fruit_type

            max_fruits = max(max_fruits, current_fruits)

        return max_fruits
