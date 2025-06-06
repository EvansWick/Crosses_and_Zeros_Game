#include "GameForm.h"
#include "StartForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Назва твого простору імен і форми
    Crossesandzerosgame::StartForm form; // заміни ProjectName на свій namespace
    Application::Run(% form);

    return 0;
}
