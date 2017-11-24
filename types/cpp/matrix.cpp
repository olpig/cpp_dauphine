#include "matrix.hpp"
#include <algorithm>

namespace dauphine
{
	matrix::matrix(size_t nb_rows, size_t nb_cols)
		: m_nb_rows(nb_rows),
		  m_nb_cols(nb_cols),
		  m_data(nb_rows * nb_cols)
	{
	}

	std::size_t matrix::nb_rows() const
	{
		return m_nb_rows;
	}

	std::size_t matrix::nb_cols() const
	{
		return m_nb_cols;
	}

	void matrix::resize(std::size_t nb_rows, std::size_t nb_cols)
	{
		m_nb_rows = nb_rows;
		m_nb_cols = nb_cols;
		m_data.resize(m_nb_rows * m_nb_cols);
	}

	double& matrix::operator()(std::size_t i, std::size_t j)
	{
		return m_data[i * m_nb_cols + j];
	}

	const double& matrix::operator()(std::size_t i, std::size_t j) const
	{
		return m_data[i * m_nb_cols + j];
	}
//this function prints in a stream all the elements of the matrix m
//we are assigning the << operator the following function.. it means that when using the << operator we will call this procedure
	std::ostream& operator<<(std::ostream& out, const matrix& m)
	{
		for(std::size_t i = 0; i < m.nb_rows(); ++i)
		{
			for(std::size_t j = 0; j < m.nb_cols(); ++j)
			{
				out << m(i,j) << ", ";
			}
			out << std::endl;
		}
		return out;

	}

	void init(matrix& m, size_t rows, size_t cols)
	{
		m.resize(rows,cols);
		for(std::size_t i = 0; i < rows; ++i)
		{
			for(std::size_t j = 0; j < cols; ++j)
			{
				m(i,j) = 2*i + j;
			}
		}
	}

	//this function does the element by element sum of 2 matrices. rhs refers to the matrix on the right hand side of the operator
	matrix& matrix::operator+=(const matrix& rhs)
	{
		//this function can be implemented with double for loops
		//this implementation is easier to read
		std::transform(m_data.begin(), m_data.end(), rhs.m_data.begin(),m_data.begin(), std::plus<double>());
		//return *this means that the operator += will return the object being modified
		return *this;
	}

	//this is an overload for the definition of the operator +=. This overload takes a double as argument (it will add the constant to each element of the matrix
	matrix& matrix::operator+=(double rhs)
	{
		std::transform(m_data.begin(),m_data.end(),m_data.begin(), [rhs](double arg) {return arg + rhs; });
		return *this;
	}


//	matrix& operator-=(const matrix& rhs)
//	{
//		//use transform as in +=
//		std::transform(m_data.begin(), m_data.end(), rhs.m_data.begin(), m_data.begin(),std::minus<double>());
//	}
//
//
//	matrix& operator*=(const matrix& rhs)
//	{
//		//use transform as in +=
//		std::transform(m_data.begin(), m_data.end(), rhs.m_data.begin(), m_data.begin(),std::multiplies<double>());
//	}
//
//	
//	matrix& operator/=(const matrix& rhs)
//	{
//		//use transform as in +=
//		std::transform(m_data.begin(), m_data.end(), rhs.m_data.begin(), m_data.begin(),std::divides<double>());
//	}


}
