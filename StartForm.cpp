#include "StartForm.h"
#include "GameForm.h"




System::Void Crossesandzerosgame::StartForm::StartForm_Load(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void Crossesandzerosgame::StartForm::menuStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e)
{
    return System::Void();
}

System::Void Crossesandzerosgame::StartForm::aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void Crossesandzerosgame::StartForm::exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void Crossesandzerosgame::StartForm::buttonStartGame_Click(System::Object^ sender, System::EventArgs^ e)
{
    GameForm^ form = gcnew GameForm();
    
    form->Show();
    form->NewGame();
    this->Hide();
}
