#pragma once

#ifdef MAC_ENV
	#ifndef DllImport
		#define DllImport 
	#endif

	#ifndef DllExport 
		#define DllExport __attribute__((visibility("default")))
	#endif
#else
	#ifndef DllImport
		#define DllImport __declspec( dllimport )
	#endif

	#ifndef DllExport 
		#define DllExport __declspec( dllexport )
	#endif
#endif

// https://docs.microsoft.com/en-us/cpp/build/reference/implib-name-import-library
// This is needed becuase otherwise MSVC linker will try to look for 
// default STATIC lib enven though we are making a SHARED lib.
#ifdef __LIB_COMPONENT__
	#define LIB_IMP_EXP DllExport
#else
	#define LIB_IMP_EXP DllImport
#endif
