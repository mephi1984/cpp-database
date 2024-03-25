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

	std::vector<std::tuple<int, std::string, std::string, std::string, std::string, int, int, int>> getAllWorkers();

	int createNewDish();

	void deleteDish(int id);

	void updateWorker(int oldid, std::tuple<int, std::string, std::string, std::string, std::string, int, int, int> value);

	void updateDish(int oldid, std::tuple<int, std::string, int, int, int, int, bool, std::string, std::string> value);

};

extern DatabaseClass database;

