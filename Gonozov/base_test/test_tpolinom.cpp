#include "polinom.h"

#include <gtest.h>
TEST(Polinom, can_create_polinom)
{
	ASSERT_NO_THROW(Polinom a("2x2y2+3x3y4-6x4y1z5"));
}
TEST(Polinom, cant_create_polinom_with_zero_size)
{
	ASSERT_ANY_THROW(Polinom a(""));
}

TEST(Polinom, cant_create_polinom_with_invalid_characters)
{
	ASSERT_ANY_THROW(Polinom a("2x2y2][+3x3y4- 6x4y1z5"));
}

TEST(Polinom, cant_create_polinom_with_variable_that_has_no_degree)
{
	ASSERT_ANY_THROW(Polinom a("2x2y2+3x3y4-6x4yz"));
}

TEST(Polinom, cant_create_polinom_with_multiple_operations_recorded_in_row)
{
	ASSERT_ANY_THROW(Polinom a("2x2y2+--3x3y4-6x4y4z1"));
}

TEST(Polinom, cant_create_polinom_with_two_numbers_running_in_row)
{
	ASSERT_ANY_THROW(Polinom a("2x2y22+3x3y4-6x4y2z3"));
}

TEST(Polinom, check_correctness_of_stored_monomes)
{
	Polinom a("2x2y2+3x3y4");
	vector<pair<int, int>> res;
	pair <int, int> h;
	h.first = 2;
	h.second = 220;
	res.push_back(h);
	h.first = 3;
	h.second = 340;
	res.push_back(h);
	h.first = 0;
	h.second = 0;
	res.push_back(h);
	EXPECT_EQ(res, a.get_information());
}

TEST(Polinom, check_addition_of_polynomials)
{
	Polinom a("2x2y2+3x3y4");
	Polinom b("x2y2+3y4z2");
	vector<pair<int, int>> res;
	pair <int, int> h;
	h.first = 3;
	h.second = 220;
	res.push_back(h);
	h.first = 3;
	h.second = 340;
	res.push_back(h);
	h.first = 3;
	h.second = 42;
	res.push_back(h);
	h.first = 0;
	h.second = 0;
	res.push_back(h);
	EXPECT_EQ(res, (a+b).get_information());
}

TEST(Polinom, check_subtraction_of_polynomials)
{
	Polinom a("2x2y2+3x3y4");
	Polinom b("x2y2+3y4z2");
	vector<pair<int, int>> res;
	pair <int, int> h;
	h.first = 1;
	h.second = 220;
	res.push_back(h);
	h.first = 3;
	h.second = 340;
	res.push_back(h);
	h.first = -3;
	h.second = 42;
	res.push_back(h);
	h.first = 0;
	h.second = 0;
	res.push_back(h);
	EXPECT_EQ(res, (a - b).get_information());
}

TEST(Polinom, ability_to_assign_an_element)
{
	Polinom a("3x3y4");
	Polinom b("3x2y4z2");
	a = b;
	EXPECT_EQ(b.get_information(), a.get_information());
}

TEST(Polinom, successful_calculation_of_a_polynomial_at_a_point)
{
	Polinom a("2x2y2+3y3z4");
	EXPECT_EQ(392.0, a.calculate_at_point(1, 2, 2));
}
/*TEST(TCluster, cant_create_cluster_with_impossible_number_of_threshold_for_the_appearance_of_the_program)
{
	struct programm y1 = { "78923", 0, 18, 9 };
	struct programm y2 = { "78623", 0, 24, 7 };
	struct programm y3 = { "72323", 0, 36, 5 };
	struct programm y4 = { "75623", 0, 48, 3 };
	vector<programm> n = { y1, y2, y3, y4 };
	ASSERT_ANY_THROW(Cluster q(64, 1.4, n, 2));
}

TEST(TCluster, there_are_programs_that_cannot_be_executed_on_the_cluster_with_so_many_processors)
{
	struct programm y1 = { "78923", 0, 18, 9 };
	struct programm y2 = { "78623", 0, 24, 7 };
	struct programm y3 = { "72323", 0, 36, 5 };
	struct programm y4 = { "75623", 0, 48, 3 };
	vector<programm> n = { y1, y2, y3, y4 };
	ASSERT_ANY_THROW(Cluster q(24, 0.8, n, 2));
}

TEST(TCluster, can_start_a_cluster)
{
	struct programm y1 = { "78923", 0, 18, 9 };
	struct programm y2 = { "78623", 0, 24, 7 };
	struct programm y3 = { "72323", 0, 36, 5 };
	struct programm y4 = { "75623", 0, 48, 3 };
	vector<programm> n = { y1, y2, y3, y4 };
	Cluster q(64, 0.8, n, 2);
	ASSERT_NO_THROW(q.Starting—luster(47));
}
TEST(TCluster, cant_start_a_cluster_with_negative_value_of_tact_work_max)
{
	struct programm y1 = { "78923", 0, 18, 9 };
	struct programm y2 = { "78623", 0, 24, 7 };
	struct programm y3 = { "72323", 0, 36, 5 };
	struct programm y4 = { "75623", 0, 48, 3 };
	vector<programm> n = { y1, y2, y3, y4 };
	Cluster q(64, 0.8, n, 2);
	ASSERT_ANY_THROW(q.Starting—luster(-9));
}
TEST(TCluster, can_get_result_of_strting_cluster)
{
	struct programm y1 = { "78923", 0, 18, 9 };
	struct programm y2 = { "78623", 0, 2, 7 };
	struct programm y3 = { "72323", 0, 6, 5 };
	struct programm y4 = { "75623", 0, 8, 3 };
	vector<programm> n = { y1, y2, y3, y4 };
	Cluster q(64, 0.8, n, 2);
	q.Starting—luster(10);
	ASSERT_NO_THROW(q.get_result());
}*/