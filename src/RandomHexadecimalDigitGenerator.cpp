#include <RandomHexadecimalDigitGenerator.hpp>

#include <iostream>
#include <sstream>
#include <functional>


using std::cout;
using std::endl;
using std::stringstream;


int                  RandomHexadecimalDigitGenerator::instanceCount        = 0;

RandomHexadecimalDigitGenerator * RandomHexadecimalDigitGenerator::randomHexadecimalDigitGenerator_p = nullptr;



RandomHexadecimalDigitGenerator *
RandomHexadecimalDigitGenerator::createRandomHexadecimalDigitGenerator
(
)
{
	const
	string   nameFunction = "RandomHexadecimalDigitGenerator::createRandomHexadecimalDigitGenerator : ";


	cout << nameFunction << "Enter" << endl;

	// Does an instance of the RandomHexadecimalDigitGenerator already exist?
	
	if (RandomHexadecimalDigitGenerator::randomHexadecimalDigitGenerator_p == nullptr)
	{
		RandomHexadecimalDigitGenerator::randomHexadecimalDigitGenerator_p = new RandomHexadecimalDigitGenerator();
	}
	else
	{
		cout << "Random Hex Generator already eists." << endl;
	}

	cout << nameFunction << "Exit" << endl;

	return(RandomHexadecimalDigitGenerator::randomHexadecimalDigitGenerator_p);
}


RandomHexadecimalDigitGenerator::RandomHexadecimalDigitGenerator
(
)
{
	const
	string   nameFunction = "RandomHexadecimalDigitGenerator Ctor : ";


	cout << nameFunction << "Enter" << endl;

	this->setupRNG_default();
	this->setupRNG_mt19937();

	cout << nameFunction << "Exit" << endl;
}


RandomHexadecimalDigitGenerator::~RandomHexadecimalDigitGenerator
(
)
{
	const
	string   nameFunction = "RandomHexadecimalDigitGenerator Dtor : ";


	cout << nameFunction << "Enter" << endl;

	cout << nameFunction << "Exit" << endl;
}


void
RandomHexadecimalDigitGenerator::setupRNG_default
(
)
{
	const
	string   nameFunction = "RandomHexadecimalDigitGenerator::setupRNG_default : ";


	cout << nameFunction << "Enter" << endl;

	cout << nameFunction << "Exit" << endl;
}


void
RandomHexadecimalDigitGenerator::setupRNG_mt19937
(
)
{
	const
	string   nameFunction = "RandomHexadecimalDigitGenerator::setupRNG_mt19937 : ";


	cout << nameFunction << "Enter" << endl;

	// Initialise the seed for the Random Number Generator (rng).

	this->seed = time(0);

	// Create an instance of the RNG, seeding it with the value which was just created.

	this->rng_p = new mt19937(this->seed);

	// mt19937(this->seed)
	
	this->distribution_p = new uniform_int_distribution<int>(0, 15);

	cout << nameFunction << "Exit" << endl;
}


string
RandomHexadecimalDigitGenerator::generateRandomHexValue_invokeUsingBoundFunction
(
 int  amount
)
{
	auto
	rng = std::bind
	      (
	       * this->distribution_p,
	       * this->rng_p
	      );

	int                             counter;

	char                            hexValue;
	
	stringstream                    hexString;

	// auto                            rng = (* this->distribution_p)(* this->rng_p);

	// mt19937                       * rng_p = nullptr;

	// uniform_int_distribution<int>   distribution(0, 15);


	// Get a random integer which is in the range 0 - 15.

	// (* this->distribution_p)(* this->rng_p);

	// value = rng();

	// value = this->distribution_p(* this->rng_p);

	// Convert this integer into a hexadecimal character.

	hexValue = (* this->distribution_p)(* this->rng_p);
	cout << "First hexadecimal value = " << (int)(hexValue) << endl;
	hexValue = (* this->distribution_p)(* this->rng_p);
	cout << "First hexadecimal value = " << (int)(hexValue) << endl;
	hexValue = (* this->distribution_p)(* this->rng_p);
	cout << "First hexadecimal value = " << (int)(hexValue) << endl;

	// hexValue = (* this->distribution_p)(* this->rng_p)();
	hexValue = this->convertIntToChar(rng());
	cout << "Hexadecimal value = " << hexValue << endl;
	// hexValue = (* this->distribution_p)(* this->rng_p)();
	hexValue = this->convertIntToChar(rng());
	cout << "Hexadecimal value = " << hexValue << endl;
	// hexValue = (* this->distribution_p)(* this->rng_p)();
	hexValue = this->convertIntToChar(rng());
	cout << "Hexadecimal value = " << hexValue << endl;

	for
	(
	 int   counter = 0;
	 counter < amount;
	 ++counter
	)
	{
		// rng();

		hexValue = this->convertIntToChar(10);

		hexString << hexValue;
		cout << hexValue << endl;
	}

	// cout << hexString.str() << endl;

	return(hexString.str());
}


string
RandomHexadecimalDigitGenerator::generateRandomHexValue_invokeUsingDirectFunction
(
 int  amount
)
{
	int            counter;

	stringstream   hexString,
	               hexString_humanReadable;


	// Get a random integer which is in the range 0 - 15.

	// Can the following be turned into a Lambda function?
	
	(* this->distribution_p)(* this->rng_p);

	// value = rng();

	// value = this->distribution_p(* this->rng_p);

	// Convert this integer into a hexadecimal character.

	for
	(
	 int   counter = 1;
	 counter <= 4 ;
	 ++counter
	)
	{
		for
		(
		 int   counter = 1;
		 counter <= 4;
		 ++counter
		)
		{
			char   hexDigit;


			hexDigit = this->convertIntToChar((* this->distribution_p)(* this->rng_p));

			hexString               << hexDigit;
			hexString_humanReadable << hexDigit;
		}

		if (counter < 4)
		{
			hexString_humanReadable << '-';
		}
	}

	cout << "Hex string                  = " << hexString.str() << endl;
	cout << "Hex string (human readable) = " << hexString_humanReadable.str() << endl;

	return(hexString.str());
}


char
RandomHexadecimalDigitGenerator::convertIntToChar
(
 int   value
)
{
	char   hexValue;

	char   hexValueArray[] = {'0',
	                          '1',
	                          '2',
	                          '3',
	                          '4',
	                          '5',
	                          '6',
	                          '7',
	                          '8',
	                          '9',
	                          'A',
	                          'B',
	                          'C',
	                          'D',
	                          'E',
	                          'F'};


	hexValue = hexValueArray[value];

	// cout << "Hex value = " << hexValue << endl;

	return(hexValue);
}
