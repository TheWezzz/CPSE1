#ifndef set_h
#define set_h

#include "array"
#include "iostream"

class set {
private:
    std::array<int, 10> entries;
    std::array<bool, 10> occupied;

public:
    set() {
        for (auto i = 0; i <= 9; i++) {
            occupied[i] = false;
        }
    }
    unsigned int size = 0;

    std::array<int, 10> get_occupied_entries() {
        unsigned int count = 0;
        std::array<int, 10> res;
        for (auto i = 0; i <= 9; i++) {
            if (occupied[i]) {
                res[count] = entries[i];
                count++;
            }
        }
        return res;
    }

    void add(int x) {
        if (contains( x )) return;
        for (auto i = 0; i <= 9; i++) {
            if (!occupied[i]) {
                entries[i] = x;
                size++;
                occupied[i] = true;
                return;
            }
        }
    }

    void remove(int x) {
        for (auto i = 0; i <= 9; i++) {
            if (entries[i] == x) {
                size--;
                occupied[i] = false;
                return;
            }
        }
    }

    bool contains(int x) {
        for (auto i = 0; i <= 9; i++) {
            if(!occupied[i]) {
                continue;
            }else if (entries[i] == int(x)) {
                std::cout << "error. " << x << " already exists!" << std::endl;
                return true;
            }
        }
        return false;
    }
};

void operator<<(std::ostream& lhs, set& rhs) {
    std::array<int, 10> x = rhs.get_occupied_entries();

    for (unsigned int i = 0; i <= rhs.size-1; i++) {
        lhs << x[i] << std::endl;
    }
    return;
}


#endif //set_h
