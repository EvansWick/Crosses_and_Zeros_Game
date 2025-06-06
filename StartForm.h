#pragma once

namespace Crossesandzerosgame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ StartForm
	/// </summary>
	public ref class StartForm : public System::Windows::Forms::Form
	{
	public:
		StartForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~StartForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelGameMode;
	private: System::Windows::Forms::Label^ labelFieldSize;
	private: System::Windows::Forms::Label^ labelLengthComb;
	protected:



	private: System::Windows::Forms::ListBox^ listBoxGameMode;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownFieldSize;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownCombLength;



	private: System::Windows::Forms::MenuStrip^ menuStrip1;

	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::Button^ buttonStartGame;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->labelGameMode = (gcnew System::Windows::Forms::Label());
			this->labelFieldSize = (gcnew System::Windows::Forms::Label());
			this->labelLengthComb = (gcnew System::Windows::Forms::Label());
			this->listBoxGameMode = (gcnew System::Windows::Forms::ListBox());
			this->numericUpDownFieldSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownCombLength = (gcnew System::Windows::Forms::NumericUpDown());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->buttonStartGame = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownFieldSize))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCombLength))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// labelGameMode
			// 
			this->labelGameMode->AutoSize = true;
			this->labelGameMode->Font = (gcnew System::Drawing::Font(L"Minecraft Rus", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelGameMode->Location = System::Drawing::Point(12, 45);
			this->labelGameMode->Name = L"labelGameMode";
			this->labelGameMode->Size = System::Drawing::Size(223, 32);
			this->labelGameMode->TabIndex = 0;
			this->labelGameMode->Text = L"Game mode";
			// 
			// labelFieldSize
			// 
			this->labelFieldSize->AutoSize = true;
			this->labelFieldSize->Font = (gcnew System::Drawing::Font(L"Minecraft Rus", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelFieldSize->Location = System::Drawing::Point(12, 108);
			this->labelFieldSize->Name = L"labelFieldSize";
			this->labelFieldSize->Size = System::Drawing::Size(204, 32);
			this->labelFieldSize->TabIndex = 1;
			this->labelFieldSize->Text = L"Field size";
			// 
			// labelLengthComb
			// 
			this->labelLengthComb->AutoSize = true;
			this->labelLengthComb->Font = (gcnew System::Drawing::Font(L"Minecraft Rus", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelLengthComb->Location = System::Drawing::Point(12, 178);
			this->labelLengthComb->Name = L"labelLengthComb";
			this->labelLengthComb->Size = System::Drawing::Size(548, 32);
			this->labelLengthComb->TabIndex = 2;
			this->labelLengthComb->Text = L"Length combination for win";
			// 
			// listBoxGameMode
			// 
			this->listBoxGameMode->Font = (gcnew System::Drawing::Font(L"Minecraft Rus", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBoxGameMode->FormattingEnabled = true;
			this->listBoxGameMode->ItemHeight = 27;
			this->listBoxGameMode->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"PvP", L"PvE" });
			this->listBoxGameMode->Location = System::Drawing::Point(603, 41);
			this->listBoxGameMode->Name = L"listBoxGameMode";
			this->listBoxGameMode->Size = System::Drawing::Size(112, 58);
			this->listBoxGameMode->TabIndex = 3;
			// 
			// numericUpDownFieldSize
			// 
			this->numericUpDownFieldSize->Font = (gcnew System::Drawing::Font(L"Minecraft Rus", 20.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->numericUpDownFieldSize->Location = System::Drawing::Point(603, 106);
			this->numericUpDownFieldSize->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 6, 0, 0, 0 });
			this->numericUpDownFieldSize->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->numericUpDownFieldSize->Name = L"numericUpDownFieldSize";
			this->numericUpDownFieldSize->Size = System::Drawing::Size(112, 34);
			this->numericUpDownFieldSize->TabIndex = 4;
			this->numericUpDownFieldSize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// numericUpDownCombLength
			// 
			this->numericUpDownCombLength->Font = (gcnew System::Drawing::Font(L"Minecraft Rus", 20.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->numericUpDownCombLength->Location = System::Drawing::Point(603, 175);
			this->numericUpDownCombLength->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 6, 0, 0, 0 });
			this->numericUpDownCombLength->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->numericUpDownCombLength->Name = L"numericUpDownCombLength";
			this->numericUpDownCombLength->Size = System::Drawing::Size(112, 34);
			this->numericUpDownCombLength->TabIndex = 5;
			this->numericUpDownCombLength->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->aboutToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(732, 24);
			this->menuStrip1->TabIndex = 6;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &StartForm::menuStrip1_ItemClicked);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartForm::aboutToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(38, 20);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartForm::exitToolStripMenuItem_Click);
			// 
			// buttonStartGame
			// 
			this->buttonStartGame->Font = (gcnew System::Drawing::Font(L"Minecraft Rus", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonStartGame->Location = System::Drawing::Point(275, 257);
			this->buttonStartGame->MaximumSize = System::Drawing::Size(211, 62);
			this->buttonStartGame->MinimumSize = System::Drawing::Size(211, 62);
			this->buttonStartGame->Name = L"buttonStartGame";
			this->buttonStartGame->Size = System::Drawing::Size(211, 62);
			this->buttonStartGame->TabIndex = 7;
			this->buttonStartGame->Text = L"Start game";
			this->buttonStartGame->UseVisualStyleBackColor = true;
			this->buttonStartGame->Click += gcnew System::EventHandler(this, &StartForm::buttonStartGame_Click);
			// 
			// StartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(732, 357);
			this->Controls->Add(this->buttonStartGame);
			this->Controls->Add(this->numericUpDownCombLength);
			this->Controls->Add(this->numericUpDownFieldSize);
			this->Controls->Add(this->listBoxGameMode);
			this->Controls->Add(this->labelLengthComb);
			this->Controls->Add(this->labelFieldSize);
			this->Controls->Add(this->labelGameMode);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"StartForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"New Game";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &StartForm::StartForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &StartForm::StartForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownFieldSize))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCombLength))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void StartForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void menuStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e);

		   private: System::Media::SoundPlayer^ sound;
private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonStartGame_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void StartForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	

};
}
