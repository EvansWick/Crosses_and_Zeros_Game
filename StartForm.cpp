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
    MessageBox::Show("It's a simple game when you need build line by cross or zero", "Game rules");
}

System::Void Crossesandzerosgame::StartForm::exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (MessageBox::Show("Continue?", "Exit", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
        Application::Exit();
    }
}

System::Void Crossesandzerosgame::StartForm::buttonStartGame_Click(System::Object^ sender, System::EventArgs^ e)
{
    GameForm^ form = gcnew GameForm();
    form->SelectedGameMode = listBoxGameMode->SelectedIndex;
    //MessageBox::Show(Convert::ToString(listBoxGameMode->SelectedItem));
    form->rows = (int)numericUpDownFieldSize->Value;
    form->columns = (int)numericUpDownFieldSize->Value;
    form->length = (int)numericUpDownCombLength->Value;

    if (form->rows < form->length) form->length = form->rows;

    if (form->rows == 4) form->ClientSize = System::Drawing::Size(250, 300);
    if(form->rows == 3) form->ClientSize = System::Drawing::Size(250, 280);
    if (form->rows == 5) form->ClientSize = System::Drawing::Size(300, 350);
    if (form->rows == 6) form->ClientSize = System::Drawing::Size(360, 400);

    this->Hide();
    form->Show();
    //form->NewGame();
    
}

System::Void Crossesandzerosgame::StartForm::StartForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
    Application::Exit();
}

