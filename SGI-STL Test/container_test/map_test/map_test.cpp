#include <map>
#include <iostream>

using namespace std;

template <typename T>
void printMap(T& m)
{
    cout << "{ ";
    for (auto& n : m) {
        cout << n.first << " : " << n.second << " ";
    }
    
    cout << "}\n";
}

int main()
{
    // map 构造函数
    map<string, int> simap;
    simap["why"] = 1;
    simap["always"] = 2;
    simap["me"] = 3;
    
    printMap(simap);
    
    // 插入操作
    pair<string, int> value("steve", 4);
    simap.insert(value);

    printMap(simap);
    
    // operator[]
    int number = simap["steve"];

    cout << "number = " << number << endl;
    // find 查找
    auto it = simap.find("why");
    if (it != simap.end()) {
        cout << "why found" << endl;
        simap.erase(it);  // erase
    }
    printMap(simap);

    return 0;
}
