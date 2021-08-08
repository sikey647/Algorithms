#include <iostream>
#include <vector>
#include "Heap.h"

/*
// 大顶堆
class Heap {
public:
    Heap(int cap) : m_capacity(cap + 1), m_size(0) {
        m_array.resize(m_capacity + 1, 0);
    }

    // 建堆，方式二
    Heap(const std::vector<int>& array) {
        m_size = array.size();
        m_capacity = array.size() + 1;
        m_array.reserve(m_capacity);
        m_array.push_back(0);
        m_array.insert(m_array.end(), array.begin(), array.end());

        build();
    }

    Heap() = delete;

    // 插入
    // 0：成功，1:失败
    int push(int val) {
        if (m_size >= m_capacity) {
            return -1;
        }

        // 插入元素，更新size
        m_array[++m_size] = val;

        // 从下往上 堆化
        // 条件：i/2 > 0 && a[i/2] > a[i]
        int index = m_size;
        while (index / 2 > 0 && m_array[index / 2] < m_array[index]) {
            std::swap(m_array[index / 2], m_array[index]);
            index = index / 2;
        }

        return 0;
    }

    // 删除
    // 0：成功，1:失败    
    int pop() {
        if (m_size == 0) {
            return -1;
        }

        // 把最后一个元素放到堆顶
        m_array[1] = m_array[m_size--];

        // 从上往下 堆化
        int index = 1;
        heapify(1);

        return 0;
    }

    int top() {
        return m_array[1];
    }

    bool empty() {
        return m_size == 0;
    }

    void print() {
        for (int i = 1; i <= m_size; i++) {
            std::cout << m_array[i] << " " ;
        }
        std::cout << std::endl;
    }
 
    static void sort(std::vector<int>& array, int size) {
        if (size <= 1) {
            return;
        }

        build(array, size);
        std::cout << "-----build heap end!-------" << std::endl;

        int k = size - 1;
        while (k > 0) {
            std::swap(array[0], array[k]);
            k--;
            heapify(array, k, 0);
            print(array);
        }
        std::cout << "-----heap sort end!-------" << std::endl;
    }

    static void print(std::vector<int>& array) {
        for (auto d : array) {
            std::cout << d << " ";
        }
        std::cout << std::endl;
    } 

private:
    void heapify(int index) {
        while (true) {
            int nextIndex = index;
            // 条件：max(a[i], a[2*i], a[2*i+1])
            if (index * 2 <= m_size && m_array[index * 2] > m_array[index]) {
                nextIndex = index * 2;
            }
            if (index * 2 + 1 <= m_size && m_array[index * 2 + 1] > m_array[nextIndex]) {
                nextIndex = index * 2 + 1;
            }

            if (nextIndex == index) {
                break;
            }

            std::swap(m_array[index], m_array[nextIndex]);
            index = nextIndex;
        }
    }

    void build() {
        for (int i = m_size / 2; i >= 1; i--) {
            heapify(i);
        }
    }

    static void heapify(std::vector<int>& array, int end, int index) {
        while (true) {
            int nextIndex = index;
            if (index * 2 + 1 <= end && array[index * 2 + 1] > array[index]) {
                nextIndex = index * 2 + 1;
            }
            
            if (index * 2 + 2 <= end && array[index * 2 + 2] > array[nextIndex]) {
                nextIndex = index * 2 + 2;
            }

            if (index == nextIndex) {
                break;
            }

            std::swap(array[index], array[nextIndex]);
            index = nextIndex;
        }
    }

    static void build(std::vector<int>& array, int size) {
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(array, size, i);
            print(array);
        }      
    }

private:
    std::vector<int> m_array;
    int m_capacity;
    int m_size;
};
*/

int main() {
    std::vector<int> data = {7, 5, 19, 8, 4, 1, 20, 13, 16};

    // test 1
    // std::cout << "------test 2------" << std::endl;
    // Heap::sort(data);
    // for (auto d : data) {
    //     std::cout << d << " ";
    // }
    // std::cout << std::endl;

    // test 2
    std::cout << "------test 2------" << std::endl;
    Heap heap(data.size());
    for (auto& d : data) {
        heap.push(d);
        heap.print();
    }
    while (!heap.empty()) {
        std::cout << heap.top() << " ";
        heap.pop();
    }
    std::cout << std::endl;

    // test3
    std::cout << "------test 3------" << std::endl;
    Heap heap2(data);
    heap2.print();
    while (!heap2.empty()) {
        std::cout << heap2.top() << " ";
        heap2.pop();
    }
    std::cout << std::endl;

    return 0;
}