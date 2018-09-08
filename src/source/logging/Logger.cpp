#include "../../headers/logging/Logger.h"
#include "../../headers/Utilities.h"

const string CLogger::m_sFileName = "Log.txt";
CLogger* CLogger::m_pThis = NULL;
ofstream CLogger::m_Logfile;

CLogger::CLogger()
{
	log_console_enabled = true;
}

CLogger* CLogger::GetLogger()
{
	if (m_pThis == NULL)
	{
		m_pThis = new CLogger();
		m_Logfile.open(m_sFileName.c_str(), ios::out | ios::app);
	}
	return m_pThis;
}

int _vscprintf(const char * format, va_list pargs) {
	int retval;
	va_list argcopy;
	va_copy(argcopy, pargs);
	retval = vsnprintf(NULL, 0, format, argcopy);
	va_end(argcopy);
	return retval;
}

void CLogger::Log(const char * format, ...)
{
	char* sMessage = NULL;
	int nLength = 0;
	va_list args;
	va_start(args, format);
	//  Return the number of characters in the string referenced the list of arguments.
	// _vscprintf doesn't count terminating '\0' (that's why +1)
	nLength = _vscprintf(format, args) + 1;
	sMessage = new char[nLength];
	//vsprintf_s(sMessage, nLength, format, args);
	vsprintf(sMessage, format, args);
	m_Logfile << Util::CurrentDateTime() << ":\t";
	m_Logfile << sMessage << "\n";

	if(log_console_enabled)
	{
		//cout << Util::CurrentDateTime() << ":\t" << sMessage << endl;
		cout << sMessage << endl;
	}

	va_end(args);

	delete[] sMessage;
}

void CLogger::Log(const string& sMessage)
{
	m_Logfile << Util::CurrentDateTime() << ":\t";
	m_Logfile << sMessage << "\n";
}

CLogger& CLogger::operator<<(const string& sMessage)
{
	m_Logfile << "\n" << Util::CurrentDateTime() << ":\t";
	m_Logfile << sMessage << "\n";
	return *this;
}