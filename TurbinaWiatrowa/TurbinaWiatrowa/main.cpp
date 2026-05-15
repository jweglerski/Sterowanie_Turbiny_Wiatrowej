#include "Form1.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace TurbinaWiatrowa;

[STAThread]
void main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew Form1());
}