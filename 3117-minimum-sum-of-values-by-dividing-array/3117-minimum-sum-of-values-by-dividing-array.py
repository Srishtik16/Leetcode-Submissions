class Solution:
    def minimumValueSum(self, nums: List[int], andValues: List[int]) -> int:
        n = len(nums)
        m = len(andValues)
        
        mask = (1 << 20) - 1
        @cache
        def dfs(i, j, val):
            # when nums is finishing, check whether the ansValues is also finishing
            if i == n:
                return 0 if j == m else inf
            
            # if ansValues is finishing before nums, return inf
            if j == m:
                return inf
            
            result = inf
            # if the subarray AND is matching, we stop and start a new subarray
            if val & nums[i] == andValues[j]:
                result = nums[i] + dfs(i + 1, j + 1, mask)
            
            # otherwise, we need to continue
            result = min(result, dfs(i + 1, j, val & nums[i]))
            return result
        
        result = dfs(0, 0, mask)
        if result == inf:
            return -1
        return result