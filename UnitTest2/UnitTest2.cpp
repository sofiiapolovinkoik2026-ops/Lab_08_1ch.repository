#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_08_1ch/Lab_08_1ch.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81C
{
	TEST_CLASS(UnitTest81C)
	{
	public:
		TEST_METHOD(TestInclude)
		{
			Assert::IsTrue(Include("abc!!!def"));
			Assert::IsFalse(Include("abc!!def"));
		}

		TEST_METHOD(TestChange)
		{
			char str[50] = "a!!!b!!!c";
			char dest[50];
			Change(dest, str);
			Assert::AreEqual("a**b**c", dest);
		}
	};
}