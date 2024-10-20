#include "List.h"
#include <iostream>
void printList(const List<int> &lst)
{
    for (auto it = lst.begin(); it != lst.end(); ++it)
    {
        std::cout << *it << " "; // 使用后置++操作符
    }
    std::cout << std::endl;
}
void testList()
{
    // 测试初始化列表构造函数
    List lst0 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "Using the initializer List" << std::endl;
    printList(lst0);
    //  测试是否为空
    List<int> lst;
    std::cout << "List is empty: " << (lst0.empty() ? "true" : "false") << std::endl;
    // 测试push_back
    std::cout << "Pushing back elements 0 to 9:" << std::endl;
    for (int i = 0; i < 10; ++i)
        lst.push_back(i);
    for (const auto &x : lst0)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << "List is empty: " << (lst.empty() ? "true" : "false") << std::endl;
    // 测试大小
    std::cout << "List size after adding 10 elements: " << lst.size() << std::endl;
    // 测试访问元素
    std::cout << "First element: " << lst.front() << std::endl;
    std::cout << "Last element: " << lst.back() << std::endl;
    std::cout << "First element: " << lst0.front() << std::endl;
    std::cout << "Last element: " << lst0.back() << std::endl;
    // 测试删除元素
    lst.pop_front();
    std::cout << "List size after popping front: " << lst.size() << std::endl;
    lst.pop_back();
    std::cout << "List size after popping back: " << lst.size() << std::endl;
    std::cout << "First element after popping front:" << lst.front() << std::endl;
    std::cout << "Last element after popping back: " << lst.back() << std::endl;
    // 测试插入元素
    lst.push_back(5);
    lst.push_front(1);
    std::cout << "List size after inserting 1 and 5 at the front: " << lst.size() << std::endl;
    std::cout << "List elements after more insertions: ";
    printList(lst);
    // 测试定向插入元素
    std::cout << "List elements after directional insertions: ";
    lst.insert(++lst.begin(), 66);
    printList(lst);
    // 测试定向删除
    lst.erase(++lst.begin(), --lst.end());
    std::cout << "After delete elements:" << std::endl;
    printList(lst);
    // 测试clear
    lst.clear();
    lst.clear();
    std::cout << "List size after clearing: " << lst.size() << std::endl;
    std::cout << "We refresh the list to its original state" << std::endl;
    for (int i = 0; i < 10; ++i)
        lst.push_back(i);
    // 测试前置++操作
    std::cout << "Using iterator and ++it:" << std::endl;
    printList(lst);
    printList(lst0);
    // 测试后置++操作
    std::cout << "Using iterator and it++:" << std::endl;
    for (auto it = lst.begin(); it != lst.end(); it++)
    {
        std::cout << *it << " "; // 使用后置++操作符
    }
    std::cout << std::endl;
    for (auto it = lst0.begin(); it != lst0.end(); it++)
    {
        std::cout << *it << " "; // 使用后置++操作符
    }
    std::cout << std::endl;
    // 测试前置--操作
    std::cout << "Using iterator and --it(reverse):" << std::endl;
    for (auto it = --lst.end(); it != lst.begin(); --it)
    {
        std::cout << *it << " ";
    }
    std::cout << *lst.begin();
    std::cout << std::endl;
    for (auto it = --lst0.end(); it != lst0.begin(); --it)
    {
        std::cout << *it << " ";
    }
    std::cout << *lst0.begin();
    std::cout << std::endl;
    // 测试后置--操作
    std::cout << "Using iterator and it--(reverse) :" << std::endl;
    for (auto it = --lst.end(); it != lst.begin(); it--)
    {
        std::cout << *it << " "; // 使用后置--操作符
    }
    std::cout << *lst.begin();
    std::cout << std::endl;
    for (auto it = --lst0.end(); it != lst0.begin(); it--)
    {
        std::cout << *it << " "; // 使用后置--操作符
    }
    std::cout << *lst0.begin();
    std::cout << std::endl;
    // 测试拷贝构造函数
    std::cout << "Copying list to a new list:" << std::endl;
    List<int> lst_copy(lst); // 使用拷贝构造函数
    printList(lst_copy);
    if (&lst_copy != &lst)
    {
        std::cout << "The address of new list is different." << std::endl;
    }
    // 测试赋值运算符
    std::cout << "Assigning list to a new list:" << std::endl;
    List<int> lst_assign;
    lst_assign = lst; // 使用赋值运算符
    printList(lst_assign);
    if (&lst_assign != &lst)
    {
        std::cout << "The address of new list is different." << std::endl;
    }
    // 测试移动构造函数
    std::cout << "Moving list to a new list:" << std::endl;
    List<int> lst_move(std::move(lst)); // 使用移动构造函数
    printList(lst_move);
    if (&lst_move != &lst)
    {
        std::cout << "The address of new list is different." << std::endl;
    }
    // 测试移动赋值运算符
    std::cout << "Move-assigning list to a new list:" << std::endl;
    List<int> lst_move_assign;
    lst_move_assign = std::move(lst_copy); // 使用移动赋值运算符
    printList(lst_move_assign);
    if (&lst_move_assign != &lst)
    {
        std::cout << "The address of new list is different." << std::endl;
    }
}
int main()
{
    testList();

    return 0;
}