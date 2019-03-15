//面试题5：替换空格
//题目：实现一个函数，把字符串中的每个空格替换成“%20”
//例如：We are happy. -> We%20are%20happy.

#include <iostream>
#include <cstring>
using namespace std;

string replace(string s, string s1){
	int pos = s.find(" ");
	while(pos < s.length()){
		s.replace(pos, 1, s1);
		pos = s.find(" ");
	}
	return s;
}

int main(){
	string s = "We are happy";
	string s1 = "%20";
	
	cout << replace(s, s1);
	return 0;
}
