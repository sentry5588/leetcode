class Solution:
    def simplifyPath(self, path: str) -> str:
        proper_path_stack = []
        folders = path.split('/')
        for f in folders:
            if f == '..':
                if len(proper_path_stack) > 0:
                    proper_path_stack.pop()
            elif f != '' and f != '.':
                proper_path_stack.append(f)

        # ######################################################
        # ######## these lines can be written in one line 
        # ######################################################
        # proper_path = ''
        # for f in proper_path_stack:
        #     proper_path = proper_path + '/' + f
        # if len(proper_path) == 0:
        #     proper_path = '/'
        proper_path = '/' + '/'.join(proper_path_stack)
        # ######################################################

        return proper_path
        