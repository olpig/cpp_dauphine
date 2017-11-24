#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <ostream>

namespace dauphine
{
	class matrix
	{
	public:
		matrix(std::size_t nb_rows, std::size_t nb_cols);

		std::size_t nb_rows() const;
		std::size_t nb_cols() const;

		void resize(std::size_t nb_rows, std::size_t nb_cols);

		double& operator()(std::size_t i, std::size_t j);
		const double& operator()(std::size_t i, std::size_t j) const;

		matrix& operator+=(const matrix& rhs);
		matrix& operator-=(const matrix& rhs);
		matrix& operator*=(const matrix& rhs);
		matrix& operator/=(const matrix& rhs);

		matrix& operator+=(double rhs);
		matrix& operator-=(double rhs);
		matrix& operator*=(double rhs);
		matrix& operator/=(double rhs);

	private:

		std::size_t m_nb_rows;
		std::size_t m_nb_cols;
		std::vector<double> m_data;
	};

	std::ostream& operator<<(std::ostream& out, const matrix& m);
	void init(matrix& m, std::size_t rows, std::size_t cols);
}

#endif

