#ifndef set_h
#define set_h


class set {
private:
    std::array<int, 10> entries;

public:

    set();

    void add(int x);

    void remove(int x);

    bool contains(int);

    std::ostream operator<<(std::ostream&, const set&);

};


#endif //set_h
