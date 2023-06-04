#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace ariel;

TEST_SUITE("Container basics")
{
    TEST_CASE("Checking addElement, removeElement, size functions")
    {
        MagicalContainer container;
        CHECK(container.size() == 0);

        for (int i = 0; i < 10; ++i)
        {
            container.addElement(i);
        }
        CHECK(container.size() == 10);

        for (int i = 0; i < 5; i++)
        {
            container.removeElement(i);
        }
        CHECK(container.size() == 5);

        // Removing an element that does not exist in the container
        CHECK_THROWS(container.removeElement(20));
        CHECK(container.size() == 5);
    }

    TEST_CASE("Checking deep copy")
    {
        MagicalContainer container5;
        for (int i = 0; i < 5; ++i)
        {
            container5.addElement(i);
        }

        MagicalContainer container10(container5);
        CHECK_EQ(container10.size(), container5.size());

        // Changing container5 should not affect container10
        container5.removeElement(0);
        CHECK_FALSE(container10.size() == container5.size());

        // add 5 more element to container10
        for (int i = 0; i < 5; ++i)
        {
            container10.addElement(i);
        }

        container10 = container5;
        CHECK_EQ(container10.size(), 5);
    }
}

// ===================== AscendingIterator =====================

TEST_SUITE("AscendingIterator")
{
    TEST_CASE("Testing begin and end")
    {
        MagicalContainer container;
        container.addElement(6);
        container.addElement(2);
        container.addElement(1);
        container.addElement(-2);
        container.addElement(0);
        MagicalContainer::AscendingIterator ascIter(container);
        CHECK_EQ(*(ascIter.begin()), -2);
        CHECK_EQ(*(ascIter.end()), 6);
    }

    TEST_CASE("Testing equality and inequality operators")
    {
        MagicalContainer container;
        container.addElement(-2);
        container.addElement(6);
        container.addElement(0);
        MagicalContainer::AscendingIterator ascIter1(container);
        MagicalContainer::AscendingIterator ascIter2(container);

        ++ascIter1;
        ++ascIter2;

        CHECK(ascIter1 == ascIter1);
        CHECK_FALSE(ascIter1 != ascIter1);

        CHECK(ascIter1 == ascIter2);
        CHECK_FALSE(ascIter1 != ascIter2);

        ++ascIter2;
        CHECK_FALSE(ascIter1 == ascIter2);
        CHECK(ascIter1 != ascIter2);
    }

    TEST_CASE("Testing GT, LT")
    {
        MagicalContainer container;
        container.addElement(-2);
        container.addElement(6);
        container.addElement(0);
        MagicalContainer::AscendingIterator ascIter1(container);
        MagicalContainer::AscendingIterator ascIter2(container);

        ++ascIter2;

        CHECK(ascIter1 < ascIter2);
        CHECK_FALSE(ascIter1 > ascIter2);

        ++ascIter1;
        ++ascIter1;

        CHECK_FALSE(ascIter1 < ascIter2);
        CHECK(ascIter1 > ascIter2);
    }

    TEST_CASE("Testing the traversal order")
    {

        MagicalContainer container;
        container.addElement(2);
        container.addElement(6);
        container.addElement(-2);
        container.addElement(0);
        MagicalContainer::AscendingIterator ascIter(container);

        CHECK(*ascIter == -2);
        ++ascIter;
        CHECK(*ascIter == 0);
        ++ascIter;
        CHECK(*ascIter == 2);
        ++ascIter;
        CHECK(*ascIter == 6);
    }
}

// ===================== SideCrossIterator =====================

TEST_SUITE("SideCrossIterator")
{
    TEST_CASE("Testing begin and end")
    {
        MagicalContainer container;
        container.addElement(6);
        container.addElement(2);
        container.addElement(1);
        container.addElement(-2);
        container.addElement(0);
        MagicalContainer::SideCrossIterator crossIter(container);
        CHECK_EQ(*(crossIter.begin()), 6);
        CHECK_EQ(*(crossIter.end()), 0);
    }

    TEST_CASE("Testing equality and inequality operators")
    {
        MagicalContainer container;
        container.addElement(-2);
        container.addElement(6);
        container.addElement(0);
        MagicalContainer::SideCrossIterator crossIter1(container);
        MagicalContainer::SideCrossIterator crossIter2(container);

        ++crossIter1;
        ++crossIter2;

        CHECK(crossIter1 == crossIter1);
        CHECK_FALSE(crossIter1 != crossIter1);

        CHECK(crossIter1 == crossIter2);
        CHECK_FALSE(crossIter1 != crossIter2);

        ++crossIter2;
        CHECK_FALSE(crossIter1 == crossIter2);
        CHECK(crossIter1 != crossIter2);
    }

    TEST_CASE("Testing GT, LT")
    {
        MagicalContainer container;
        container.addElement(6);
        container.addElement(0);
        container.addElement(-2);

        MagicalContainer::SideCrossIterator crossIter1(container);
        MagicalContainer::SideCrossIterator crossIter2(container);
        // [6, -2, 0]

        ++crossIter2;

        CHECK(crossIter1 < crossIter2);
        CHECK_FALSE(crossIter1 > crossIter2);

        ++crossIter1;
        ++crossIter1;

        CHECK_FALSE(crossIter1 < crossIter2);
        CHECK(crossIter1 > crossIter2);
    }

    TEST_CASE("Testing the traversal order")
    {

        MagicalContainer container;
        container.addElement(2);
        container.addElement(6);
        container.addElement(-2);
        container.addElement(0);
        MagicalContainer::SideCrossIterator crossIter(container);
        // [2, 0, 6, -2]

        CHECK(*crossIter == 2);
        ++crossIter;
        CHECK(*crossIter == 0);
        ++crossIter;
        CHECK(*crossIter == 6);
        ++crossIter;
        CHECK(*crossIter == -2);
    }
}

// ===================== PrimeIterator =====================

TEST_SUITE("PrimeIterator")
{
    TEST_CASE("Testing begin and end")
    {
        MagicalContainer container;
        container.addElement(6);
        container.addElement(3);
        container.addElement(1);
        container.addElement(-2);
        container.addElement(5);
        container.addElement(2);
        MagicalContainer::PrimeIterator primeIter(container);
        CHECK_EQ(*(primeIter.begin()), 3);
        CHECK_EQ(*(primeIter.end()), 2);
    }

    TEST_CASE("Testing equality and inequality operators")
    {
        MagicalContainer container;
        container.addElement(-2);
        container.addElement(5);
        container.addElement(3);
        container.addElement(7);

        MagicalContainer::PrimeIterator primeIter1(container);
        MagicalContainer::PrimeIterator primeIter2(container);
        // [5, 3, 7]

        ++primeIter1;
        ++primeIter2;

        CHECK(primeIter1 == primeIter1);
        CHECK_FALSE(primeIter1 != primeIter1);

        CHECK(primeIter1 == primeIter2);
        CHECK_FALSE(primeIter1 != primeIter2);

        ++primeIter2;
        CHECK_FALSE(primeIter1 == primeIter2);
        CHECK(primeIter1 != primeIter2);
    }

    TEST_CASE("Testing GT, LT")
    {
        MagicalContainer container;
        container.addElement(-2);
        container.addElement(5);
        container.addElement(3);
        container.addElement(7);

        MagicalContainer::PrimeIterator primeIter1(container);
        MagicalContainer::PrimeIterator primeIter2(container);
        // [5, 3, 7]

        ++primeIter2;

        CHECK(primeIter1 < primeIter2);
        CHECK_FALSE(primeIter1 > primeIter2);

        ++primeIter1;
        ++primeIter1;

        CHECK_FALSE(primeIter1 < primeIter2);
        CHECK(primeIter1 > primeIter2);
    }

    TEST_CASE("Testing the traversal order")
    {

        MagicalContainer container;
        container.addElement(6);
        container.addElement(3);
        container.addElement(1);
        container.addElement(-2);
        container.addElement(5);
        container.addElement(2);
        MagicalContainer::PrimeIterator ascIter(container);
        // [3, 5, 2]

        CHECK(*ascIter == 3);
        ++ascIter;
        CHECK(*ascIter == 5);
        ++ascIter;
        CHECK(*ascIter == 2);
    }
}
