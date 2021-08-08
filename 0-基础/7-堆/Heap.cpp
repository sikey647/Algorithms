#include <iostream>
#include "Heap.h"

Heap::Heap(int cap) : m_capacity(cap + 1), m_size(0) {
    m_array.resize(m_capacity, 0);
}

int Heap::push(int val) {
    if (m_size == m_capacity - 1) {
        return -1;    
    }

    m_array[++m_size] = val;

    int index = m_size;
    while (index / 2 >= 1 && m_array[index / 2] < m_array[index]) {
        std::swap(m_array[index], m_array[index / 2]);
        index = index / 2;    
    }

    return 0;
}

int Heap::pop() {
    if (m_size == 0) {
        return -1;
    }

    m_array[1] = m_array[m_size--];

    heapify(1);

    return 0;
}

int Heap::top() {
    return m_array[1];
}

bool Heap::empty() {
    return m_size == 0;
}

void Heap::print() {
    for (int i = 1; i <= m_size; i++) {
        std::cout << m_array[i] << " " ;
    }
    std::cout << std::endl;
}

void Heap::heapify(int index) {
    while (true) {
        int nextIndex = index;
        if (2 * index <= m_size && m_array[2 * index] > m_array[index]) {
            nextIndex = 2 * index;
        }
        if (2 * index + 1 <= m_size && m_array[2 * index + 1] > m_array[nextIndex]) {
            nextIndex = 2 * index + 1;
        }
        if (nextIndex == index) {
            break;
        }
        std::swap(m_array[index], m_array[nextIndex]);
        index = nextIndex;
    }
}

Heap::Heap(const std::vector<int>& array) {
    m_size = array.size();
    m_capacity = m_size + 1;
    m_array.reserve(m_capacity);
    m_array.push_back(0);
    m_array.insert(m_array.end(), array.begin(), array.end());
    build();
}

void Heap::build() {
    for (int i = m_size / 2; i >= 1; i--) {
        heapify(i);
    }
}

void Heap::sort(std::vector<int>& array) {
    int size = array.size();
    if (size <= 1) {
        return ;
    }

    // 建堆
    build(array, size);

    // 排序
    int k = size - 1;
    while (k > 0) {
        std::swap(array[0], array[k--]);
        heapify(array, k, 0);
    }
}

// 下标从0开始
void Heap::build(std::vector<int>& array, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(array, size, i);
    }
}

// 下标从0开始
void Heap::heapify(std::vector<int>& array, int end, int index) {
    while (true) {
        int nextIndex = index;
        if (index * 2 + 1 <= end && array[index * 2 + 1] > array[index]) {
            nextIndex = index * 2 + 1;
        }
        if (index * 2 + 2 <= end && array[index * 2 + 2] > array[nextIndex]) {
            nextIndex = index * 2 + 2;
        }
        if (nextIndex == index) {
            break;
        }
        std::swap(array[index], array[nextIndex]);
        index = nextIndex;
    }
}