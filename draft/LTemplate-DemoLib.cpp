/*  This file was automatically generated by LTemplate. DO NOT EDIT.  */
/*  https://github.com/szhorvat/LTemplate  */

#define LTEMPLATE_MMA_VERSION  1210

#include "LTemplate.h"
#include "LTemplateHelpers.h"
#include "Demo1.h"


#define LTEMPLATE_MESSAGE_SYMBOL  "LTemplate`LTemplate"

#include "LTemplate.inc"


std::map<mint, Demo1 *> Demo1_collection;

namespace mma
{
	template<> const std::map<mint, Demo1 *> & getCollection<Demo1>()
	{
		return Demo1_collection;
	}
}

DLLEXPORT void Demo1_manager_fun(WolframLibraryData libData, mbool mode, mint id)
{
	if (mode == 0) { // create
	  Demo1_collection[id] = new Demo1();
	} else {  // destroy
	  if (Demo1_collection.find(id) == Demo1_collection.end()) {
	    libData->Message("noinst");
	    return;
	  }
	  delete Demo1_collection[id];
	  Demo1_collection.erase(id);
	}
}

extern "C" DLLEXPORT int Demo1_get_collection(WolframLibraryData libData, mint Argc, MArgument * Args, MArgument Res)
{
	mma::TensorRef<mint> res = mma::detail::get_collection(Demo1_collection);
	mma::detail::setTensor<mint>(Res, res);
	return LIBRARY_NO_ERROR;
}


extern "C" DLLEXPORT mint WolframLibrary_getVersion()
{
	return WolframLibraryVersion;
}

extern "C" DLLEXPORT int WolframLibrary_initialize(WolframLibraryData libData)
{
	mma::libData = libData;
	{
		int err;
		err = (*libData->registerLibraryExpressionManager)("Demo1", Demo1_manager_fun);
		if (err != LIBRARY_NO_ERROR) return err;
	}
	return LIBRARY_NO_ERROR;
}

extern "C" DLLEXPORT void WolframLibrary_uninitialize(WolframLibraryData libData)
{
	(*libData->unregisterLibraryExpressionManager)("Demo1");
	return;
}


extern "C" DLLEXPORT int Demo1_addTwo(WolframLibraryData libData, mint Argc, MArgument * Args, MArgument Res)
{
	mma::detail::MOutFlushGuard flushguard;
	const mint id = MArgument_getInteger(Args[0]);
	if (Demo1_collection.find(id) == Demo1_collection.end()) { libData->Message("noinst"); return LIBRARY_FUNCTION_ERROR; }
	
	try
	{
		mint var1 = MArgument_getInteger(Args[1]);
		mint var2 = MArgument_getInteger(Args[2]);
		
		mint res = (Demo1_collection[id])->addTwo(var1, var2);
		MArgument_setInteger(Res, res);
	}
	catch (const mma::LibraryError & libErr)
	{
		libErr.report();
		return libErr.error_code();
	}
	catch (const std::exception & exc)
	{
		mma::detail::handleUnknownException(exc.what(), "Demo1::addTwo()");
		return LIBRARY_FUNCTION_ERROR;
	}
	catch (...)
	{
		mma::detail::handleUnknownException(NULL, "Demo1::addTwo()");
		return LIBRARY_FUNCTION_ERROR;
	}
	
	return LIBRARY_NO_ERROR;
}


extern "C" DLLEXPORT int Demo1_trace(WolframLibraryData libData, mint Argc, MArgument * Args, MArgument Res)
{
	mma::detail::MOutFlushGuard flushguard;
	const mint id = MArgument_getInteger(Args[0]);
	if (Demo1_collection.find(id) == Demo1_collection.end()) { libData->Message("noinst"); return LIBRARY_FUNCTION_ERROR; }
	
	try
	{
		mma::TensorRef<double> var1 = mma::detail::getTensor<double>(Args[1]);
		
		double res = (Demo1_collection[id])->trace(var1);
		MArgument_setReal(Res, res);
	}
	catch (const mma::LibraryError & libErr)
	{
		libErr.report();
		return libErr.error_code();
	}
	catch (const std::exception & exc)
	{
		mma::detail::handleUnknownException(exc.what(), "Demo1::trace()");
		return LIBRARY_FUNCTION_ERROR;
	}
	catch (...)
	{
		mma::detail::handleUnknownException(NULL, "Demo1::trace()");
		return LIBRARY_FUNCTION_ERROR;
	}
	
	return LIBRARY_NO_ERROR;
}


