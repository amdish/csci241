/**/
#include <string>
#include "ProviderDB.h"
//#include "Provider.h"

using std::string;

int main()
{
	string fileName = "providerdb";
	ProviderDB pDatabase = ProviderDB(fileName.c_str());
	pDatabase.print();

	return 0;
}
