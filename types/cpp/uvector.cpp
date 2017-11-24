#include "uvector.hpp"
#include <algorithm>

namespace dauphine
{
	uvector::uvector(size_t size)
		: p_data(nullptr), m_size(0)
	{
		if(size != 0)
		{
			p_data = new double[size];
			m_size = size;
		}
	}

	uvector::uvector(std::size_t size, double value)
		: p_data(nullptr), m_size(0)
	{
		if(size != 0)
		{
			p_data = new double[size];
			m_size = size;
		}
		std::fill(p_data, p_data + size, value);
	}
	
//	uvector::uvector(size_t size, double value)
//		: uvector(size) //delegating constructor (we don't need to replicate the code from the previous definition of uvector::uvector)
//	{
//		std::fill(p_data, p_data + size, value);
//	}
	
	uvector::~uvector()
	{
		delete[] p_data;
		p_data = nullptr;
		m_size = 0;
	}

}
