#include <cstring>
#include <iostream>

#include "MyString.h"

using namespace std;
using namespace assignment1;

int main()
{
    cout << "Assignment1" << endl;
    char* c1 = "char";
    //const int LINE_SIZE = 512;
    
    for(int i=0;i<=strlen(c1);i++)
    {
        cout << c1[i];
    }
    bool bNull = false;
    int j = 0;
    while(!bNull)
    {
        cout << c1[j];
        
        
        if(c1[j]==NULL)
        {
            break;
        }
        j++;
    }
    cout << "the Length is: " << j << endl;
    cout << c1 << endl;

   //MyString ms(c1);
   //cout << ms.GetLength() << endl;
}