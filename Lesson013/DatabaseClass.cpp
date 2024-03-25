#include "pch.h"
#include "DatabaseClass.h"

DatabaseClass database;

DatabaseClass::DatabaseClass()
	: conn("host=127.0.0.1 port=5432 dbname=lesson03 user=lesson03user password=lesson03user")
{
	conn.prepare("insert_dish", "INSERT INTO dish(	id, title, type, price, out, typeofout, present, contains, photo) VALUES($1, '', 1, 0, 0, 0, false, '', '')");
	conn.prepare("delete_dish", "DELETE FROM dish where id=$1");

}

int DatabaseClass::getWorkerCount()
{
	pqxx::transaction tx{ conn };

	return tx.query_value<int>("SELECT COUNT(*) FROM worker");
}

int DatabaseClass::getDishCount()
{
	pqxx::transaction tx{ conn };

	return tx.query_value<int>("SELECT COUNT(*) FROM dish");
}

std::vector<std::tuple<int, std::string, int, int, int, int, bool, std::string, std::string>> DatabaseClass::getAllDishes()
{
	std::vector<std::tuple<int, std::string, int, int, int, int, bool, std::string, std::string>> result;
	
	pqxx::transaction tx{ conn };

	auto values = tx.query<int, std::string, int, int, int, int, bool, std::string, std::string>("SELECT id, title, type, price, out, typeofout, present, contains, photo FROM dish");

	for (auto& value : values)
	{
		result.push_back(value);
	}

	return result;
}

int DatabaseClass::createNewDish()
{
	pqxx::transaction tx{ conn };

	int maxId = tx.query_value<int>("SELECT MAX(id) FROM dish LIMIT 1");

	tx.exec_prepared("insert_dish", maxId + 1);

	tx.commit();

	return maxId + 1;

}

void DatabaseClass::deleteDish(int id)
{
	pqxx::transaction tx{ conn };

	tx.exec_prepared("delete_dish", id);

	tx.commit();
}