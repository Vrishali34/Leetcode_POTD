class Solution(object):
    def lexicalOrder(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        ordered_numbers = []  # Initialize an empty list to store the lexicographically ordered numbers
        current_digit = 1     # Start with the first number in lexicographical order, which is 1

        # Loop 'n' times, as we need to find 'n' numbers
        for _ in range(n):
            ordered_numbers.append(current_digit)  # Add the current number to our result list

            # Check if we can "go deeper" by appending a zero (e.g., from 1 to 10)
            if current_digit * 10 <= n:
                current_digit *= 10
            else:
                # If we cannot go deeper, we need to find the next sibling or backtrack

                # This loop handles two scenarios:
                # 1. current_digit % 10 == 9: If the last digit is 9 (e.g., 9, 19, 29),
                #    we cannot simply increment it. We need to "backtrack" by dividing by 10
                #    until we find a non-9 digit to increment (e.g., from 19 to 2, we first go 19->1)
                # 2. current_digit + 1 > n: If incrementing the current_digit would exceed 'n'
                #    (e.g., if n=13 and current_digit=13), we also need to backtrack
                #    to find the next valid number.
                while current_digit % 10 == 9 or current_digit + 1 > n:
                    current_digit //= 10  # Backtrack by removing the last digit

                current_digit += 1  # Increment the current digit to find the next sibling (e.g., from 1 to 2)

        return ordered_numbers # Return the list of lexicographically ordered numbers
