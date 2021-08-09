#include <iostream>
#include <vector>

// 归并排序、快排 都采用分治思想

// 归并排序
//  原理：将要排序的数组从中间分成前后两部分，然后对用前后两部分分别排序，再将排序好的两部分合并在一起，这样整个数组就有序了。
//  过程：
/*
        mergeSort(array, size) {
            _mergeSort(array, 0, size-1)
        }

        _mergeSort(array, start, end) {
            // 递归终止条件
            if (start >= end) {
                return
            }

            // 获取中间位置
            mid = (start + end) / 2

            // 分治
            _mergeSort(array, start, mid)
            _mergeSort(array, mid + 1, end)

            // 合并
            merge(array, start, mid, end)
        }
*/
//  稳定：在合并过程中前后数组有相同的元素，先把前一个数组的元素放在前面。
//  时间复杂度：O(nlogn)
//      与原始数据的有序程度无关，无论是最好情况、最坏情况、平均情况，时间复杂度都是O(nlogn)
//  空间复杂度：O(n)
//      归并排序缺点：不是原地排序

void merge(std::vector<int>& data, int left, int mid, int right) {
    std::vector<int> tmp(right - left + 1, 0);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        tmp[k++] = data[i] <= data[j] ? data[i++] : data[j++];
    }
    
    while (i <= mid) {
        tmp[k++] = data[i++];
    }

    while (j <= right) {
        tmp[k++] = data[j++];
    }

    for (int c = 0; c < tmp.size(); c++) {
        data[left+c] = tmp[c];
    }
}

void _mergeSort(std::vector<int>& data, int left, int right) {
    // 递归终止条件
    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;
    _mergeSort(data, left, mid);
    _mergeSort(data, mid + 1, right);

    merge(data, left, mid, right);
}

void mergeSort(std::vector<int>& data) {
    _mergeSort(data, 0, data.size() - 1);
}

int main() {
    std::vector<int> data = {7, 5, 19, 8, 4, 1, 20, 13, 16};
    mergeSort(data);
    for (auto d : data) {
        std::cout << d << " ";
    }
    std::cout << std::endl;
}
