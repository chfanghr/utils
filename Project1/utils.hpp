// Don't use cconstexpr because Arduino doesn't support it.
// Also exception.
// F**K

// Exception Handling
#ifdef ARDUINO
#define panic(m) Serial.println("OOPS!!!");Serial.println(String(m.c_str()));while(true)
#define THROW_EXCEPTION(m) panic(m)
#else
#define THROW_EXCEPTION(m) \
	throw m
#endif // ARDUINO

// Configuration
#ifdef ADRUINO
#define QUEUE_DEFAULT_CAP 10
#define QUEUE_MAX_CAP 50
#else
#define QUEUE_DEFAULT_CAP 100;
//#define QUEUE_MAX_CAP 500
#endif // ARDUINO

// Headers
#ifdef ARDUINO
#include "map_slow.h"
#else
#include <string>
#include <string.h>
#include "map.hpp"
#endif // ARDUINO

#include "list.hpp"
#include "queue.hpp"
