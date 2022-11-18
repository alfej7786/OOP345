/*
Student Name: Alfej Savaya
ID: 118823210
Email: aasavaya@myseneca.ca
Date: 18/11/2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <memory>
#include <utility>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList(){}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's
		bool checkLuhn(const std::string str) {
			size_t len = str.length();
			size_t num = 0;
			size_t sum = 0;

			for (size_t i = 0; i < len; i++)
			{
				num = str[i] - '0';
				if (i % 2 != 0)
				{
					num *= 2;
					if (num > 9)
					{
						num -= 9;
					}
				}
				sum += num;
			}
			return sum % 10 == 0;
		}

		//TODO: Overload the += operator with a smart pointer
		// as a second operand.
		void operator+=(T& object) {
			list.push_back(object);
		}

		//TODO: Overload the += operator with a raw pointer
		// as a second operand.
		void operator+=(T* object) {
			list.push_back(*object);
		}


		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
