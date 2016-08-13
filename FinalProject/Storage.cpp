#include "Storage.h"

Storage::Storage() 
{
	driver = get_driver_instance();
}

void Storage::connectToDb()
{
	con = driver->connect("tcp://127.0.0.1:3306", "root", "1234");
}

void Storage::seedDb()
{

}