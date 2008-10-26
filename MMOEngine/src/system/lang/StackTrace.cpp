/*
Copyright (C) 2007 <SWGEmu>. All rights reserved.
Distribution of this file for usage outside of Core3 is prohibited.
*/

#include "../io/StringTokenizer.h"

#include "StackTrace.h"

StackTrace::StackTrace() {
	#ifdef PLATFORM_UNIX
		void* array[25];
		count = backtrace(array, 25);

		#ifdef LINE_TRACING
			symbols = new void*[count];

			for (int i = 0; i < count; ++i) {
				symbols[i] = array[i];
			}
		#else
			symbols = backtrace_symbols(array, count);
		#endif
	#endif
}

StackTrace::~StackTrace() {
	#ifdef PLATFORM_UNIX
		if (symbols != NULL) {
			#ifdef LINE_TRACING
				delete [] symbols;
			#else
				free(symbols);
			#endif

			symbols = NULL;
		}
	#endif
}

void StackTrace::print() {
	#ifdef PLATFORM_UNIX
		#ifdef LINE_TRACING
			stringstream command;
			command << "/usr/bin/addr2line -e core3";
		#endif
		for (int i = 0; i < count; ++i) {
			#ifdef LINE_TRACING
				command << " " << hex << symbols[i];
			#else
				cout << symbols[i] << endl;
			#endif
		}
		#ifdef LINE_TRACING
			system(command.str().c_str());
		#endif
	#elif defined PLATFORM_CYGWIN
		cygwin_stackdump();
	#endif
}

void StackTrace::getStackTrace(string& trace) {
	stringstream out;

	#ifdef PLATFORM_UNIX
		for (int i = 0; i < count; i++) {
		}
	#endif

	trace = out.str();
}

void StackTrace::printStackTrace() {
	StackTrace trace;
	trace.print();
}