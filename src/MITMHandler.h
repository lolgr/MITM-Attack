#ifndef MITMHandler_CEFCLIENT_HEADER
#define MITMHandler_CEFCLIENT_HEADER

#include <list>

#include "include/cef_client.h"

class MITMHandler : public CefClient, public CefLifeSpanHandler {
public:
    MITMHandler();
    ~MITMHandler();

    void OnAfterCreated(CefRefPtr<CefBrowser> browser) override;
  
    static MITMHandler* GetInstance();

private:
    std::list<CefRefPtr<CefBrowser>> gBrowserList;

    IMPLEMENT_REFCOUNTING(MITMHandler);
};

#endif
