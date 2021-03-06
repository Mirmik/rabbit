#ifndef RABBIT_UTIL_H
#define RABBIT_UTIL_H

#include <linalg/linalg.h>

namespace rabbit 
{
	template <class T, int N, class IT, class EIT>
	IT
	nearest_point_from_array(
		const linalg::vec<T,N>& pnt,
		IT  it,
		EIT eit
	) 
	{
		T dist;
		IT minit = it;
		T mindist = linalg::distance(pnt, *it++);

		for (; it!=eit; ++it) 
		{
			dist = linalg::distance(pnt, *it);

			if (mindist > dist) 
			{
				mindist = dist;
				minit = it;
			} 
		}

		return minit;
	}
}

#endif