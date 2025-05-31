import collections

class Solution(object):
    def snakesAndLadders(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        n = len(board) # Dimension of the board (n)
        total_squares = n * n # Total number of squares (n*n)

        # Queue for BFS: stores tuples of (current_square, moves_taken)
        q = collections.deque()
        q.append((1, 0)) # Start at square 1 with 0 moves

        # Dictionary to store minimum moves to reach each square,
        # initialized to a state that signifies unvisited.
        # Using a dictionary allows us to store only visited squares efficiently.
        visited = {1: 0} # Mark starting square as visited with 0 moves

        # Helper function to get the actual value from the board given a 1-indexed square number
        # It handles the Boustrophedon (alternating) numbering style of the board
        def get_board_value(square_num):
            # Calculate 0-indexed row from 1-indexed square number
            row_zero_indexed = (square_num - 1) // n
            # Calculate 0-indexed column from 1-indexed square number
            col_zero_indexed = (square_num - 1) % n

            # If the row is odd (0-indexed), the direction is right-to-left, so adjust column
            if row_zero_indexed % 2 == 1:
                col_zero_indexed = n - 1 - col_zero_indexed
            
            # The board is given with row n-1 at the bottom, so invert the row index
            return board[n - 1 - row_zero_indexed][col_zero_indexed]

        while q:
            current_sq, current_moves = q.popleft() # Dequeue the current square and its moves

            # If we reached the target square (n*n), return the moves
            if current_sq == total_squares:
                return current_moves

            # Explore possible moves from current square (1 to 6 steps)
            for next_step in range(1, 7):
                potential_sq = current_sq + next_step # Potential next square

                # If potential square is beyond the board, skip
                if potential_sq > total_squares:
                    continue

                # Get the value at the potential square on the board
                # This handles snakes (-1) and ladders (destination square)
                board_val = get_board_value(potential_sq)
                # If it's a snake or ladder (value is not -1), the final destination is 'board_val',
                # otherwise it's 'potential_sq' itself.
                final_sq = board_val if board_val != -1 else potential_sq

                # If this final square has not been visited yet
                if final_sq not in visited:
                    visited[final_sq] = current_moves + 1 # Mark as visited with one more move
                    q.append((final_sq, current_moves + 1)) # Enqueue for further exploration
        
        # If the queue becomes empty and n*n is not reached, it's impossible
        return -1
