#ifndef LIST_H_
#define LIST_H_

namespace nwacc
{
	template <typename T,int U,int L>
	class array
	{
	private:
		int lower_index_bounds;
		int Upper_index_bounds;
		int range;
		T * my_array;

	public:

		array();
		~array();
		//void set_bounds(int, int);

		int get_upper_bound();
		int get_lower_bound();

		T& operator[] (int);
		array<T,U,L>& operator=(const array<T,U,L>& x);
		array<T,U,L>& operator= (T);  // move-assignment
	};

	template <typename T,int U,int L>
	array<T,U,L>::array() 
	{
		if (L > 0 && L < U && U>0) {
			lower_index_bounds = L;
			Upper_index_bounds = U;
			range = Upper_index_bounds - lower_index_bounds;
			my_array = new T[range];
		}else
		{
			throw 11;//invalid index boundaries
		}

	}

	template <typename T,int U,int L>
	array<T,U,L>::~array()
	{
		delete[] my_array;
	}

	template <typename T, int U, int L>
	int array<T, U, L>::get_upper_bound()
	{
		return Upper_index_bounds;
	}

	template <typename T, int U, int L>
	int array<T, U, L>::get_lower_bound()
	{
		return  lower_index_bounds;
	}

	template <typename T,int U,int L>
	T& array<T,U,L>::operator[](int index)
	{
		
			
			if(index>=lower_index_bounds && index<Upper_index_bounds)
			{
				return my_array[index - lower_index_bounds];
			}
			else {
				throw 10;
			}
	}
	template <typename T, int U, int L>
	array<T,U,L>& array<T,U,L>::operator=(const array<T,U,L>& x)
	{
		delete[] my_array;
		my_array = new T[range];
		my_array = x;
		return *this;
	}

	template <typename T,int U,int L>
	array<T,U,L>& array<T,U,L>::operator=(T x)
	{
		delete[] my_array;
		my_array = new T[range];
		for (auto e=0;e<range;e++)
		{
			my_array[e] = e;
		}
		return *this;
	}
}

#endif

