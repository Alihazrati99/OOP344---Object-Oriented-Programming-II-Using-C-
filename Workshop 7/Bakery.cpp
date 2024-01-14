#include "Bakery.h"
#include <iomanip>
#include <algorithm>

namespace sdds {

	Bakery::Bakery(const std::string fileName)
	{
		std::ifstream file(fileName);
		if (!file) // check file exist
		{
			throw;
		}

		while (file)
		{
			std::string line;
			std::getline(file, line);
			if (line == "")
				continue;
			BakedGood baked; //read baked info
			if (line.substr(0, 8).find("Bread") != std::string::npos)
				baked.type = BakedType::BREAD;
			else
				baked.type = BakedType::PASTERY;

			baked.description = removeSpaces(line.substr(8, 20));
			baked.shellLife = std::stoi(line.substr(28, 14));
			baked.amountOfStock = std::stoi(line.substr(42, 8));
			baked.price = std::stod(line.substr(50, 6));
			m_array.push_back(baked);
		}
	}

	std::string Bakery::removeSpaces(std::string input) {
		// clean extra spaces from start
		while (input[0] == ' ')
			input = input.substr(1, input.length() - 1);

		// clean extra spaces from end
		while (input[input.length() - 1] == ' ')
			input = input.substr(0, input.length() - 1);

		return input;
	}

	Bakery::~Bakery()
	{
	}

	void Bakery::showGoods(std::ostream& os)
	{
		int totallAmount = 0;
		double totalPrice = 0;

		std::for_each(m_array.begin(), m_array.end(), [&](const BakedGood& b) {
			os << b << "\n"; // use insertion operator
			totallAmount += b.amountOfStock;
			totalPrice += (b.price); }
		);

		os << "Total Stock: " << totallAmount
		<< "\nTotal Price: " << std::setprecision(2) << std::fixed << totalPrice << "\n";
	}

	std::ostream& operator<<(std::ostream& out, const BakedGood& b)
	{
		out << "* " << std::left << std::setw(10);
		if (b.type == BakedType::BREAD)
			out << "Bread";
		else
			out << "Pastry";
		out << " * " << std::left << std::setw(20) << b.description
			<< " * " << std::setw(5) << b.shellLife
			<< " * " << std::setw(5) << b.amountOfStock
			<< " * " << std::right << std::setw(8) << std::fixed << std::setprecision(2)  << b.price
			<< " * ";
		return out;
	}

	void Bakery::sortBakery(const std::string& sortBy)
	{
		// sort by stock
		if (sortBy == "Stock") {
			std::sort(m_array.begin(), m_array.end(), [](const BakedGood& a, const BakedGood& b) {
				return a.amountOfStock < b.amountOfStock; });
		}
		// sort by description
		if (sortBy == "Description") {
			std::sort(m_array.begin(), m_array.end(), [](const BakedGood& a, const BakedGood& b) {
				return a.description < b.description; });
		}
		
		if (sortBy == "Shelf") {
			std::sort(m_array.begin(), m_array.end(), [](const BakedGood& a, const BakedGood& b) {
				return a.shellLife < b.shellLife;
			});
		}
		if (sortBy == "Price") {
			std::sort(m_array.begin(), m_array.end(), [](const BakedGood& a, const BakedGood& b) {
				return a.price < b.price; });
		}
	}
	// combine current collection with given collection
	std::vector<BakedGood> Bakery::combine(const Bakery& input) {

		std::vector<BakedGood> result(input.m_array.size() + m_array.size());

		std::sort(m_array.begin(), m_array.end(), [](BakedGood& a, BakedGood& b) {
			return a.price < b.price; }
		);

		std::merge(m_array.begin(), m_array.end(), input.m_array.begin(), input.m_array.end(),
			result.begin(), [&](const BakedGood& a, const BakedGood& b) {
			return a.price < b.price;
		});

		return result;

	}

	bool Bakery::inStock(const std::string& description, BakedType type) const {
		bool result;
		result = std::any_of(m_array.begin(), m_array.end(), [&](const BakedGood& item) {
			return  item.type == type && item.amountOfStock > 0 && item.description == description;
		});

		return result;
	}

	std::list<BakedGood> Bakery::outOfStock(BakedType type) const {
		std::list<BakedGood> result;

		std::copy_if(m_array.begin(), m_array.end(), std::back_inserter(result), [&](const BakedGood& item) {
			return item.amountOfStock == 0 && item.type == type; 
		});
		return result;
	}
}