#pragma once
#include <iostream>

template <class T>
class Vector {
public:
    Vector();//构造函数，初始化列表
    ~Vector();//析构函数，释放内存
    Vector(const Vector& vec);//深拷贝

    void Push_Back(const T& value);//向实例化对象尾部增添元素
    void Pop_Back();//删除实例化对象最后一个元素
    void insert(size_t it, const T& value);//向容器it位置插入元素
    void erase(size_t it);//从容器it位置删除元素
    const T& operator[](size_t index) const;//[]运算符重载，取出容器第index个元素
    Vector& operator=(const Vector& vec);//=赋值运算符重载
    bool operator==(const Vector& vec) const;//==号运算符重载，判断两个vector是否相等
    T front() const;//取出vector容器第一个元素
    T back() const;//取出vector容器最后一个元素
    T* begin();//取出vector容器首地址
    T* end();//取出vector容器最后一个元素的下一个地址
    size_t Size() const;//获取实例化对象容器大小
    size_t Capacity() const;//获取实例化对象容器容量
    bool empty();//判断容器是否为空

private:
    void ReAlloc(size_t newCapacity);//分配内存空间

private:
    T* m_Data;
    size_t m_Size;//容器大小
    size_t m_Capacity;//容器容量
};
