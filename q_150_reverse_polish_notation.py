class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        operators = {'+', '-', '*', '/'} # use set, faster
        for token in tokens:
            if token not in operators:
                stack.append(int(token))
            else:
                top = stack.pop()
                if token == '+':
                    stack[-1] = stack[-1] + top
                elif token == '-':
                    stack[-1] = stack[-1] - top
                elif token == '*':
                    stack[-1] = stack[-1] * top
                else:
                    if stack[-1] * top >= 0:
                        stack[-1] = stack[-1] // top
                    else:
                        stack[-1] = - ( abs(stack[-1]) // abs(top) )
        
        return stack[0]