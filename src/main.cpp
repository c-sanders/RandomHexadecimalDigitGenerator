#include <string>
#include <iostream>
#include <cassert>

#include <RandomHexadecimalDigitGenerator.hpp>


using std::string;
using std::cout;
using std::endl;


RandomHexadecimalDigitGenerator *
createAndTestRHDG
(
);


int
main
(
 void
)
{
	const
	string                            nameFunction = "main : ";

	RandomHexadecimalDigitGenerator * rhdg_p = nullptr;

	int                               stringLength = 0;


	cout << nameFunction << "Enter" << endl;

	rhdg_p = createAndTestRHDG();

	// Test if an instance of the RandomHexadecimalDigitGenerator class has been successfully
	// created.

	assert(rhdg_p != nullptr);

	cout << nameFunction << "rhdg_p = " << rhdg_p << endl;

	// Ask the RandomHexadecimalDigitGenerator to generate some test strings.

	cout << nameFunction << "Random hex string = " << rhdg_p->generateRandomHexValue_invokeUsingDirectFunction(stringLength) << endl;
	cout << nameFunction << "Current string length setting = " << rhdg_p->getStringLength() << endl;
	cout << nameFunction << "----------------------------------------" << endl;

	stringLength = 1;
	cout << nameFunction << "Random hex string = " << rhdg_p->generateRandomHexValue_invokeUsingDirectFunction(stringLength) << endl;
	cout << nameFunction << "Current string length setting = " << rhdg_p->getStringLength() << endl;
	cout << nameFunction << "----------------------------------------" << endl;

	stringLength = 2;
	cout << nameFunction << "Random hex string = " << rhdg_p->generateRandomHexValue_invokeUsingDirectFunction(stringLength) << endl;
	cout << nameFunction << "Current string length setting = " << rhdg_p->getStringLength() << endl;
	cout << nameFunction << "----------------------------------------" << endl;

	stringLength = 4;
	cout << nameFunction << "Random hex string = " << rhdg_p->generateRandomHexValue_invokeUsingDirectFunction(stringLength) << endl;
	cout << nameFunction << "Current string length setting = " << rhdg_p->getStringLength() << endl;
	cout << nameFunction << "----------------------------------------" << endl;

	stringLength = 8;
	cout << nameFunction << "Random hex string = " << rhdg_p->generateRandomHexValue_invokeUsingDirectFunction(stringLength) << endl;
	cout << nameFunction << "Current string length setting = " << rhdg_p->getStringLength() << endl;
	cout << nameFunction << "----------------------------------------" << endl;

	stringLength = 16;
	cout << nameFunction << "Random hex string = " << rhdg_p->generateRandomHexValue_invokeUsingDirectFunction(stringLength) << endl;
	cout << nameFunction << "Current string length setting = " << rhdg_p->getStringLength() << endl;
	cout << nameFunction << "----------------------------------------" << endl;

	rhdg_p->setStringLength(0);
	cout << nameFunction << "Random hex string = " << rhdg_p->generate() << endl;
	cout << nameFunction << "Current string length setting = " << rhdg_p->getStringLength() << endl;
	cout << nameFunction << "----------------------------------------" << endl;

	rhdg_p->setStringLength(3);
	cout << nameFunction << "Random hex string = " << rhdg_p->generate() << endl;
	cout << nameFunction << "Current string length setting = " << rhdg_p->getStringLength() << endl;
	cout << nameFunction << "----------------------------------------" << endl;

	rhdg_p->setStringLength(5);
	cout << nameFunction << "Random hex string = " << rhdg_p->generate() << endl;
	cout << nameFunction << "Current string length setting = " << rhdg_p->getStringLength() << endl;
	cout << nameFunction << "----------------------------------------" << endl;

	rhdg_p->setStringLength(6);
	cout << nameFunction << "Random hex string = " << rhdg_p->generate() << endl;
	cout << nameFunction << "Current string length setting = " << rhdg_p->getStringLength() << endl;
	cout << nameFunction << "----------------------------------------" << endl;

	rhdg_p->setStringLength(7);
	cout << nameFunction << "Random hex string = " << rhdg_p->generate() << endl;
	cout << nameFunction << "Current string length setting = " << rhdg_p->getStringLength() << endl;
	cout << nameFunction << "----------------------------------------" << endl;

	rhdg_p->setStringLength(9);
	cout << nameFunction << "Random hex string = " << rhdg_p->generate() << endl;
	cout << nameFunction << "Current string length setting = " << rhdg_p->getStringLength() << endl;
	cout << nameFunction << "----------------------------------------" << endl;

	rhdg_p->setStringLength(-10);
	cout << nameFunction << "Random hex string = " << rhdg_p->generate() << endl;
	cout << nameFunction << "Current string length setting = " << rhdg_p->getStringLength() << endl;
	cout << nameFunction << "----------------------------------------" << endl;
}


RandomHexadecimalDigitGenerator *
createAndTestRHDG
(
)
{
	const
	string                            nameFunction = "createAndTestRHDG : ";

	RandomHexadecimalDigitGenerator * rhdg_a_p = nullptr,
	                                * rhdg_b_p = nullptr;


	cout << nameFunction << "Enter" << endl;

	// The RandomHexadecimalDigitGenerator class is implemented as a singleton.
	//
	// This means that a maximum of only one instance of it should ever exist at any point in time.
	//
	// Test this by attempting to create two instances of the RandomHexadecimalDigitGenerator.

	rhdg_a_p = RandomHexadecimalDigitGenerator::createRandomHexadecimalDigitGenerator();
	rhdg_b_p = RandomHexadecimalDigitGenerator::createRandomHexadecimalDigitGenerator();

	// The two instances, i.e. rhdg_a_p and rhdg_b_p, should both point to the same instance. That
	// is, they should both point to the address in memory where the single
	// RandomHexadecimalGenerator object resides. If they don't, then this is a problem.

	assert(rhdg_a_p == rhdg_b_p);

	cout << nameFunction << "rhdg_a_p = " << rhdg_a_p << endl;
	cout << nameFunction << "rhdg_b_p = " << rhdg_b_p << endl;

	cout << nameFunction << "Exit" << endl;

	return(rhdg_a_p);
}

