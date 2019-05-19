// Whitespace.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <cassert>
#include <iostream>

using namespace std;

namespace samples
{
	bool print(std::string::size_type n, std::string const& s)
	{
		if (n == std::string::npos) {
			std::cout << "not found\n";
			return false;
		}
		else {
			std::cout << "found, position is : " << n <<endl;//s.substr(n) << '\n';
			return true;
		}
	}
	string GetSubWithWhitespace(std::string const& s)
	{
		string::size_type n;
		n = s.find(" ");
		string subString;
		subString = s.substr(n);

		return subString;
	}
	string GetSubWithWhitespaceAndTab(std::string const& s)
	{
		string::size_type whitespaceN;
		string::size_type tabN;
		string::size_type returnN;
		whitespaceN = s.find(" ");
		tabN = s.find("\t");
		if (whitespaceN > tabN)
		{
			returnN = tabN;
		}
		else if (whitespaceN < tabN)
		{
			returnN = whitespaceN;
		}
		else
		{
			returnN = tabN;
		}

		string subString;
		if (returnN == string::npos)
		{
			returnN = (unsigned int)0;
		}
		subString = s.substr(returnN);

		return subString;
	}
	string trimLspaces(std::string const& s)
	{
		string::size_type n;
		n = s.find(" ");
		int tempCount=0;
		string trimmedString;
		while (true)
		{
			if (s[tempCount] == ' ' || s[tempCount] == '\t')
			{
				//trimmedString = s.substr(1);
			}
			if (s[tempCount] != ' ' && s[tempCount] != '\t')
			{
				trimmedString = s.substr(tempCount);
				return trimmedString;
				break;
			}
			tempCount++;
			if (tempCount > 100)
			{
				break;
			}
			
		}
	}
	std::string::size_type GetPositionOfTab(std::string const& s)
	{
		string::size_type n = s.find("\t");
		if (n == std::string::npos)
		{

			return n;
		}
		else
		{

			return n;
		}

	}
}

int main()
{
	string s = "1dsa	sdi		  ji  dj	  ds  a2w	  s3s";
	string::size_type n;
	n = s.find(" ");
	samples::print(n, s);
	n = s.find("\t");
	samples::print(n, s);
	n = 1;
	string s2(s, 0, n);

	string s3 = "		aa		bb		cc";

	string::size_type n2;
	n2 = samples::GetPositionOfTab(s3);
	cout << n2 << endl;

	s3 = samples::GetSubWithWhitespaceAndTab(s3);
	s3 = samples::trimLspaces(s3);
	n2 = samples::GetPositionOfTab(s3);

	cout << n2 << endl;

	string s4 = "s3s	231421";
	int whileCount = 0;

	cout << s4.find(" ") << endl;

	if (s4.find(' ') == string::npos)
	{
		cout << "clearif" << endl;
	}

	//cout << s4.find(" ") == string::npos << endl;

	cout << s4.find("\t") << endl;

	while (s4.find(' ') != std::string::npos
		&& s4.find('\t') != std::string::npos)
	{
		cout << s4 << endl;
		s4 = samples::GetSubWithWhitespaceAndTab(s4);
		s4 = samples::trimLspaces(s4);
		cout << s4 << endl;

		whileCount++;
		if (whileCount > 64)
		{
			cout << "something is wrong" << endl;
			break;
		}
	}
	
	cout << s4 << endl;
	s4 = samples::GetSubWithWhitespaceAndTab(s4);
	s4 = samples::trimLspaces(s4);
	cout << s4 << endl;

	s4 = samples::GetSubWithWhitespaceAndTab(s4);
	s4 = samples::trimLspaces(s4);
	cout << s4 << endl;




	cout << s2 << endl;

	s = samples::GetSubWithWhitespaceAndTab(s);
	cout << s << endl;
	s = samples::trimLspaces(s);
	cout << s << endl;

	s = samples::GetSubWithWhitespaceAndTab(s);
	cout << s << endl;
	s = samples::trimLspaces(s);
	cout << s << endl;

	s = samples::GetSubWithWhitespaceAndTab(s);
	cout << s << endl;
	s = samples::trimLspaces(s);
	cout << s << endl;


	s = samples::GetSubWithWhitespaceAndTab(s);
	cout << s << endl;
	s = samples::trimLspaces(s);
	cout << s << endl;


	
	
	if ((int)s2[0] == 45)
	{

	}
	



}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
