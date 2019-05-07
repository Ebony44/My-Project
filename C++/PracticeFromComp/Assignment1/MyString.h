#pragma once
//#ifndef MYSTRING_H
//#define MYSTRING_H
namespace assignment1
{
	class MyString
	{
        private:

			const char* mCString;
        	int mCLength;
	public:
	
		MyString(const char* s);
		MyString(const MyString& other); // copy constructor
        //MyString& MyString::operator=(const MyString& other); // Overload for Deep Copy
		~MyString();
		
		unsigned int GetLength() const;
		const char* GetCString() const;
		void Append(const char* s);
		MyString operator+(const MyString& other) const;
		int IndexOf(const char* s);
		int LastIndexOf(const char* s);
		void Interleave(const char* s);
		bool RemoveAt(unsigned int i);
		void PadLeft(unsigned int totalLength);
		void PadLeft(unsigned int totalLength, const char c);
		void PadRight(unsigned int totalLength);
		void PadRight(unsigned int totalLength, const char c);
		void Reverse();
		bool operator==(const MyString& rhs) const;
		MyString& operator=(const MyString& rhs);
		void ToLower();
		void ToUpper();
	};
}

//#endif