#include <string>
#include <iostream>
#include <cassert>

#include <RandomHexadecimalDigitGenerator.hpp>


using std::string;
using std::cout;
using std::endl;


int
main
(
 void
)
{
	const
	string                            nameFunction = "main : ";

	RandomHexadecimalDigitGenerator * rhdg_a_p = nullptr,
	                                * rhdg_b_p = nullptr;


	cout << nameFunction << "Enter" << endl;

	rhdg_a_p = RandomHexadecimalDigitGenerator::createRandomHexadecimalDigitGenerator();
	rhdg_b_p = RandomHexadecimalDigitGenerator::createRandomHexadecimalDigitGenerator();

	// Both of the above two invocations of the createRandomHexadecimalDigitGenerator method should
	// return the same value. That is, they should both point to the address in memory where the
	// RandomHexadecimalGenerator object resides. If they don't, then this is a problem.

	assert(rhdg_a_p == rhdg_b_p);

	cout << nameFunction << "rhdg_a_p = " << rhdg_a_p << endl;
	cout << nameFunction << "rhdg_b_p = " << rhdg_b_p << endl;

	cout << nameFunction << "Exit" << endl;
}
