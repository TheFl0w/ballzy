#pragma once
#include <cstddef>

namespace ballzy {
    class List;

    void swap(List& a, List& b) noexcept;

    class List {
    private:
        struct Node {
            Node* next = nullptr;
            int value;
            Node(int value);
        };
        class ConstIterator {
        private:
            Node* m_node;

        public:
            ConstIterator(Node* init);
            const int& operator*() const;
            ConstIterator& operator++();
            bool operator==(const ConstIterator& other);
            bool operator!=(const ConstIterator& other);
        };
        class Iterator : public ConstIterator {
        public:
            Iterator(Node* init);
            int& operator*();
        };
        Node* m_head = nullptr;
        std::size_t m_size = 0;

    public:
        List() = default;
        List(const List& other);
        List(List&& other);
        List& operator=(const List& other);
        List& operator=(List&& other);
        void swap(List& other) noexcept;
        Iterator begin();
        Iterator end();
        ConstIterator begin() const;
        ConstIterator end() const;
        ConstIterator cbegin() const;
        ConstIterator cend() const;
        std::size_t size() const;
        void push_back(int value);
        void push_front(int value);
        int pop_back();
        int pop_front();
        void insert(ConstIterator)
    };

} // namespace ballzy
