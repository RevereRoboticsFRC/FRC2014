#include <string>
#include <iostream>

using namespace std;

enum Level { 
	ALL = 0,
	FATAL = 100,
	WARN = 200,
	INFO = 300,
	DEBUG = 400,
	FINE = 500,
	SILENT = 900
};

class Logger {
	
	Level filterLevel;
	string loggerName;
	
public:
	Logger(Level, string);
	
	
	void Log(Level, string);
	
	void All(string);
	void Fatal(string);
	void Warn(string);
	void Info(string);
	void Debug(string);
	void Fine(string);
	
};
