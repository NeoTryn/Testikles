#include <exception>
#include <iostream>

namespace testikles {
	
	template<typename F, typename R>
	void test(F func, R expected) {
		try {
			R actual = func();

			if (actual == expected) {
				std::cout << "\033[32m| OK |\033[0m" << " " << __func__ << " returned expected value.\n";
			}
			else {
				std::cout << "\033[31m| FAIL |\033[0m" << " " << __func__ << " returned " << actual << " instead of " << expected << ".\n";
			}

		}
		catch(const std::exception& e) {
			std::cout << "Runtime Error: " << e.what() << std::endl;			
		}
	}
}

std::string print() {
	return "HELLO";
}

int main() {
	std::string hello = "HELLO2";
	testikles::test(print, hello);
}
