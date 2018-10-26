#include "Vector.hpp"
#include <algorithm>

namespace ballzy {

    void swap(Vector& a, Vector& b) noexcept { a.swap(b); }

    void Vector::swap(Vector& other) noexcept {
        using std::swap;
        swap(m_data, other.m_data);
        swap(m_size, other.m_size);
        swap(m_capacity, other.m_capacity);
    }

    //Vector::Vector() {}

    //Vector::~Vector() {}

    //Vector::Vector(const Vector& other) {}

    //Vector::Vector(Vector&& other) {}

    //Vector& Vector::operator=(const Vector& other) {}

    //Vector& Vector::operator=(Vector&& other) {}

    //std::size_t Vector::size() const {}
    
    //bool Vector::empty() const {}

    //void Vector::push_back(int value) {}

    //int Vector::pop_back() {}

    //Vector::ConstIterator Vector::begin() const {}

    //Vector::Iterator Vector::begin() {}

    //Vector::ConstIterator Vector::end() const {}

    //Vector::Iterator Vector::end() {}

    //Vector::ConstIterator Vector::cbegin() const {}

    //Vector::ConstIterator Vector::cend() const {}

    //int& Vector::operator[](std::size_t index) {}
    
    //const int& Vector::operator[](std::size_t index) const {}

} // namespace ballzy
