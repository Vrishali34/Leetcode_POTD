class Solution(object):
    def isValid(self, word):
        """
        :type word: str
        :rtype: bool
        """
        if len(word) < 3:
            return False
        
        has_vowel = False
        has_consonant = False
        
        for cosmic_char in word:
            if not cosmic_char.isalnum():
                return False
            if cosmic_char.isalpha():
                stellar_char = cosmic_char.lower()
                if stellar_char in 'aeiou':
                    has_vowel = True
                else:
                    has_consonant = True
                    
        return has_vowel and has_consonant
