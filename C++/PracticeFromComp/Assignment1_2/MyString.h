#pragma once

namespace assignment1
{
	class MyString
	{
	private:
		
		char* mBuffer;
		unsigned int mSize;
	public:
		MyString(const char* s);
		MyString(const MyString& other);
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

		unsigned int GetSize(const char* s);
		char* GetCopiedString(const char* s, const int size);
		char* CharAppend(char* first, char* second, const int firstSize, const int secondSize);
		char FillBlank(char* s);


	};
}