#include <iostream>
#include "MITMApp.h"
#include "MITMHandler.h"

#include "include/cef_command_line.h"

void MITMApp::OnContextInitialized() {

}

//CefSimple Implementation
NO_STACK_PROTECTOR
int main(int argc, char* argv[]) {
  CefMainArgs main_args(argc, argv);

  int exit_code = CefExecuteProcess(main_args, nullptr, nullptr);
  if (exit_code >= 0) {
    return exit_code;
  }

  CefRefPtr<CefCommandLine> command_line = CefCommandLine::CreateCommandLine();
  command_line->InitFromArgv(argc, argv);
  CefSettings settings;

  CefRefPtr<MITMApp> app(new MITMApp);
  if (!CefInitialize(main_args, settings, app.get(), nullptr)) {
    return CefGetExitCode();
  }
  CefRunMessageLoop();

  CefShutdown();

  return 0;
}
