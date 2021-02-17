#include <string>
#include <iostream>
#include <cassert>

#include <RandomHexadecimalDigitGenerator.hpp>


using std::string;
using std::cout;
using std::endl;


RandomHexadecimalDigitGenerator * rhdg_p = nullptr;


RandomHexadecimalDigitGenerator *
createAndTestRHDG
(
);


void
generateTestStrings_batch_1
(
);


void
generateTestStrings_batch_2
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


	cout << nameFunction << "Enter" << endl;

	rhdg_p = createAndTestRHDG();

	// Test if an instance of the RandomHexadecimalDigitGenerator class has been successfully
	// created.

	assert(rhdg_p != nullptr);

	cout << nameFunction << "rhdg_p = " << rhdg_p << endl;

	generateTestStrings_batch_1();

	cout << nameFunction << endl;
	cout << nameFunction << endl;

	rhdg_p->setUseSeparatorCharacter(true);

	generateTestStrings_batch_2();

	cout << nameFunction << endl;
	cout << nameFunction << endl;

	rhdg_p->setSeparatorCharacter(':');

	generateTestStrings_batch_2();

	cout << nameFunction << endl;
	cout << nameFunction << endl;

	rhdg_p->setSeparatorCharacter('|');

	generateTestStrings_batch_1();
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


void
generateTestStrings_batch_1
(
)
{
	const
	string   nameFunction = "generateTestStrings_batch_1 : ";

	int      stringLength = 0;


	cout << nameFunction << "Enter" << endl;

	// Ask the RandomHexadecimalDigitGenerator to generate some test strings.
	//
	// The length of the test string to be generated, will be passed as an argument to the test
	// function, i.e. generate(), when it is invoked.

	for
	(
	 stringLength  = 0;
	 stringLength <= 16;
	 stringLength++
	)
	{
		cout << nameFunction << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;

		cout << nameFunction << "Random hex string = " << rhdg_p->generate(stringLength) << endl;

		cout << nameFunction << "Current string length setting = " << rhdg_p->getStringLength() << endl;

		cout << nameFunction << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	}

	cout << nameFunction << "Exit" << endl;
}


void
generateTestStrings_batch_2
(
)
{
	const
	string   nameFunction = "generateTestStrings_batch_2 : ";

	int      stringLength = 0;


	cout << nameFunction << "Enter" << endl;

	// Ask the RandomHexadecimalDigitGenerator to generate some test strings.
	//
	// The length of the test string to be generated, will be explicitly set before the test
	// function, i.e. generate(), is invoked. Note that when the test function is invoked, it is
	// invoked without any arguments. When it is invoked without any arguments, the default value
	// for ...

	for
	(
	 stringLength  = 0;
	 stringLength <= 16;
	 stringLength++
	)
	{
		string   randomHexString;

		int      stringLength_current;


		rhdg_p->setStringLength(stringLength);

		stringLength_current = rhdg_p->getStringLength();

		randomHexString = rhdg_p->generate();


		cout << nameFunction << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;

		cout << nameFunction << "Random hex string = " << randomHexString << endl;

		cout << nameFunction << "Current string length setting = " << stringLength_current << endl;

		cout << nameFunction << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	}

	cout << nameFunction << "Exit" << endl;
}


