#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
private:
    vector<int> heap;

    int getParentIndex(int childIndex) const { return (childIndex - 1) / 2; }
    int getLeftChildIndex(int parentIndex) const { return 2 * parentIndex + 1; }
    int getRightChildIndex(int parentIndex) const { return 2 * parentIndex + 2; }

    int leftChild(int index) const { return heap[getLeftChildIndex(index)]; }
    int rightChild(int index) const { return heap[getRightChildIndex(index)]; }
    int parent(int index) const { return heap[getParentIndex(index)]; }

    bool hasLeftChild(int index) const { return getLeftChildIndex(index) < size(); }
    bool hasRightChild(int index) const { return getRightChildIndex(index) < size(); }
    bool hasParent(int index) const { return getParentIndex(index) >= 0; }

    void heapifyUp(int index)
    {
        while (hasParent(index) && parent(index) > heap[index])
        {
            swap(heap[index], heap[getParentIndex(index)]);
            index = getParentIndex(index);
        }
    }

    void heapifyDown(int index)
    {
        while (true)
        {
            int smallest = index;

            if (hasLeftChild(index) && leftChild(index) < heap[smallest])
                smallest = getLeftChildIndex(index);

            if (hasRightChild(index) && rightChild(index) < heap[smallest])
                smallest = getRightChildIndex(index);

            if (smallest == index)
                break;

            swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }

public:
    MinHeap() = default;

    explicit MinHeap(const vector<int> &elements)
    {
        heap = elements;
        for (int i = size() / 2 - 1; i >= 0; --i)
        {
            heapifyDown(i);
        }
    }

    void insert(int key)
    {
        heap.push_back(key);
        heapifyUp(size() - 1);
    }

    void removeMin()
    {
        if (isEmpty())
            throw out_of_range("Heap is empty, cannot remove minimum element.");

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int getMin() const
    {
        if (isEmpty())
            throw out_of_range("Heap is empty, cannot retrieve minimum element.");

        return heap[0];
    }

    int size() const { return heap.size(); }

    bool isEmpty() const { return heap.empty(); }
};

int main()
{
    try
    {
        MinHeap heap;
        // cout << "Min element: " << heap.getMin() << endl;

        heap.insert(3);
        heap.insert(2);
        heap.insert(15);
        heap.insert(5);
        heap.insert(4);
        heap.insert(45);

        cout << "Min element: " << heap.getMin() << endl;

        heap.removeMin();
        cout << "Min element after removing the minimum: " << heap.getMin() << endl;

        // Initialize heap from a vector
        vector<int> elements = {1, 20, 5, 7, 9, 3};
        MinHeap heapFromVector(elements);
        cout << "Min element from vector: " << heapFromVector.getMin() << endl;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}
