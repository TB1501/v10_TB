#include "CppUnitTest.h"

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <random>
#include <iostream>
#include<iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace all_tests
{
	TEST_CLASS(test_v10)
	{
	public:
		TEST_METHOD(test_01)
		{
			std::stringstream ss("14 -78 22");
			std::vector<int> v;
		
		
			// TODO: read values from input stream into vector

						
			std::istream_iterator<int> in(ss);
			std::istream_iterator<int> eof;

			std::copy(in, eof, std::back_inserter(v));

			

			Assert::AreEqual(3ull, v.size());
			Assert::AreEqual(14, v[0]);
			Assert::AreEqual(-78, v[1]);
			Assert::AreEqual(22, v[2]);

		}
		TEST_METHOD(test_02a)
		{
			std::vector<int> v(10);
			// TODO: fill vector with incremental values

			std::iota(v.begin(), v.end(), 1);


			Assert::AreEqual(10ull, v.size());
			Assert::IsTrue(std::is_sorted(v.cbegin(), v.cend()));
			Assert::AreEqual(1, v[0]);
			Assert::AreEqual(10, v[9]);
		}
		
		TEST_METHOD(test_02b)
		{
			// generate
			std::vector<int> v(10);
			int startValue = 1;
			int step = 2;

			int value = startValue;
			std::generate(v.begin(), v.end(), [&value, step]() 
				{
				int current = value;
				value += step;
				return current;
				}
			);

			Assert::IsTrue(std::is_sorted(v.cbegin(), v.cend()));
			Assert::IsTrue(v.cend() == std::adjacent_find(v.cbegin(), v.cend(), [](int a, int b) { return b - a != 2;  }));
			Assert::AreEqual(1, v[0]);
			Assert::AreEqual(19, v[9]);
		}
		
		TEST_METHOD(test_03a)
		{
			std::vector<int> v = { 1, 5, 10 };
			// TODO: change all values in a vector

			 
			std::transform(v.begin(), v.end(), v.begin(), [](int& element) 
				{
	
				return element * element*element; 
				});

		
			Assert::AreEqual(3ull, v.size());
			Assert::AreEqual(1, v[0]);
			Assert::AreEqual(125, v[1]);
			Assert::AreEqual(1000, v[2]);
		}
		
		TEST_METHOD(test_03b)
		{
			int x[] = { 3, 5, 10 };
			std::vector<int> y = { 4, 12, 10 };
			std::vector<double> d;

			// TODO: calculate distances from origin (from x and y collections) to new vector

			std::transform(std::begin(x), std::end(x), std::begin(y), std::back_inserter(d), [](int a, int b) { return sqrt(a * a + b * b); });

			Assert::AreEqual(3ull, d.size());
			Assert::AreEqual(5., d[0]);
			Assert::AreEqual(13., d[1]);
			Assert::AreEqual(sqrt(200), d[2]);
		}
		
		TEST_METHOD(test_04a)
		{
			std::stringstream ss("1.5 2.5 3.5");
			std::istream_iterator<double> it(ss), end;
			auto res = std::accumulate(it, end, 0.); // TODO: sum of all values in input stream
			Assert::AreEqual(7.5, res);
		}
		
		TEST_METHOD(test_04b)
		{
			std::vector<std::string> v{ "V", "S", "I", "T", "E", "!" };
			auto res = std::accumulate(std::begin(v), std::end(v), std::string("GO ")); // TODO: concatenated string with additional prefix 
			Assert::AreEqual("GO VSITE!", res.c_str());
		}
		
		TEST_METHOD(test_04c)
		{
			struct person { std::string name; int age; };
			std::vector<person> v{ {"Pero", 33}, {"Iva", 25} };
			auto total_age = std::accumulate(std::begin(v), std::end(v), 0, [](int age, person const& p) { return age + p.age; }); // TODO: sum of all ages
			Assert::AreEqual(58, total_age);
		}
	

		TEST_METHOD(test_05a)
		{
			std::vector<int> v{ -5, 8, 11, 0, -9, 77, -4 };
			auto number_of_negative = std::count_if(std::begin(v), std::end(v), [](int n) {  return n < 0; });// TODO: 
			Assert::AreEqual(3ll, number_of_negative);
		}
		
		
		TEST_METHOD(test_05b)
		{
			std::vector<double> v{ 1.5, 8, -11.23, 0, 1e10, 1e10, 1e10, 0, 99 };
			auto number_of_invalid = std::count(std::begin(v), std::end(v), 1e10); // TODO: 
			Assert::AreEqual(3ll, number_of_invalid);
		}

		

		TEST_METHOD(test_05c)
		{
			struct point { int x, y; };
			std::vector<point> v{ {1,1}, {-5,3}, {2,2}, {-7,-6}, {9,-4} };
			auto number_in_first_quadrant = std::count_if(std::begin(v), std::end(v), [](point const& p) { return p.x > 0 && p.y > 0; }); // TODO: 
			Assert::AreEqual(2ll, number_in_first_quadrant);
		}

		
		TEST_METHOD(test_06)
		{
			std::vector<int> v{ 33, 16, 24, 41, 25, 19, 9 };
			auto first_prime = *std::find_if(std::begin(v), std::end(v), [](int n)
				{
					if (n <= 1) return false;
					for (int i = 2; i < n; i++) if (n % i == 0) return false;
					return true;
				});

				// TODO: 
			Assert::AreEqual(41, first_prime);
		}

		
		TEST_METHOD(test_07a)
		{
			std::vector<double> v{ 1e10, 8, -11.23, 0, 1e10, 1e10, 1e10, 0, 99 };
			// TODO: change every invalid value (1e10) with -1 
			std::replace(std::begin(v), std::end(v), 1e10, -1.);

			Assert::AreEqual(-1., v[0]);
			Assert::AreEqual(-1., v[4]);
			Assert::AreEqual(-1., v[6]);
		}

		TEST_METHOD(test_07b)
		{
			std::string s("neisporuka");
			// TODO: change every vowel with x

			const std::string vowel ="aeiou";
			
			std::replace_if(s.begin(), s.end(),[&vowel](char c) {
				return vowel.find(c) != std::string::npos;
				}, 'x');


			Assert::AreEqual("nxxspxrxkx", s.c_str());
		}

	
		TEST_METHOD(test_08a)
		{
			std::vector<double> v{ 1e10, 8, -11.23, 0, 1e10, 1e10, 1e10, 0, 99 };
			// TODO: delete all invalid values (1e10)

			auto it = std::remove(std::begin(v), std::end(v), 1e10);
			v.erase(it, std::end(v));
			Assert::AreEqual(5ull, v.size());
			Assert::AreEqual(8., v[0]);
			Assert::AreEqual(99., v[4]);
		}

		

		TEST_METHOD(test_08b)
		{
			std::string s("poliuretan");
			// TODO: delete all vowels
			const std::string vowels = "aeiou";

			auto it = std::remove_if(s.begin(), s.end(), [&vowels](char c) {
				return vowels.find(c) != std::string::npos;
				});
			
			s.erase(it, s.end());
			Assert::AreEqual("plrtn", s.c_str());
		}

	
		TEST_METHOD(test_09)
		{
			struct exam { std::string name; int points, grade; };
			std::vector<exam> v{ {"Pero", 55, 2}, {"Iva", 93, 5}, {"Marko", 89, 5} };
			// TODO: sort vector by grade, then by points
			std::sort(std::begin(v), std::end(v), [](exam const& e1, exam const& e2) {
				if (e1.grade != e2.grade)
					return e1.grade > e2.grade;
				else
					return e1.points > e2.points;
				});
			Assert::AreEqual("Iva", v[0].name.c_str());
			Assert::AreEqual("Marko", v[1].name.c_str());
			Assert::AreEqual("Pero", v[2].name.c_str());

		}

		
		TEST_METHOD(test_10)
		{
			std::vector<double> v(2e7);
			// half of the values less than 1000
			std::generate(v.begin(), v.begin() + v.size() / 2, []() { return rand() % 1000; });
			// other half of the values greater than 1000
			std::generate(v.begin() + v.size() / 2, v.end(), []() { return 1001 + rand() % 1000; });
			v.push_back(1000); // to be median

			std::random_device rd;
			std::mt19937 g(rd());
			std::shuffle(v.begin(), v.end(), g);

			// TODO: put median value in the middle of vector. fast.
			std::nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
			Assert::AreEqual(1000., v[v.size() / 2]); // median value
		}

		
		TEST_METHOD(test_11)
		{
			std::vector<double> v{ 11, 0.5, -97.23, -23.11, 48.78, 22.96, -77 };
			auto smallest_value = *std::min_element(std::begin(v), std::end(v));// TODO: 
			Assert::AreEqual(-97.23, smallest_value);
			auto largest_value = *std::max_element(std::begin(v), std::end(v)); // TODO: 
			Assert::AreEqual(48.78, largest_value);
		}


		TEST_METHOD(test_12)
		{
			std::vector<int> atp_points{ 8445, 7480, 6220, 5300, 5285 };

			std::vector<int> differences;

			std::sort(std::begin(atp_points), std::end(atp_points));
			std::adjacent_difference(atp_points.begin(), atp_points.end(), std::back_inserter(differences));

			auto smallest_difference = *std::min_element(std::begin(differences) + 1, std::end(differences));
			
			// TODO: 
			Assert::AreEqual(15, smallest_difference);
		}
		
		
	};
}
