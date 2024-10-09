#include "linkedlist.cpp"

int main()
{
    SingleLinkedList<int> a{1, 2, 3, 4, 5};
    int a_get = a.getCurrentVal();
    std::cout << a_get << std::endl;
    SingleLinkedList<char> b{'a', 'c', 'e'};
    b.setCurrentVal('g');
    b.printList();
    SingleLinkedList<char> e;
    std::cout << b.isEmpty() << " " << e.isEmpty() << std::endl;
    SingleLinkedList<double> c1;
    SingleLinkedList<double> c2{1.5, 2.0, 9.0, 4.7};
    SingleLinkedList<double> c3;
    SingleLinkedList<double> c22;
    c3 = c2;
    c1.insert(3.0);
    c2.insert(8.8);
    bool f_c3 = c3.find(2.0);
    c3.insert(8.8);
    c1.printList();
    c2.printList();
    c3.printList();
    e.remove();
    c1.removeCurrent();
    c1.removeCurrent();
    bool f = c2.find(9.0);
    c22 = c2;
    std::cout << "输出c22的值" << c22.getCurrentVal() << std::endl;
    c2.remove();
    e.printList();
    c2.printList();
    std::cout << "输出c2的值" << c2.getCurrentVal() << std::endl;
    c22.removeCurrent();
    std::cout << "输出c22的值" << c22.getCurrentVal() << std::endl;
    c22.printList();
    return 0;
}