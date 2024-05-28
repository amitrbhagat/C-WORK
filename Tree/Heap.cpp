#include <bits/stdc++.h>
using namespace std;

class Heap
{

    vector<int> heap;

public:
    Heap()
    {
    }
    void insert(int data);

    int peek();

    void Heapify(int i);

    int Delete();

    int isEmpty();
};

void Heap::insert(int data)
{

    heap.push_back(data);

    int x = heap.size() - 1;

    int par = (x - 1) / 2;

    while (heap[x] < heap[par])
    {

        swap(heap[x], heap[par]);

        x = par;
        par = (x - 1) / 2;
    }
}

int Heap::peek()
{

    return heap[0];
}

void Heap::Heapify(int i)
{

    int left = 2 * i + 1;

    int right = 2 * i + 2;

    int minidx = i;

    if (left < heap.size() && heap[minidx] > heap[left])
    {

        minidx = left;
    }

    if (right < heap.size() && heap[minidx] > heap[right])
    {

        minidx = right;
    }

    if (minidx != i)
    {

        swap(heap[i], heap[minidx]);

        Heapify(minidx);
    }
}

int Heap::Delete()
{

    int data = heap[0];

    swap(heap[0], heap[heap.size() - 1]);

    heap.pop_back();

    Heapify(0);

    return data;
}

int Heap::isEmpty()
{

    return heap.empty();
}

int main()
{

    Heap pq;

    pq.insert(3);

    pq.insert(7);

    pq.insert(9);

    pq.insert(4);

    pq.insert(1);

    pq.insert(5);

    while (!pq.isEmpty())
    {

        cout << pq.peek() << " ";

        pq.Delete();
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void Heapify(int arr[], int i, int n)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int maxidx = i;

    if (left < n && arr[left] > arr[maxidx])
    {
        maxidx = left;
    }

    if (right < n && arr[right] > arr[maxidx])
    {
        maxidx = right;
    }

    if (maxidx != i)
    {
        int temp = arr[i];
        arr[i] = arr[maxidx];
        arr[maxidx] = temp;

        Heapify(arr, maxidx, n);
    }
}

void HeapSort(int arr[], int n)
{

    for (int i = n / 2; i >= 0; i--)
    {
        Heapify(arr, i, n);
    }

    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        Heapify(arr, 0, i);
    }
}

int main()
{
    int n = 5;
    int arr[n] = {1, 2, 4, 5, 3};
    HeapSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

static void findPrefixesUtil(TrieNode root, char[] prefix,
                             int ind)
{
    // Corner case
    if (root == null)
        return;

    // Base case
    if (root.freq == 1)
    {
        prefix[ind] = '\0';
        int i = 0;
        while (prefix[i] != '\0')
            System.out.print(prefix[i++]);
        System.out.print("  ");
        return;
    }

    for (int i = 0; i < MAX; i++)
    {
        if (root.child[i] != null)
        {
            prefix[ind] = (char)i;
            findPrefixesUtil(root.child[i], prefix, ind + 1);
        }
    }
}

Node removeCancellableNodes(Node listHead)
{
    if (listHead == null)
    {
        return null;
    }
    Stack<Node> stack = new Stack<Node>();
    Node node = listHead;
    while (node != null)
    {
        if (node.value < 0)
        {
            int sum = node.value;
            while (!stack.isEmpty())
            {
                Node temp = stack.pop();
                sum += temp.value;
                if (sum == 0)
                {
                    temp = stack.peek();
                    if (temp == null)
                    {
                        listHead = node->next;
                    }
                    else
                    {
                        temp->next = node->next;
                    }
                    break;
                }
            }
        }
        else
        {
            stack.push(node);
        }
        node = node.next;
    }
    return listHead;
}