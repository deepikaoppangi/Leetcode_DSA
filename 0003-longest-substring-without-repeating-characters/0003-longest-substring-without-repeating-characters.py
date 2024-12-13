class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        char_map = {}
        start = 0  # Start of the sliding window
        max_len = 0  # To store the maximum length found
        
        for end in range(len(s)):
            char = s[end]
            # If the character is in the window, move start to the right of its last position
            if char in char_map and char_map[char] >= start:
                start = char_map[char] + 1
            
            # Update the last position of the character
            char_map[char] = end
            
            # Calculate the window size and update max_len if necessary
            max_len = max(max_len, end - start + 1)
        
        return max_len
        