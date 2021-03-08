#include <string>
#include <vector>
#include <array>

#include <yaramod/yaramod.h>

using namespace std;

int main(int argc, char* argv[])
{
	// std::vector<std::array<double, 4>>
	if (argc < 3)
	{
		cout << "Error: No Argument" << endl;
		return 1;
	}

	std::vector<std::string> allArgs(argv, argv + argc);
	const char beginParam = '-';
	string paramFolder = "-d";
	string pathFolder = "";

	for(int i=1; i<argc; i++) {
		cout << "argument: " << allArgs[i] << endl;
		if(allArgs[i] == paramFolder && (i+1) < argc){
			cout << "argument1: " << allArgs[i] << endl;
			if(allArgs[i+1][0] != beginParam){
				pathFolder = allArgs[i+1];
				cout << "Path Folder: " << pathFolder << endl;
				i++;
			}
		}
	}

	if(pathFolder.empty()){
		cout << "Error: Argument -d incorrect" << endl;
		return 1;
	}

	cout << "Path Folder: " << pathFolder << endl;

	yaramod::Yaramod yaramod;

	auto yaraFile = yaramod.parseFile(pathFolder);
	for (auto& rule : yaraFile->getRules()){
		for (const auto& string : rule->getStrings()) {
			if (string->isHex()){

			}
		}
		cout << "==== RULE: " << rule->getName() << endl;
		cout << "==== BEFORE" << endl;
		cout << rule->getText() << endl;	
	}
}
