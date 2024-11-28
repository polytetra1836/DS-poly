#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template <typename T>
class LeftistHeap
{
public:
    LeftistHeap() : root{nullptr} {}
    ~LeftistHeap() { makeEmpty(); }

    LeftistHeap(const LeftistHeap &rhs) : root{clone(rhs.root)} {}
    LeftistHeap(LeftistHeap &&rhs) noexcept : root{rhs.root} { rhs.root = nullptr; }

    void insert(const T &x)
    {
        root = merge(new Node(x), root);
    }
    void insert(T &&x)
    {
        root = merge(new Node(std::move(x)), root);
    }
    T deleteMin()
    {
        if (isEmpty())
            std::cerr << "Heap is empty." << std::endl;
        T minelement = root->element;
        Node *tem = root;
        root = merge(root->left, root->right);
        delete tem;
        return minelement;
    }

    void buildHeap(const std::vector<T> &data)
    {
        for (const auto &elem : data)
        {
            insert(elem);
        }
    }

    bool isEmpty() const
    {
        return root == nullptr;
    }

    void makeEmpty()
    {
        makeEmpty(root);
    }
    void printHeap() const
    {
        printHeap(root);
        std::cout << std::endl;
    }

protected:
    struct Node
    {
        T element;
        Node *left;
        Node *right;
        int npl;
        // 到没有2个子节点的子节点的最短路径，空节点默认为-1
        Node(const T &theElement) : element{theElement},
                                    left{nullptr}, right{nullptr}, npl{0} {}
        Node(T &&theElement) : element{std::move(theElement)},
                               left{nullptr}, right{nullptr}, npl{0} {}
    };
    Node *root;
    Node *merge(Node *h1, Node *h2)
    {
        if (h1 == nullptr)
            return h2;
        if (h2 == nullptr)
            return h1;
        if (h1->element > h2->element)
            std::swap(h1, h2);
        // 要求h1的最小元更小，将h2并入h1的右子树，否则交换
        h1->right = merge(h1->right, h2);
        if (h1->left == nullptr || h1->left->npl < h1->right->npl)
        {
            std::swap(h1->left, h1->right);
        }
        // 如果h1变成了右树，交换左右子节点
        if (h1->right == nullptr)
        {
            h1->npl = 0;
        }
        else
        {
            h1->npl = h1->right->npl + 1;
        }
        // 更新npl
        return h1;
    }
    Node *clone(Node *t) const
    {
        if (t == nullptr)
            return nullptr;
        return new Node(t->element, clone(t->left), clone(t->right), t->npl);
    }

    void makeEmpty(Node *t)
    {
        if (t != nullptr)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
    }
};
template <typename T>
std::vector<T> Sort(const std::vector<T> &vec)
{
    // 判断空输入
    if (vec.empty())
    {
        return {};
    }
    LeftistHeap<T> heap;
    heap.buildHeap(vec);
    std::vector<T> sortedElements;
    while (!heap.isEmpty())
    {
        sortedElements.push_back(heap.deleteMin());
    }
    return sortedElements;
}