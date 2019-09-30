#pragma once
#include <iostream>

class Example6Parent
{
public:
	Example6Parent() = default;
	virtual ~Example6Parent() = default;
	virtual void DoSomething(char c) { std::cout << c << std::endl; }
};

class Example6Child: Example6Parent
{
public:
	Example6Child() : Example6Parent() {};
	virtual ~Example6Child() override = default;
	virtual void DoSomething(char c) override { std::cout << "override" << c << std::endl; }
};


// 1. Foo final -> Foo
// 2. ~Bar() = delete; -> virtual ~Bar() = default
/*
심각도	코드	설명	프로젝트	파일	줄	비표시 오류(Suppression) 상태
오류(활성)	E1788	삭제된 함수가 삭제되지 않은 함수 "Foo::~Foo"을(를) 재정의합니다.
*/
// 3. virtual void DoSomething(int x) override { std::cout << x << std::endl; }
// -> virtual void DoSomething(char c) override { std::cout << c << std::endl; }