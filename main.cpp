#include <exception>
#include <iostream>

namespace testikles {
	
	#ifndef RESULT_STRINGS
	#define RESULT_STRINGS
	#define OK "\033[32m|  OK  |\033[0m"
	#define FAIL "\033[31m| FAIL |\033[0m"  
	#endif

	static inline void printResult(std::string strToPrint, bool success) {
		if (success) {
			std::cout << OK << " " << strToPrint << std::endl;
		}
		else {
			std::cout << FAIL << " " << strToPrint << std::endl;
		}
	}

	template<typename F, typename R>
	void assertReturns(F func, R expected) {
		try {
			R actual = func();

			if (actual == expected) {
				std::string strToPrint = expected + " was returned";
					
				printResult(strToPrint, true);
			}
			else {
				std::string strToPrint = actual + " was returned instead of " + expected + ".";

				printResult(strToPrint, false);
			}
		}
		catch(const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;			
		}
	}

	template<typename V>
	void assertEquals(V value, V expected) {
		if (value == expected) {
			printResult("The values match.", true);
		}
		else {
			std::string strToPrint = value + " and " + expected + " do not match.";
			printResult(strToPrint, false);
		}
	}
}

std::string print() {
	return "HELLO";
}

int main() {
	std::string hello = "HELLO2";
	std::string hell2 = "HELLO2";
	std::string hell3 = "HELLO3";
	int bye = 1;

	testikles::assertReturns(print, hello);
	testikles::assertEquals(hello, hell2);
}
