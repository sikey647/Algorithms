#include <vector>
#include <cmath> 
#include <iostream>
using namespace std;

vector<int> absSort(vector<int>& data) {
    vector<int> res(data.size());

    int i = 0;

    while (data[i] < 0) {
        i++;
    }

    // 都为正（j=-1）、都为负(i=data.size())
    int j = i - 1, k = 0;
    while (j >= 0 && i < data.size()) {
        res[k++] = abs(data[j]) > data[i] ? data[i++] : data[j--];
    }

    while (j >= 0) {
        res[k++] = data[j--];
    }

    while (i < data.size()) {
        res[k++] = data[i++];
    }

    return res;
}

int main() {
    vector<int> data = {-9, -3, -1, 2, 6, 15, 19, 30};
    //vector<int> data = {-9};
    //vector<int> data = {6};
    //vector<int> data = {-9, -3, -1};
    //vector<int> data = {2, 6, 15, 19, 30};
    vector<int> res = absSort(data);
    for (auto& e : res) {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}