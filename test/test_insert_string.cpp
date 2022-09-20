//
// Created by shiby on 22-9-17.
//
#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
	char* data;
	size_t length;

public:
	String(const char* str, size_t length)
			:length(length)
	{
		data = new char[length];
		if (str!=nullptr)
			strcpy(data, str);
	}
	~String()
	{
		delete[] data;
	}
	friend ostream& operator<<(ostream& os, const String& s)
	{
		cout << s.data << endl;
	}

	void insert(const String& other_str, int position)
	{
		size_t current_len = strlen(data);
		size_t istr_len = strlen(other_str.data);
		size_t A = current_len+istr_len;
		int B = max(int(A)-int(length), 0);
		int start_i = int(current_len)-B-1;
		for (int i = start_i; i>=position; --i) {
			data[i+istr_len] = data[i];
		}
		for (int i = 0; i<istr_len; ++i) {
			data[i+position] = other_str.data[i];
		}
	}

};

/*?
 * 在一个字符数组中插入一个字符数组
 * 原始数组A长度 10 已保存数据7
 * 插入数组B长度5
 * 插入位子3
 * 实现超出原始数组长度的数据自动丢失
 *
 */



int main()
{
	String s1("ABCDEFGHI", 9);
	String s2("123", 3);
	cout << s1 << endl;
	cout << s2 << endl;
	s1.insert(s2, 3);
	cout << s1 << endl;

	return 0;
}