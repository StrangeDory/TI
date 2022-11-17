#include "MyForm.h"
#include <windows.h>
#include <string>
using namespace Project2;
[STAThread]
int WINAPI wmain() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}

