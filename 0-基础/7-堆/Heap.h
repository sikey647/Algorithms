#include <vector>

// 堆的两个特点
//  1. 一个完全二叉树
//  2. 每个节点的值都【大于等于/小于等于】其【子树每个节点/左右子节点】的值

// 如何实现堆
//  数组存储：
//      下标从1开始：节点i、左子节点i*2、右子节点i*2+1、父节点i/2
//      下标从0开始：节点i、左子节点i*2+1、右子节点i*2+2、父节点(i-1)/2       
//  插入：放到堆最后，从下往上堆化【见push】
//  删除：把最后一个节点放到堆顶，从上往下堆化【见pop】
//  堆化复杂度：跟树的高度成正比，O(logn)

// 堆排序
//  步骤：建堆+排序
//  建堆（原地）：
//      方式一：假设堆中只包含i=1的数据，依次调用插入操作将i=2...n树插入堆中（从下往上堆化）
//      方式二：从最后一个非叶子节点，依次堆化（从上往下）【见Heap(array)】
//          复杂度：O(n)
//  排序：将堆顶元素i=1和最后一个元素i=n交换顺序，然后将n-1个元素重新建堆。直至堆中只剩下i=1
//      复杂度：O(nlogn)
//      不稳定：因为将堆中最后一个元素和堆顶元素进行交换，有可能会改变相同数据的原始相对顺序。
//      快排性能好：
//          1). 堆排中的堆化操作，数据跳着访问（1,2,4,8）；快排局部顺序访问，对CPU缓存友好。
//          2). 相同的数据，堆排的数据交换次数多于快排。

class Heap {
public:
    Heap(int cap);
    Heap(const std::vector<int>& array);    // 建堆，方式二
    Heap() = delete;
    
    int push(int val);  // 插入，0：成功，1:失败
    int pop();          // 删除，0：成功，1:失败    
    int top();
    bool empty();
    void print();

    // 堆排序
    static void sort(std::vector<int>& array);

private:
    void heapify(int index);
    void build();

    static void heapify(std::vector<int>& array, int end, int index);
    static void build(std::vector<int>& array, int size);

private:
    std::vector<int> m_array;
    int m_capacity;
    int m_size;
};
