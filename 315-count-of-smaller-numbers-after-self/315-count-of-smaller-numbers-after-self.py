class Solution(object):
    def countSmaller(self, nums):
        result = [0 for i in range(len(nums))]
        arr = [nums[-1]]
        # iterate from bottom, use binary seach to find how many elements smaller than nums[i]
        for i in reversed(range(len(nums) - 1)):
            start = 0
            end = len(arr) - 1
            while start <= end:
                mid = start + (end - start) / 2
                if arr[mid] < nums[i]:
                    start = mid + 1
                else:
                    end = mid - 1
            
            if end >= 0:
                # there are end - 0 + 1 elements smaller than nums[i]
                result[i] = end + 1
                # check the edge case
                if len(arr) < end + 2:
                    arr.append(nums[i])
                else:
                    arr.insert(end + 1, nums[i])
            else:
                # there are no elements smaller than nums[i]
                result[i] = 0
                arr.insert(0, nums[i])

        return result
        
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        