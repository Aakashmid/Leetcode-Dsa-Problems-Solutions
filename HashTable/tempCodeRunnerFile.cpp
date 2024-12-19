 int n = arr.size();
    unordered_map<int,int> nums;
    for(int i = 0; i < n;i++){
        if(nums.count(arr[i])){
            return arr[i];
        }
        else
        {
            nums[arr[i]] = 1;
        }
    }
