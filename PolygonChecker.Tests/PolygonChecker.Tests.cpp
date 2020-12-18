#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "main.h"
}

extern "C" {
#include "triangleSolver.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonCheckerTests
{
	TEST_CLASS(TypeOfTriangle)// Arun Kumar Thulaseedharan Pillai
	{
	public:

		TEST_METHOD(T001_analyzeTriangle_2_2and2_EquilateralTriangle) // Equal numbers are written to test it for Equilateral Triangle
		{
			// Arrange
			int side1 = 2;
			int side2 = 2;
			int side3 = 2;
			char* EXPECTED = "Equilateral Triangle";

			// Act
			char* actual = analyzeTriangle(side1, side2, side3);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T002_analyzeTriangle_12_16and20_ScaleneTriangle) // Numbers are written to test it for Scalene Triangle
		{
			// Arrange
			int side1 = 12;
			int side2 = 16;
			int side3 = 20;
			char* EXPECTED = "Scalene Triangle";

			// Act
			char* actual = analyzeTriangle(side1, side2, side3);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T003_analyzeTriangle_2_2and1_IsoscelesTriangle) // Two Numbers are equal to test it for Isosceles Triangle
		{
			// Arrange
			int side1 = 2;
			int side2 = 2;
			int side3 = 1;
			char* EXPECTED = "Isosceles Triangle";

			// Act
			char* actual = analyzeTriangle(side1, side2, side3);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T004_analyzeTriangle_minus2_2and2_NotATriangle) // One of the numbers is kept negative to check if the program doesn't crash after entering the invalid input
		{
			// Arrange
			int side1 = -2;
			int side2 = 2;
			int side3 = 2;
			char* EXPECTED = "Not a Triangle";

			// Act
			char* actual = analyzeTriangle(side1, side2, side3);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T005_analyzeTriangle_10_0and20_NotATriangle) // One of the numbers is kept zero to check if the program doesn't crash after entering the invalid input
		{
			// Arrange
			int side1 = 10;
			int side2 = 0;
			int side3 = 20;
			char* EXPECTED = "Not a Triangle";

			// Act
			char* result = analyzeTriangle(side1, side2, side3);

			// Assert
			Assert::AreEqual(EXPECTED, result);
		}

		TEST_METHOD(T006_analyzeTriangle_2_3and5_NotATriangle) // This combination of numbers will check if the sides form a triangle or not by checking if the sum of either two of the sides is greater than the third one. 
		{
			//Arrange
			int side1 = 2;
			int side2 = 3;
			int side3 = 5;
			char* EXPECTED = "Not a Triangle";

			// Act
			char* actual = analyzeTriangle(side1, side2, side3);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}
	};
}
