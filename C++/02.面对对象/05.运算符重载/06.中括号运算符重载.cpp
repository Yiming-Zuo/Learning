// 数组类封装
// 链式编程：返回自身引用
int &MyArray::operator[](int pos) {
	return p_address[pos];
}