#include "GameForm.h"
#include "StartForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // ����� ����� �������� ���� � �����
    Crossesandzerosgame::StartForm form; // ����� ProjectName �� ��� namespace
    Application::Run(% form);

    return 0;
}
