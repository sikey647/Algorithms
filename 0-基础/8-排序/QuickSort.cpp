#include <iostream>
#include <vector>

// 问题：如何在 O(n) 的时间复杂度内查找一个无序数组中的第 K 大元素？

// 快速排序
//  原理：在要排序的数组之间（left, right），找一个分区点（pivot），
//      将小于分区点（pivot）放到左边，大于分区点（pivot）放到右边。
//  过程：
/*
        quickSort(array) {
            _quickSort(array, 0, array.size - 1)
        }

        _quickSort(array, left, right) {
            // 终止条件
            if (left >= right) {
                return
            }

            // 获取分区点
            pivot = partition(array, left, right)

            _quickSort(array, left, pivot - 1)
            _quickSort(array, pivot + 1, right)
        }
*/

//  不稳定
//  时间复杂度：O(nlogn)
//      最坏情况，数据已有序，复杂度退化为O(n^2)
//  空间复杂度：O(1)
//      原地排序

int partition(std::vector<int>& data, int left, int right) {
    int pivot = right;
    int deal = left;  // 待处理节点
    for (int i = left; i < right; i ++) {
        if (data[i] < data[pivot]) {
            std::swap(data[i], data[deal++]);
        }
    }
    std::swap(data[pivot], data[deal]);

    return deal;
}

void _quickSort(std::vector<int>& data, int left, int right) {
    if (left >= right) {
        return;
    }

    int pivot = partition(data, left, right);
    _quickSort(data, left, pivot - 1);
    _quickSort(data, pivot + 1, right);
}

void quickSort(std::vector<int>& data) {
    _quickSort(data, 0, data.size() - 1);
}

int main() {
    std::vector<int> data = {7, 5, 19, 8, 4, 1, 20, 13, 16};
    quickSort(data);
    for (auto d : data) {
        std::cout << d << " ";
    }
    std::cout << std::endl;
}