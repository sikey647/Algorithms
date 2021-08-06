/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

#include <list>
#include <unordered_map>
using namespace std;

// @lc code=start
class LRUCache {
public:
    LRUCache(int capacity) : m_capacity(capacity) {
        
    }
    
    int get(int key) {
        auto itr = m_map.find(key);
        if (itr == m_map.end()) return -1;

        // key存在，获取k-v
        auto oldPairItr = itr->second;
        auto newPair = *oldPairItr;
        m_list.erase(m_map[key]);
        m_list.push_front(newPair);
        m_map[key] = m_list.begin();

        return newPair.second;
    }
    
    void put(int key, int value) {
        // 判断当前key是否存在
        auto itr = m_map.find(key);
        if (itr != m_map.end()) {
            // 找到key值，链表删除对应的节点
            m_list.erase(m_map[key]);
        } else {
            // key不存在，判断容量
            if (m_list.size() >= m_capacity) {
                auto lastPair = m_list.back();
                int lastKey = lastPair.first;
                m_map.erase(lastKey);
                m_list.pop_back();
            }
        }

        // 在链表尾部插入新节点
        m_list.push_front(make_pair(key, value));
        // 更新节点位置
        m_map[key] = m_list.begin();
    }

private:
    int m_capacity;
    // 节点为k-v对，
    list<pair<int, int>> m_list;
    unordered_map<int, list<pair<int, int>>::iterator> m_map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

