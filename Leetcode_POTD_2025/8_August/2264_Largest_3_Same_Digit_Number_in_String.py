class Solution(object):
    def largestGoodInteger(self, num):
        possible_goods = ["999", "888", "777", "666", "555", "444", "333", "222", "111", "000"]
        for candidate in possible_goods:
            if candidate in num:
                return candidate
        return ""
