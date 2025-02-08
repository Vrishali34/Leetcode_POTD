from sortedcontainers import SortedSet
from collections import defaultdict

class NumberContainers:
    def __init__(x): x.l, x.m = {}, defaultdict(SortedSet)
    def change(x, i, v): x.m[x.l.pop(i, 0)].discard(i); x.l[i] = v; x.m[v].add(i)
    def find(x, v): return next(iter(x.m[v]), -1)
