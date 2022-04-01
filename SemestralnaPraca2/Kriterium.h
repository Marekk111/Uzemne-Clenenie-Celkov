#pragma once
namespace structures
{
	template <typename T, typename O>
	class Kriterium
	{
	public:
		virtual T ohodnot(O* jednotka) = 0;
	};
}