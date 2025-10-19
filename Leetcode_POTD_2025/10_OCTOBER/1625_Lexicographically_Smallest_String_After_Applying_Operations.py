class Solution(object):
    def findLexSmallestString(self, s, a, b):
        def add_a_op(str_in, val_a):
            lst = list(str_in)
            for i in range(1, len(lst), 2):
                lst[i] = str((int(lst[i]) + val_a) % 10)
            return "".join(lst)

        def rotate_b_op(str_in, val_b):
            k = len(str_in)
            val_b %= k
            return str_in[k - val_b:] + str_in[:k - val_b]

        galaxy = {s}
        path_finder = [s]
        star_dust = s

        while path_finder:
            current_star = path_finder.pop(0)
            if current_star < star_dust:
                star_dust = current_star

            next_star_add = add_a_op(current_star, a)
            if next_star_add not in galaxy:
                galaxy.add(next_star_add)
                path_finder.append(next_star_add)

            next_star_rot = rotate_b_op(current_star, b)
            if next_star_rot not in galaxy:
                galaxy.add(next_star_rot)
                path_finder.append(next_star_rot)

        return star_dust
