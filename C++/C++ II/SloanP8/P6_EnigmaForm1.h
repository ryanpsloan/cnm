#pragma once


#include "Enigma.h"
#include "StringConversion.h"
namespace EnigmaOnAForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;		//Added this namespace for file I/O

	/// <summary>
	/// Summary for Form1
	/// </summary>

	Enigma enig;			//################# Create Enigma Object #########################
	public ref class Form1 : public System::Windows::Forms::Form
	{
		
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  grpEncode;
	private: System::Windows::Forms::NumericUpDown^  nudKey;
	private: System::Windows::Forms::RadioButton^  bgGenerateKey;
	private: System::Windows::Forms::RadioButton^  rbenterKey;
	private: System::Windows::Forms::Label^  lblMessage;
	private: System::Windows::Forms::TextBox^  txtMessage;





	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  lblDecode;
	private: System::Windows::Forms::Button^  btnDecode;
	private: System::Windows::Forms::Button^  btnEncode;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::TextBox^  txtmess;
	private: System::Windows::Forms::TextBox^  txtcodedmess;
	private: System::Windows::Forms::TextBox^  txtkkey;



	private: System::Windows::Forms::Label^  Lblmess;
	private: System::Windows::Forms::Label^  lblCodedmess;
	private: System::Windows::Forms::Label^  lblkey;

	private: System::Windows::Forms::Label^  lblResults;
	private: System::Windows::Forms::Button^  btnClear;

	protected: 

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->grpEncode = (gcnew System::Windows::Forms::GroupBox());
			this->nudKey = (gcnew System::Windows::Forms::NumericUpDown());
			this->bgGenerateKey = (gcnew System::Windows::Forms::RadioButton());
			this->rbenterKey = (gcnew System::Windows::Forms::RadioButton());
			this->lblMessage = (gcnew System::Windows::Forms::Label());
			this->txtMessage = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->lblDecode = (gcnew System::Windows::Forms::Label());
			this->btnDecode = (gcnew System::Windows::Forms::Button());
			this->btnEncode = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->txtmess = (gcnew System::Windows::Forms::TextBox());
			this->txtcodedmess = (gcnew System::Windows::Forms::TextBox());
			this->txtkkey = (gcnew System::Windows::Forms::TextBox());
			this->Lblmess = (gcnew System::Windows::Forms::Label());
			this->lblCodedmess = (gcnew System::Windows::Forms::Label());
			this->lblkey = (gcnew System::Windows::Forms::Label());
			this->lblResults = (gcnew System::Windows::Forms::Label());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->grpEncode->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudKey))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe Print", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(234, 36);
			this->label1->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(672, 66);
			this->label1->TabIndex = 0;
			this->label1->Text = L" Welcome to the Enigma Encoding and Decoding Machine! \r\n Please enter your secret" 
				L" message to be encoded or decoded below:";
			// 
			// grpEncode
			// 
			this->grpEncode->Controls->Add(this->nudKey);
			this->grpEncode->Controls->Add(this->bgGenerateKey);
			this->grpEncode->Controls->Add(this->rbenterKey);
			this->grpEncode->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->grpEncode->Location = System::Drawing::Point(72, 133);
			this->grpEncode->Margin = System::Windows::Forms::Padding(4);
			this->grpEncode->Name = L"grpEncode";
			this->grpEncode->Padding = System::Windows::Forms::Padding(4);
			this->grpEncode->Size = System::Drawing::Size(311, 113);
			this->grpEncode->TabIndex = 1;
			this->grpEncode->TabStop = false;
			this->grpEncode->Text = L"ENCODE:  Choose one:";
			// 
			// nudKey
			// 
			this->nudKey->Location = System::Drawing::Point(180, 32);
			this->nudKey->Margin = System::Windows::Forms::Padding(4);
			this->nudKey->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {50, 0, 0, 0});
			this->nudKey->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->nudKey->Name = L"nudKey";
			this->nudKey->Size = System::Drawing::Size(55, 29);
			this->nudKey->TabIndex = 2;
			this->nudKey->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// bgGenerateKey
			// 
			this->bgGenerateKey->AutoSize = true;
			this->bgGenerateKey->Location = System::Drawing::Point(8, 71);
			this->bgGenerateKey->Margin = System::Windows::Forms::Padding(4);
			this->bgGenerateKey->Name = L"bgGenerateKey";
			this->bgGenerateKey->Size = System::Drawing::Size(227, 26);
			this->bgGenerateKey->TabIndex = 1;
			this->bgGenerateKey->TabStop = true;
			this->bgGenerateKey->Text = L"Use EnigmaGenerated Key";
			this->bgGenerateKey->UseVisualStyleBackColor = true;
			// 
			// rbenterKey
			// 
			this->rbenterKey->AutoSize = true;
			this->rbenterKey->Location = System::Drawing::Point(8, 33);
			this->rbenterKey->Margin = System::Windows::Forms::Padding(4);
			this->rbenterKey->Name = L"rbenterKey";
			this->rbenterKey->Size = System::Drawing::Size(112, 26);
			this->rbenterKey->TabIndex = 0;
			this->rbenterKey->TabStop = true;
			this->rbenterKey->Text = L"Enter a key";
			this->rbenterKey->UseVisualStyleBackColor = true;
			// 
			// lblMessage
			// 
			this->lblMessage->AutoSize = true;
			this->lblMessage->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblMessage->Location = System::Drawing::Point(76, 260);
			this->lblMessage->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblMessage->Name = L"lblMessage";
			this->lblMessage->Size = System::Drawing::Size(207, 22);
			this->lblMessage->TabIndex = 3;
			this->lblMessage->Text = L"Enter your secret message:";
			// 
			// txtMessage
			// 
			this->txtMessage->Location = System::Drawing::Point(72, 286);
			this->txtMessage->Margin = System::Windows::Forms::Padding(4);
			this->txtMessage->Multiline = true;
			this->txtMessage->Name = L"txtMessage";
			this->txtMessage->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtMessage->Size = System::Drawing::Size(438, 33);
			this->txtMessage->TabIndex = 4;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(72, 43);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(121, 59);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 10;
			this->pictureBox1->TabStop = false;
			// 
			// lblDecode
			// 
			this->lblDecode->AutoSize = true;
			this->lblDecode->Location = System::Drawing::Point(625, 133);
			this->lblDecode->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblDecode->Name = L"lblDecode";
			this->lblDecode->Size = System::Drawing::Size(301, 26);
			this->lblDecode->TabIndex = 11;
			this->lblDecode->Text = L"DECODE:  Just press the button!";
			// 
			// btnDecode
			// 
			this->btnDecode->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->btnDecode->Location = System::Drawing::Point(630, 169);
			this->btnDecode->Margin = System::Windows::Forms::Padding(4);
			this->btnDecode->Name = L"btnDecode";
			this->btnDecode->Size = System::Drawing::Size(277, 77);
			this->btnDecode->TabIndex = 12;
			this->btnDecode->Text = L"DECODE";
			this->btnDecode->UseVisualStyleBackColor = false;
			this->btnDecode->Click += gcnew System::EventHandler(this, &Form1::btnEncodeDecode_Click);
			// 
			// btnEncode
			// 
			this->btnEncode->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->btnEncode->Location = System::Drawing::Point(72, 343);
			this->btnEncode->Margin = System::Windows::Forms::Padding(4);
			this->btnEncode->Name = L"btnEncode";
			this->btnEncode->Size = System::Drawing::Size(268, 77);
			this->btnEncode->TabIndex = 13;
			this->btnEncode->Text = L"ENCODE";
			this->btnEncode->UseVisualStyleBackColor = false;
			this->btnEncode->Click += gcnew System::EventHandler(this, &Form1::btnEncode_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// txtmess
			// 
			this->txtmess->Location = System::Drawing::Point(310, 509);
			this->txtmess->Margin = System::Windows::Forms::Padding(4);
			this->txtmess->Name = L"txtmess";
			this->txtmess->ReadOnly = true;
			this->txtmess->Size = System::Drawing::Size(597, 33);
			this->txtmess->TabIndex = 14;
			// 
			// txtcodedmess
			// 
			this->txtcodedmess->Location = System::Drawing::Point(310, 548);
			this->txtcodedmess->Margin = System::Windows::Forms::Padding(4);
			this->txtcodedmess->Name = L"txtcodedmess";
			this->txtcodedmess->ReadOnly = true;
			this->txtcodedmess->Size = System::Drawing::Size(596, 33);
			this->txtcodedmess->TabIndex = 15;
			// 
			// txtkkey
			// 
			this->txtkkey->Location = System::Drawing::Point(310, 593);
			this->txtkkey->Margin = System::Windows::Forms::Padding(4);
			this->txtkkey->Name = L"txtkkey";
			this->txtkkey->ReadOnly = true;
			this->txtkkey->Size = System::Drawing::Size(81, 33);
			this->txtkkey->TabIndex = 16;
			this->txtkkey->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// Lblmess
			// 
			this->Lblmess->AutoSize = true;
			this->Lblmess->Location = System::Drawing::Point(190, 512);
			this->Lblmess->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Lblmess->Name = L"Lblmess";
			this->Lblmess->Size = System::Drawing::Size(93, 26);
			this->Lblmess->TabIndex = 17;
			this->Lblmess->Text = L"Message:";
			// 
			// lblCodedmess
			// 
			this->lblCodedmess->AutoSize = true;
			this->lblCodedmess->Location = System::Drawing::Point(126, 551);
			this->lblCodedmess->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblCodedmess->Name = L"lblCodedmess";
			this->lblCodedmess->Size = System::Drawing::Size(157, 26);
			this->lblCodedmess->TabIndex = 18;
			this->lblCodedmess->Text = L"Coded Message:";
			// 
			// lblkey
			// 
			this->lblkey->AutoSize = true;
			this->lblkey->Location = System::Drawing::Point(221, 593);
			this->lblkey->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblkey->Name = L"lblkey";
			this->lblkey->Size = System::Drawing::Size(53, 26);
			this->lblkey->TabIndex = 19;
			this->lblkey->Text = L"Key:";
			// 
			// lblResults
			// 
			this->lblResults->AutoSize = true;
			this->lblResults->Font = (gcnew System::Drawing::Font(L"Segoe Print", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblResults->Location = System::Drawing::Point(313, 449);
			this->lblResults->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblResults->Name = L"lblResults";
			this->lblResults->Size = System::Drawing::Size(345, 37);
			this->lblResults->TabIndex = 20;
			this->lblResults->Text = L"<=Secret Messsage Summary=>";
			// 
			// btnClear
			// 
			this->btnClear->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnClear->Location = System::Drawing::Point(630, 343);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(277, 77);
			this->btnClear->TabIndex = 21;
			this->btnClear->Text = L"CLEAR";
			this->btnClear->UseVisualStyleBackColor = false;
			this->btnClear->Click += gcnew System::EventHandler(this, &Form1::btnClear_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 26);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->ClientSize = System::Drawing::Size(1003, 652);
			this->Controls->Add(this->btnClear);
			this->Controls->Add(this->lblResults);
			this->Controls->Add(this->lblkey);
			this->Controls->Add(this->lblCodedmess);
			this->Controls->Add(this->Lblmess);
			this->Controls->Add(this->txtkkey);
			this->Controls->Add(this->txtcodedmess);
			this->Controls->Add(this->txtmess);
			this->Controls->Add(this->btnEncode);
			this->Controls->Add(this->btnDecode);
			this->Controls->Add(this->lblDecode);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->txtMessage);
			this->Controls->Add(this->lblMessage);
			this->Controls->Add(this->grpEncode);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"Form1";
			this->Text = L"Ivonne Nelson Enigma Coding Machine";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->grpEncode->ResumeLayout(false);
			this->grpEncode->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudKey))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void btnEncodeDecode_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 //Decode Button	make two managed strings to read in the data from the file			 
				 String^ mess;
				 String^ kkey;
				 
				 //instantiate the openFileDialog control on the form
				 OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

				 //initialize properties (see MSDN)
				 openFileDialog1->InitialDirectory = "\\";
				 openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
				 openFileDialog1->FilterIndex = 2;
				 openFileDialog1->RestoreDirectory = true;
				 			 
				 
				 if( openFileDialog1-> ShowDialog() == System::Windows::Forms::DialogResult::OK )
				 {
					 if( (openFileDialog1->OpenFile()) != nullptr )  //Check that file is open
					 {
						 //read the stream now using the Stream Reader class by making a new streamreader object

						 StreamReader^ input = gcnew StreamReader(openFileDialog1->FileName);
						 mess = input->ReadLine();
						 kkey = input->ReadLine();

						 input->Close();

						//now we have two managed strings and we will have to convert them to native strings
						 std::string codedMess, k;
						 To_string(mess, codedMess);
						 To_string(kkey, k);

						 //now set the inputs into our Enigma object
						 enig.setCodedMessage(codedMess, k);

						 //and display the results: message, key and filename
						 txtmess->Text = gcnew String(enig.getDecodedMessage().c_str());
						 txtkkey->Text = gcnew String(enig.getKey().c_str());						 
						 txtcodedmess->Text = mess;
						 
					 }
				 else 
						txtmess->Text = " File not opened!";
				

				 }
			 
			 }
private: System::Void btnEncode_Click(System::Object^  sender, System::EventArgs^  e) 
		
		 {

				std::string mess;
				std::string k;

				SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;
				saveFileDialog1->InitialDirectory = "\\";
				saveFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
				saveFileDialog1->FilterIndex = 2;
				saveFileDialog1->RestoreDirectory = true;

				 if( saveFileDialog1-> ShowDialog() == System::Windows::Forms::DialogResult::OK )
				 {
					 //convert managed strings to native strings
					To_string(txtMessage->Text, mess);

					 if(rbenterKey->Checked)
					 {
						 //convert managed strings to native strings
						 
						 /*String ^ nk = nudKey->Value.ToString();*/
						/* double kk = (Double)nudKey->Value;*/
						/* Int32Value = Decimal::ToInt32( argument );*/
						int kk = Decimal::ToInt32(nudKey->Value);
						 /*To_string(nk, k);*/
						 enig.setMessage(mess, kk);
							
					 }

					 if(bgGenerateKey->Checked)
					 {
						 enig.setMessage(mess);
					 }

					 //now get back the result

					  txtmess->Text = gcnew String(enig.getDecodedMessage().c_str());					 
					  txtcodedmess->Text = gcnew String(enig.getCodedMessage().c_str());
					  txtkkey->Text = gcnew String(enig.getKey().c_str());

					  //and open the output stream
					  StreamWriter^ output = gcnew StreamWriter(saveFileDialog1->FileName);
					  output->WriteLine(gcnew String(enig.getCodedMessage().c_str()));
					  output->WriteLine(gcnew String(enig.getKey().c_str()));
					  output->Close();
				 }
	    
					 
		
				 else
					txtmess->Text = "No file opened.";

		 }

private: System::Void btnClear_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			txtmess->Text = "";
			txtcodedmess->Text = "";
			txtkkey->Text= "";
			txtMessage->Text= "";
			nudKey->Value = (Decimal)1.0;
		 }

};
}

