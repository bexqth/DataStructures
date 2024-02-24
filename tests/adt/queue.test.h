#pragma once

#include <tests/_details/test.hpp>
#include <libds/adt/queue.h>
#include <type_traits>

namespace ds::tests
{
    /**
     * @brief Tests the push operation.
     * @tparam QueueT Type of the queue.
     */
    template<class QueueT>
    class QueueTestPushPeek : public LeafTest
    {
    public:
        QueueTestPushPeek() :
            LeafTest("push-peek")
        {
        }

    protected:
        void test() override
        {
            constexpr int n = 10;

            QueueT queue;

            this->assert_throws([&queue]()
                {
                    queue.peek();
                },
                "Empty queue throws on peek"
            );

            for (int i = 0; i < n; ++i)
            {
                queue.push(i);
                this->assert_equals(0, queue.peek());
            }

            this->assert_equals(static_cast<size_t>(n), queue.size());
        }
    };

    /**
     * @brief Tests the pop operation.
     * @tparam QueueT Type of the queue.
     */
    template<class QueueT>
    class QueueTestPop : public LeafTest
    {
    public:
        QueueTestPop() :
            LeafTest("pop")
        {
        }

    protected:
        void test() override
        {
            constexpr int n = 10;

            QueueT queue;

            this->assert_throws([&queue]()
                {
                    queue.pop();
                },
                "Empty queue throws on pop"
            );

            for (int i = 0; i < n; ++i)
            {
                queue.push(i);
            }

            for (int i = 0; i < n; ++i)
            {
                this->assert_equals(i, queue.pop());
            }

            this->assert_true(queue.isEmpty(), "Queue is empty.");
        }
    };

    /**
     * @brief Tests the clear operation.
     * @tparam QueueT Type of the queue.
     */
    template<class QueueT>
    class QueueTestClear : public LeafTest
    {
    public:
        QueueTestClear() :
            LeafTest("clear")
        {
        }

    protected:
        void test() override
        {
            constexpr int n = 10;

            QueueT queue;
            for (int i = 0; i < n; ++i)
            {
                queue.push(i);
            }

            queue.clear();

            this->assert_true(queue.isEmpty(), "Cleared queue is empty.");
            this->assert_equals(static_cast<size_t>(0), queue.size());
        }
    };

    /**
     * @brief Tests copy construction, assign, and equals.
     * @tparam QueueT Type of the queue.
     */
    template<class QueueT>
    class QueueTestCopyAssignEquals : public LeafTest
    {
    public:
        QueueTestCopyAssignEquals() :
            LeafTest("copy-assign-equals")
        {
        }

    protected:
        void test() override
        {
            QueueT queue1;
            constexpr int n = 10;
            for (int i = 0; i < n; ++i)
            {
                queue1.push(i);
            }

            QueueT queue2(queue1);
            this->assert_true(queue1.equals(queue2), "Copy constructed queue is the same.");
            queue1.pop();
            this->assert_false(queue1.equals(queue2), "Modified copy is different.");

            QueueT queue3;
            queue3.assign(queue1);
            this->assert_true(queue1.equals(queue3), "Assigned queue is the same.");
            queue1.pop();
            queue1.pop();
            this->assert_false(queue1.equals(queue3), "Modified assigned queue is different.");

            if constexpr (std::is_same_v<QueueT, adt::ImplicitQueue<int>>)
            {
                QueueT queue4;
                QueueT queue5;
                for (size_t i = 0; i < queue4.getCapacity() - 1; ++i)
                {
                    queue4.push(7);
                    queue5.push(7);
                }
                queue4.push(1);
                queue5.push(2);
                this->assert_false(queue4.equals(queue5), "Full different implicit queues are different");
            }

        }
    };

    /**
     * @brief All queue leaf tests.
     * @tparam QueueT Type of the queue.
     */
    template<class QueueT>
    class GeneralQueueTest : public CompositeTest
    {
    public:
        GeneralQueueTest(const std::string& name) :
            CompositeTest(name)
        {
            this->add_test(std::make_unique<QueueTestPushPeek<QueueT>>());
            this->add_test(std::make_unique<QueueTestPop<QueueT>>());
            this->add_test(std::make_unique<QueueTestClear<QueueT>>());
            this->add_test(std::make_unique<QueueTestCopyAssignEquals<QueueT>>());
        }
    };

    /**
     * @brief All queue tests.
     */
    class QueueTest : public CompositeTest
    {
    public:
        QueueTest() :
            CompositeTest("Queue")
        {
            this->add_test(std::make_unique<GeneralQueueTest<adt::ImplicitQueue<int>>>("ImplicitQueue"));
            this->add_test(std::make_unique<GeneralQueueTest<adt::ExplicitQueue<int>>>("ExplicitQueue"));
        }
    };
}
