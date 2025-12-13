#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    
    // 第一行提示音
    if (A == 2) {
        cout << "-" << endl;
    } else {
        if (B == 1) {
            cout << "-" << endl;
        } else {
            if (A == 0) {
                cout << "biii" << endl;
            } else { // A == 1
                cout << "dudu" << endl;
            }
        }
    }
    
    // 第二行动作
    if (A == 0 || A == 2) {
        cout << "stop" << endl;
    } else { // A == 1
        cout << "move" << endl;
    }
    
    return 0;
}