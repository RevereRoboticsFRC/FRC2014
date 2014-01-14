#include "Logger.h"

Logger::Logger(Level filterLvl, string name) {
	filterLevel = filterLvl;
	loggerName = name;
}

void Logger::Log(Level logLevel, string message) {
	//	The lower the log level the more severe
	if(logLevel > filterLevel) {
		return;
	}
	string s = "";
	switch(logLevel) {
	case ALL:
		s = "ALL";
		break;
	case FATAL:
		s = "FATAL";
		break;
	case WARN:
		s = "WARNING";
		break;
	case INFO:
		s = "INFO";
		break;
	case DEBUG:
		s = "DEBUG";
		break;
	case FINE:
		s = "FINE";
		break;
	default:
		s = "undef";
	}
	cout << "[" << s << "]" << message << endl;
}

void Logger::All(string s) {
	Log(ALL, s);
}

void Logger::Fatal(string s) {
	Log(FATAL, s);
}

void Logger::Warn(string s) {
	Log(WARN, s);
}

void Logger::Info(string s) {
	Log(INFO, s);
}

void Logger::Debug(string s) {
	Log(DEBUG, s);
}

void Logger::Fine(string s) {
	Log(FINE, s);
}

