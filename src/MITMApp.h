#ifndef MITMAPP_CEFAPP_HEADER
#define MITMAPP_CEFAPP_HEADER

#include "include/cef_app.h"
#include "MITMHandler.h"

class MITMApp : public CefApp, public CefBrowserProcessHandler {
public:
    MITMApp() { }
    
    CefRefPtr<CefClient> GetDefaultClient() override { return MITMHandler::GetInstance(); }
    CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() override { return this; }
  
    void OnContextInitialized() override;
    
private:
    IMPLEMENT_REFCOUNTING(MITMApp);
};

#endif