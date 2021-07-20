class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        cont_dict = {}
        for pa in paths:
            pas = pa.split(' ')
            root = pas[0]
            for f in pas[1:]:
                i = f.find('(')
                fn = f[:i]
                cont = f[i+1:-1]
                if cont not in cont_dict:
                    cont_dict[cont] = []
                cont_dict[cont].append('{}/{}'.format(root, fn))
        return [v for c,v in cont_dict.items() if len(v)>1]
