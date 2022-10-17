#ifndef set_h
#define set_h

#include "array"
#include "vector"
#include "iostream"

template<typename entry_type, const unsigned int capacity>
    class set {
    private:
        std::array <entry_type, capacity> entries;
        std::array<bool, capacity> occupied;
        unsigned int size = 0;

    public:
        set() {
            for (unsigned int i = 0; i <= capacity - 1; i++) {
                occupied[i] = false;
            }
        }

        std::vector <entry_type> get_occupied_entries() {
            unsigned int count = 0;
            std::vector <entry_type> res;
            for (unsigned int i = 0; i <= capacity - 1; i++) {
                if (occupied[i]) {
                    res.push_back( entries[i] );
                    count++;
                }
            }
            return res;
        }

        void add(entry_type x) {
            if (contains( x )) return;
            for (unsigned int i = 0; i <= capacity - 1; i++) {
                if (!occupied[i]) {
                    entries[i] = x;
                    occupied[i] = true;
                    size++;
                    return;
                }
            }
        }

        void remove(entry_type x) {
            for (unsigned int i = 0; i <= capacity - 1; i++) {
                if (entries[i] == x) {
                    occupied[i] = false;
                    size--;
                    return;
                }
            }
        }

        bool contains(entry_type x) {
            for (unsigned int i = 0; i <= capacity - 1; i++) {
                if (!occupied[i]) {
                    continue;
                } else if (entries[i] == x) {
                    return true;
                }
            }
            return false;
        }
    };

void operator<<(std::ostream& lhs, set<int, 10>& rhs) {
    std::vector<int> x = rhs.get_occupied_entries();

    for (unsigned int i = 0; i <= x.size() - 1; i++) {
        lhs << x.at( i ) << std::endl;
    }
    return;
}


#endif //set_h
