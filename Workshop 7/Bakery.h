#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <list>

namespace sdds {

	enum class BakedType {
		BREAD, PASTERY
	};

	struct BakedGood {
		BakedType type;
		std::string description;
		size_t shellLife;
		size_t amountOfStock;
		double price;
	};

	class Bakery
	{
		std::vector<BakedGood> m_array;
		std::string removeSpaces(std::string input);
	public:
		Bakery(const std::string fileName);
		~Bakery();
		void showGoods(std::ostream& os);
		friend std::ostream& operator<<(std::ostream& out, const BakedGood& b);
		void sortBakery(const std::string& sortBy);
		std::vector<BakedGood> combine(const Bakery& input);
		bool inStock(const std::string& description, BakedType type) const;
		std::list<BakedGood> outOfStock(BakedType type) const;
	};

	std::ostream& operator<<(std::ostream& out, const BakedGood& b);
}