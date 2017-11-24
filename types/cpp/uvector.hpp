#ifndef UVECTOR_HPP
#define UVECTOR_HPP

namespace dauphine
{
	class uvector
	{
	public:

		uvector(size_t size = 0);
		uvector(size_t size, double value = 0.);
		//defining a destructor
		~uvector();

	private:

		double* p_data;
		size_t m_size;
	};

}

#endif
