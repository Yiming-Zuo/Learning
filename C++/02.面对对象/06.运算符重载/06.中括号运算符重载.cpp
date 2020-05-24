// 数组类封装
int &MyArray::operator[](int pos) {
	return p_address[pos];
}