#include <cstdio>
#include <dlfcn.h>
#include <string>
#include <gnu/lib-names.h>  /* Defines LIBM_SO (which will be a
									  string such as "libm.so.6") */
									  //#include "../LibraryTest/lib_finction.h"

int main()
{

	puts("This is a shared library test...");
	puts("Opening LibraryTest1.so...");
	void* handle = dlmopen(LM_ID_NEWLM, "./LibraryTest1.so", RTLD_LAZY);

	if (!handle) {
		puts("Cannot open library: ");
		puts(dlerror());
		return 1;
	}
	else {
		puts("Load OK");
		// load the symbol
		puts("Loading symbol function...\n");
		typedef void (*function_t)(char*);
		// reset errors
		dlerror();
		function_t f_instance = (function_t)dlsym(handle, "lib_finction");
		const char* dlsym_error = dlerror();
		if (dlsym_error) {

			puts("Cannot load symbol 'lib_finction': ");
			puts(dlsym_error);
			dlclose(handle);
			return 1;
		}
		// use it to do the calculation
		puts("run function ...\n");

		f_instance("run dynamic loaded function");
	}

	//    lib_finction("shared library function");
	dlclose(handle);
	return 0;
}