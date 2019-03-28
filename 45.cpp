//面试题45：把数组排成最小的数
//｛3，32，321｝最小数字是321323
//
//方法：重新定义static bool compare,数字转换成字符串 
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

static bool compare(int item1, int item2){
	string m = to_string(item1);
	string n = to_string(item2);
	
	string mn = m + n;
	string nm = n + m;
	
	return mn < nm;
}

string PrintMinNumber(vector<int> numbers){
	string resu;
	if(numbers.size() <= 0){
		return resu;
	}
	
	sort(numbers.begin(), numbers.end(), compare);
	
	for(auto num: numbers){
		resu += to_string(num);
	}
	
	return resu;
}

int main(){
	vector<int> test{3,32,321};
	cout << PrintMinNumber(test);
	
	return 0;
}
