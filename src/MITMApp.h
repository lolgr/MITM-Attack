#ifndef MITMAPP_CEFAPP_HEADER
#define MITMAPP_CEFAPP_HEADER

#include "include/cef_app.h"

class MITMApp : public CefApp, public CefBrowserProcessHandler {
public:
  MITMApp();

  CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() override {
    return this;
  }

  void OnContextInitialized() override;
  CefRefPtr<CefClient> GetDefaultClient() override;

private:
  IMPLEMENT_REFCOUNTING(MITMApp);
};

#endif