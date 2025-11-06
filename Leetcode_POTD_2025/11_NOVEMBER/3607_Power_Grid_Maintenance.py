class Solution(object):
    def processQueries(self, c, connections, queries):
        galaxy_map = list(range(c + 1))
        galaxy_mass = [1] * (c + 1)

        def find_star(s):
            if galaxy_map[s] == s:
                return s
            galaxy_map[s] = find_star(galaxy_map[s])
            return galaxy_map[s]

        def merge_galaxies(s1, s2):
            root1, root2 = find_star(s1), find_star(s2)
            if root1 != root2:
                if galaxy_mass[root1] < galaxy_mass[root2]:
                    root1, root2 = root2, root1
                galaxy_map[root2] = root1
                galaxy_mass[root1] += galaxy_mass[root2]

        for u, v in connections:
            merge_galaxies(u, v)

        galaxy_contents = [[] for _ in range(c + 1)]
        for i in range(1, c + 1):
            galaxy_contents[find_star(i)].append(i)

        is_dark = [False] * (c + 1)
        beacon_index = [0] * (c + 1)
        nova_bursts = []

        for q_type, x in queries:
            if q_type == 2:
                is_dark[x] = True
            else:
                if not is_dark[x]:
                    nova_bursts.append(x)
                    continue
                
                core = find_star(x)
                star_list = galaxy_contents[core]
                idx = beacon_index[core]
                
                while idx < len(star_list) and is_dark[star_list[idx]]:
                    idx += 1
                
                beacon_index[core] = idx
                nova_bursts.append(-1 if idx == len(star_list) else star_list[idx])
                
        return nova_bursts
