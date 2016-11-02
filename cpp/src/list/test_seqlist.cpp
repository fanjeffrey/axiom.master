#include <iostream>
#include <algorithm>
#include <iterator>
#include "SeqList.h"

using namespace std;

template <class T>
void Display(SeqList<T> & list)
{
    cout << "Elements: " << list.Length() << endl;
    T * data = list.Elements();
    copy(data, data + list.Length(), ostream_iterator<T>(cout, " "));
    cout << endl;
}

int main()
{
    try{
        SeqList<int> isl;
        cout << "Created a sequencial list..." << endl;
        cout << "length = " << isl.Length() << endl;
        
        for(int i=1; i<=10; i++)
        {
            int val = i * 2;
            cout << "Inserting " << val << " at " << isl.Length() << "..." << endl;
            isl.Insert(val, isl.Length() + 1);
            cout << "Inserted. length = " << isl.Length() << endl;
        }    
        Display<int>(isl);
        
        int idx = 1;
        int val = isl.Get(idx);
        cout << "Get(" << idx << ") = " << val << "." << endl;
        idx = isl.Locate(val);
        cout << "Locate(" << val << ") = " << idx << "." << endl;
        if (idx == isl.Locate(val))
        {
            cout << val << " is at " << idx << "." << endl;
        }

        idx = 7;
        val = isl.Get(idx);
        if (idx == isl.Locate(val))
        {
            cout << val << " is at " << idx << "." << endl;
        }

        idx = isl.Length();
        val = isl.Get(idx);
        if (idx == isl.Locate(val))
        {
            cout << val << " is at " << idx << "." << endl;
        }

        val = 9999999;
        if (-1 == isl.Locate(val))
        {
            cout << "Unable to locate " << val << "." << endl;
        }

        cout << "Inserting 3 at 3 ..." << endl;
        isl.Insert(3, 3);
        Display<int>(isl);
        cout << "Deleting 3 ..." << endl;
        isl.Delete(3);
        Display<int>(isl);

        cout << "Inserting 0 at 1 ..." << endl;
        isl.Insert(0, 1);
        Display<int>(isl);
        cout << "Deleting 0 ..." << endl;
        isl.Delete(1);
        Display<int>(isl);

        cout << "Inserting 11 at 12 ..." << endl;
        isl.Insert(11, 11);
        Display<int>(isl);
        cout << "Deleting 11 ..." << endl;
        isl.Delete(11);
        Display<int>(isl);
    }
    catch(const char* ex)
    {
        cout << ex << endl;
    }
    
    return 0;
}