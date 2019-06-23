#pragma once

namespace midterm
{
	class Class3
	{
	public:
		Class3(int x);
		virtual ~Class3();
		Class3 operator+(const Class3& other);

		inline int GetX() const;
	private: 
		int mX;
	};
}