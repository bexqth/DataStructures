#pragma once

#include <libds/amt/explicit_hierarchy.h>
#include <tests/_details/test.hpp>
#include <tests/amt/hierarchy.test.h>
#include <memory>
#include <type_traits>

namespace ds::tests
{
    /**
     * @brief Tests insertion of root and sons.
     */
    class MWEHTestInsert : public LeafTest
    {
    public:
        MWEHTestInsert() :
            LeafTest("insert")
        {
        }

    protected:
        void test() override
        {
            auto fixture = details::makeMWEH();
            auto& hierarchy = *fixture.hierarchy_;
            //        0
            //   /         \
            //   1         2
            // / | \       |
            // 3 4 5       6

            this->assert_equals(static_cast<size_t>(7), hierarchy.size());
        }
    };

    /**
     *  @brief Tests access of parent and sons.
     */
    class MWEHTestAccess : public LeafTest
    {
    public:
        MWEHTestAccess() :
            LeafTest("access")
        {
        }

    protected:
        void test() override
        {
            const auto emptyHierarchy = amt::MultiWayExplicitHierarchy<int>();
            this->assert_null(emptyHierarchy.accessRoot());

            auto fixture = details::makeMWEH();
            auto& hierarchy = *fixture.hierarchy_;
            //        0
            //   /         \
            //   1         2
            // / | \       |
            // 3 4 5       6

            auto* root = hierarchy.accessRoot();
            this->assert_not_null(root);
            this->assert_equals(0, root->data_);

            auto* one = hierarchy.accessSon(*root, 0);
            this->assert_not_null(one);
            this->assert_equals(1, one->data_);

            auto* two = hierarchy.accessSon(*root, 1);
            this->assert_not_null(two);
            this->assert_equals(2, two->data_);

            auto* six = hierarchy.accessSon(*two, 0);
            this->assert_not_null(six);
            this->assert_equals(6, six->data_);

            auto* notseven = hierarchy.accessSon(*two, 1);
            this->assert_null(notseven);

            this->assert_equals(two, hierarchy.accessParent(*six));
            this->assert_equals(root, hierarchy.accessParent(*one));
            this->assert_null(hierarchy.accessParent(*root));
        }
    };

    /**
     * @brief Tests method for calculation of node count, level and degree.
     */
    class MWEHTestLevelsCountsDegs : public LeafTest
    {
    public:
        MWEHTestLevelsCountsDegs() :
            LeafTest("level-count-degree")
        {
        }

    protected:
        void test() override
        {
            auto fixture = details::makeMWEH();
            auto& hierarchy = *fixture.hierarchy_;
            //        0
            //   /         \
            //   1         2
            // / | \       |
            // 3 4 5       6

            auto& root = *hierarchy.accessRoot();
            auto& one = *hierarchy.accessSon(root, 0);
            auto& two = *hierarchy.accessSon(root, 1);
            auto& six = *hierarchy.accessSon(two, 0);

            this->assert_equals(static_cast<size_t>(7), hierarchy.nodeCount());
            this->assert_equals(static_cast<size_t>(4), hierarchy.nodeCount(one));

            this->assert_equals(static_cast<size_t>(0), hierarchy.level(root));
            this->assert_equals(static_cast<size_t>(1), hierarchy.level(one));
            this->assert_equals(static_cast<size_t>(2), hierarchy.level(six));

            this->assert_equals(static_cast<size_t>(2), hierarchy.degree(root));
            this->assert_equals(static_cast<size_t>(3), hierarchy.degree(one));
            this->assert_equals(static_cast<size_t>(1), hierarchy.degree(two));
            this->assert_equals(static_cast<size_t>(0), hierarchy.degree(six));

            auto otherHierarchy = std::remove_reference_t<decltype(hierarchy)>();
            hierarchy.changeRoot(nullptr);
            otherHierarchy.changeRoot(&root);
            this->assert_equals(static_cast<size_t>(7), otherHierarchy.nodeCount());
            this->assert_true(hierarchy.isEmpty(), "Old hierarchy is empty.");
            this->assert_equals(static_cast<size_t>(0), hierarchy.nodeCount());
        }
    };

    /**
     *  @brief Tests removal of a son and sub-hierarchy.
     */
    class MWEHTestRemove : public LeafTest
    {
    public:
        MWEHTestRemove() :
            LeafTest("remove")
        {
        }

    protected:
        void test() override
        {
            auto fixture = details::makeMWEH();
            auto& hierarchy = *fixture.hierarchy_;
            //        0
            //   /         \
            //   1        x2
            // / | \       |
            // 3 4 5       6
            //   x         ~
            auto& root = *hierarchy.accessRoot();
            auto& one = *hierarchy.accessSon(root, 0);
            auto& two = *hierarchy.accessSon(root, 1);

            hierarchy.removeSon(one, 1);
            hierarchy.removeSon(root, 1);

            this->assert_equals(static_cast<size_t>(2), hierarchy.degree(one));
            this->assert_equals(5, hierarchy.accessSon(one, 1)->data_);
            this->assert_equals(static_cast<size_t>(1), hierarchy.degree(root));
            this->assert_null(hierarchy.accessSon(root, 1));
        }
    };

    /**
     *  @brief Tests copy constructor, assign and equals.
     */
    class MWEHTestCopyAssignEquals : public LeafTest
    {
    public:
        MWEHTestCopyAssignEquals() :
            LeafTest("copy-assign-equals")
        {
        }

    protected:
        void test() override
        {
            auto fixture = details::makeMWEH();
            auto& hierarchy1 = *fixture.hierarchy_;

            auto& root1 = *hierarchy1.accessRoot();
            auto& one1 = *hierarchy1.accessSon(root1, 0);

            auto hierarchy2(hierarchy1);
            this->assert_true(hierarchy1.equals(hierarchy2), "Copy constructed hierarchy is the same.");
            hierarchy1.removeSon(root1, 1);
            this->assert_false(hierarchy1.equals(hierarchy2), "Modified copy is different.");

            auto hierarchy3 = amt::MultiWayExplicitHierarchy<int>();
            hierarchy3.assign(hierarchy1);
            this->assert_true(hierarchy1.equals(hierarchy3), "Assigned hierarchy is the same.");
            hierarchy1.removeSon(one1, 0);
            hierarchy1.removeSon(one1, 0);
            this->assert_false(hierarchy1.equals(hierarchy3), "Modified assigned hierarchy is different.");
        }
    };

    /**
     *  @brief Tests clear.
     */
    class MWEHTestClear : public LeafTest
    {
    public:
        MWEHTestClear() :
            LeafTest("clear")
        {
        }

    protected:
        void test() override
        {
            auto fixture = details::makeMWEH();
            auto& hierarchy = *fixture.hierarchy_;

            hierarchy.clear();

            this->assert_equals(static_cast<size_t>(0), hierarchy.size());
            this->assert_null(hierarchy.accessRoot());
            this->assert_true(hierarchy.isEmpty(), "Cleared hierarchy is empty.");
        }
    };

    /**
     * @brief All MultiwayExplicitHierarchy tests.
     */
    class MultiwayExplicitHierarchyTest : public CompositeTest
    {
    public:
        MultiwayExplicitHierarchyTest() :
            CompositeTest("MultiwayExplicitHierarchy")
        {
            this->add_test(std::make_unique<MWEHTestInsert>());
            this->add_test(std::make_unique<MWEHTestAccess>());
            this->add_test(std::make_unique<MWEHTestLevelsCountsDegs>());
            this->add_test(std::make_unique<MWEHTestRemove>());
            this->add_test(std::make_unique<MWEHTestCopyAssignEquals>());
            this->add_test(std::make_unique<MWEHTestClear>());
        }
    };

    /**
     * @brief Tests insertion of root and sons.
     */
    class KWEHTestInsert : public LeafTest
    {
    public:
        KWEHTestInsert() :
            LeafTest("insert")
        {
        }

    protected:
        void test() override
        {
            auto fixture = details::makeKWEH();
            auto& hierarchy = *fixture.hierarchy_;
            //
            //         0
            //    /    |    \
            //    1    -    2
            //  / | \     / | \
            //  3 - 4     - 5 -

            this->assert_equals(static_cast<size_t>(6), hierarchy.size());
        }
    };

    /**
     * @brief Tests access of root, son, and parent.
     */
    class KWEHTestAccess : public LeafTest
    {
    public:
        KWEHTestAccess() :
            LeafTest("access")
        {
        }

    protected:
        void test() override
        {
            auto emptyHierarchy = amt::KWayExplicitHierarchy<int, 3>();
            this->assert_null(emptyHierarchy.accessRoot());

            auto fixture = details::makeKWEH();
            auto& hierarchy = *fixture.hierarchy_;
            //
            //         0
            //    /    |    \
            //    1    -    2
            //  / | \     / | \
            //  3 - 4     - 5 -

            auto* root = hierarchy.accessRoot();
            this->assert_not_null(root);
            this->assert_equals(0, root->data_);

            auto* one = hierarchy.accessSon(*root, 0);
            this->assert_not_null(one);
            this->assert_equals(1, one->data_);

            auto* mid1 = hierarchy.accessSon(*root, 1);
            this->assert_null(mid1);

            auto* two = hierarchy.accessSon(*root, 2);
            this->assert_not_null(two);
            this->assert_equals(2, two->data_);

            auto* three = hierarchy.accessSon(*one, 0);
            this->assert_not_null(three);
            this->assert_equals(3, three->data_);

            auto* four = hierarchy.accessSon(*one, 2);
            this->assert_not_null(four);
            this->assert_equals(4, four->data_);

            auto* five = hierarchy.accessSon(*two, 1);
            this->assert_not_null(five);
            this->assert_equals(5, five->data_);

            auto* mid2 = hierarchy.accessSon(*one, 1);
            this->assert_null(mid2);

            auto* notsix = hierarchy.accessSon(*two, 10);
            this->assert_null(notsix);

            this->assert_equals(root, hierarchy.accessParent(*one));
            this->assert_equals(root, hierarchy.accessParent(*two));
            this->assert_equals(one, hierarchy.accessParent(*four));
            this->assert_equals(two, hierarchy.accessParent(*five));
            this->assert_not_equals(root, hierarchy.accessParent(*three));
            this->assert_not_equals(root, hierarchy.accessParent(*four));
            this->assert_null(hierarchy.accessParent(*root));
        }
    };

    /**
     * @brief Tests method for calculation of node count, level and degree.
     */
    class KWEHTestLevelCountDeg : public LeafTest
    {
    public:
        KWEHTestLevelCountDeg() :
            LeafTest("level-count-degree")
        {
        }

    protected:
        void test() override
        {
            auto fixture = details::makeKWEH();
            auto& hierarchy = *fixture.hierarchy_;
            //
            //         0
            //    /    |    \
            //    1    -    2
            //  / | \     / | \
            //  3 - 4     - 5 -
            auto& root = *hierarchy.accessRoot();
            auto& one = *hierarchy.accessSon(root, 0);
            auto& two = *hierarchy.accessSon(root, 2);
            auto& three = *hierarchy.accessSon(one, 0);
            auto& four = *hierarchy.accessSon(one, 2);
            auto& five = *hierarchy.accessSon(two, 1);

            this->assert_equals(static_cast<size_t>(0), hierarchy.level(root));
            this->assert_equals(static_cast<size_t>(1), hierarchy.level(one));
            this->assert_equals(static_cast<size_t>(1), hierarchy.level(two));
            this->assert_equals(static_cast<size_t>(2), hierarchy.level(three));
            this->assert_equals(static_cast<size_t>(2), hierarchy.level(five));

            this->assert_equals(static_cast<size_t>(2), hierarchy.degree(root));
            this->assert_equals(static_cast<size_t>(2), hierarchy.degree(one));
            this->assert_equals(static_cast<size_t>(0), hierarchy.degree(four));
            this->assert_equals(static_cast<size_t>(0), hierarchy.degree(five));
            this->assert_equals(static_cast<size_t>(1), hierarchy.degree(two));

            this->assert_equals(static_cast<size_t>(6), hierarchy.nodeCount(root));
            this->assert_equals(static_cast<size_t>(2), hierarchy.nodeCount(two));
            this->assert_equals(static_cast<size_t>(3), hierarchy.nodeCount(one));
            this->assert_equals(static_cast<size_t>(1), hierarchy.nodeCount(three));
            this->assert_equals(static_cast<size_t>(1), hierarchy.nodeCount(four));

            auto otherHierarchy = std::remove_reference_t<decltype(hierarchy)>();
            hierarchy.changeRoot(nullptr);
            otherHierarchy.changeRoot(&root);
            this->assert_equals(static_cast<size_t>(6), otherHierarchy.nodeCount());
            this->assert_true(hierarchy.isEmpty(), "Old hierarchy is empty.");
            this->assert_equals(static_cast<size_t>(0), hierarchy.nodeCount());
        }
    };

    /**
     *  @brief Tests removal of a son and sub-hierarchy.
     */
    class KWEHTestRemove : public LeafTest
    {
    public:
        KWEHTestRemove() :
            LeafTest("remove")
        {
        }

    protected:
        void test() override
        {
            auto fixture = details::makeKWEH();
            auto& hierarchy = *fixture.hierarchy_;
            //
            //         0
            //    /    |    \
            //    1    -    2x
            //  / | \     / | \
            //  3x- 4     - 5~-
            auto& root = *hierarchy.accessRoot();
            auto& one = *hierarchy.accessSon(root, 0);

            hierarchy.removeSon(root, 2);
            hierarchy.removeSon(one, 0);

            this->assert_equals(static_cast<size_t>(3), hierarchy.size());
            this->assert_equals(static_cast<size_t>(1), hierarchy.degree(root));
            this->assert_equals(static_cast<size_t>(1), hierarchy.degree(one));
            this->assert_not_null(hierarchy.accessSon(root, 0));
            this->assert_null(hierarchy.accessSon(root, 1));
            this->assert_null(hierarchy.accessSon(root, 2));
            this->assert_null(hierarchy.accessSon(one, 0));
            this->assert_null(hierarchy.accessSon(one, 1));
            this->assert_not_null(hierarchy.accessSon(one, 2));
        }
    };

    /**
     *  @brief Tests copy constructor, assign and equals.
     */
    class KWEHTestCopyAssignEquals : public LeafTest
    {
    public:
        KWEHTestCopyAssignEquals() :
            LeafTest("copy-assign-equals")
        {
        }

    protected:
        void test() override
        {
            auto fixture = details::makeKWEH();
            auto& hierarchy1 = *fixture.hierarchy_;
            //         0
            //    /    |    \
            //    1    -    2
            //  / | \     / | \
            //  3 - 4     - 5 -
            auto& root1 = *hierarchy1.accessRoot();
            auto& one1 = *hierarchy1.accessSon(root1, 0);

            auto hierarchy2(hierarchy1);
            this->assert_true(hierarchy1.equals(hierarchy2), "Copy constructed hierarchy is the same.");
            hierarchy1.removeSon(root1, 2);
            this->assert_false(hierarchy1.equals(hierarchy2), "Modified copy is different.");

            auto hierarchy3 = amt::KWayExplicitHierarchy<int, 3>();
            hierarchy3.assign(hierarchy1);
            this->assert_true(hierarchy1.equals(hierarchy3), "Assigned hierarchy is the same.");
            hierarchy1.removeSon(one1, 0);
            hierarchy1.removeSon(one1, 0);
            this->assert_false(hierarchy1.equals(hierarchy3), "Modified assigned hierarchy is different.");
        }
    };

    /**
     *  @brief Tests clear.
     */
    class KWEHTestClear : public LeafTest
    {
    public:
        KWEHTestClear() :
            LeafTest("clear")
        {
        }

    protected:
        void test() override
        {
            auto fixture = details::makeKWEH();
            auto& hierarchy = *fixture.hierarchy_;
            //         0
            //    /    |    \
            //    1    -    2
            //  / | \     / | \
            //  3 - 4     - 5 -

            hierarchy.clear();

            this->assert_equals(static_cast<size_t>(0), hierarchy.size());
            this->assert_null(hierarchy.accessRoot());
            this->assert_true(hierarchy.isEmpty(), "Cleared hierarchy is empty.");
        }
    };

    /**
     * @brief All KWayExplicitHierarchy tests.
     */
    class KWayExplicitHierarchyTest : public CompositeTest
    {
    public:
        KWayExplicitHierarchyTest() :
            CompositeTest("KWayExplicitHierarchy")
        {
            this->add_test(std::make_unique<KWEHTestInsert>());
            this->add_test(std::make_unique<KWEHTestAccess>());
            this->add_test(std::make_unique<KWEHTestLevelCountDeg>());
            this->add_test(std::make_unique<KWEHTestRemove>());
            this->add_test(std::make_unique<KWEHTestCopyAssignEquals>());
            this->add_test(std::make_unique<KWEHTestClear>());
        }
    };

    /**
     * @brief All ExplicitHierarchy tests.
     */
    class ExplicitHierarchyTest : public CompositeTest
    {
    public:
        ExplicitHierarchyTest() :
            CompositeTest("ExplicitHierarchy")
        {
            this->add_test(std::make_unique<MultiwayExplicitHierarchyTest>());
            this->add_test(std::make_unique<KWayExplicitHierarchyTest>());
        }
    };
}
