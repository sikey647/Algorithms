/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */

#include <unordered_map>
#include <list>
#include <iostream>
using namespace std;

// @lc code=start
struct Node {
    int key;
    int value;
    int freq;
    Node(int _key, int _value, int _freq) : key(_key), value(_value), freq(_freq) {}
};

class LFUCache {
public:
    LFUCache(int capacity) : m_capacity(capacity), m_minFreq(0) {
        m_keyMap.clear();
        m_freqMap.clear();        
    }
    
    int get(int key) {
        if (m_capacity == 0) {
            return -1;
        }

        // 校验：key不存在，返回-1
        auto itr = m_keyMap.find(key);
        if (itr == m_keyMap.end()) {
            return -1;
        }

        // 获取数据
        auto nodeItr = itr->second;
        int value = nodeItr->value;
        int freq = nodeItr->freq;

        // 在旧频次链表中删除
        m_freqMap[freq].erase(nodeItr);
        // 检验旧频次链表是否为空，需要删除key
        if (m_freqMap[freq].size() == 0) {
            m_freqMap.erase(freq);
            // 更新最小频次
            if (freq == m_minFreq) {
                m_minFreq++;
            }
        }

        // 在新频次链表中插入
        m_freqMap[freq + 1].emplace_front(key, value, freq + 1);
        // 更新keyMap
        m_keyMap[key] = m_freqMap[freq + 1].begin();

        return value;
    }
    
    void put(int key, int value) {
        // 先判断数据是否存在
        auto itr = m_keyMap.find(key);
        // key不存在
        if (itr == m_keyMap.end()) {
            // 如果容量已满，先进行删除操作
            if (m_keyMap.size() == m_capacity) {
                // 删除最小频次链表的末尾节点
                auto delItr = m_freqMap[m_minFreq].end();
                // 在keyMap中删除对应的key
                m_keyMap.erase(delItr->key);
                m_freqMap[m_minFreq].pop_back();
                if (m_freqMap[m_minFreq].size() == 0) {
                    m_freqMap.erase(m_minFreq);
                }
            }

            // 插入数据
            m_freqMap[1].emplace_front(key, value, 1);
            m_keyMap[key] = m_freqMap[1].begin();
            m_minFreq = 1;    
        } else {    // key 存在
            auto nodeItr = itr->second;
            int freq = nodeItr->freq;
            // 在旧频次链表中删除
            m_freqMap[freq].erase(nodeItr);
            // 如何旧频次链表为空，则删除key
            if (m_freqMap[freq].size() == 0) {
                m_freqMap.erase(freq);
                if (m_minFreq == freq) {
                    m_minFreq++;
                }
            }

            // 插入数据
            m_freqMap[freq + 1].emplace_front(key, value, freq + 1);
            m_keyMap[key] = m_freqMap[freq + 1].begin();
        }
    }

private:
    // key: key, value: 链表对应的节点指针
    unordered_map<int, list<Node>::iterator> m_keyMap;
    // key: freq, value: 该频次对应的节点列表
    unordered_map<int, list<Node>> m_freqMap;
    // 保存最小频次
    int m_minFreq;
    int m_capacity;    
};

// int main() {
//     LFUCache lfu(2);
//     lfu.put(1, 1);
//     lfu.put(2, 2);
//     cout << "get(1): " << lfu.get(1) << endl;
//     lfu.put(3, 3);
//     cout << "get(2): " << lfu.get(2) << endl;
//     cout << "get(3): " << lfu.get(3) << endl;
//     lfu.put(4, 4);
//     cout << "get(1): " << lfu.get(1) << endl;
//     cout << "get(3): " << lfu.get(3) << endl;
//     cout << "get(4): " << lfu.get(4) << endl;

//     return 0;
// }

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

