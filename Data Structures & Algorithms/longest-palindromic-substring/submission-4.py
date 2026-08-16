class Solution:
    def longestPalindrome(self, s: str) -> str:
        def rev(s : str) -> bool :
            if s[::-1] == s:
                return True;
            else :
                return False;
        max = 0
        ans = s[0]
        if len(s) <= 1:
            return s
        for i in range(len(s)):
            for j in range(i+1, len(s)):
                if(s[j] == s[i]):
                    temp = s[i:j+1]
                    if rev(temp):
                        if j-i>max:
                            max = j-i
                            ans = temp
        return ans
            
        