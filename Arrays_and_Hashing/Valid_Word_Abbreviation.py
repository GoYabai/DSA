class Solution:
    def validWordAbbreviation(self, word: str, abbr: str) -> bool:
        l = len(word)
        i = 0
        j = 0
        short_l = ""
        while i < l and j < len(abbr):
            if word[i] == abbr[j]:
                i += 1
                j += 1
            else:
                if abbr[j].isnumeric():
                    while j < len(abbr) and abbr[j].isnumeric():
                        short_l += abbr[j]
                        j += 1
                    if short_l[0] == "0":
                        return False
                    else:
                        if int(short_l) + i <= l:
                            i += int(short_l)
                            short_l = ""
                        else:
                            return False
                else:
                    return False
        return i == l and j == len(abbr)