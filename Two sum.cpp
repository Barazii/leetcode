class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map{};

        for (int i = 0; i < nums.size(); i++)
        {
            int comp = target - nums[i];
            if (map.find(comp) != map.end())
                return vector<int>{i, map[comp]};
            map[nums[i]] = i;
        }
        return vector<int>{};
    }
};

// 1. std::vector is for storing/pushing data into container. std::vector is not for searching for an element, it doesn't even have any finding functon 
// scuh as 'find' or 'get'.
// 2. Using two for loops to fix on an iteration and then iterating through the rest of elements causes O(n2). And using algorithms for_each and find_if
// will not change anything.