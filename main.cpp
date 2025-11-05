#include <exception>
#include <iostream>

namespace testikles {
	
	#ifndef RESULT_STRINGS
	#define RESULT_STRINGS
	#define OK "\033[32m| OK |\033[0m"
	#define FAIL "\033[31m| FAIL |\033[0m"  
	#endif

	static void printResult(std::string strToPrint, bool success) {
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
				std::string strToPrint = actual + " was returned instead of " + expected + ".\n";

				printResult(strToPrint, false);
			}

		}
		catch(const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;			
		}
	}
}

std::string print() {
	return "HELLO";
}

int main() {
	std::string hello = "HELLO2";
	testikles::assertReturns(print, hello);
}
