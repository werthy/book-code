#define GENSRV_ServiceName      TEXT("WDJSrvc")
#define GENSRV_DisplayName      TEXT("WDJ Sample Service")

// prototypes
BOOL ServiceInitialization(DWORD, LPTSTR *);
VOID ServiceTermination(VOID);
DWORD MainServiceThread(LPDWORD);
