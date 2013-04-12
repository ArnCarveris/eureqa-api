#ifndef EUREQA_EUREQA_API_H
#define EUREQA_EUREQA_API_H

/*---------------------------------------------------------
	Eureqa Header API
	
	To start you should simply include eureqa.h.

	In order to improve compile times for more complex programs, the Eureqa
	library is split into two pieces: the API (this header) and the
	implementation (eureqa_impl.h).

	NOTE: In order to use the Eureqa API, you must have exactly one
	compilation unit (aka cpp file) #include "eureqa_impl.h"
*--------------------------------------------------------*/

#include <eureqa/data_set.h>
#include <eureqa/connection.h>
#include <eureqa/server_info.h>
#include <eureqa/search_progress.h>
#include <eureqa/search_options.h>

#endif
