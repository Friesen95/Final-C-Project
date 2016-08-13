#include "Storage.h"

using namespace std;

Storage::Storage() 
{
	driver = get_driver_instance();
}

void Storage::connect()
{
	con = driver->connect("tcp://127.0.0.1:3306", "root", "1234");
	con->setSchema("cppfinal");

}

void Storage::disconnect()
{
	con->close();
	delete con;
}

void Storage::query()
{
	connect();

	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT * FROM Players");

	while (res->next()) 
	{
		cout << "First Name: " << res->getString("firstName") << " "; 
		cout << ", Last Name: " << res->getString("lastName") << endl;
	}
	
	res->close();
	delete res;
	stmt->close();
	delete stmt;

	disconnect();
}

void Storage::seedDb()
{

}