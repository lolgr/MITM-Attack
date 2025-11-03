#include "MITMHandler.h"

namespace {
    MITMHandler* gInstance;
}

MITMHandler* MITMHandler::GetInstance() { return gInstance; }

MITMHandler::MITMHandler() { gInstance = this; }
MITMHandler::~MITMHandler() { gInstance = nullptr; }

void MITMHandler::OnAfterCreated(CefRefPtr<CefBrowser> browser) {
    gBrowserList.push_back(browser);
}