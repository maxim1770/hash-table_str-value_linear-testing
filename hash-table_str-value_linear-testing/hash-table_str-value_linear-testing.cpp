// лаба3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<windows.h>
#include<vector>
#include<list>
#include<iomanip>
using namespace std;
class Hashtable
{
private:
    int size;
    vector<list<char>>Table;
public:
    Hashtable(const int& _s)
    {
        size = _s;
        Table.resize(size);
    }
    int getHash(const char& symbol)
    {
        return abs(11 * (symbol - 'A' + 1)) % size;
    }
    void Add(const char& symbol)
    {
        Table[getHash(symbol)].push_back(symbol);
    }
    void Print()
    {
        cout << "Table:" << endl;
        for (int i = 0; i < Table.size(); i++)
        {
            cout << i << ": ";
            for (auto it : Table[i])
                cout << it << " ";
            // copy(Table[i].begin(), Table[i].end(), ostream_iterator<char>(cout, " "));
            cout << endl;
        }
    }
};


int main()
{
    const int M = 5;
    Hashtable table(M);
    table.Add('E');
    table.Add('A');
    table.Add('S');
    table.Add('Y');
    table.Add('Q');
    table.Add('U');
    table.Add('T');
    table.Add('I');
    table.Add('O');
    table.Add('N');
    table.Print();
    return 0;
}