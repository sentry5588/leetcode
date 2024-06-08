class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        matched_par = {'(': ')',
                       '[': ']',
                       '{': '}'}
        # print(matched_par)
        for c in s:
            if c == '(' or c == '[' or c == '{':
                stack.append(c)
            else:
                if len(stack) > 0 and c == matched_par[stack[-1]]:
                    stack.pop()
                else:
                    return False
        if len(stack) > 0:
            return False

        return True