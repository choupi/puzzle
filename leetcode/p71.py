class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []
        paths = path.split('/')
        print(paths)
        for p in paths:
            if p == '' or p == '.':
                continue
            elif p == '..':
                if stack:
                    stack.pop(-1)
            else:
                stack.append(p)
        return '/'+'/'.join(stack)
