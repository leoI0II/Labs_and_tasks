class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        used_syms = []
        max_ = 0
        curr_max_substr = 0;
        for i in range(0, len(s)):
            for j in range(i, len(s)):
                if s[j] in used_syms:
                    used_syms.clear()
                    break
                else:
                    curr_max_substr += 1
                    used_syms.append(s[j])
            if curr_max_substr > max_:
                max_ = curr_max_substr
            curr_max_substr = 0
        return max_
    
sol = Solution()
print(sol.lengthOfLongestSubstring("abcabcbb"))