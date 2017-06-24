#include <iostream>
#include "List.h"

int main() {
    List a, x;
    IntNode b(1);
    StrNode c("aaaa");
    DouNode d(11.21);
    IntNode e(2);
    a.Push_back(b);
    a.Push_back(c);
    a.Push_back(d);
    a.Print();
    cout << "创建第一个链表" << "\n";
    x.Push_back(c);
    x.Push_back(d);
    x.Push_back(b);
    x.Push_back(e);
    x.Print();
    cout << "创建第二个链表" << "\n";
    x.Combine(a);
    x.Print();
    cout << "联合两个链表" << "\n";
    x.Turn();
    x.Print();
    cout << "逆转链表" << "\n";
    x.Delete(2);
    x.Print();
    cout << "删除第二个节点" << "\n";
    x.InsertK(2, c);
    x.Print();
    cout << "插入第二个节点,值为aaaa" << "\n";

}