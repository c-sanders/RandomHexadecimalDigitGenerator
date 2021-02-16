#ifndef RANDOMHEXADECIMALDIGITGENERATOR_HPP
#define RANDOMHEXADECIMALDIGITGENERATOR_HPP


#include <string>
#include <random>


using std::string;
using std::mt19937;
using std::uniform_int_distribution;


/**
 * @brief The RandomHexadecimalDigitGenerator class can be used to generate strings which are
 *        comprised solely of randomly generated hexadecimal digits.
 * 
 * The number of digits which the resulting strings will contain, can be set independently set by
 * the user of the class.
 */

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

		int
		setStringLength
		(
		 int   stringLength
		);

		int
		getStringLength
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

		string
		generate
		(
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

		int                               stringLength;
};


#endif

