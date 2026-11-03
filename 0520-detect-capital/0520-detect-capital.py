class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        s1= word.upper()
        s2= word.lower()
        s3= word[0].upper() + word[1:].lower()

        if(word == s1 or word == s2 or word == s3):
            return True
        
        return False