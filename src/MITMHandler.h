// Copyright (c) 2013 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#ifndef MITMHandler_CEF_HEADER
#define MITMHandler_CEF_HEADER

#include <list>

#include "include/cef_client.h"

class MITMHandler : public CefClient,
                      public CefDisplayHandler,
                      public CefLifeSpanHandler,
                      public CefLoadHandler {
public:
  MITMHandler() : gInstance(this) { }
  ~MITMHandler() override {
    gInstance = nullptr;
  }

  // Provide access to the single global instance of this object.
  static MITMHandler* GetInstance();

  // CefLifeSpanHandler methods:
  void OnAfterCreated(CefRefPtr<CefBrowser> browser) override;
  bool DoClose(CefRefPtr<CefBrowser> browser) override;
  void OnBeforeClose(CefRefPtr<CefBrowser> browser) override;

  // CefLoadHandler methods:
  void OnLoadError(CefRefPtr<CefBrowser> browser,
                   CefRefPtr<CefFrame> frame,
                   ErrorCode errorCode,
                   const CefString& errorText,
                   const CefString& failedUrl) override;

private:
    static MITMHandler gInstance;
  std::list<CefRefPtr<CefBrowser>> gBrowserList;

  IMPLEMENT_REFCOUNTING(SimpleHandler);
};

#endif
