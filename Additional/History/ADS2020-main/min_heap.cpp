#include <iostream>
#include <vector>

using namespace std;

class MinHeap
{
public:
    vector<int> a;

    int parentIndex(int i)
    {
        return (i - 1) / 2;
    }
    int leftChildIndex(int i)
    {
        return 2 * i + 1;
    }

    int rightChildIndex(int i)
    {
        return 2 * i + 2;
    }

    void insert(int k)
    {
        a.push_back(k);
        int i = a.size() - 1;
        siftUp(i);
    }
    void siftUp(int i)
    {
        while (i > 0 && a[parentIndex(i)] > a[i])
        {
            swap(a[parentIndex(i)], a[i]);
            i = parentIndex(i);
        }
    }

    void heapifyDown(int i)
    {
        if (leftChildIndex(i) > a.size() - 1)
            return;

        int j = leftChildIndex(i);
        if (rightChildIndex(i) < a.size() && a[rightChildIndex(i)] < a[leftChildIndex(i)])
            j = rightChildIndex(i);

        if (a[i] > a[j])
        {
            swap(a[i], a[j]);
            heapifyDown(j);
        }
    }

    int extractMin()
    {
        int root = a[0];
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0)
            heapifyDown(0);
        return root;
    }

    void decreaseKey(int i, int new_value)
    {
        a[i] = new_value;
        siftUp(i);
    }

    void increaseKey(int i, int new_value)
    {
        a[i] = new_value;
        heapifyDown(i);
    }

    void print()
    {
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << " ";
        cout << endl;
    }

    int getMin()
    {
        return a[0];
    }
};

int main()
{
    MinHeap *min_heap = new MinHeap();
    min_heap->insert(10);
    min_heap->insert(20);
    min_heap->insert(30);
    min_heap->insert(40);
    min_heap->insert(50);
    min_heap->insert(60);
    min_heap->insert(70);

    int n = min_heap->a.size();
    vector<int> sorted;
    for (int i = 0; i < n; i++)
    {
        sorted.push_back(min_heap->extractMin());
    }

    for (int i = 0; i < n; i++)
        cout << sorted[i] << " ";
    return 0;
}

// 6 8 6 15 10 18 9
//