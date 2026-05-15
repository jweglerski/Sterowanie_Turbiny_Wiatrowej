#pragma once

namespace TurbinaWiatrowa {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelTurbina;
	protected:

	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ btnZmianaKierunku;
	private: System::Windows::Forms::Button^ btnSilnyWiatr;
	private: System::Windows::Forms::Button^ btnNormalne;
	private: System::Windows::Forms::Button^ btnHamowanie;




	private: System::Windows::Forms::Label^ lblMoc;
	private: System::Windows::Forms::Label^ lblObroty;


	private: System::Windows::Forms::Label^ lblPitch;

	private: System::Windows::Forms::Label^ lblYaw;
	private: System::Windows::Forms::Label^ lblKierunek;
	private: System::Windows::Forms::Label^ lblPredkosc;



	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;

	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panelTurbina = (gcnew System::Windows::Forms::Panel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->lblMoc = (gcnew System::Windows::Forms::Label());
			this->lblObroty = (gcnew System::Windows::Forms::Label());
			this->lblPitch = (gcnew System::Windows::Forms::Label());
			this->lblYaw = (gcnew System::Windows::Forms::Label());
			this->lblKierunek = (gcnew System::Windows::Forms::Label());
			this->lblPredkosc = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->btnHamowanie = (gcnew System::Windows::Forms::Button());
			this->btnZmianaKierunku = (gcnew System::Windows::Forms::Button());
			this->btnSilnyWiatr = (gcnew System::Windows::Forms::Button());
			this->btnNormalne = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelTurbina
			// 
			this->panelTurbina->Location = System::Drawing::Point(303, 255);
			this->panelTurbina->Name = L"panelTurbina";
			this->panelTurbina->Size = System::Drawing::Size(333, 334);
			this->panelTurbina->TabIndex = 0;
			this->panelTurbina->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panelTurbina_Paint);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->lblMoc);
			this->groupBox1->Controls->Add(this->lblObroty);
			this->groupBox1->Controls->Add(this->lblPitch);
			this->groupBox1->Controls->Add(this->lblYaw);
			this->groupBox1->Controls->Add(this->lblKierunek);
			this->groupBox1->Controls->Add(this->lblPredkosc);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(98, 50);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(152, 138);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Odczyt czujników";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &Form1::groupBox1_Enter);
			// 
			// lblMoc
			// 
			this->lblMoc->AutoSize = true;
			this->lblMoc->Location = System::Drawing::Point(105, 82);
			this->lblMoc->Name = L"lblMoc";
			this->lblMoc->Size = System::Drawing::Size(17, 13);
			this->lblMoc->TabIndex = 11;
			this->lblMoc->Text = L"0°";
			// 
			// lblObroty
			// 
			this->lblObroty->AutoSize = true;
			this->lblObroty->Location = System::Drawing::Point(105, 72);
			this->lblObroty->Name = L"lblObroty";
			this->lblObroty->Size = System::Drawing::Size(17, 13);
			this->lblObroty->TabIndex = 10;
			this->lblObroty->Text = L"0°";
			this->lblObroty->Click += gcnew System::EventHandler(this, &Form1::label11_Click);
			// 
			// lblPitch
			// 
			this->lblPitch->AutoSize = true;
			this->lblPitch->Location = System::Drawing::Point(105, 59);
			this->lblPitch->Name = L"lblPitch";
			this->lblPitch->Size = System::Drawing::Size(17, 13);
			this->lblPitch->TabIndex = 9;
			this->lblPitch->Text = L"0°";
			this->lblPitch->Click += gcnew System::EventHandler(this, &Form1::label10_Click);
			// 
			// lblYaw
			// 
			this->lblYaw->AutoSize = true;
			this->lblYaw->Location = System::Drawing::Point(105, 46);
			this->lblYaw->Name = L"lblYaw";
			this->lblYaw->Size = System::Drawing::Size(17, 13);
			this->lblYaw->TabIndex = 8;
			this->lblYaw->Text = L"0°";
			// 
			// lblKierunek
			// 
			this->lblKierunek->AutoSize = true;
			this->lblKierunek->Location = System::Drawing::Point(105, 33);
			this->lblKierunek->Name = L"lblKierunek";
			this->lblKierunek->Size = System::Drawing::Size(17, 13);
			this->lblKierunek->TabIndex = 7;
			this->lblKierunek->Text = L"0°";
			// 
			// lblPredkosc
			// 
			this->lblPredkosc->AutoSize = true;
			this->lblPredkosc->Location = System::Drawing::Point(105, 20);
			this->lblPredkosc->Name = L"lblPredkosc";
			this->lblPredkosc->Size = System::Drawing::Size(34, 13);
			this->lblPredkosc->TabIndex = 6;
			this->lblPredkosc->Text = L"0 m/s";
			this->lblPredkosc->Click += gcnew System::EventHandler(this, &Form1::label7_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(7, 85);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(31, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Moc:";
			this->label6->Click += gcnew System::EventHandler(this, &Form1::label6_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(7, 72);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(41, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Obroty:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(7, 59);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(34, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Pitch:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(7, 46);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(31, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Yaw:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(7, 33);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(83, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Kierunek wiatru:";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Prêdkoœæ wiatru:";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->btnHamowanie);
			this->groupBox2->Controls->Add(this->btnZmianaKierunku);
			this->groupBox2->Controls->Add(this->btnSilnyWiatr);
			this->groupBox2->Controls->Add(this->btnNormalne);
			this->groupBox2->Location = System::Drawing::Point(632, 70);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(133, 138);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Sterowanie symulacj¹";
			// 
			// btnHamowanie
			// 
			this->btnHamowanie->Location = System::Drawing::Point(7, 106);
			this->btnHamowanie->Name = L"btnHamowanie";
			this->btnHamowanie->Size = System::Drawing::Size(75, 23);
			this->btnHamowanie->TabIndex = 3;
			this->btnHamowanie->Text = L"Hamowanie";
			this->btnHamowanie->UseVisualStyleBackColor = true;
			// 
			// btnZmianaKierunku
			// 
			this->btnZmianaKierunku->Location = System::Drawing::Point(6, 77);
			this->btnZmianaKierunku->Name = L"btnZmianaKierunku";
			this->btnZmianaKierunku->Size = System::Drawing::Size(75, 23);
			this->btnZmianaKierunku->TabIndex = 2;
			this->btnZmianaKierunku->Text = L"Zmiana kierunku";
			this->btnZmianaKierunku->UseVisualStyleBackColor = true;
			this->btnZmianaKierunku->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// btnSilnyWiatr
			// 
			this->btnSilnyWiatr->Location = System::Drawing::Point(6, 48);
			this->btnSilnyWiatr->Name = L"btnSilnyWiatr";
			this->btnSilnyWiatr->Size = System::Drawing::Size(75, 23);
			this->btnSilnyWiatr->TabIndex = 1;
			this->btnSilnyWiatr->Text = L"Silny wiatr";
			this->btnSilnyWiatr->UseVisualStyleBackColor = true;
			// 
			// btnNormalne
			// 
			this->btnNormalne->Location = System::Drawing::Point(6, 19);
			this->btnNormalne->Name = L"btnNormalne";
			this->btnNormalne->Size = System::Drawing::Size(75, 23);
			this->btnNormalne->TabIndex = 0;
			this->btnNormalne->Text = L"Normalne warunki";
			this->btnNormalne->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(987, 601);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->panelTurbina);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label11_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panelTurbina_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	Graphics^ g = e->Graphics;

	Pen^ pen = gcnew Pen(Color::Black, 3);

	g->DrawLine(pen, 200, 50, 200, 180);

	g->DrawEllipse(pen, 180, 70, 40, 40);

	g->DrawLine(pen, 200, 90, 200, 40);

	g->DrawLine(pen, 200, 90, 240, 120);

	g->DrawLine(pen, 200, 90, 160, 120);
}
};
}
