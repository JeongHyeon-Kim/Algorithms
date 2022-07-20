# problem source: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/submissions/

# discussion reference: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/discuss/360962/JavaPython-3-Count-chars-in-each-word-.
# Runtime: 331 ms, faster than 29.42% of Python3 online submissions for Find Words That Can Be Formed by Characters.
# Memory Usage: 14.5 MB, less than 36.94% of Python3 online submissions for Find Words That Can Be Formed by Characters.

class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        sum = 0
        chars_counter = collections.Counter(chars)
        print(chars_counter)
        for word in words:
            word_counter = collections.Counter(word)
            for char_index in word_counter:
                if word_counter[char_index] > chars_counter[char_index]:
                    break
            else:
                sum += len(word)
        return sum
