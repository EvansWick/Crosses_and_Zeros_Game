#include "StartForm.h"
#include "GameForm.h"




System::Void Crossesandzerosgame::StartForm::StartForm_Load(System::Object^ sender, System::EventArgs^ e)
{
    this->listBoxGameMode->SelectedIndex = 0;

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
    form->SelectedGameMode = listBoxGameMode->SelectedIndex;
    //MessageBox::Show(Convert::ToString(listBoxGameMode->SelectedItem));
    form->rows = (int)numericUpDownFieldSize->Value;
    form->columns = (int)numericUpDownFieldSize->Value;
    form->length = (int)numericUpDownCombLength->Value;
    if(form->rows == 4) form->ClientSize = System::Drawing::Size(250, 320);
    this->Hide();
    form->Show();
    //form->NewGame();
    
}

