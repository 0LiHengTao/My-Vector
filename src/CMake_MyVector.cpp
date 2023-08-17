#include "CMake_MyVector.h"

// 将成员函数的实现移到类外部分
template <class T>
Vector<T>::Vector() : m_Data(nullptr), m_Size(0), m_Capacity(0) {
    ReAlloc(2);
}

template <class T>
Vector<T>::~Vector() {
    if (m_Data != nullptr) {
        delete[] m_Data;
        m_Data = nullptr;
    }
}

template <class T>
Vector<T>::Vector(const Vector& vec) {
    this->m_Size = vec.m_Size;
    this->m_Capacity = vec.m_Capacity;
    this->m_Data = new T[vec.m_Capacity];//深拷贝 分配缓冲区

    //数据拷贝
    for (size_t i = 0; i < vec.m_Size; i++) {
        this->m_Data[i] = vec.m_Data[i];
    }
}

template <class T>
void Vector<T>::Push_Back(const T& value) {
    if (m_Size >= m_Capacity) {
        ReAlloc(m_Capacity + m_Capacity / 2);
    }
    m_Data[m_Size] = value;
    m_Size++;
}

template <class T>
void Vector<T>::Pop_Back() {
    if (this->m_Size > 0) {
        this->m_Size--;
        this->m_Data[this->m_Size].~T();
    }
}

template <class T>
void Vector<T>::insert(size_t it, const T& value) {
    if (it <= this->m_Size) {
        if (m_Capacity <= m_Size) {
            ReAlloc(m_Capacity + m_Capacity / 2);
        }
        //从it位置开始，元素向后移一位
        for (size_t i = m_Size; i > it; i--) {
            m_Data[i] = m_Data[i - 1];
        }
        m_Data[it] = value;
        m_Size++;
    }
    else {
        std::cout << "插入位置无法索引，无法插入新数据" << std::endl;
    }
}

template <class T>
void Vector<T>::erase(size_t it) {
    if (it < m_Size) {
        for (size_t i = it; i < m_Size; i++) {
            m_Data[i] = m_Data[i + 1];
        }

        //销毁最后一个元素
        m_Data[m_Size - 1].~T();
        m_Size--;
    }
    else {
        std::cout << "删除位置无法索引，无法删除数据" << std::endl;
    }
}

template <class T>
const T& Vector<T>::operator[](size_t index) const {
    if (index < m_Size) {
        return m_Data[index];
    }
    else {
        //处理超出索引范围的情况
        throw std::out_of_range("Index out of range");
    }
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector& vec) {
    //避免自我赋值
    if (this != &vec) {
        delete[] this->m_Data;//释放当前内存

        this->m_Size = vec.m_Size;
        this->m_Capacity = vec.m_Capacity;
        this->m_Data = new T[this->m_Capacity];

        for (size_t i = 0; i < this->m_Size; i++) {
            this->m_Data[i] = vec.m_Data[i];
        }
    }
    return *this;//链式赋值
}

template <class T>
bool Vector<T>::operator==(const Vector& vec) const {
    if (this->m_Size != vec.m_Size) {
        return false;
    }
    for (size_t i = 0; i < this->m_Size; i++) {
        if (this->m_Data[i] != vec.m_Data[i]) {
            return false;
            break;
        }
    }
    return true;
}

template <class T>
T Vector<T>::front() const {
    return this->m_Data[0];
}

template <class T>
T Vector<T>::back() const {
    return this->m_Data[m_Size - 1];
}

template <class T>
T* Vector<T>::begin() {
    return this->m_Data;
}

template <class T>
T* Vector<T>::end() {
    return &this->m_Data[m_Size];
}

template <class T>
size_t Vector<T>::Size() const {
    return this->m_Size;
}

template <class T>
size_t Vector<T>::Capacity() const {
    return this->m_Capacity;
}

template <class T>
bool Vector<T>::empty() {
    if (this->m_Size != 0) {
        return false;
    }
    else {
        return true;
    }
}

template <class T>
void Vector<T>::ReAlloc(size_t newCapacity) {
    //1.分配一块新内存
    //2.拷贝原有内存的数据到这块新内存上
    //3.释放原有内存空间
    if (m_Size > newCapacity) {
        m_Size = newCapacity;
    }
    T* newSpace = new T[newCapacity];
    for (size_t i = 0; i < m_Size; i++) {
        newSpace[i] = m_Data[i];
    }
    delete[] m_Data;
    m_Data = newSpace;
    m_Capacity = newCapacity;
}


