#include <gtest/gtest.h>

#include "WorkflowApp.h"
#include "tests/TestWorkflowConstants.h"
#include "tests/TestFunction.h"

TEST(TEST1, TEST_TRUE_WORK) {
	workflow::insertStringInFile(workflow::innerTEST1, "in.txt");
	workflow::insertStringInFile(workflow::workflowTEST1, "w.txt");
	workflow::WorkflowApp app("w.txt", true);
	app.runApp();
	auto result = workflow::getStringFromFile("out.txt");

	ASSERT_EQ(workflow::resultTEST1, result);
};

TEST(TEST2, TEST_TRUE_WORK) {
	workflow::insertStringInFile(workflow::innerTEST2, "in.txt");
	workflow::insertStringInFile(workflow::workflowTEST2, "w.txt");
	workflow::WorkflowApp app("w.txt", true);
	app.runApp();
	auto result = workflow::getStringFromFile("out.txt");

	ASSERT_EQ(workflow::resultTEST2, result);
}

TEST(NOT_COORECT_PATH, TEST_NOT_WORK) {
	workflow::WorkflowApp app("incorrectFilePath.txt", true);
	ASSERT_ANY_THROW(app.runApp());
}

TEST(DUPLICATE_TEST, TEST_NOT_WORK) {
	workflow::insertStringInFile(workflow::workflowOpenTEST1, "w.txt");

	workflow::WorkflowApp app("w.txt", true);
	ASSERT_ANY_THROW(app.runApp(););
}

TEST(READ_NOT_BEGIN_TEST, TEST_NOT_WORK) {
	workflow::insertStringInFile(workflow::workflowValidTEST2, "w.txt");

	workflow::WorkflowApp app("w.txt", true);
	ASSERT_ANY_THROW(app.runApp();
	);
}

TEST(WRITE_NOT_END_TEST, TEST_NOT_WORK) {
	workflow::insertStringInFile(workflow::worfklowValidTEST3, "w.txt");

	workflow::WorkflowApp app("w.txt", true);
	ASSERT_ANY_THROW(app.runApp());
}

TEST(INCORRECT_COUNT_ARGUMENTS_TEST, TEST_NOT_WORK) {
	workflow::insertStringInFile(workflow::worfklowValidTEST3, "w.txt");

	workflow::WorkflowApp app("w.txt", true);
	ASSERT_ANY_THROW(app.runApp());
}

int main() {

	::testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
