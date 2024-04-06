#1249. Minimum Remove to make valid parantheses
class Solution(object):
    def minRemoveToMakeValid(self, s):
        """
        :type s: str
        :rtype: str
        """
        stack = []
        invalid = set()
        for i, char in enumerate(s):
            if char == '(':
                stack.append(i)
            elif char == ')':
                if stack:
                    stack.pop()
                else:
                    invalid.add(i)
        invalid.update(stack)
        res = [char for i, char in enumerate(s) if i not in invalid]
        return ''.join(res)
                
        
            


        
