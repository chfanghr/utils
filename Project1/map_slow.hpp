#pragma once
#include "utils.hpp"

namespace utils {
	template<typename key_type, typename data_type>
	class map {
	private:
		struct pair {
			key_type key;
			data_type data;
		};
		list<pair> l;
	public:
		map() {

		}
	};
}