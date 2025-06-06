#include "GameForm.h"
#include "StartForm.h"


enum GameMode {
    PVP = 0,
    PVE
} gameMode;

//Game information
GameMap map;
Gamer player1;
Gamer player2;
GamerStatus CurrentPlayer;
Vector2 SelectedCellPlayer;

//flags
bool CanPlay;
bool endGame;


//For AI
std::vector<Vector2> allMoves;
int currentMoves;

System::Void Crossesandzerosgame::GameForm::GameForm_Load(System::Object^ sender, System::EventArgs^ e)
{
    //Parametrs inicialization
    if (SelectedGameMode == 0) gameMode = PVP;
    else gameMode = PVE;


    NewGame();
}

System::Void Crossesandzerosgame::GameForm::newGameToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (MessageBox::Show("Continue?", "Exit", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
        NewGame();
    }
}

System::Void Crossesandzerosgame::GameForm::backToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (MessageBox::Show("Continue?", "Exit", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
        StartForm^ form = gcnew StartForm();
        form->Show();
        this->Hide();
    }
}

System::Void Crossesandzerosgame::GameForm::powerOnoffSoundsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{

}

System::Void Crossesandzerosgame::GameForm::aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("It's a simple game when you need build line by cross or zero", "Game rules");
}

System::Void Crossesandzerosgame::GameForm::exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    //if (sound) soundClick->Play();
    if (MessageBox::Show("Continue?", "Exit", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
        Application::Exit();
    }
}

System::Void Crossesandzerosgame::GameForm::dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{

    auto SenderGrid = (DataGridView^)sender; // Convert to table

    SelectedCellPlayer.x = e->RowIndex;
    SelectedCellPlayer.y = e->ColumnIndex;

    // Move
    SetPositionPlayer(SelectedCellPlayer);
}

void Crossesandzerosgame::GameForm::GameLogic() //////////////////////////////////////////////
{
    if (gameMode == PVE) {
        if (CurrentPlayer == Computer) StepAI();//////////////////////////////////////////////
        UpDate();
    }
    else {
        
    }
}

void Crossesandzerosgame::GameForm::UpDate()
{
    int StateGame = map.CheckingWin();
    if (endGame) return;

    if (StateGame == 1) {
        UpdateGamerGrid();
        if (gameMode == PVP) MessageBox::Show("Player 1 won!", "Win");
        else MessageBox::Show("Player won!", "Win");

        
        endGame = true;
    }
    if (StateGame == 2) {
        UpdateGamerGrid();
        if (gameMode == PVP) MessageBox::Show("Player 2 won!", "Win");
        else MessageBox::Show("Computer won!", "Lose");

        
        endGame = true;
    }
    if (StateGame == 3) {
        UpdateGamerGrid();
        MessageBox::Show("Won nobody", "Draw");
        endGame = true;
    }

    if (endGame) {
        if (MessageBox::Show("Do you want play again?", "New Game", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
            NewGame();
        }
        return;
    }

    if (gameMode == PVE) {
        if (CurrentPlayer == Computer) {
            toolStripStatusLabel1->Text = "Player's move";
            CurrentPlayer = Player;
            return;
        }
        else {
            toolStripStatusLabel1->Text = "Computer's move";
            CurrentPlayer = Computer;

            GameLogic();
            UpdateGamerGrid();
            return;
        }
    }
    else {
        if (CurrentPlayer == GamerStatus::Player1) {
            toolStripStatusLabel1->Text = "Player 2's move";
            CurrentPlayer = GamerStatus::Player2;
        }
        else {
            toolStripStatusLabel1->Text = "Player 1's move";
            CurrentPlayer = GamerStatus::Player1;
        }
    }

    GameLogic();
    UpdateGamerGrid();
}

void Crossesandzerosgame::GameForm::NewGame()
{
    // data inicialization


    map.setMap(rows, columns, length);
    
    rand = gcnew Random();
    endGame = false;
    CreateGameGrid(map.getSize());

    // all possible moves inicialization
    currentMoves = 0;
    allMoves.clear();
    Vector2 buff;

    for (int i = 0; i < map.getSize().x; i++) {
        for (int j = 0; j < map.getSize().x; j++) {
            buff.x = i;
            buff.y = j;
            allMoves.push_back(buff);
        }
        
    }

    //Peremesh moves
    int num_mixing = rand->Next(1, 10);
    for (int i = 0; i < num_mixing; i++) {
        std::random_shuffle(allMoves.begin(), allMoves.end());

        // Check ochered
        int state_gamer = rand->Next(1, 3);
        if (state_gamer == 1) {
            if (gameMode == PVE) {
                player1.SetField(Player, 1);
                player2.SetField(Computer, 2);

                toolStripStatusLabel1->Text = "Player's move";
                CurrentPlayer = Player;
            }
            else {
                player1.SetField(GamerStatus::Player1, 1);
                player2.SetField(GamerStatus::Player2, 2);

                toolStripStatusLabel1->Text = "Player 1's move";
                CurrentPlayer = GamerStatus::Player1;
            }
        }
        else if (state_gamer == 2) {
            if (gameMode == PVE) {
                player1.SetField(Player, 1);
                player2.SetField(Computer, 2);

                toolStripStatusLabel1->Text = "Computer's move";
                CurrentPlayer = Computer;
                //GameLogic();
                //UpdateGamerGrid();
            }
            else {
                player1.SetField(GamerStatus::Player1, 1);
                player2.SetField(GamerStatus::Player2, 2);

                toolStripStatusLabel1->Text = "Player 1's move";
                CurrentPlayer = GamerStatus::Player1;
            }
        }
        else {
            MessageBox::Show("Error in generation of player's select", "Error");
            return;
        }
    }
    // п≥сл€ циклу num_mixing
    if (gameMode == PVE && CurrentPlayer == Computer) {
        GameLogic();
        UpdateGamerGrid();
    }




}

void Crossesandzerosgame::GameForm::StepAI()
{
    // Does exit moves more
    if (currentMoves < allMoves.size()) {
        //Is emptry this cell
        if (map.isEmpty(allMoves[currentMoves])) {
            map.setPosition(allMoves[currentMoves], player2.getMark());
            currentMoves++;
        }
        else {
            currentMoves++;
            StepAI();
        }
    }
}

void Crossesandzerosgame::GameForm::UpdateGamerGrid()
{
    for (int i = 0; i < map.getSize().x; i++) {
        for (int j = 0; j < map.getSize().y; j++) {
            if (!map.isEmpty(i, j)) {
                if (map.getValue(i, j) == 1) dataGridView1->Rows[i]->Cells[j]->Value = "X";
                if (map.getValue(i, j) == 2) dataGridView1->Rows[i]->Cells[j]->Value = "0";
            } 
            //else dataGridView1->Rows[i]->Cells[j]->Value = "X";
        }
    }
}

void Crossesandzerosgame::GameForm::CreateGameGrid(Vector2 _size)
{
    // Clear table
    dataGridView1->Rows->Clear();
    dataGridView1->Columns->Clear();

    // Set style
    System::Drawing::Font^ font = gcnew System::Drawing::Font("Minecraft Rus", 20);
    dataGridView1->DefaultCellStyle->Font = font;
    dataGridView1->ColumnHeadersDefaultCellStyle->Font = font;
    dataGridView1->RowHeadersDefaultCellStyle->Font = font;

    // Creating columns
    for (int i = 0; i < _size.x; i++) {
        DataGridViewButtonColumn^ column = gcnew DataGridViewButtonColumn();
        column->HeaderCell->Value = Convert::ToString(i + 1);
        column->Name = "column" + i;
        column->Width = 50;

        dataGridView1->Columns->Add(column);
    }

    // Creating rows
    for (int i = 0; i < _size.y; i++) {
        dataGridView1->Rows->Add();
        dataGridView1->Rows[i]->HeaderCell->Value = Convert::ToSingle(i + 1);
        dataGridView1->Rows[i]->Height = 50;
    }
    //MessageBox::Show("grid is created", "Map");
}

System::Void Crossesandzerosgame::GameForm::SetPositionPlayer(Vector2 cell)
{
    if (gameMode == PVE) {
        if (CurrentPlayer == Player) {
            if (!map.setPosition(cell, player1.getMark())) {
                MessageBox::Show("This cell already busy", "Stop Game");
                return;
            }
        }
        else {
            MessageBox::Show("Now not your move", "Stop Game");
            return;
        }
    }
    else { // режим PVP
        if (CurrentPlayer == GamerStatus::Player1) {
            if (!map.setPosition(cell, player1.getMark())) {
                MessageBox::Show("This cell already busy", "Stop Game");
                return;
            }
        }
        else if (CurrentPlayer == GamerStatus::Player2) {
            if (!map.setPosition(cell, player2.getMark())) {
                MessageBox::Show("This cell already busy", "Stop Game");
                return;
            }
        }
        else {
            MessageBox::Show("Now not your move", "Stop Game");
            return;
        }
    }

    UpDate(); // оновленн€ гри та зм≥на гравц€
}

System::Void Crossesandzerosgame::GameForm::GameForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
    Application::Exit();
}

