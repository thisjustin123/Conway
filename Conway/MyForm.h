#pragma once
#include <string>
#include <unordered_map>
#include <thread>

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			for (int i = 0; i < 4900; i++) {
				cells[i] = false;
			}
			array<int^>^ cellStatuses = gcnew array<int^>(4900);
			mouseRect = gcnew Rectangle(10,10,10,10);
			hoverGraphics = this->CreateGraphics();
			prevGridX = -1;
			prevGridY = -1;
			/*System::Drawing::Size buttonSize = System::Drawing::Size(12, 12);
			for (int r = 0; r < 70; r++) {
				for (int c = 0; c < 70; c++) {
					Button^ but = gcnew Button();
					but->Location = System::Drawing::Point(12 + c * 10, 39 + r * 10);
					but->Size = buttonSize;
					but->Click += gcnew System::EventHandler(this, &MyForm::buttonClick);
					this->Controls->Add(but);
					but->BringToFront();
					items[r * 70 + c] = but;
				}
			}*/
			//this->listView1->Items->AddRange(items);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	public: System::Windows::Forms::Button^ button1;
	private: array<Button^>^ items = gcnew array<Button^>(4900);
	private: static array<bool>^ cells = gcnew array<bool>(4900);
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
		   int mouseY, mouseX;
		   System::Drawing::Rectangle^ mouseRect;
		   Graphics^ hoverGraphics;
		   bool mouseDown, isLeft, isRight;
		   int prevGridX, prevGridY;
	private: System::Windows::Forms::Button^ button2;
	protected:
	protected:
	private: System::Windows::Forms::Button^ button3;
	protected:
	private: System::Windows::Forms::Label^ label4;
	protected:











	protected: static int speed = 100;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(15, 9);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(118, 20);
			this->textBox1->TabIndex = 100;
			this->textBox1->Text = L"Conway\'s Game Of Life";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(433, 9);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(279, 20);
			this->textBox2->TabIndex = 1;
			this->textBox2->Text = L"[Left Click: Make Cell Live]  [Right Click: Make Cell Dead]";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(150, 7);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(108, 24);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start Game";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->trackBar1->Location = System::Drawing::Point(12, 763);
			this->trackBar1->Maximum = 1000;
			this->trackBar1->Minimum = 100;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(700, 45);
			this->trackBar1->SmallChange = 5;
			this->trackBar1->TabIndex = 3;
			this->trackBar1->Value = 550;
			this->trackBar1->ValueChanged += gcnew System::EventHandler(this, &MyForm::speedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(318, 749);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(89, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Simulation Speed";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label2->Location = System::Drawing::Point(12, 795);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(30, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Slow";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label3->Location = System::Drawing::Point(685, 795);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(27, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Fast";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(362, 7);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(55, 24);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Clear All";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::clearButton);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(281, 7);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 24);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Grid Toggle";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::gridToggle);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Location = System::Drawing::Point(9, 740);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(71, 13);
			this->label4->TabIndex = 101;
			this->label4->Text = L"Generation: 0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(724, 811);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->MaximumSize = System::Drawing::Size(740, 850);
			this->MinimumSize = System::Drawing::Size(740, 850);
			this->Name = L"MyForm";
			this->Text = L"Conway\'s Game of Life, by Justin Guo";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::closed);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::paintForm);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::formClick);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::formMDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::formMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::formMUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!gameStarted) {
			button1->Text = "Pause Game";
			beginSimulation(items, cells, this);
		}
		else {
			gamePaused = !gamePaused;
			if (gamePaused) {
				button1->Text = "Resume Game";
			}
			else {
				button1->Text = "Pause Game";
			}
		}
	}
	private: System::Void buttonClick(System::Object^ sender, System::EventArgs^ e) {
		Button^ b = dynamic_cast<System::Windows::Forms::Button^>(sender);
		for (int i = 0; i < 4900; i++) {
			Button^ but = items[i];
			if (but->Equals(b)) {
				System::Diagnostics::Trace::WriteLine("Row : " + i / 70 + "\nColumn: " + i % 70);
				cells[i] = !cells[i];
				if (cells[i]) {
					items[i]->BackColor = Color::Black;
					items[i]->ForeColor = Color::ForestGreen;
				}
				else {
					items[i]->BackColor = Color::Transparent;
					items[i]->ForeColor = Color::Transparent;
				}
				break;
			}
		}
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void speedChanged(System::Object^ sender, System::EventArgs^ e) {
	speed = trackBar1->Maximum - trackBar1->Value;

}
private: System::Void paintForm(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		g->Clear(Color::LightGray);

		System::Drawing::Brush^ brush = gcnew System::Drawing::SolidBrush(Color::White);

		g->FillRectangle(brush, 13, 40, 700, 700);

	if (gridUp) {
		System::Drawing::Pen^ pen = gcnew Pen(Color::Black);
		for (int i = 0; i < 71; i++) {
			g->DrawLine(pen, 12 + 10 * i, 39, 12 + 10 * i, 739);
		}
		for (int i = 0; i < 71; i++) {
			g->DrawLine(pen, 12, 39 + 10 * i, 711, 39 + 10 * i);
		}
	}
	else {
		System::Drawing::Pen^ pen = gcnew Pen(Color::Black);
		g->DrawLine(pen, 11, 38, 11, 740);
		g->DrawLine(pen, 11, 38, 713, 38);
		g->DrawLine(pen, 713, 38, 713, 740);
		g->DrawLine(pen, 11, 740, 713, 740);
	}
}
private: System::Void formClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	/*int gridX = (mouseX - 12) / 10;
	int gridY = (mouseY - 39) / 10;
	if (gridX > 0 && gridX < 70 && gridY > 0 && gridY < 70) {
		cells[gridY * 70 + gridX] = !cells[gridY * 70 + gridX];
		fillGrid(gridX, gridY);
	}*/
}
private: System::Void formMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	System::Drawing::Brush^ brushGray = gcnew System::Drawing::SolidBrush(Color::White);
	prevGridX = (mouseX - 12) / 10;
	prevGridY = (mouseY - 39) / 10;

	mouseX = e->Location.X;
	mouseY = e->Location.Y;

	System::Drawing::Brush^ brush = gcnew System::Drawing::SolidBrush(Color::LightBlue);

	int gridX = (mouseX - 12) / 10;
	int gridY = (mouseY - 39) / 10;

	if ((gridX != prevGridX || gridY != prevGridY) && mouseDown && gridX >= 0 && gridX < 70 && gridY >= 0 && gridY < 70) {
		if (isLeft && !isRight)
			cells[gridY * 70 + gridX] = true;
		else if (isRight && !isLeft) {
			cells[gridY * 70 + gridX] = false;
		}
	}

	rwl->AcquireReaderLock(1000);
	if (prevGridX >= 0 && prevGridX < 70 && prevGridY >= 0 && prevGridY < 70 && (prevGridX!=gridX || prevGridY!=gridY)) {
		fillGrid(prevGridY, prevGridX);
	}

	
	if (gridX >= 0 && gridX < 70 && gridY >= 0 && gridY < 70) {
		hoverGraphics->FillRectangle(brush, 13 + gridX * 10, 40 + gridY * 10, 9, 9);
		if (cells[gridY * 70 + gridX]) {
			System::Drawing::Brush^ brush = gcnew System::Drawing::SolidBrush(Color::DarkBlue);
			hoverGraphics->FillRectangle(brush, 14 + gridX * 10, 41 + gridY * 10, 7, 7);
		}
	}
	rwl->ReleaseReaderLock();
	

}
/*private: void capFPS() {
	Thread::Sleep(100);
	this->Refresh();
}*/
	private: System::Drawing::Brush^ whiteBrush = gcnew System::Drawing::SolidBrush(Color::White);
		   System::Drawing::Brush^ blackBrush = gcnew System::Drawing::SolidBrush(Color::Black);
public: System::Void fillGrid(int row, int col) {
	if (gridUp) {
		hoverGraphics->FillRectangle(whiteBrush, 13 + col * 10, 40 + row * 10, 9, 9);
		if (cells[row * 70 + col]) {
			hoverGraphics->FillRectangle(blackBrush, 14 + col * 10, 41 + row * 10, 7, 7);
		}
	}
	else {
		hoverGraphics->FillRectangle(whiteBrush, 12 + col * 10, 39 + row * 10, 10, 10);
		if (cells[row * 70 + col]) {
			hoverGraphics->FillRectangle(blackBrush, 12 + col * 10, 39 + row * 10, 10, 10);
		}
	}
}

private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void formMDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left) {
		isLeft = true;
	}
	else if (e->Button == System::Windows::Forms::MouseButtons::Right) {
		isRight = true;
	}
	mouseDown = true;

	int gridX = (mouseX - 12) / 10;
	int gridY = (mouseY - 39) / 10;
	rwl->AcquireWriterLock(100);
	if (gridX >= 0 && gridX < 70 && gridY >= 0 && gridY < 70) {
		if (isLeft && !isRight)
			cells[gridY * 70 + gridX] = true;
		else if (isRight && !isLeft)
			cells[gridY * 70 + gridX] = false;
	}
	rwl->ReleaseWriterLock();
}
private: System::Void formMUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left) {
		isLeft = false;
	}
	else if (e->Button == System::Windows::Forms::MouseButtons::Right) {
		isRight = false;
	}
	mouseDown = false;
}
private: System::Void clearButton(System::Object^ sender, System::EventArgs^ e) {
	rwl->AcquireWriterLock(100);
	for (int i = 0; i < 70; i++) {
		for (int j = 0; j < 70; j++) {
			cells[i * 70 + j] = false;
			neighborArray[i * 70 + j] = false;
		}
	}
	rwl->ReleaseWriterLock();
	rwl->AcquireReaderLock(100);
	for (int i = 0; i < 70; i++) {
		for (int j = 0; j < 70; j++) {
			fillGrid(i, j);
		}
	}
	rwl->ReleaseReaderLock();
}

	 static array<int>^ neighborArray=gcnew array<int>(4900);
	 static MyForm^ form;
	 static ReaderWriterLock^ rwl = gcnew ReaderWriterLock();
	 static Thread^ gameSimulator;
	 bool gameStarted = false;
	 bool gamePaused = false;
	 bool gridUp = true;
	 static int generation = 0;

public:
	static void beginSimulation(array<Button^>^ buttons, array<bool>^ c, MyForm^ f) {
		neighborArray = gcnew array<int>(4900);
		f->gameStarted = true;
		form = f;
		cells = c;
		gameSimulator = gcnew Thread(gcnew ThreadStart(start));
		gameSimulator->Start();
	}

	static void start() {
		if (!form->gamePaused) {
			rwl->AcquireReaderLock(100);
			calculateNeighbors(cells);
			array<bool>^ temp = gcnew array<bool>(4900);
			temp = dynamic_cast<array<bool>^>(cells->Clone());
			rwl->ReleaseReaderLock();


			rwl->AcquireWriterLock(100);
			for (int i = 0; i < 4900; i++) {
				bool cell = temp[i];
				if (cell) {
					if (neighborArray[i] != 2 && neighborArray[i] != 3) {
						//Kill the living cell.
						cells[i] = false;
						form->fillGrid(i / 70, i % 70);
					}
				}
				else {
					if (neighborArray[i] == 3) {
						//Revive the dead cell.
						cells[i] = true;
						form->fillGrid(i / 70, i % 70);
					}
				}
			}
			generation++;
			updateGeneration();

			rwl->ReleaseWriterLock();
		}
		while (form->gamePaused) {
			Thread::Sleep(40);
		}
		Thread::Sleep(speed);
		start();
	}
	public: static void updateGeneration()
	{
		// Call this same method but append THREAD2 to the text
		Action^ safeWrite = gcnew Action(setGenerationText);
		form->BeginInvoke(safeWrite);
	}
	private: static void setGenerationText() {
		form->label4->Text = "Generation: " + generation;
	}
	

	static void calculateNeighbors(array<bool>^ cells) {
		for (int i = 0; i < 4900; i++) {
			int col = i % 70;
			int row = i / 70;
			std::vector<int> indexesToCheck;
			std::vector<int> rowsToCheck;
			std::vector<int> colsToCheck;
			if (row > 0 && row < 69) {
				rowsToCheck.push_back(row - 1);
				rowsToCheck.push_back(row);
				rowsToCheck.push_back(row + 1);
			}
			else if (row > 0) {
				rowsToCheck.push_back(row - 1);
				rowsToCheck.push_back(row);
			}
			else {
				rowsToCheck.push_back(row);
				rowsToCheck.push_back(row + 1);
			}

			if (col > 0 && col < 69) {
				colsToCheck.push_back(col - 1);
				colsToCheck.push_back(col);
				colsToCheck.push_back(col + 1);
			}
			else if (col > 0) {
				colsToCheck.push_back(col - 1);
				colsToCheck.push_back(col);
			}
			else {
				colsToCheck.push_back(col);
				colsToCheck.push_back(col + 1);
			}

			for (int rowIt : rowsToCheck) {
				for (int colIt : colsToCheck) {
					if (rowIt != row || colIt != col) {
						indexesToCheck.push_back(rowIt * 70 + colIt);
					}
				}
			}

			int total = 0;
			for (int index : indexesToCheck) {
				total += cells[index] ? 1 : 0;
			}
			neighborArray[i] = total;
		}
	}
private: System::Void closed(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	Application::Exit();
	if (gameStarted)
		gameSimulator->Abort();
}
private: System::Void gridToggle(System::Object^ sender, System::EventArgs^ e) {
	gridUp = !gridUp;
	MyForm::Refresh();

	rwl->AcquireReaderLock(1000);
	for (int i = 0; i < 70; i++) {
		for (int j = 0; j < 70; j++) {
			fillGrid(i, j);
		}
	}
	rwl->ReleaseLock();
}
};