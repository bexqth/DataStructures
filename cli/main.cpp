#include <tests/root.h>
#include <complexities/list_analyzer.h>

#ifndef ANALYZER_OUTPUT
#define ANALYZER_OUTPUT "."
#endif

std::vector<std::unique_ptr<ds::tests::Test>> createTests()
{
	auto root = std::make_unique<ds::tests::CompositeTest>("root");
    auto mm   = std::make_unique<ds::tests::CompositeTest>("mm");
	auto amt  = std::make_unique<ds::tests::CompositeTest>("amt");
	auto adt  = std::make_unique<ds::tests::CompositeTest>("adt");

	mm->add_test(std::make_unique<ds::tests::MemoryManagerTest>());

	// TODO 02
	mm->add_test(std::make_unique<ds::tests::CompactMemoryManagerTest>());

	// TODO 03
    amt->add_test(std::make_unique<ds::tests::ImplicitSequenceTest>());

	// TODO 04
	 amt->add_test(std::make_unique<ds::tests::ExplicitSequenceTest>());

	// TODO 05
	 amt->add_test(std::make_unique<ds::tests::ImplicitHierarchyTest>());

	// TODO 06
	amt->add_test(std::make_unique<ds::tests::ExplicitHierarchyTest>());
    amt->add_test(std::make_unique<ds::tests::HierarchyTest>());

	// TODO 07
	// adt->add_test(std::make_unique<ds::tests::ListTest>());
	// adt->add_test(std::make_unique<ds::tests::ArraysTest>());

	// TODO 08
	// adt->add_test(std::make_unique<ds::tests::StackTest>());
	// adt->add_test(std::make_unique<ds::tests::QueueTest>());
	// adt->add_test(std::make_unique<ds::tests::PriorityQueueTest>());

	// TODO 09
	// adt->add_test(std::make_unique<ds::tests::SequenceTableTest>());

    // TODO 11
	// adt->add_test(std::make_unique<ds::tests::NonSequenceTableTest>());

	// TODO 12
	// adt->add_test(std::make_unique<ds::tests::SortTest>());

	root->add_test(std::move(mm));
	root->add_test(std::move(amt));
	root->add_test(std::move(adt));
	std::vector<std::unique_ptr<ds::tests::Test>> tests;
	tests.emplace_back(std::move(root));
	return tests;
}

std::vector<std::unique_ptr<ds::utils::Analyzer>> createAnalyzers()
{
	std::vector<std::unique_ptr<ds::utils::Analyzer>> analyzers;

    // TODO 01
    analyzers.emplace_back(std::make_unique<ds::utils::ListsAnalyzer>());

	return analyzers;
}

void runTests(const std::vector<std::unique_ptr<ds::tests::Test>>& tests)
{
    for (const std::unique_ptr<ds::tests::Test>& test : tests)
    {
        test->run();
    }
}

void printResults(const std::vector<std::unique_ptr<ds::tests::Test>>& tests)
{
    for (const std::unique_ptr<ds::tests::Test>& test : tests)
    {
        ds::tests::console_print_results(*test, ds::tests::ConsoleOutputType::NoLeaf);
    }
}

void runAnalyzers(const std::vector<std::unique_ptr<ds::utils::Analyzer>>& analyzers)
{
    for (const std::unique_ptr<ds::utils::Analyzer>& analyzer : analyzers)
    {
        analyzer->analyze();
    }
}

void setAnalyzersParameters(
    const std::vector<std::unique_ptr<ds::utils::Analyzer>>& analyzers,
    const std::string& path
)
{
    for (const std::unique_ptr<ds::utils::Analyzer>& analyzer : analyzers)
    {
        analyzer->setOutputDirectory(path);
        analyzer->setReplicationCount(100);
        analyzer->setStepSize(10'000);
        analyzer->setStepCount(10);
    }
}

int main()
{
    std::vector<std::unique_ptr<ds::tests::Test>> tests = createTests();
    std::vector<std::unique_ptr<ds::utils::Analyzer>> analyzers = createAnalyzers();
    runTests(tests);
    printResults(tests);
    setAnalyzersParameters(analyzers, ANALYZER_OUTPUT);
    runAnalyzers(analyzers);
}
