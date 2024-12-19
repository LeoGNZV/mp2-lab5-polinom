#include <gtest.h>
#include "polinom.h"

int main(int argc, char** argv)
{
	Polinom a("3x3y4");
	Polinom b("3x2y4z2");
	b.get_information();
	a = b;
	a.get_information();
	//EXPECT_EQ(b.get_information(), a.get_information());
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
