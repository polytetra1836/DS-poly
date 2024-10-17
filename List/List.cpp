#include "List.h"
#include <iostream>

void testList()
{
    List<int> lst;
    //  测试是否为空
    std::cout << "List is empty: " << (lst.empty() ? "true" : "false") << std::endl;
    // 测试push_back
    std::cout << "Pushing back elements 0 to 9:" << std::endl;
    for (int i = 0; i < 10; ++i)
        lst.push_back(i);
    for (const auto &x : lst)
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
    // 测试迭代器遍历
    std::cout << "List elements: ";
    for (auto it = lst.begin(); it != lst.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    // 测试删除元素
    lst.pop_front();
    std::cout << "List size after popping front: " << lst.size() << std::endl;

    lst.pop_back();
    std::cout << "List size after popping back: " << lst.size() << std::endl;
    std::cout << "First element after popping front:" << lst.front() << std::endl;
    std::cout << "Last element after popping back: " << lst.back() << std::endl;
    // 测试插入元素
    lst.push_front(5);
    lst.push_front(1);
    std::cout << "List size after inserting 1 and 5 at the front: " << lst.size() << std::endl;
    std::cout << "List elements after more insertions: ";
    for (auto it = lst.begin(); it != lst.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    // 测试clear
    lst.clear();
    lst.clear();
    std::cout << "List size after clearing: " << lst.size() << std::endl;
    std::cout << "We refresh the list to its original state" << std::endl;
    std::cout << "After popping back an element:" << std::endl;
    for (int i = 0; i < 10; ++i)
        lst.push_back(i);
    // 测试前置++操作
    std::cout << "Using iterator and ++it:" << std::endl;
    for (auto it = lst.begin(); it != lst.end(); ++it)
    {
        std::cout << *it << " "; // 使用前置++操作符
    }
    std::cout << std::endl;

    // 测试后置++操作
    std::cout << "Using iterator and it++:" << std::endl;
    for (auto it = lst.begin(); it != lst.end(); it++)
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
    std::cout << std::endl; //
    // 测试后置--操作
    std::cout << "Using iterator and it--(reverse) :" << std::endl;
    for (auto it = --lst.end(); it != lst.begin(); it--)
    {
        std::cout << *it << " "; // 使用后置--操作符
    }
    std::cout << *lst.begin();
    std::cout << std::endl;
    // 测试拷贝构造函数
    std::cout << "Copying list to a new list:" << std::endl;
    List<int> lst_copy(lst); // 使用拷贝构造函数
    for (const auto &x : lst_copy)
    {
        std::cout << x << " "; // 输出拷贝的链表
    }
    std::cout << std::endl;
    if (&lst_copy != &lst)
    {
        std::cout << "The address of new list is different." << std::endl;
    }
    // 测试赋值运算符
    std::cout << "Assigning list to a new list:" << std::endl;
    List<int> lst_assign;
    lst_assign = lst; // 使用赋值运算符
    for (const auto &x : lst_assign)
    {
        std::cout << x << " "; // 输出赋值的链表
    }
    std::cout << std::endl;
    if (&lst_assign != &lst)
    {
        std::cout << "The address of new list is different." << std::endl;
    }
    // 测试移动构造函数
    std::cout << "Moving list to a new list:" << std::endl;
    List<int> lst_move(std::move(lst)); // 使用移动构造函数
    for (const auto &x : lst_move)
    {
        std::cout << x << " "; // 输出移动的链表
    }
    std::cout << std::endl;
    if (&lst_move != &lst)
    {
        std::cout << "The address of new list is different." << std::endl;
    }
    // 测试移动赋值运算符
    std::cout << "Move-assigning list to a new list:" << std::endl;
    List<int> lst_move_assign;
    lst_move_assign = std::move(lst_copy); // 使用移动赋值运算符
    for (const auto &x : lst_move_assign)
    {
        std::cout << x << " "; // 输出移动赋值的链表
    }
    std::cout << std::endl;
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