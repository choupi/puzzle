class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        piece_dict = {}
        for p in pieces:
            piece_dict[p[0]] = p
        i = 0
        while i<len(arr):
            if arr[i] not in piece_dict:
                return False
            p = piece_dict[arr[i]]
            #print(p)
            #print(arr[i:i+len(p)])
            if arr[i:i+len(p)] != p:
                return False
            i += len(p)
        return True
