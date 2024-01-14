#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <memory>
#include <cstring>

namespace sdds {
	enum class Err_Status
	{
		Err_Success,
		Err_NotFound,
		Err_OutOfMemory,
	};

	template <class T>
	class Database
	{
		size_t m_itemCounter{ 0 };
		std::string m_keys[20]{};
		T m_values[20];
		std::string m_databaseFileName{""};

		Database(const std::string& filename);
		static std::shared_ptr<Database> m_databaseAddr;
		
	public:
		~Database();
		void encryptDecrypt(T&);
		static std::shared_ptr<Database<T>> getInstance(const std::string& filename);

		Err_Status GetValue(const std::string& key, T& value);
		Err_Status SetValue(const std::string& key, const T& value);
	};

	template <class T>
	std::shared_ptr<Database<T>> Database<T>::m_databaseAddr = nullptr;

	template <class T>
	Database<T>::~Database()
	{
		std::ofstream file(m_databaseFileName + ".bkp.txt");
		for (size_t i = 0; i < m_itemCounter; i++) {
			T tmp = m_values[i];
			encryptDecrypt(tmp);
			file << std::setw(26) << std::left << m_keys[i] << "-> ";
			file << tmp << std::endl;
		}
		std::cout << "[" << m_databaseAddr << "] ~Database()" << std::endl;
	}

	template <class T>
	Database<T>::Database(const std::string& filename) {
		std::ifstream file(filename);
		m_databaseFileName = filename;
		while (file) {

			std::string str;
			file >> str;
			for (size_t i = 0; i < str.length(); i++) {
				if (str[i] == '_')
					str[i] = ' ';
			}
			m_keys[m_itemCounter] = str;
			file >> m_values[m_itemCounter];
			encryptDecrypt(m_values[m_itemCounter]);
			m_itemCounter++;
			file.ignore(1024, '\n');
		}
	}

	template <class T>
	std::shared_ptr<Database<T>> Database<T>::getInstance(const std::string& filename) {
		if (m_databaseAddr)
			return m_databaseAddr;

		std::shared_ptr<Database> tmp(new Database(filename));
		m_databaseAddr = tmp;
		std::cout << "[" << tmp << "] Database(const std::string&)" << std::endl;
		return m_databaseAddr;
	}

	template <class T>
	Err_Status Database<T>::GetValue(const std::string& key, T& value) {
		for (size_t i = 0; i < m_itemCounter; i++) {
			if (key == m_keys[i]) {
				value = m_values[i];
				return Err_Status::Err_Success;
			}
		}
		return Err_Status::Err_NotFound;
	}

	template <class T>
	void Database<T>::encryptDecrypt(T& value) {
		
	}


	template <>
	void Database<std::string>::encryptDecrypt(std::string& value) {
		const char secret[]{ "secret encryption key" };
		for (char &c : value)
			for (size_t j = 0; j < strlen(secret); j++)
				c = c ^ secret[j];
	}

	template <>
	void Database<long long int>::encryptDecrypt(long long int& value) {
		const char secret[]{ "super secret encryption key" };
		char *v = reinterpret_cast<char*>(&value);
		for (size_t i = 0; i < sizeof(value); i++)
			for (size_t j = 0; j < strlen(secret); j++)
				v[i] = v[i] ^ secret[j];
	}

	template <class T>
	Err_Status Database<T>::SetValue(const std::string& key, const T& value) {
		if (m_itemCounter == 19)
			return Err_Status::Err_OutOfMemory;

		m_keys[m_itemCounter] = key;
		m_values[m_itemCounter++] = value;
		return Err_Status::Err_Success;
	}
}