#include <iostream>
#include "matrix.hpp"
#include "uvector.hpp"

int main(int argc, char* argv[])
{
	//dauphine::matrix m(2,4);
	//std::cout << m.nb_rows() << std::endl;
	//std::cout << m.nb_cols() << std::endl;
   	//const matrix m(2,4);
	// Cannot call a non-const method on a const object
	//m.resize(3,5);
	//we define the matrix
	dauphine::matrix m(2,4);
	//initialize the function using the init function
	init(m, 3, 3);
	//printing the matrix elements (both lines do the same thing)
	operator<<(std::cout,m);
	std::cout << m << std::endl;
	return 0;
}

