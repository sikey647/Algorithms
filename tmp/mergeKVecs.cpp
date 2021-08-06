#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Elem {
    Elem(int v, int w, int i) : val(v), which(w), index(i) {}
    int val;
    int which;
    int index;
};

vector<int> mergeKVecs(const vector<vector<int> >& datas) {
    vector<int> res;

    // 小顶堆
    auto greater = [](Elem* e1, Elem* e2)->bool{
        return e1->val > e2->val;
    };
    
    priority_queue<Elem*, vector<Elem*>, decltype(greater)> heap(greater);
    // 哪个序列，哪个位置
    for (int i = 0; i < datas.size(); i++) {
        if (datas[i].size() != 0) {
            // 入堆
            heap.push(new Elem(datas[i][0], i, 0));
        }
    }

    while (!heap.empty()) {
        Elem* tmp = heap.top();
        res.push_back(tmp->val);
        heap.pop();
        if (datas[tmp->which].size() > tmp->index + 1) {
            heap.push(new Elem(datas[tmp->which][tmp->index + 1], tmp->which, tmp->index + 1));
        }
        delete tmp;
    }
    
    return res;
}

int main() {
    vector<vector<int>> datas = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6}
    };

    vector<int> res = mergeKVecs(datas);

    for (auto data : res) {
        cout << data << " ";
    }

    cout << endl;
}