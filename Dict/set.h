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
        for (auto i: occupied) {
            occupied[i] = false;
        }
    }

    std::array<int, 10> get_occupied_entries() {
        unsigned int count = 0;
        std::array<int, 10> res;
        for (auto i: occupied) {
            if (occupied[i]) {
                res[count] = entries[i];
                count++;
            }
        }
        return res;
    }

    void add(int x) {
        if (contains( x )) return;
        for (auto i: occupied) {
            if (!occupied[i]) {
                entries[i] = x;
                occupied[i] = true;
                return;
            }
        }
    }

    void remove(int x) {
        for (auto i: entries) {
            if (entries[i] == x) {
                occupied[i] = false;
                return;
            }
        }
    }

    bool contains(int x) {
        for (auto i: entries) {
            if (entries[i] == x) return true;
        }
        return false;
    }
};

//std::ostream operator<<(std::ostream& lhs, set& rhs) {
//    std::array<int, 10> x = rhs.get_occupied_entries();
//
//    return lhs << rhs.get_occupied_entries()[0];
//}


#endif //set_h
