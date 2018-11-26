#pragma once
#include "utils.hpp"

namespace utils {
	template<typename data_type>
	class queue {
	private:
		size_t cap, len, head, tail;
		bool is_dynamic;
		data_type* data_arr;
	public:
		queue(size_t _cap = 0) {
			if (_cap<0
#ifdef QUEUE_MAX_CAP
				|| _cap>QUEUE_MAX_CAP
#endif // QUEUE_MAX_CAP
				)THROW_EXCEPTION(exception_bad_size());
			if (_cap == 0) {
				is_dynamic = true;
				cap = QUEUE_DEFAULT_CAP;
			}
			else {
				is_dynamic = false;
				cap = _cap;
			}
			auto new_ptr = (data_type*)malloc(sizeof(data_type)*cap);
			data_arr = new_ptr != nullptr ? new_ptr : THROW_EXCEPTION(exception_memory());
			head = tail = 0;
			len = 0;
		}
		~queue() {
			for (auto i = 0; i < len; i++)
				data_arr[i].~data_type();
		}
		bool empty() {
			return len == 0;
		}
		size_t size() {
			return len;
		}
		data_type front() {
			if (len > 0)
				return data_arr[head];
			THROW_EXCEPTION(exception_empty());
		}
		data_type end() {
			if (len > 0)
				return data_arr[tail];
			THROW_EXCEPTION(exception_empty());
		}
		void push(data_type data) {
			if (len == cap) {
#ifdef QUEUE_MAX_CAP
				if (cap == QUEUE_MAX_CAP)THROW_EXCEPTION(exception_full());
#endif // QUEUE_MAX_CAP
				if (!is_dynamic)THROW_EXCEPTION(exception_full());
				else {
					auto new_ptr = (data_type*)realloc((void*)data_arr, sizeof(data_type)*(cap + 1));
					if (new_ptr == nullptr)THROW_EXCEPTION(exception_memory());
					data_arr = new_ptr;
					cap++;
				}
			}

			if (head + len > cap) {
				data_arr[head + len - cap] = data_type(data);
				tail = head + len - cap;
			}
			else {
				data_arr[head + len] = data_type(data);
				tail = head + len;
			}
			len++;
		}
		void pop() {
			if (len > 0) {
				data_arr[head].~data_type();
				if (head - (cap - 1) == 0)head = 0;
				else head = head++;
				len--;
				return;
			}
			THROW_EXCEPTION(exception_empty());
		}
		void reset(size_t _cap = 0) {
			for (auto i = 0; i < len; i++)
				data_arr[i].~data_type();
			free(data_arr);
			if (_cap<0
#ifdef QUEUE_MAX_CAP
				|| _cap>QUEUE_MAX_CAP
#endif // QUEUE_MAX_CAP
				)THROW_EXCEPTION(exception_bad_size());
			if (_cap == 0) {
				is_dynamic = true;
				cap = QUEUE_DEFAULT_CAP;
			}
			else {
				is_dynamic = false;
				cap = _cap;
			}
			auto new_ptr = (data_type*)malloc(sizeof(data_type)*cap);
			data_arr = new_ptr != nullptr ? new_ptr : THROW_EXCEPTION(exception_memory());
			head = tail = 0;
			len = 0;
		}
		class exception_full {
		public:
			const char* c_str() {
				return "queue is full\n";
			}
		};
		class exception_empty {
		public:
			const char* c_str() {
				return "queue is empty\n";
			}
		};
		class exception_memory {
		public:
			const char* c_str() {
				return "can not allocate memory\n";
			}
		};
		class exception_bad_size {
		public:
			const char* c_str() {
				return "given size is invaild\n";
			}
		};
	};
}