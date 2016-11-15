#if !defined(BinaryTree_H)
#define BinaryTree_H

#include <string>
#include <sstream>
#include "../stack/SeqStack.h"

using namespace std;

template <typename T>
class BinaryTree;

template <typename T>
class BinaryTreeNode
{
  public:
    BinaryTreeNode() : lchild(nullptr), rchild(nullptr) {}

  private:
    T data;
    BinaryTreeNode<T> *lchild;
    BinaryTreeNode<T> *rchild;

    //
    friend class BinaryTree<T>;
};

template <typename T>
class BinaryTree
{
  public:
    virtual string PreOrder();
    virtual string PreOrderWithArray();
    virtual string PreOrderWithStack();

  public:
    BinaryTree() : root(nullptr) {}
    BinaryTree(string &glist) { root = CreateFrom(glist); }

  protected:
    virtual BinaryTreeNode<T> *CreateFrom(string &);
    virtual void Print(BinaryTreeNode<T> *, ostringstream &);

  protected:
    BinaryTreeNode<T> *root;
};

template <typename T>
BinaryTreeNode<T> *BinaryTree<T>::CreateFrom(string &glist)
{
    BinaryTreeNode<T> *arr[100];
    BinaryTreeNode<T> *p = nullptr, *r = nullptr;
    int top = -1, k, j = 0;
    char ch;

    for (int i = 0; i < glist.size(); i++)
    {
        ch = glist[i];
        switch (ch)
        {
        case '(':
            top++;
            arr[top] = p;
            k = 1;
            break;
        case ')':
            top--;
            break;
        case ',':
            k = 2;
            break;
        default:
            p = new BinaryTreeNode<T>;
            p->data = ch;

            if (r == nullptr)
            {
                r = p;
            }
            else
            {
                switch (k)
                {
                case 1:
                    arr[top]->lchild = p;
                    break;
                case 2:
                    arr[top]->rchild = p;
                    break;
                }
            }
        }
    }

    return r;
}

// PreOrder with recursion
template <typename T>
string BinaryTree<T>::PreOrder()
{
    if (root == nullptr)
    {
        return "The tree is empty.";
    }

    ostringstream os;
    os << "Nodes in pre-order:";

    Print(root, os);

    return os.str();
}

template <typename T>
void BinaryTree<T>::Print(BinaryTreeNode<T> *n, ostringstream &os)
{
    if (n)
    {
        os << " " << n->data;
        Print(n->lchild, os);
        Print(n->rchild, os);
    }
}

// PreOrder with array
template <typename T>
string BinaryTree<T>::PreOrderWithArray()
{
    if (root == nullptr)
    {
        return "The tree is empty.";
    }

    ostringstream os;
    os << "Nodes in pre-order:";

    int top = -1;
    BinaryTreeNode<T> *stack[100];
    stack[++top] = root;
    BinaryTreeNode<T> *t;
    while (top > -1)
    {
        t = stack[top--];
        if (t)
        {
            os << " " << t->data;
            stack[++top] = t->rchild;
            stack[++top] = t->lchild;
        }
    }

    return os.str();
}

// PreOrder with stack
template <typename T>
string BinaryTree<T>::PreOrderWithStack()
{
    if (root == nullptr)
    {
        return "The tree is empty.";
    }

    ostringstream os;
    os << "Nodes in pre-order:";

    SeqStack<BinaryTreeNode<T> *> stack;
    stack.Push(root);
    BinaryTreeNode<T> *t;
    while (!stack.IsEmpty())
    {
        t = stack.GetTop();
        stack.Pop();
        if (t)
        {
            os << " " << t->data;
            stack.Push(t->rchild);
            stack.Push(t->lchild);
        }
    }

    return os.str();
}

#endif