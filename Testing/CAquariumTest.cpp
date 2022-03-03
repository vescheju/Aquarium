#include "pch.h"
#include "CppUnitTest.h"

#include <regex>
#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>

#include "Aquarium.h"
#include "FishBeta.h"
#include "SpartanFish.h"
#include "FishNemo.h"
#include "FishAngler.h"
#include "DecorCastle.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Gdiplus;
using namespace std;

// constant for random seed
const unsigned int RandomSeed = 1238197374;
/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 50;

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedY = 30;

namespace Testing
{
	TEST_CLASS(CAquariumTest)
	{
	public:
		/**
		* Create a path to a place to put temporary files
		*/
		wstring TempPath()
		{
			// Create a path to temporary files
			wchar_t path_nts[MAX_PATH];
			GetTempPath(MAX_PATH, path_nts);

			// Convert null terminated string to wstring
			return wstring(path_nts);
		}

		/**
		* Read a file into a wstring and return it.
		* \param filename Name of the file to read
		* \return File contents
		*/
		wstring ReadFile(const wstring& filename)
		{
			ifstream t(filename);
			wstring str((istreambuf_iterator<char>(t)),
				istreambuf_iterator<char>());

			return str;
		}

		/**
		* Test to ensure an aquarium .aqua file is empty
		* \param filename name of the file
		*/
		void TestEmpty(wstring filename)
		{
			Logger::WriteMessage(filename.c_str());

			wstring xml = ReadFile(filename);
			Logger::WriteMessage(xml.c_str());


			Assert::IsTrue(regex_search(xml, wregex(L"<\\?xml.*\\?>")));
			Assert::IsTrue(regex_search(xml, wregex(L"<aqua/>")));
		}
		/**
		*  Test betas
		* \param filename name of the file
		*/
		void TestThreeBetas(wstring filename)
		{
			Logger::WriteMessage(filename.c_str());

			wstring xml = ReadFile(filename);
			Logger::WriteMessage(xml.c_str());

			// Ensure three items
			Assert::IsTrue(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*</aqua>")));

			// Ensure the positions are correct
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\"")));

			// Ensure the types are correct
			Assert::IsTrue(regex_search(xml,
				wregex(L"<aqua><item.* type=\"beta\"/><item.* type=\"beta\"/><item.* type=\"beta\"/></aqua>")));
		}
		/**
		*  test all items
		* \param filename name of the file
		*/
		void TestAllTypes(wstring filename)
		{
			Logger::WriteMessage(filename.c_str());

			wstring xml = ReadFile(filename);
			Logger::WriteMessage(xml.c_str());

			// Ensure five items
			Assert::IsTrue(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*<item.*<item.*</aqua>")));

			// Ensure the positions are correct
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"100\" y=\"100\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"500\" y=\"500\"")));

			// Ensure the types are correct
			Assert::IsTrue(regex_search(xml,
				wregex(L"<aqua><item.* type=\"beta\"/><item.* type=\"angler\"/><item.* type=\"nemo\"/><item.* type=\"sparty\"/><item.* type=\"castle\"/></aqua>")));
		}
		/**
		*  test beta items
		* \param filename name of the file
		*/
		void TestThreeBetasMoving(wstring filename)
		{
			Logger::WriteMessage(filename.c_str());

			wstring xml = ReadFile(filename);
			Logger::WriteMessage(xml.c_str());

			// Ensure three items
			Assert::IsTrue(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*</aqua>")));
			
			// Ensure the positions are correct
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\" speedx=\"34\\.8301.*\" speedy=\"22\\.548.*\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\" speedx=\"32\\.501.*\" speedy=\"24\\.469.*\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\" speedx=\"22\\.3664.*\" speedy=\"21\\.114.*\"")));

			// Ensure the types are correct
			Assert::IsTrue(regex_search(xml,
				wregex(L"<aqua><item.* type=\"beta\"/><item.* type=\"beta\"/><item.* type=\"beta\"/></aqua>")));
		}
		/**
		*  test all items
		* \param filename name of the file
		*/
		void TestAllTypesMoving(wstring filename)
		{
			Logger::WriteMessage(filename.c_str());

			wstring xml = ReadFile(filename);
			Logger::WriteMessage(xml.c_str());

			// Ensure five items
			Assert::IsTrue(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*<item.*<item.*</aqua>")));


			// Ensure the positions are correct
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\" speedx=\"34\\.8301.*\" speedy=\"22\\.548.*\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\" speedx=\"28\\.125.*\" speedy=\"19\\.469.*\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\" speedx=\"62\\.366.*\" speedy=\"36\\.686.*\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"100\" y=\"100\" speedx=\"113\\.1955.*\" speedy=\"107\\.810.*\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"500\" y=\"500\"")));

			// Ensure the types are correct
			Assert::IsTrue(regex_search(xml,
				wregex(L"<aqua><item.* type=\"beta\"/><item.* type=\"angler\"/><item.* type=\"nemo\"/><item.* type=\"sparty\"/><item.* type=\"castle\"/></aqua>")));
		}

		/**
		*  Populate an aquarium with three Beta fish
		* \param aquarium the aquarium to be placed
		*/
		void PopulateThreeBetas(CAquarium* aquarium)
		{
			shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(aquarium);
			fish1->SetLocation(100, 200);
			aquarium->Add(fish1);

			shared_ptr<CFishBeta> fish2 = make_shared<CFishBeta>(aquarium);
			fish2->SetLocation(400, 400);
			aquarium->Add(fish2);

			shared_ptr<CFishBeta> fish3 = make_shared<CFishBeta>(aquarium);
			fish3->SetLocation(600, 100);
			aquarium->Add(fish3);
		}
		/**
		*  Populate an aquarium with all items
		* \param aquarium the aquarium to be placed
		*/
		void PopulateAllTypes(CAquarium* aquarium)
		{
			shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(aquarium);
			fish1->SetLocation(100, 200);
			aquarium->Add(fish1);

			shared_ptr<CFishAngler> fish2 = make_shared<CFishAngler>(aquarium);
			fish2->SetLocation(400, 400);
			aquarium->Add(fish2);

			shared_ptr<CFishNemo> fish3 = make_shared<CFishNemo>(aquarium);
			fish3->SetLocation(600, 100);
			aquarium->Add(fish3);

			shared_ptr<CSpartanFish> fish4 = make_shared<CSpartanFish>(aquarium);
			fish4->SetLocation(100, 100);
			aquarium->Add(fish4);

			shared_ptr<CDecorCastle> decor1 = make_shared<CDecorCastle>(aquarium);
			decor1->SetLocation(500, 500);
			aquarium->Add(decor1);

		}
		/**
		*  Populate an aquarium with all fish moving
		* \param aquarium the aquarium to be placed
		*/
		void PopulateAllTypesMoving(CAquarium* aquarium)
		{
			srand(RandomSeed);
			shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(aquarium);
			fish1->SetLocation(100, 200);
			aquarium->Add(fish1);

			shared_ptr<CFishAngler> fish2 = make_shared<CFishAngler>(aquarium);
			fish2->SetLocation(400, 400);
			aquarium->Add(fish2);

			shared_ptr<CFishNemo> fish3 = make_shared<CFishNemo>(aquarium);
			fish3->SetLocation(600, 100);
			aquarium->Add(fish3);

			shared_ptr<CSpartanFish> fish4 = make_shared<CSpartanFish>(aquarium);
			fish4->SetLocation(100, 100);
			aquarium->Add(fish4);

			shared_ptr<CDecorCastle> decor1 = make_shared<CDecorCastle>(aquarium);
			decor1->SetLocation(500, 500);
			aquarium->Add(decor1);

		}

		/**
		*  Populate an aquarium with three Beta fish moving
		* \param aquarium the aquarium to be placed
		*/
		void PopulateThreeBetasMoving(CAquarium* aquarium)
		{
			srand(RandomSeed);
			shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(aquarium);
			fish1->SetLocation(100, 200);
			aquarium->Add(fish1);

			shared_ptr<CFishBeta> fish2 = make_shared<CFishBeta>(aquarium);
			fish2->SetLocation(400, 400);
			aquarium->Add(fish2);

			shared_ptr<CFishBeta> fish3 = make_shared<CFishBeta>(aquarium);
			fish3->SetLocation(600, 100);
			aquarium->Add(fish3);
		}

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestCAquariumConstruct)
		{
			CAquarium aquarium;
		}

		TEST_METHOD(TestCAquariumHitTest)
		{
			CAquarium aquarium;

			Assert::IsTrue(aquarium.HitTest(100, 200) == nullptr,
				L"Testing empty aquarium");

			shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(&aquarium);
			fish1->SetLocation(100, 200);
			aquarium.Add(fish1);

			Assert::IsTrue(aquarium.HitTest(100, 200) == fish1,
				L"Testing fish at 100, 200");

			// Testing if fish is not clicked on
			Assert::IsTrue(aquarium.HitTest(100, 300) == nullptr,
				L"Testing blank space");
			
			// Testing if two fish are on top of each other
			shared_ptr<CFishBeta> fish2 = make_shared<CFishBeta>(&aquarium);
			fish2->SetLocation(100, 200);
			aquarium.Add(fish2);

			Assert::IsTrue(aquarium.HitTest(100, 200) == fish2,
				L"Testing top fish");
			Assert::IsFalse(aquarium.HitTest(100, 200) == fish1,
				L"Testing bottom fish");

			// Testing if fish is not clicked on with 2 fish
			Assert::IsTrue(aquarium.HitTest(100, 100) == nullptr,
				L"Testing new blank");


		}
		TEST_METHOD(TestCAquariumSave)
		{
			// Create a path to temporary files
			wstring path = TempPath();

			// Create an aquarium
			CAquarium aquarium;

			//
			// First test, saving an empty aquarium
			//
			wstring file1 = path + L"test1.aqua";
			aquarium.Save(file1);

			TestEmpty(file1);

			//
			// Now populate the aquarium
			//

			PopulateThreeBetas(&aquarium);

			wstring file2 = path + L"test2.aqua";
			aquarium.Save(file2);

			TestThreeBetas(file2);

			//
			// Test all types
			//
			CAquarium aquarium3;
			PopulateAllTypes(&aquarium3);

			wstring file3 = path + L"test3.aqua";
			aquarium3.Save(file3);

			TestAllTypes(file3);


		}

		TEST_METHOD(TestCAquariumClear)
		{
			// Create a path to temporary files
			wstring path = TempPath();

			// Create an aquarium
			CAquarium aquarium;

			//
			// Populate the aquarium
			//

			PopulateThreeBetas(&aquarium);

			wstring file1 = path + L"test4.aqua";
			aquarium.Save(file1);
			
			//
			//	Check if populated
			//

			TestThreeBetas(file1);

			//
			// Clear the aquarium, save it, check it.
			//

			aquarium.Clear();

			aquarium.Save(file1);

			TestEmpty(file1);


		}

		TEST_METHOD(TestCAquariumLoad)
		{
			// Create a path to temporary files
			wstring path = TempPath();

			// Create two aquariums
			CAquarium aquarium, aquarium2;

			//
			// First test, saving an empty aquarium
			//
			wstring file1 = path + L"test1.aqua";

			aquarium.Save(file1);
			TestEmpty(file1);

			aquarium2.Load(file1);
			aquarium2.Save(file1);
			TestEmpty(file1);

			//
			// Now populate the aquarium
			//

			PopulateThreeBetas(&aquarium);

			wstring file2 = path + L"test2.aqua";
			aquarium.Save(file2);
			TestThreeBetas(file2);

			aquarium2.Load(file2);
			aquarium2.Save(file2);
			TestThreeBetas(file2);

			//
			// Test all types
			//
			CAquarium aquarium3;
			PopulateAllTypes(&aquarium3);

			wstring file3 = path + L"test3.aqua";
			aquarium3.Save(file3);
			TestAllTypes(file3);

			aquarium2.Load(file3);
			aquarium2.Save(file3);
			TestAllTypes(file3);
		}

		TEST_METHOD(TestCAquariumLoadMoving)
		{
			// Create a path to temporary files
			wstring path = TempPath();

			// Create two aquariums
			CAquarium aquarium, aquarium2;


			PopulateThreeBetasMoving(&aquarium);

			wstring file2 = path + L"test2.aqua";
			aquarium.Save(file2);
			TestThreeBetasMoving(file2);

			//
			// Test all types
			//
			CAquarium aquarium3;
			PopulateAllTypesMoving(&aquarium3);

			wstring file3 = path + L"test3.aqua";
			aquarium3.Save(file3);
			TestAllTypesMoving(file3);

			aquarium2.Load(file2);
			aquarium2.Save(file2);
			TestThreeBetasMoving(file2);

			aquarium3.Load(file3);
			aquarium3.Save(file3);
			TestAllTypesMoving(file3);
		
		}


	};
}