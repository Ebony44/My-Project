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
�ɰ���	�ڵ�	����	������Ʈ	����	��	��ǥ�� ����(Suppression) ����
����(Ȱ��)	E1788	������ �Լ��� �������� ���� �Լ� "Foo::~Foo"��(��) �������մϴ�.
*/
// 3. virtual void DoSomething(int x) override { std::cout << x << std::endl; }
// -> virtual void DoSomething(char c) override { std::cout << c << std::endl; }