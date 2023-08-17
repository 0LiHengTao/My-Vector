#include"CMake_MyVector.cpp"
#include<iostream>

using namespace std;

template<class T>
void PrintVector(const Vector<T>& vector) {
	for (size_t i = 0; i < vector.Size(); i++) {
		cout << vector[i] << endl;
	}
}
int main() {
	//实例化对象
	Vector<int> vector;
	vector.Push_Back(1);
	vector.Push_Back(2);
	vector.Push_Back(3);
	vector.Push_Back(4);
	PrintVector(vector);
	cout << "-------------------" << endl;
	//vector.Pop_Back();
	Vector<int> vector2(vector);
	vector2.insert(2, 100);
	vector2.erase(0);
	PrintVector(vector2);
	cout << "-------------------" << endl;

	Vector<int> vector3 = vector;
	PrintVector(vector3);
	cout << "vector3和vector2是否相等:" << endl;
	if (vector3 == vector2) {
		cout << "相等" << endl;
	}
	else {
		cout << "不相等" << endl;
	}
	cout << "--------------------" << endl;

	cout << "vector是否为空：" << vector.empty() << endl;
	cout << "vector的大小为：" << vector.Size() << endl;
	cout << "vector的容量为：" << vector.Capacity() << endl;
	cout << "vector第一个元素的地址为：" << vector.begin() << endl;
	cout << "vector第一个元素为：" << vector.front() << endl;
	cout << "vector最后一个元素的下一个地址为：" << vector.end() << endl;
	cout << "vector最后一个元素为：" << vector.back() << endl;

	return 0;
}