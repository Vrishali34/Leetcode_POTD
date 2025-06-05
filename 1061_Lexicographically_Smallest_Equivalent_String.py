class Solution(object):
    def smallestEquivalentString(self, s1, s2, baseStr):
        """
        :type s1: str
        :type s2: str
        :type baseStr: str
        :rtype: str
        """
        # Initialize the parent array for the Disjoint Set Union (DSU) data structure.
        # Each character (represented by its 0-25 integer equivalent) is initially its own parent.
        parent = list(range(26))

        # Helper function to find the representative (root) of the set a character belongs to.
        # It also applies path compression for optimization.
        def find(i):
            if parent[i] == i:
                return i  # If the character is its own parent, it's the root.
            # Path compression: set the parent of 'i' directly to the root
            parent[i] = find(parent[i])
            return parent[i]

        # Helper function to union (merge) two sets.
        def union(x, y):
            rootX = find(x)  # Find the root of character x
            rootY = find(y)  # Find the root of character y

            if rootX != rootY:  # If they are in different sets
                # To ensure the lexicographically smallest equivalent string,
                # the smaller character's root becomes the parent of the larger character's root.
                if rootX < rootY:
                    parent[rootY] = rootX
                else:
                    parent[rootX] = rootY

        # Iterate through s1 and s2 to establish equivalence relationships.
        # For each corresponding pair of characters, union their sets.
        for i in range(len(s1)):
            # Convert characters to their 0-25 integer equivalents.
            char1_int = ord(s1[i]) - ord('a')
            char2_int = ord(s2[i]) - ord('a')
            union(char1_int, char2_int)

        # Build the result string.
        result = []
        for char_code in baseStr:
            # For each character in baseStr, find its equivalent smallest character
            # (which is the root of its set) and append it to the result.
            equivalent_char_int = find(ord(char_code) - ord('a'))
            result.append(chr(equivalent_char_int + ord('a')))

        # Join the list of characters to form the final string.
        return "".join(result)
