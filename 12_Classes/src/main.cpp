 #include <iostream>

 class Log
 {
	 public:
	 	
		enum LogLevel
 		{
			LogLevelError,
     		LogLevelWarning,
	 		LogLevelInfo 
 		};

	 	void Setlevel(const LogLevel& level)
	 	{
			m_LogLevel = level;	 
	 	}

	 	void Error(const char *msg)
		 {
			 if(LogLevelError <= m_LogLevel)
				std::cout<<"[Error]"<<msg<<std::endl;
	 	}

	 	void Warn(const char *msg)
	 	{
		 	if(LogLevelWarning <= m_LogLevel)
				std::cout<<"[Warning]"<<msg<<std::endl;
	 	}

	 	void Info(const char *msg)
	 	{
		 	if(LogLevelInfo <= m_LogLevel)
				std::cout<<"[Info]"<<msg<<std::endl;
	 	}

	 private:
	 	LogLevel m_LogLevel = LogLevelInfo;
 };

int main()
{	
	Log log;
	log.Setlevel(Log::LogLevelWarning);
	log.Warn("Its a warning");
	log.Error("Its an Error");
	log.Info("Its an Info");
	
	return 0;
}