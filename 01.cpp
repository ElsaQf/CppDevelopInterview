//面试题1：赋值运算符函数
//题目：如下为类型CMyString的声明，请为该类型添加复制运算符函数

#include <iostream>
#include <cstring>
using namespace std;

class CMyString{
	public:
		CMyString(char *pData = nullptr);
		CMyString(const CMyString &str);
		~CMyString(void);
		
		CMyString &operator=(const CMyString &str);
		
		void Print();
	private:
		char *m_pData;
}; 

CMyString::CMyString(char *pData){
	if(pData == nullptr){
		m_pData = new char[1];
		m_pData[0] = '\0'; 
	}else{
		int length = strlen(pData);
		m_pData = new char[length+1];
		strcpy(m_pData, pData);
	}
}

CMyString::CMyString(const CMyString &str){
	int length = strlen(str.m_pData);
	m_pData = new char[length+1];
	strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString(){
	delete []m_pData;
}

CMyString &CMyString::operator=(const CMyString &str){
	if(this == &str){
		return *this;
	}
	delete []m_pData;
	m_pData = nullptr;
	m_pData = new char[strlen(str.m_pData)+1];
	strcpy(m_pData, str.m_pData);
}

void CMyString::Print(){
	cout << m_pData << endl;
}

//Test: 
//构造函数
//拷贝构造函数
//operator = 
void Test(){
	cout << "Test" << endl;
	char *text = "Hello world";
	
	CMyString str1(text);
	CMyString str2(str1);
	CMyString str3;
	str3 = str2;
	
	str1.Print();
	str2.Print();
	str3.Print(); 
}

int main(){
	Test();
}
