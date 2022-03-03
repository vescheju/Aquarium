#include "pch.h"
#include "CppUnitTest.h"

#include "Item.h"
#include "Aquarium.h"
#include "FishBeta.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CBetaFishTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(TestCFishBetaConst)
		{
			CAquarium aquarium;
			CFishBeta fish(&aquarium);
		}
        

	};
}