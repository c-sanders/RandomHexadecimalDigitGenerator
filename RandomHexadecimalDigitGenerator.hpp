#ifndef RANDOMHEXADECIMALDIGITGENERATOR_HPP
#define RANDOMHEXADECIMALDIGITGENERATOR_HPP


#include <string>
#include <random>


using std::string;
using std::mt19937;
using std::uniform_int_distribution;


class
RandomHexadecimalDigitGenerator
{
	public :

		// Use the following two methods to create and destroy an instance of this class.

		static
		RandomHexadecimalDigitGenerator *
		createRandomHexadecimalDigitGenerator
		(
		);

		void
		destroyRandomHexadecimalDigitGenerator
		(
		);

		string
		generateRandomHexValue_invokeUsingBoundFunction
		(
		 int   amount
		);

		string
		generateRandomHexValue_invokeUsingDirectFunction
		(
		 int   amount
		);


	private :

		// By making the Ctor private, clients of this class can't invoke it.

		RandomHexadecimalDigitGenerator
		(
		);

		~RandomHexadecimalDigitGenerator
		(
		);

		void
		setupRNG_default
		(
		);

		void
		setupRNG_mt19937
		(
		);

		char
		convertIntToChar
		(
		 int   value
		);


	private :

		static
		int                               instanceCount;

		static
		RandomHexadecimalDigitGenerator * randomHexadecimalDigitGenerator_p;

		mt19937                         * rng_p;

		mt19937::result_type              seed;

		uniform_int_distribution<int>   * distribution_p = nullptr;  // (0, 15);
};


#endif

