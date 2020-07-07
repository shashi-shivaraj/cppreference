 #include <iostream>

 class Log
 {
	 public:
	 	const int LogLevelError = 0;
	 	const int LogLevelWarning = 1;
	 	const int LogLevelInfo = 2; 

	 	void Setlevel(const int& level)
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
	 	int m_LogLevel = LogLevelInfo;
 };

int main()
{	
	Log log;
	log.Setlevel(log.LogLevelWarning);
	log.Warn("Its a warning");
	log.Error("Its an Error");
	log.Info("Its an Info");
	
	return 0;
}