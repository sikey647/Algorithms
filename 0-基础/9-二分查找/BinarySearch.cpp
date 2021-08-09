#include <iostream>
#include <vector>

// ---------基本二分查找-代码模板----------
// 写法一
int binarySearch1(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;    // 注意

    while (left <= right) {     // 注意
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;    // 注意
        }
    }

    return -1;  
}

// 写法二
int binarySearch2(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();    // 注意

    while (left < right) {     // 注意
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;    // 注意
        }
    }

    return -1;  
}

// 4种常见变形问题
//  1). 查找第一个值等于给定值的元素
//  2). 查找最后一个值等于给定值的元素
//  3). 查找第一个大于等于给定值的元素
//  4). 查找最后一个小于等于给定值的元素

int main() {
    // 1 4 5 7 8 13 16 19 20
    std::vector<int> nums = {1, 4, 5, 7, 8, 13, 16, 19, 20};

    int k1 = binarySearch1(nums, 20);
    std::cout << "k1 = " << k1 << std::endl;

    int k2 = binarySearch2(nums, 1);
    std::cout << "k2 = " << k2 << std::endl;

    return 0;
}