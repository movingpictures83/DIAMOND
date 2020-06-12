#ifndef DIAMONDPLUGIN_H
#define DIAMONDPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>

class DIAMONDPlugin : public Plugin
{
public: 
 std::string toString() {return "DIAMOND";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::map<std::string, std::string> parameters;

};

#endif
