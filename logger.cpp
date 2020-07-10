//
// Created by spounka on 07/07/2020.
//

#include "logger.hpp"

#include <ctime>
#include <iostream>

#ifdef linux
#include <unistd.h>
#endif

#ifdef _WIN32
#include <windows.h>
#include <Lmcons.h>
#endif

namespace SE::Util
{
	Logger::Logger(int Level, int logFormat) : loggingFormat(logFormat), logLevel(Level)
	{
		// Linux platform
#ifdef __linux
		username = getlogin();
#endif

		// Windows Platform
		// Warning: NOT TESTED !!!

#ifdef _WIN32
		char usrname[UNLEN + 1];
		auto username_length = UNLEN + 1;
		GetUserName(usrname, &username_length);
#endif

		infoLog.open("info.log", std::ios::app | std::ios::out);
		errorLog.open("error.log", std::ios::app | std::ios::out);
	}
	void Logger::LogMessage(const std::string& message, int logLvl)
	{
		if (logLvl > logLevel)
			return;
		std::string output;
		char timestamp[10];
		char datestamp[15];
		std::time_t t = std::time(nullptr);

		if (loggingFormat & (unsigned int)LOG_TIME)
		{
			std::strftime(timestamp, 10, "%H:%M ", localtime(&t));
			output.append(timestamp);
		}
		if (loggingFormat & (unsigned int)LOG_DATE)
		{
			std::strftime(datestamp, 15, "%m/%d/%Y ", localtime(&t));
			output.append(datestamp);
		}
		if (loggingFormat & (unsigned int)LOG_USER)
			output.append(username);

		output.append(":\t" + message);
		if (message[message.length() - 1] != '\n')
			output.append("\n");

		infoLog << output;
	}
	void Logger::LogError(const std::string& message)
	{
		std::string output;
		char format[15];
		std::time_t t = std::time(nullptr);

		std::strftime(format, 15, "%H:%M ", localtime(&t));
		output.append(format);

		std::strftime(format, 15, "%m/%d/%Y ", localtime(&t));
		output.append(format);

		output.append(username + ":\t");
		output.append(message);

		if (message[message.length() - 1] != '\n')
			output.append("\n");

		errorLog << output;
	}
	void Logger::Destroy()
	{
		if (infoLog) infoLog.close();
		if (errorLog) errorLog.close();
	}
}