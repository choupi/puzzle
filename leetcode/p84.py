class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        max_r = 0
        stack = []
        heights += [0]
        for i in range(len(heights)):
            while stack and heights[stack[-1]] >= heights[i]:
                h = heights[stack.pop()]
                w = i
                if stack:
                    w = i - stack[-1] - 1
                max_r = max(max_r, h*w)
            stack.append(i)
        return max_r
