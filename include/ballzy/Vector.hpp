#pragma once
#include <cstddef>

namespace ballzy {

    class Vector;
    void swap(Vector& a, Vector& b) noexcept;

    class Vector {
    private:
        int* m_data;
        std::size_t m_size;
        std::size_t m_capacity;

    public:
        using ConstIterator = const int*;
        using Iterator = int*;
        Vector();
        ~Vector();
        Vector(const Vector& other);
        Vector(Vector&& other);
        Vector& operator=(const Vector& other);
        Vector& operator=(Vector&& other);
        std::size_t size() const;
        bool empty() const;
        void push_back(int value);
        int pop_back();
        Iterator begin();
        Iterator end();
        ConstIterator begin() const;
        ConstIterator end() const;
        ConstIterator cbegin() const;
        ConstIterator cend() const;
        int& operator[](std::size_t index);
        const int& operator[](std::size_t index) const;
        void swap(Vector& other) noexcept;
    };

} // namespace ballzy
