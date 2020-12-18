#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "main.h"
}

extern "C" {
#include "triangleSolver.h"
}

extern "C" {
#include "rectangleSolver.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonCheckerTests
{
	TEST_CLASS(TypeOfTriangle) // Arun Kumar Thulaseedharan Pillai
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

	TEST_CLASS(TriangleInsideAngle)  // Dhyey Brijeshkumar Vaghela
	{
	public:

		TEST_METHOD(T001_Sides_2_2_2_result_60_60_60)  // This test was written to prove that when the sides of the triangle are 2, 2 and 2. The respective angles will be 60, 60 and 60.

		{
			//Arrange
			int side1 = 2;
			int side2 = 2;
			int side3 = 2;
			float expectedalpha = 60;
			float expectedbeta = 60;
			float expectedgamma = 60;

			// Act
			float resultalpha = GiveAlpha(side1, side2, side3);
			float resultbeta = GiveBeta(side1, side2, side3);
			float resultgamma = GiveGamma(side1, side2, side3);

			// Assert
			Assert::AreEqual(expectedalpha, resultalpha);
			Assert::AreEqual(expectedbeta, resultbeta);
			Assert::AreEqual(expectedgamma, resultgamma);

		}

		TEST_METHOD(T002_printAngle_2_3_4_result_29_47_104) // This test was written to prove that when the sides of the triangle are 2, 3 and 4. The respective angles will be 29, 47 and 104.
		{
			// Arrange
			int side1 = 2;
			int side2 = 3;
			int side3 = 4;
			float expectedalpha = 28.955023;
			float expectedbeta = 46.567463;
			float expectedgamma = 104.477509;

			// Act
			float resultalpha = GiveAlpha(side1, side2, side3);
			float resultbeta = GiveBeta(side1, side2, side3);
			float resultgamma = GiveGamma(side1, side2, side3);

			// Assert
			Assert::AreEqual(expectedalpha, resultalpha);
			Assert::AreEqual(expectedbeta, resultbeta);
			Assert::AreEqual(expectedgamma, resultgamma);
		}

		TEST_METHOD(T003_printAngle_2_3_4_result_29_47_104) // This test was written to prove that when the sides of the triangle are 2, 3 and 4. The respective angles will be 41, 41 and 97.
		{
			// Arrange
			int side1 = 2;
			int side2 = 2;
			int side3 = 3;
			float expectedalpha = 41.409622;
			float expectedbeta = 41.409622;
			float expectedgamma = 97.180763;

			// Act
			float resultalpha = GiveAlpha(side1, side2, side3);
			float resultbeta = GiveBeta(side1, side2, side3);
			float resultgamma = GiveGamma(side1, side2, side3);

			// Assert
			Assert::AreEqual(expectedalpha, resultalpha);
			Assert::AreEqual(expectedbeta, resultbeta);
			Assert::AreEqual(expectedgamma, resultgamma);
		}
	};

	TEST_CLASS(FourPoints) // Pankit Chandrakant Thakkar
	{
	public:
		TEST_METHOD(T001_makeSides_3_5_6_5_3_7_6_7__Yes) // This will check if a rectangle is formed using these coordinates (3,5), (6,5), (3,7) and (6,7) in this order.
		{
			// Arrange
			point p1, p2, p3, p4;

			p1.x = 3;
			p1.y = 5;

			p2.x = 6;
			p2.y = 5;

			p3.x = 3;
			p3.y = 7;

			p4.x = 6;
			p4.y = 7;

			const int EXPECTED = 0;

			// Act
			int actual = makeSides(p1, p2, p3, p4);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T002_makeSides_3_5_6_5_6_7_3_7__Yes) // This will check if a rectangle is formed using these coordinates (3,5), (6,5), (6,7) and (3,7) in this order.
		{
			// Arrange
			point p1, p2, p3, p4;

			p1.x = 3;
			p1.y = 5;

			p2.x = 6;
			p2.y = 5;

			p3.x = 6;
			p3.y = 7;

			p4.x = 3;
			p4.y = 7;

			const int EXPECTED = 0;

			// Act
			int actual = makeSides(p1, p2, p3, p4);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T003_makeSides_3_5_3_7_6_7_6_5__Yes) // This will check if a rectangle is formed using these coordinates (3,5), (3,7), (6,7) and (6,5) in this order.
		{
			// Arrange
			point p1, p2, p3, p4;

			p1.x = 3;
			p1.y = 5;

			p2.x = 3;
			p2.y = 7;

			p3.x = 6;
			p3.y = 7;

			p4.x = 6;
			p4.y = 5;

			const int EXPECTED = 0;

			// Act
			int actual = makeSides(p1, p2, p3, p4);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T004_makeSides_3_5_3_7_6_5_6_7__Yes) // This will check if a rectangle is formed using these coordinates (3,5), (3,7), (6,5) and (6,7) in this order.
		{
			// Arrange
			point p1, p2, p3, p4;

			p1.x = 3;
			p1.y = 5;

			p2.x = 3;
			p2.y = 7;

			p3.x = 6;
			p3.y = 5;

			p4.x = 6;
			p4.y = 7;

			const int EXPECTED = 0;

			// Act
			int actual = makeSides(p1, p2, p3, p4);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T005_makeSides_3_5_6_7_6_5_3_7__Yes) // This will check if a rectangle is formed using these coordinates (3,5), (6,7), (6,5) and (3,7) in this order.
		{
			// Arrange
			point p1, p2, p3, p4;

			p1.x = 3;
			p1.y = 5;

			p2.x = 6;
			p2.y = 7;

			p3.x = 6;
			p3.y = 5;

			p4.x = 3;
			p4.y = 7;

			const int EXPECTED = 0;

			// Act
			int actual = makeSides(p1, p2, p3, p4);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T006_makeSides_3_5_6_7_3_7_6_5__Yes) // This will check if a rectangle is formed using these coordinates (3,5), (6,7), (3,7) and (6,5) in this order.
		{
			// Arrange
			point p1, p2, p3, p4;

			p1.x = 3;
			p1.y = 5;

			p2.x = 6;
			p2.y = 7;

			p3.x = 3;
			p3.y = 7;

			p4.x = 6;
			p4.y = 5;

			const int EXPECTED = 0;

			// Act
			int actual = makeSides(p1, p2, p3, p4);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T007_makeSides_6_5_3_5_3_7_6_7__Yes) // This will check if a rectangle is formed using these coordinates (6,5), (3,5), (3,7) and (6,7) in this order.
		{
			// Arrange
			point p1, p2, p3, p4;

			p1.x = 6;
			p1.y = 5;

			p2.x = 3;
			p2.y = 5;

			p3.x = 3;
			p3.y = 7;

			p4.x = 6;
			p4.y = 7;

			const int EXPECTED = 0;

			// Act
			int actual = makeSides(p1, p2, p3, p4);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T008_makeSides_6_5_3_5_6_7_3_7__Yes) // This will check if a rectangle is formed using these coordinates (6,5), (3,5), (6,7) and (3,7) in this order.
		{
			// Arrange
			point p1, p2, p3, p4;

			p1.x = 6;
			p1.y = 5;

			p2.x = 3;
			p2.y = 5;

			p3.x = 6;
			p3.y = 7;

			p4.x = 3;
			p4.y = 7;

			const int EXPECTED = 0;

			// Act
			int actual = makeSides(p1, p2, p3, p4);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T009_makeSides_6_5_3_7_6_7_3_5__Yes) // This will check if a rectangle is formed using these coordinates (6,5), (3,7), (6,7) and (3,5) in this order.
		{
			// Arrange
			point p1, p2, p3, p4;

			p1.x = 6;
			p1.y = 5;

			p2.x = 3;
			p2.y = 7;

			p3.x = 6;
			p3.y = 7;

			p4.x = 3;
			p4.y = 5;

			const int EXPECTED = 0;

			// Act
			int actual = makeSides(p1, p2, p3, p4);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T010_makeSides_6_5_3_7_3_5_6_7__Yes) // This will check if a rectangle is formed using these coordinates (6,5), (3,7), (3,5) and (6,7) in this order.
		{
			// Arrange
			point p1, p2, p3, p4;

			p1.x = 6;
			p1.y = 5;

			p2.x = 3;
			p2.y = 7;

			p3.x = 3;
			p3.y = 5;

			p4.x = 6;
			p4.y = 7;

			const int EXPECTED = 0;

			// Act
			int actual = makeSides(p1, p2, p3, p4);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T011_makeSides_6_5_6_7_3_5_3_7__Yes) // This will check if a rectangle is formed using these coordinates (6,5), (6,7), (3,5) and (3,7) in this order.
		{
			// Arrange
			point p1, p2, p3, p4;

			p1.x = 6;
			p1.y = 5;

			p2.x = 6;
			p2.y = 7;

			p3.x = 3;
			p3.y = 5;

			p4.x = 3;
			p4.y = 7;

			const int EXPECTED = 0;

			// Act
			int actual = makeSides(p1, p2, p3, p4);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T012_makeSides_6_5_6_7_3_7_3_5__Yes) // This will check if a rectangle is formed using these coordinates (6,5), (6,7), (3,7) and (3,5) in this order.
		{
			// Arrange
			point p1, p2, p3, p4;

			p1.x = 6;
			p1.y = 5;

			p2.x = 6;
			p2.y = 7;

			p3.x = 3;
			p3.y = 7;

			p4.x = 3;
			p4.y = 5;

			const int EXPECTED = 0;

			// Act
			int actual = makeSides(p1, p2, p3, p4);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T013_makeSides_3_7_6_7_3_5_6_5__Yes) // This will check if a rectangle is formed using these coordinates (3,7), (6,7), (3,5) and (6,5) in this order.
		{
			// Arrange
			point p1, p2, p3, p4;

			p1.x = 3;
			p1.y = 7;

			p2.x = 6;
			p2.y = 7;

			p3.x = 3;
			p3.y = 5;

			p4.x = 6;
			p4.y = 5;

			const int EXPECTED = 0;

			// Act
			int actual = makeSides(p1, p2, p3, p4);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T014_makeSides_3_7_6_7_6_5_3_5__Yes) // This will check if a rectangle is formed using these coordinates (3,7), (6,7), (6,5) and (3,5) in this order.
		{
			// Arrange
			point p1, p2, p3, p4;

			p1.x = 3;
			p1.y = 7;

			p2.x = 6;
			p2.y = 7;

			p3.x = 6;
			p3.y = 5;

			p4.x = 3;
			p4.y = 5;

			const int EXPECTED = 0;

			// Act
			int actual = makeSides(p1, p2, p3, p4);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}


		TEST_METHOD(T015_makeSides_3_7_3_5_6_5_6_7__Yes) // This will check if a rectangle is formed using these coordinates (3,7), (3,5), (6,5) and (6,7) in this order.
		{
			// Arrange
			point p1, p2, p3, p4;

			p1.x = 3;
			p1.y = 7;

			p2.x = 3;
			p2.y = 5;

			p3.x = 6;
			p3.y = 5;

			p4.x = 6;
			p4.y = 7;

			const int EXPECTED = 0;

			// Act
			int actual = makeSides(p1, p2, p3, p4);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T016_makeSides_3_7_3_5_6_7_6_5__Yes) // This will check if a rectangle is formed using these coordinates (3,7), (3,5), (6,7) and (6,5) in this order.
		{
			// Arrange
			point p1, p2, p3, p4;

			p1.x = 3;
			p1.y = 7;

			p2.x = 3;
			p2.y = 5;

			p3.x = 6;
			p3.y = 7;

			p4.x = 6;
			p4.y = 5;

			const int EXPECTED = 0;

			// Act
			int actual = makeSides(p1, p2, p3, p4);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T017_makeSides_3_7_6_5_3_5_6_7__Yes) // This will check if a rectangle is formed using these coordinates (3,7), (6,5), (3,5) and (6,7) in this order.
		{
			// Arrange
			point p1, p2, p3, p4;

			p1.x = 3;
			p1.y = 7;

			p2.x = 6;
			p2.y = 5;

			p3.x = 3;
			p3.y = 5;

			p4.x = 6;
			p4.y = 7;

			const int EXPECTED = 0;

			// Act
			int actual = makeSides(p1, p2, p3, p4);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T018_makeSides_3_7_6_5_6_7_3_5__Yes) // This will check if a rectangle is formed using these coordinates (3,7), (6,5), (6,7) and (3,5) in this order.
		{
			// Arrange
			point p1, p2, p3, p4;

			p1.x = 3;
			p1.y = 7;

			p2.x = 6;
			p2.y = 5;

			p3.x = 6;
			p3.y = 7;

			p4.x = 3;
			p4.y = 5;

			const int EXPECTED = 0;

			// Act
			int actual = makeSides(p1, p2, p3, p4);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T019_makeSides_6_7_3_5_6_5_3_7__Yes) // This will check if a rectangle is formed using these coordinates (6,7), (3,5), (6,5) and (3,7) in this order.
		{
			// Arrange
			point p1, p2, p3, p4;

			p1.x = 6;
			p1.y = 7;

			p2.x = 3;
			p2.y = 5;

			p3.x = 6;
			p3.y = 5;

			p4.x = 3;
			p4.y = 7;

			const int EXPECTED = 0;

			// Act
			int actual = makeSides(p1, p2, p3, p4);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T020_makeSides_6_7_3_5_3_7_6_5__Yes) // This will check if a rectangle is formed using these coordinates (6,7), (3,5), (3,7) and (6,5) in this order.
		{
			// Arrange
			point p1, p2, p3, p4;

			p1.x = 6;
			p1.y = 7;

			p2.x = 3;
			p2.y = 5;

			p3.x = 3;
			p3.y = 7;

			p4.x = 6;
			p4.y = 5;

			const int EXPECTED = 0;

			// Act
			int actual = makeSides(p1, p2, p3, p4);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T021_makeSides_6_7_3_7_3_5_6_5__Yes) // This will check if a rectangle is formed using these coordinates (6,7), (3,7), (3,5) and (6,5) in this order.
		{
			// Arrange
			point p1, p2, p3, p4;

			p1.x = 6;
			p1.y = 7;

			p2.x = 3;
			p2.y = 7;

			p3.x = 3;
			p3.y = 5;

			p4.x = 6;
			p4.y = 5;

			const int EXPECTED = 0;

			// Act
			int actual = makeSides(p1, p2, p3, p4);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T022_makeSides_6_7_3_7_6_5_3_5__Yes) // This will check if a rectangle is formed using these coordinates (6,7), (3,7), (6,5) and (3,5) in this order.
		{
			// Arrange
			point p1, p2, p3, p4;

			p1.x = 6;
			p1.y = 7;

			p2.x = 3;
			p2.y = 7;

			p3.x = 6;
			p3.y = 5;

			p4.x = 3;
			p4.y = 5;

			const int EXPECTED = 0;

			// Act
			int actual = makeSides(p1, p2, p3, p4);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T023_makeSides_6_7_6_5_3_5_3_7__Yes) // This will check if a rectangle is formed using these coordinates (6,7), (6,5), (3,5) and (3,7) in this order.
		{
			// Arrange
			point p1, p2, p3, p4;

			p1.x = 6;
			p1.y = 7;

			p2.x = 6;
			p2.y = 5;

			p3.x = 3;
			p3.y = 5;

			p4.x = 3;
			p4.y = 7;

			const int EXPECTED = 0;

			// Act
			int actual = makeSides(p1, p2, p3, p4);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T024_makeSides_6_7_6_5_3_7_3_5__Yes) // This will check if a rectangle is formed using these coordinates (6,7), (6,5), (3,7) and (3,5) in this order.
		{
			// Arrange
			point p1, p2, p3, p4;

			p1.x = 6;
			p1.y = 7;

			p2.x = 6;
			p2.y = 5;

			p3.x = 3;
			p3.y = 7;

			p4.x = 3;
			p4.y = 5;

			const int EXPECTED = 0;

			// Act
			int actual = makeSides(p1, p2, p3, p4);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T025_makeSides_6_7_6_6_3_7_3_5__No) // This test will show that these coordinates ((6,7), (6,6), (3,7) and (3,5)) don't form a rectangle.
		{
			// Arrange
			point p1, p2, p3, p4;

			p1.x = 6;
			p1.y = 7;

			p2.x = 6;
			p2.y = 6;

			p3.x = 3;
			p3.y = 7;

			p4.x = 3;
			p4.y = 5;

			const int EXPECTED = 1;

			// Act
			int actual = makeSides(p1, p2, p3, p4);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}

		TEST_METHOD(T026_makeSides_0_0_9_0_7_5_16_5__No) // This test will show that these coordinates ((0,0), (9,0), (7,5) and (16,5)) don't form a rectangle because it is a parallelogram.
		{
			// Arrange
			point p1, p2, p3, p4;

			p1.x = 0;
			p1.y = 0;

			p2.x = 9;
			p2.y = 0;

			p3.x = 7;
			p3.y = 5;

			p4.x = 16;
			p4.y = 5;

			const int EXPECTED = 1;

			// Act
			int actual = makeSides(p1, p2, p3, p4);

			// Assert
			Assert::AreEqual(EXPECTED, actual);
		}
	};
}