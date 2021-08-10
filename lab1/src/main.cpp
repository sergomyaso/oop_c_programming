#include "tritSet.h"
#include <gtest/gtest.h>

class TestTritSet : public ::testing::Test {

protected:
	const size_t SIZE_FIRST_SET = 10;
	const size_t SIZE_SECOND_SET = 100;
	const size_t BIG_INDEX_FOR_CHECK = 1000000;

protected:
	void SetUp()
	{
		set1 = new trit::TritSet(SIZE_FIRST_SET);
		set2 = new trit::TritSet(SIZE_SECOND_SET);
	}

	void TearDown() {
		delete set1;
		delete set2;
	}
	trit::TritSet* set1;
	trit::TritSet* set2;
};

TEST_F(TestTritSet, MEMMORY_TEST) {
	ASSERT_GE(set1->capacity(),SIZE_FIRST_SET * trit::TritSet::CAPCITY_TRIT / trit::constants::BIT_IN_BYTE / trit::constants::SIZE_UINT);
	
	size_t allocMem = set1->capacity();
	(*set1)[BIG_INDEX_FOR_CHECK] = trit::Unknown;
	ASSERT_EQ(set1->capacity(), allocMem);

	allocMem = set1->capacity();
	if ((*set1)[BIG_INDEX_FOR_CHECK] == trit::True) {}
	ASSERT_EQ(set1->capacity(), allocMem);

	allocMem = set1->capacity();
	(*set1)[BIG_INDEX_FOR_CHECK] = trit::True;
	ASSERT_GT(set1->capacity(), allocMem);

	allocMem = set1->capacity();
	set1->shrink();
	ASSERT_LT(set1->capacity(), allocMem);

}

TEST_F(TestTritSet, OPERATOR_TEST) {
	trit::Trit value = trit::Unknown;

	//Tests for operator =
	(*set1)[0] = trit::True;
	(*set1)[0] = trit::False;
	ASSERT_EQ((*set1)[0], trit::False);

	(*set1)[0] = trit::False;
	(*set1)[0] = trit::True;
	ASSERT_EQ((*set1)[0], trit::True);

	(*set1)[0] = trit::False;
	(*set1)[0] = trit::Unknown;
	ASSERT_EQ((*set1)[0], trit::Unknown);

	(*set1)[0] = trit::Unknown;
	(*set1)[0] = trit::True;
	ASSERT_EQ((*set1)[0], trit::True);

	//Tests for operator &
	(*set1)[0] = trit::True;
	(*set1)[1] = trit::False;
	value = ((*set1)[0] & (*set1)[1]).getValue();
	ASSERT_EQ(value, trit::False);

	(*set1)[0] = trit::Unknown;
	(*set1)[1] = trit::False;
	value = ((*set1)[0] & (*set1)[1]).getValue();
	ASSERT_EQ(value, trit::False);

	(*set1)[0] = trit::False;
	(*set1)[1] = trit::False;
	value = ((*set1)[0] & (*set1)[1]).getValue();
	ASSERT_EQ(value, trit::False);

	(*set1)[0] = trit::True;
	(*set1)[1] = trit::Unknown;
	value = ((*set1)[0] & (*set1)[1]).getValue();
	ASSERT_EQ(value, trit::Unknown);

	(*set1)[0] = trit::Unknown;
	(*set1)[1] = trit::Unknown;
	value = ((*set1)[0] & (*set1)[1]).getValue();
	ASSERT_EQ(value, trit::Unknown);

	(*set1)[0] = trit::True;
	(*set1)[1] = trit::True;
	value = ((*set1)[0] & (*set1)[1]).getValue();
	ASSERT_EQ(value, trit::True);

	trit::TritSet result = *set1 & *set2;
	ASSERT_EQ(result.capacity(), set2->capacity());

	//Tests for operator |
	(*set1)[0] = trit::True;
	(*set1)[1] = trit::False;
	value = ((*set1)[0] | (*set1)[1]).getValue();
	ASSERT_EQ(value, trit::True);

	(*set1)[0] = trit::Unknown;
	(*set1)[1] = trit::False;
	value = ((*set1)[0] | (*set1)[1]).getValue();
	ASSERT_EQ(value, trit::Unknown);

	(*set1)[0] = trit::False;
	(*set1)[1] = trit::False;
	value = ((*set1)[0] | (*set1)[1]).getValue();
	ASSERT_EQ(value, trit::False);

	(*set1)[0] = trit::True;
	(*set1)[1] = trit::Unknown;
	value = ((*set1)[0] | (*set1)[1]).getValue();
	ASSERT_EQ(value, trit::True);

	(*set1)[0] = trit::Unknown;
	(*set1)[1] = trit::Unknown;
	value = ((*set1)[0] | (*set1)[1]).getValue();
	ASSERT_EQ(value, trit::Unknown);

	(*set1)[0] = trit::True;
	(*set1)[1] = trit::True;
	value = ((*set1)[0] & (*set1)[1]).getValue();
	ASSERT_EQ(value, trit::True);

	result = *set1 | *set2;
	ASSERT_EQ(result.capacity(), set2->capacity());

	//Tests for operators &= and |=
	result = *set1;
	result &= *set2;
	ASSERT_EQ(result.capacity(), set2->capacity());

	result = *set1;
	result |= *set2;
	ASSERT_EQ(result.capacity(), set2->capacity());
	
	//Tests for operator ~
	(*set1)[0] = trit::True;
	~(*set1)[0];
	value = (*set1)[0].getValue();
	ASSERT_EQ(value, trit::False);

	(*set1)[0] = trit::False;
	~(*set1)[0];
	value = (*set1)[0].getValue();
	ASSERT_EQ(value, trit::True);

	(*set1)[0] = trit::Unknown;
	~(*set1)[0];
	value = (*set1)[0].getValue();
	ASSERT_EQ(value, trit::Unknown);

	size_t allocMem = set2->capacity();
	~(*set2);
	ASSERT_EQ(allocMem, set2->capacity());

}

TEST_F(TestTritSet, METHOD_TEST) {
	ASSERT_EQ(set2->cardinality(trit::Unknown), SIZE_SECOND_SET);

	for (size_t i = 0; i < SIZE_FIRST_SET - 5; i++)
		(*set1)[i] = trit::True;
	ASSERT_EQ(set1->cardinality(trit::True), SIZE_FIRST_SET - 5);

	(*set1)[BIG_INDEX_FOR_CHECK] = trit::True;
	ASSERT_EQ(set1->length(), BIG_INDEX_FOR_CHECK + 1);

	ASSERT_NO_THROW(set1->trim(BIG_INDEX_FOR_CHECK));

	(*set1)[BIG_INDEX_FOR_CHECK] = trit::True;
	size_t allocMem = set1->capacity();
	set1->trim(0);
	ASSERT_LT(set2->capacity(), allocMem);

	for (size_t i = 0; i < SIZE_FIRST_SET; i++) {
		(*set1)[i] = trit::True;
	}
	for (size_t i = SIZE_FIRST_SET; i < SIZE_FIRST_SET * 2; i++) {
		(*set1)[i] = trit::False;
	}
	std::unordered_map< trit::Trit, int, std::hash<int> > result = set1->cardinality();
	ASSERT_EQ(result[trit::True], SIZE_FIRST_SET);
	ASSERT_EQ(result[trit::True], SIZE_FIRST_SET);
}

int main() {
	::testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
