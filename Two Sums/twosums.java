class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] indices = new int [2];
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        
        for (int i = 0; i < nums.length; i++)
            map.put(nums[i], i);
        
        for (int i = 0; i < nums.length; i++)
            if (map.containsKey(target - nums[i]) && map.get(target - nums[i]) != i)
            {
                indices[0] = map.get(target - nums[i]);
                indices[1] = i;
            }
        
        /*
        for (int i = 0; i < nums.length; i++)
        {
            for (int j = 0; j < nums.length; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    indices[0] = j;
                    indices[1] = i;
                    
                    break;
                }
            }
        }
        */
        
        return indices;
    }
}
