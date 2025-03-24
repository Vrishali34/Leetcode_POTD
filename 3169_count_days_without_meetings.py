class Solution(object):
    def countDays(self, days, meetings):
        sweep = {}
        for s, e in meetings:
            sweep[s] = sweep.get(s, 0) + 1
            sweep[e + 1] = sweep.get(e + 1, 0) - 1

        free, cnt, prev = 0, 0, 1
        for day in sorted(sweep):
            if cnt == 0:
                free += day - prev
            cnt += sweep[day]
            prev = day

        if cnt == 0 and prev <= days:
            free += days - prev + 1
        return free
