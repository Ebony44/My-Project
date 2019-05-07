#include <cassert>
#include <iostream>

#include "MyString.h"

using namespace std;

namespace assignment1
{

    class MyString
    {
        private:
            const char* mCString;
            int mCLength;
        public:
            MyString(const char* s);
            ~MyString();
            unsigned int MyString::GetLength() const
            {
                int mTemp=0;
                while(true)
                {
                    if(mCString[mTemp] == NULL)
                    {
                        break;
                    }
                    mTemp++;
                }
                
                return mTemp;
            }
            

        const char* MyString::GetCString() const
        {
            return 0;
        }

        void MyString::Append(const char* s)
        {
        }

        MyString MyString::operator+(const MyString& other) const
        {
            
            return MyString("temporary");
        }

        int MyString::IndexOf(const char* s)
        {
            return 0;
        }

        int MyString::LastIndexOf(const char* s)
        {
            return 0;
        }

        void MyString::Interleave(const char* s)
        {
        }

        bool MyString::RemoveAt(unsigned int index)
        {
            return false;
        }

        void MyString::PadLeft(unsigned int totalLength)
        {
        }

        void MyString::PadLeft(unsigned int totalLength, const char c)
        {
        }

        void MyString::PadRight(unsigned int totalLength)
        {
        }

        void MyString::PadRight(unsigned int totalLength, const char c)
        {
        }

        void MyString::Reverse()
        {
        }

        bool MyString::operator==(const MyString& rhs) const
        {
            return false;
        }

        MyString& MyString::operator=(const MyString& rhs)
        {

            char newChar[512];
            if(this != &rhs)
            {
                
                int mTemp=0;
                
                while(true)
                {
                    newChar[mTemp]= mCString[mTemp];

                    if(mCString[mTemp] == NULL)
                    {
                        break;
                    }
                    mTemp++;
                }
                copy(rhs.mCString, rhs.mCString + mTemp, newChar);
                delete [] mCString;
                //mCString = new char[mTemp+1];
                mCString = newChar;
                mCLength = rhs.mCLength;
                //mCString = rhs.mCString;
            }
            
            return *this;
        }

        void MyString::ToLower()
        {
        }

        void MyString::ToUpper()
        {
        }




    };
    
    //const int LINE_SIZE = 512;
    MyString::MyString(const char* s)
    {
        mCString = s;
    }

    MyString::MyString(const MyString& other)
    {
        mCLength = other.mCLength;
        mCString = other.mCString;
    }

    MyString::~MyString()
    {

    }

    
}