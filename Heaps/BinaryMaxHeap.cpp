#include <bits/stdc++.h>
using namespace std;
class MaxHeap
{
    vector<int> heap;

private:
    int getLeftChildIndex(int parentIndex) const { return 2 * parentIndex + 1; }
    int getRightChildIndex(int parentIndex) const { return 2 * parentIndex + 2; }
    int getParentIndex(int childIndex) const { return (childIndex - 1) / 2; }

    int hasLeftChild(int index) const { return index < size(); }
    int hasRightChild(int index) const { return index < size(); }
    int hasParent(int index) const { return index >= 0; }

    int leftChild(int index) const { return heap[getLeftChildIndex(index)]; }
    int rightChild(int index) const { return heap[getRightChildIndex(index)]; }
    int parent(int index) const { return heap[getParentIndex(index)]; }

    void heapifyUp(int index)
    {
        while (hasParent(index) and parent(index) < heap[index])
        {
            swap(heap[index], heap[getParentIndex(index)]);
            index = getParentIndex(index);
        }
    }
    void heapifyDown(int index)
    {
        while (true)
        {
            int largest = index;
            if (hasLeftChild(index) and leftChild(index) > heap[largest])
            {
                largest = getLeftChildIndex(index);
            }
            if (hasRightChild(index) and rightChild(index) > heap[largest])
            {
                largest = getRightChildIndex(index);
            }

            if (largest == index)
                break;
            swap(heap[largest], heap[index]);
            index = largest;
        }
    }

public:
    MaxHeap() = default;
    explicit MaxHeap(vector<int> &elements)
    {
        for (int i = elements.size() / 2 - 1; i >= 0; i--)
        {
            heap = elements;
            heapifyDown(i);
        }
    }
    int size() const { return heap.size(); }
    int isEmpty() const { return heap.empty(); }
    void pop()
    {
        if (isEmpty())
            throw out_of_range("Heap is empty, cannot poll maximum element.");
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }
    int peek() const
    {
        if (isEmpty())
            throw out_of_range("Heap is empty, cannot retrieve maximum element.");

        return heap[0];
    }
    void push(int key)
    {
        heap.push_back(key);
        heapifyUp(size() - 1);
    }
};
int main()
{
    try
    {
        MaxHeap heap;
        // cout << "Min element: " << heap.getMin() << endl;

        heap.push(3);
        heap.push(2);
        heap.push(15);
        heap.push(5);
        heap.push(4);
        heap.push(45);

        cout << "Max element: " << heap.peek() << endl;

        heap.pop();
        cout << "Max element after removing the minimum: " << heap.peek() << endl;

        // Initialize heap from a vector
        vector<int> elements = {1, 20, 5, 7, 9, 3};
        MaxHeap heapFromVector(elements);
        cout << "Max element from vector: " << heapFromVector.peek() << endl;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }
    return 0;
}