//
// Created by Spounka Von Schpeiner on 07/07/2020.
//

#ifndef UTIL_LOGGER_LOGGER_HPP_
#define UTIL_LOGGER_LOGGER_HPP_

#include <fstream>

/**
 * @file
 */

namespace SE::Util
{
	/**
	 * @class Logger
	 * @brief Class used for logging into files errors and informations instead of the console
	 * @details Often we log details into the console but they get lost as we output too much things, 
	 * 	so we use logging files to first preserve the information and to reduce spam from console,
	 * 	if running from one
	 */
	class Logger
	{
		/**
		 * @def LOG_TIME
		 * @brief Bitfield for logging time in the log file
		 * 
		 * @def LOG_DATE
		 * @brief Bitfield for logging date in the log file
		 * 
		 * @def LOG_USER
		 * @brief Bitfield for logging the username in the log file
		 * 
		 * @def LOG_TIMEUSER
		 * @brief Bitfield for mixing LOG_TIME and LOG_USER
		 * @see LOG_TIME
		 * @see LOG_USER
		 * 
		 * @def LOG_FULLTIME
		 * @brief Bitfield for mixing both time and date as they are usaully used together
		 * @see LOG_TIME
		 * @see LOG_DATE
		 * 
		 * @def LOG_ALL
		 * @brief Bitfield for logging all details into the log file
		 */

#define LOG_TIME  0x1        // 0b00000001
#define LOG_DATE  0x2        // 0b00000010
#define LOG_USER  0x4        // 0b00000100
#define LOG_TIMEUSER  0x5    // 0b00000101
#define LOG_FULLTIME  0x3    // 0b00000011
#define LOG_ALL  0xF        // 0b00001111

		/**
		 * @privatesection
		 */
	  private:
		/**
		 * @brief output file used for logging errors
		 */
		std::ofstream errorLog;
		/**
		 * @brief output file used for logging information
		 */
		std::ofstream infoLog;
		/**
		 * @brief used for holding the input bitfield options for logging.
		 * Defaults To logging everything
		 * @see LOG_ALL
		 */
		unsigned int loggingFormat;
		
		/**
		 * @brief defines verbosity of log
		 */
		int logLevel;

		/**
		 * variable holding the current username
		 */
		std::string username;
	  public:
		/**
		 * Constructor
		 * @param Level level of verbosity, bigger means more details
		 * @param loggingFormat 
		 */
		explicit Logger(int Level = 3, int loggingFormat = LOG_ALL);
		
		/**
		 * @brief Logs to info.log file
		 * @param message string to write to the file
		 * @param logLevel message log level, if it is bigger than the level defines in Logger the writing is ignored
		 * @see LogError
		 * @see LOG_ALL
		 * @see Destroy
		 */
		void LogMessage(const std::string& message, int logLevel = 3);
		
		/**
		 * @brief Logs an error into error.log file
		 * @param message the error to log
		 * @see Destroy
		 */
		void LogError(const std::string& message);
		
		/**
		 * @brief closes the files used in logging.
		 * 
		 * Use this function when you are done with the logging to clear memory
		 * @see LogMessage
		 * @see LogError
		 */
		void Destroy();

	};
}

#endif //THEDEADWOODS_INCLUDE_ENGINE_UTIL_LOGGER_LOGGER_HPP_
