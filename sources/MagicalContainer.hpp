#pragma once

#include <vector>

namespace ariel
{
    class MagicalContainer
    {
    private:
        std::vector<int> elements;

    public:
        MagicalContainer() {}

        void addElement(int element) { elements.push_back(element); }
        void removeElement(int element) { elements.pop_back(); }
        std::size_t size() const { return elements.size(); }

        //  ======================== Iterators ========================

        class AscendingIterator
        {
        private:
            const MagicalContainer *container;
            std::vector<int>::const_iterator current;

        public:
            AscendingIterator() : container(nullptr) {}
            AscendingIterator(const MagicalContainer &container) : container(&container), current(container.elements.begin()) {}
            AscendingIterator(const AscendingIterator &other) : container(other.container), current(other.current) {}
            AscendingIterator(AscendingIterator &&other) = default;
            ~AscendingIterator() = default;

            AscendingIterator &operator=(AscendingIterator &&other) = default;
            AscendingIterator &operator=(const AscendingIterator &other)
            {
                if (this != &other)
                {
                    container = other.container;
                    current = other.current;
                }
                return *this;
            }

            bool operator==(const AscendingIterator &other) const { return false; };
            bool operator!=(const AscendingIterator &other) const { return false; };
            bool operator>(const AscendingIterator &other) const { return false; };
            bool operator<(const AscendingIterator &other) const { return false; };

            const int &operator*() const { return *current; }

            AscendingIterator &operator++()
            {
                ++current;
                return *this;
            }

            std::vector<int>::const_iterator begin() const { return container->elements.begin(); }
            std::vector<int>::const_iterator end() const { return container->elements.end(); }
        };

        class SideCrossIterator
        {
        private:
            const MagicalContainer *container;
            std::vector<int>::const_iterator current;

        public:
            SideCrossIterator() : container(nullptr) {}
            SideCrossIterator(const MagicalContainer &container) : container(&container), current(container.elements.begin()) {}
            SideCrossIterator(const SideCrossIterator &other) : container(other.container), current(other.current) {}
            SideCrossIterator(SideCrossIterator &&other) = default;
            ~SideCrossIterator() = default;

            SideCrossIterator &operator=(SideCrossIterator &&other) = default;
            SideCrossIterator &operator=(const SideCrossIterator &other)
            {
                if (this != &other)
                {
                    container = other.container;
                    current = other.current;
                }
                return *this;
            }

            bool operator==(const SideCrossIterator &other) const { return false; };
            bool operator!=(const SideCrossIterator &other) const { return false; };
            bool operator>(const SideCrossIterator &other) const { return false; };
            bool operator<(const SideCrossIterator &other) const { return false; };

            const int &operator*() const { return *current; }

            SideCrossIterator &operator++()
            {
                ++current;
                return *this;
            }

            std::vector<int>::const_iterator begin() { return container->elements.begin(); }
            std::vector<int>::const_iterator end() { return container->elements.end(); }
        };

        class PrimeIterator
        {
        private:
            const MagicalContainer *container;
            std::vector<int>::const_iterator current;

        public:
            PrimeIterator() : container(nullptr) {}
            PrimeIterator(const MagicalContainer &container) : container(&container), current(container.elements.begin()) {}
            PrimeIterator(const PrimeIterator &other) : container(other.container), current(other.current) {}
            PrimeIterator(PrimeIterator &&other) = default;
            ~PrimeIterator() = default;

            PrimeIterator &operator=(PrimeIterator &&other) = default;
            PrimeIterator &operator=(const PrimeIterator &other)
            {
                if (this != &other)
                {
                    container = other.container;
                    current = other.current;
                }
                return *this;
            }

            bool operator==(const PrimeIterator &other) const { return false; };
            bool operator!=(const PrimeIterator &other) const { return false; };
            bool operator>(const PrimeIterator &other) const { return false; };
            bool operator<(const PrimeIterator &other) const { return false; };

            const int &operator*() const { return *current; }

            PrimeIterator &operator++()
            {
                ++current;
                return *this;
            }

            std::vector<int>::const_iterator begin() { return container->elements.begin(); }
            std::vector<int>::const_iterator end() { return container->elements.end(); }
        };
    };
}