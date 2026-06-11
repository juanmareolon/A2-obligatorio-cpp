#include <string>

using namespace std;

int hash2(string key) {
    int h = 0;
    for (int i = 0; i < key.length(); i++) {
        h = (h * 131) + key[i];
    }
    return (h << 1) | 1; // impar (clave para doble hashing)
}

int hash3(string key) {
    int h = 0;
    for (int i = 0; i < key.length(); i++)
        h = 31 * h + int(key[i]);
    return h;
}