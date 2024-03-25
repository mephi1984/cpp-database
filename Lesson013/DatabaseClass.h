#include "pch.h"
#include <iostream>
#include <pqxx/pqxx>
#include <tuple>

class DatabaseClass
{
public:
	pqxx::connection conn;

	DatabaseClass();

	int getWorkerCount();
	int getDishCount();

	std::vector<std::tuple<int, std::string, int, int, int, int, bool, std::string, std::string>> getAllDishes();

	int createNewDish();

	void deleteDish(int id);
};

extern DatabaseClass database;

