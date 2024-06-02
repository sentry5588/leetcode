class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        # ####################################################################
        # Learn: Use Counter to construct a counter object <char : int>
        ransomNoteDict = Counter(ransomNote)
        # print(f"{type(ransomNoteDict)=}") # <class 'collections.Counter'>
        # ====================================================
        # This is quicker to write than below method:
        # ----------------------------------------------------
        # ransomNoteDict = {}
        # for c in ransomNote:
        #     if c in ransomNoteDict:
        #         ransomNoteDict[c] = ransomNoteDict[c] + 1
        #     else:
        #         ransomNoteDict[c] = 1
        # ----------------------------------------------------
        # ####################################################################

        for c in magazine:
            if c in ransomNoteDict:
                if ransomNoteDict[c] > 1:
                    ransomNoteDict[c] = ransomNoteDict[c] - 1
                else:
                    del ransomNoteDict[c]
                if len(ransomNoteDict) == 0:
                    return True

        return False