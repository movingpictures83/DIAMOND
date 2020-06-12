#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "DIAMONDPlugin.h"

void DIAMONDPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   std::cout << key << " " << value << std::endl;
   parameters[key] = value;
 }

}

void DIAMONDPlugin::run() {
 std::string myCommand = "";
myCommand += "diamond makedb --in";
myCommand += " ";
myCommand += parameters["database"];
myCommand += " --db "+std::string(PluginManager::prefix())+"db.dmnd";
std::cout << myCommand << std::endl;
 system(myCommand.c_str());
}


void DIAMONDPlugin::output(std::string file) {
 std::string outputfile = file;
std::string myCommand = "";
myCommand += "diamond blastx --query";
myCommand += " ";
myCommand += parameters["sequences"] + " ";
myCommand += "--db "+std::string(PluginManager::prefix())+"db.dmnd --daa";
myCommand += " ";
myCommand += outputfile;
std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<DIAMONDPlugin> DIAMONDPluginProxy = PluginProxy<DIAMONDPlugin>("DIAMOND", PluginManager::getInstance());
