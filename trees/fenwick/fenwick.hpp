#include <functional>
#include <cstdint>
#include <iostream>
#include <vector>

template<typename T>
class FenwickTree {
public:
    FenwickTree(std::vector<T> &values, std::function<T(T, T)> op, T neutral) {
        _data = new T[values.size()];
        for (int i = 0; i < values.size(); i++) {
            _data[i] = neutral;
        }
        _size = values.size();
        for (int i = 0; i < values.size(); i++) {
            update(i, values[i]);
        }
    }

    void update(int i, T value) {
        for (; i < _size; i = (i | (i + 1))) {
            _data[i] = _op(_data[i], value);
        }
    }

    T prefix(int r) {
        T result = _neutal;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            result = _op(result, _data[r]);
        }
        return result;
    }
private:
    T _neutal;
    std::function<T(T, T)> _op;
    T *_data;
    std::uint32_t _size;
};

/*int main() {
    std::vector<int> v = { 1, 2 , -3, };
    FenwickTree<int> tree(v, std::plus<int>(), 0);
    std::cout << tree.prefix(0) << " " << tree.prefix(1) << " " << tree.prefix(2) << std::endl;
    tree.update(2, 3);
    std::cout << tree.prefix(0) << " " << tree.prefix(1) << " " << tree.prefix(2) << std::endl;
    return 0;
}*/
