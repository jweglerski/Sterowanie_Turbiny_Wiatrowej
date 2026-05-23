#pragma once

#include "Sterownik.h"
#include <cmath>

namespace TurbinaWiatrowa {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;
	using namespace System::IO;
	using namespace System::Windows::Forms;

	public ref class BufferedPanel : public Panel
	{
	public:
		BufferedPanel()
		{
			this->DoubleBuffered = true;
			this->ResizeRedraw = true;
			this->SetStyle(ControlStyles::AllPaintingInWmPaint | ControlStyles::UserPaint | ControlStyles::OptimizedDoubleBuffer, true);
		}
	};

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			inicjalizujSymulacje();
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
			if (sterownik != nullptr)
			{
				delete sterownik;
				sterownik = nullptr;
			}
			if (ostatniStan != nullptr)
			{
				delete ostatniStan;
				ostatniStan = nullptr;
			}
			delete obrazWirnika;
			delete obrazLopaty;
			delete obrazKompasu;
			delete obrazIglyWiatru;
			delete obrazIglyWiezy;
		}

	private:
		System::ComponentModel::Container^ components;
		Panel^ panelWirnik;
		Panel^ panelLopata;
		Panel^ panelKompas;
		GroupBox^ grupaSterowania;
		GroupBox^ grupaParametrow;
		TrackBar^ suwakPredkosc;
		TrackBar^ suwakKierunek;
		Label^ lblPredkosc;
		Label^ lblKierunek;
		Label^ lblMoc;
		Label^ lblObroty;
		Label^ lblPitch;
		Label^ lblYaw;
		Label^ lblHamowanie;
		Label^ lblGenerator;
		Label^ lblMoment;
		ProgressBar^ pasekMocy;
		Timer^ timerAnimacji;

		Image^ obrazWirnika;
		Image^ obrazLopaty;
		Image^ obrazKompasu;
		Image^ obrazIglyWiatru;
		Image^ obrazIglyWiezy;

		Sterownik* sterownik;
		StanTurbiny* ostatniStan;
		double katWirnika;
		double aktualnaPredkosc;
		double aktualnyKierunek;
		double predkoscWirnikaDoAnimacji;
		int licznikTimera;
		bool hamowanieAktywne;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panelWirnik = (gcnew TurbinaWiatrowa::BufferedPanel());
			this->panelLopata = (gcnew TurbinaWiatrowa::BufferedPanel());
			this->panelKompas = (gcnew TurbinaWiatrowa::BufferedPanel());
			this->grupaSterowania = (gcnew System::Windows::Forms::GroupBox());
			this->suwakPredkosc = (gcnew System::Windows::Forms::TrackBar());
			this->suwakKierunek = (gcnew System::Windows::Forms::TrackBar());
			this->grupaParametrow = (gcnew System::Windows::Forms::GroupBox());
			this->lblPredkosc = (gcnew System::Windows::Forms::Label());
			this->lblKierunek = (gcnew System::Windows::Forms::Label());
			this->lblMoc = (gcnew System::Windows::Forms::Label());
			this->lblObroty = (gcnew System::Windows::Forms::Label());
			this->lblPitch = (gcnew System::Windows::Forms::Label());
			this->lblYaw = (gcnew System::Windows::Forms::Label());
			this->lblHamowanie = (gcnew System::Windows::Forms::Label());
			this->lblGenerator = (gcnew System::Windows::Forms::Label());
			this->lblMoment = (gcnew System::Windows::Forms::Label());
			this->pasekMocy = (gcnew System::Windows::Forms::ProgressBar());
			this->timerAnimacji = (gcnew System::Windows::Forms::Timer(this->components));
			this->grupaSterowania->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->suwakPredkosc))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->suwakKierunek))->BeginInit();
			this->grupaParametrow->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelWirnik
			// 
			this->panelWirnik->BackColor = System::Drawing::Color::White;
			this->panelWirnik->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelWirnik->Location = System::Drawing::Point(22, 22);
			this->panelWirnik->Name = L"panelWirnik";
			this->panelWirnik->Size = System::Drawing::Size(340, 300);
			this->panelWirnik->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panelWirnik_Paint);
			// 
			// panelLopata
			// 
			this->panelLopata->BackColor = System::Drawing::Color::White;
			this->panelLopata->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelLopata->Location = System::Drawing::Point(22, 340);
			this->panelLopata->Name = L"panelLopata";
			this->panelLopata->Size = System::Drawing::Size(340, 215);
			this->panelLopata->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panelLopata_Paint);
			// 
			// panelKompas
			// 
			this->panelKompas->BackColor = System::Drawing::Color::White;
			this->panelKompas->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelKompas->Location = System::Drawing::Point(386, 22);
			this->panelKompas->Name = L"panelKompas";
			this->panelKompas->Size = System::Drawing::Size(330, 330);
			this->panelKompas->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panelKompas_Paint);
			// 
			// grupaSterowania
			// 
			this->grupaSterowania->Controls->Add(this->suwakPredkosc);
			this->grupaSterowania->Controls->Add(this->suwakKierunek);
			this->grupaSterowania->Location = System::Drawing::Point(742, 22);
			this->grupaSterowania->Name = L"grupaSterowania";
			this->grupaSterowania->Size = System::Drawing::Size(250, 210);
			this->grupaSterowania->TabStop = false;
			this->grupaSterowania->Text = L"Suwaki sterujące";
			// 
			// suwakPredkosc
			// 
			this->suwakPredkosc->LargeChange = 5;
			this->suwakPredkosc->Location = System::Drawing::Point(18, 40);
			this->suwakPredkosc->Maximum = 60;
			this->suwakPredkosc->Name = L"suwakPredkosc";
			this->suwakPredkosc->Size = System::Drawing::Size(210, 45);
			this->suwakPredkosc->SmallChange = 1;
			this->suwakPredkosc->TickFrequency = 5;
			this->suwakPredkosc->Value = 30;
			this->suwakPredkosc->Scroll += gcnew System::EventHandler(this, &Form1::suwaki_Scroll);
			// 
			// suwakKierunek
			// 
			this->suwakKierunek->LargeChange = 30;
			this->suwakKierunek->Location = System::Drawing::Point(18, 130);
			this->suwakKierunek->Maximum = 359;
			this->suwakKierunek->Name = L"suwakKierunek";
			this->suwakKierunek->Size = System::Drawing::Size(210, 45);
			this->suwakKierunek->SmallChange = 5;
			this->suwakKierunek->TickFrequency = 45;
			this->suwakKierunek->Scroll += gcnew System::EventHandler(this, &Form1::suwaki_Scroll);
			// 
			// grupaParametrow
			// 
			this->grupaParametrow->Controls->Add(this->lblPredkosc);
			this->grupaParametrow->Controls->Add(this->lblKierunek);
			this->grupaParametrow->Controls->Add(this->lblMoc);
			this->grupaParametrow->Controls->Add(this->lblObroty);
			this->grupaParametrow->Controls->Add(this->lblPitch);
			this->grupaParametrow->Controls->Add(this->lblYaw);
			this->grupaParametrow->Controls->Add(this->lblHamowanie);
			this->grupaParametrow->Controls->Add(this->lblMoment);
			this->grupaParametrow->Controls->Add(this->lblGenerator);
			this->grupaParametrow->Controls->Add(this->pasekMocy);
			this->grupaParametrow->Location = System::Drawing::Point(742, 250);
			this->grupaParametrow->Name = L"grupaParametrow";
			this->grupaParametrow->Size = System::Drawing::Size(250, 305);
			this->grupaParametrow->TabStop = false;
			this->grupaParametrow->Text = L"Parametry pracy turbiny";
			ustawLabel(this->lblPredkosc, 28);
			ustawLabel(this->lblKierunek, 56);
			ustawLabel(this->lblMoc, 84);
			ustawLabel(this->lblObroty, 112);
			ustawLabel(this->lblPitch, 140);
			ustawLabel(this->lblYaw, 168);
			ustawLabel(this->lblHamowanie, 196);
			ustawLabel(this->lblMoment, 224);
			this->lblGenerator->Location = System::Drawing::Point(15, 252);
			this->lblGenerator->Size = System::Drawing::Size(220, 35);
			this->pasekMocy->Location = System::Drawing::Point(18, 292);
			this->pasekMocy->Maximum = 100;
			this->pasekMocy->Size = System::Drawing::Size(210, 10);
			// 
			// timerAnimacji
			// 
			this->timerAnimacji->Interval = 30;
			this->timerAnimacji->Tick += gcnew System::EventHandler(this, &Form1::timerAnimacji_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(242, 245, 247);
			this->ClientSize = System::Drawing::Size(1018, 580);
			this->Controls->Add(this->grupaParametrow);
			this->Controls->Add(this->grupaSterowania);
			this->Controls->Add(this->panelKompas);
			this->Controls->Add(this->panelLopata);
			this->Controls->Add(this->panelWirnik);
			this->Name = L"Form1";
			this->Text = L"Wizualizacja turbiny wiatrowej";
			this->grupaSterowania->ResumeLayout(false);
			this->grupaSterowania->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->suwakPredkosc))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->suwakKierunek))->EndInit();
			this->grupaParametrow->ResumeLayout(false);
			this->ResumeLayout(false);
		}
#pragma endregion

		void ustawLabel(Label^ label, int y)
		{
			label->Location = System::Drawing::Point(15, y);
			label->Size = System::Drawing::Size(220, 20);
		}

		void inicjalizujSymulacje()
		{
			this->DoubleBuffered = true;
			sterownik = new Sterownik(
				0.25, 0.0, 0.0,
				0.45, 0.0, 0.0,
				0.10, 0.0, 0.0,
				0.10, 0.0, 0.0,
				6.0, 3.0, 0.02);

			ostatniStan = new StanTurbiny(0, 0, 0, 0, UI(0, 0, 0), UI(0, 0, 0));
			katWirnika = 0;
			aktualnaPredkosc = suwakPredkosc->Value / 5.0;
			aktualnyKierunek = suwakKierunek->Value;
			predkoscWirnikaDoAnimacji = 0;
			licznikTimera = 0;
			hamowanieAktywne = false;

			String^ folder = znajdzFolderObrazkow();
			obrazWirnika = Image::FromFile(Path::Combine(folder, "wirnik.png"));
			obrazLopaty = Image::FromFile(Path::Combine(folder, "lopata.png"));
			obrazKompasu = Image::FromFile(Path::Combine(folder, "kompas.png"));
			obrazIglyWiatru = Image::FromFile(Path::Combine(folder, "igla_wiatr.png"));
			obrazIglyWiezy = Image::FromFile(Path::Combine(folder, "igla_wieza.png"));

			aktualizujSymulacje();
			timerAnimacji->Start();
		}

		String^ znajdzFolderObrazkow()
		{
			// Wczytanie obrazków.
			String^ folderZrodlowy = Path::GetDirectoryName(gcnew String(__FILE__));
			return Path::Combine(folderZrodlowy, "obrazki");
		}

		void aktualizujSymulacje()
		{
			aktualnaPredkosc = suwakPredkosc->Value / 5.0;
			aktualnyKierunek = suwakKierunek->Value;

			sterownik->zmierzWiatr(aktualnaPredkosc, aktualnyKierunek);
			sterownik->czytajWartosci();
			sterownik->obliczNowyStan();
			*ostatniStan = sterownik->czytajWartosci();

			hamowanieAktywne = aktualnaPredkosc > 10.0;
			double obroty = ostatniStan->podajObroty();
			if (obroty < 0 || Double::IsNaN(obroty) || Double::IsInfinity(obroty))
			{
				obroty = 0;
			}
			if (hamowanieAktywne)
			{
				obroty *= 0.25;
			}
			predkoscWirnikaDoAnimacji = obroty;

			aktualizujOdczyty(obroty);
			panelWirnik->Invalidate();
			panelLopata->Invalidate();
			panelKompas->Invalidate();
		}

		void aktualizujOdczyty(double obroty)
		{
			double moment = ostatniStan->podajT();
			double moc = moment * obroty;
			if (moc < 0 || Double::IsNaN(moc) || Double::IsInfinity(moc))
			{
				moc = 0;
			}

			lblPredkosc->Text = String::Format("Prędkość wiatru: {0:F1} m/s", aktualnaPredkosc);
			lblKierunek->Text = String::Format("Kierunek wiatru: {0:F0} stopni", aktualnyKierunek);
			lblMoc->Text = String::Format("Generowana moc: {0:F2} kW", moc);
			lblObroty->Text = String::Format("Obroty wirnika: {0:F2} obr/min", obroty);
			lblPitch->Text = String::Format("Kąt łopaty: {0:F1} stopni", ostatniStan->podajPitch());
			lblYaw->Text = String::Format("Ustawienie wieży: {0:F1} stopni", ostatniStan->podajYaw());
			lblHamowanie->Text = hamowanieAktywne ? "Hamowanie: załączone (>10 m/s)" : "Hamowanie: wyłączone";
			lblMoment->Text = String::Format("Moment/nastawa T: {0:F2}", moment);
			lblGenerator->Text = String::Format("Prądnica U alfa/beta: {0:F2} / {1:F2}",
				ostatniStan->podajU().Alfa(), ostatniStan->podajU().Beta());

			int procentMocy = (int)Math::Min(100.0, moc);
			pasekMocy->Value = procentMocy;
		}

		void rysujObrazObrocony(Graphics^ g, Image^ obraz, Rectangle prostokat, double kat)
		{
			if (obraz == nullptr)
			{
				return;
			}

			GraphicsState^ zapis = g->Save();
			g->TranslateTransform((float)(prostokat.Left + prostokat.Width / 2.0), (float)(prostokat.Top + prostokat.Height / 2.0));
			g->RotateTransform((float)kat);
			g->DrawImage(obraz, -prostokat.Width / 2, -prostokat.Height / 2, prostokat.Width, prostokat.Height);
			g->Restore(zapis);
		}

		void podpis(Graphics^ g, String^ tekst, int x, int y)
		{
			SolidBrush^ pedzel = gcnew SolidBrush(Color::FromArgb(40, 40, 40));
			System::Drawing::Font^ font = gcnew System::Drawing::Font("Segoe UI", 9);
			g->DrawString(tekst, font, pedzel, (float)x, (float)y);
			delete font;
			delete pedzel;
		}

	private: System::Void suwaki_Scroll(System::Object^ sender, System::EventArgs^ e)
	{
		aktualizujSymulacje();
	}

	private: System::Void timerAnimacji_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		katWirnika += predkoscWirnikaDoAnimacji * 0.35;
		if (katWirnika >= 360)
		{
			katWirnika = fmod(katWirnika, 360.0);
		}
		panelWirnik->Invalidate();

		licznikTimera++;
		if (licznikTimera >= 5)
		{
			licznikTimera = 0;
			aktualizujSymulacje();
		}
	}

	private: System::Void panelWirnik_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		Graphics^ g = e->Graphics;
		g->SmoothingMode = SmoothingMode::AntiAlias;
		podpis(g, "Wirnik - prędkość zależna od wiatru", 10, 10);
		rysujMaszt(g);
		rysujWiatr(g, aktualnyKierunek);
		rysujObrazObrocony(g, obrazWirnika, Rectangle(92, 50, 160, 160), katWirnika);
	}

	private: System::Void panelLopata_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		Graphics^ g = e->Graphics;
		g->SmoothingMode = SmoothingMode::AntiAlias;
		double pitch = ostatniStan->podajPitch();
		if (Double::IsNaN(pitch) || Double::IsInfinity(pitch))
		{
			pitch = 0;
		}
		if (pitch < 0)
		{
			pitch = 0;
		}
		if (pitch > 50)
		{
			pitch = 50;
		}
		// Pitch rosnie od 0.1 do 50 stopni, potem wlacza sie hamowanie.
		double katRysunku = -pitch;
		podpis(g, "Przekrój łopaty i kąt pitch", 10, 10);

		Pen^ wiatrPen = gcnew Pen(Color::DodgerBlue, 3);
		AdjustableArrowCap^ strzalka = gcnew AdjustableArrowCap(5, 5);
		wiatrPen->CustomEndCap = strzalka;
		g->DrawLine(wiatrPen, 25, 116, 135, 116);
		podpis(g, "wiatr", 46, 122);

		rysujObrazObrocony(g, obrazLopaty, Rectangle(135, 74, 155, 70), katRysunku);
		Pen^ osPen = gcnew Pen(Color::Gray, 1);
		osPen->DashStyle = DashStyle::Dash;
		g->DrawLine(osPen, 135, 116, 300, 116);

		// Czerwona cieciwa pokazuje kat pitch wzgledem kierunku wiatru.
		Pen^ pitchPen = gcnew Pen(Color::Firebrick, 2);
		double rad = katRysunku * 3.14159265358979323846 / 180.0;
		int cx = 212;
		int cy = 116;
		int dlugosc = 78;
		int x1 = cx - (int)(cos(rad) * dlugosc);
		int y1 = cy - (int)(sin(rad) * dlugosc);
		int x2 = cx + (int)(cos(rad) * dlugosc);
		int y2 = cy + (int)(sin(rad) * dlugosc);
		g->DrawLine(pitchPen, x1, y1, x2, y2);
		if (pitch > 0.2)
		{
			g->DrawArc(pitchPen, Rectangle(cx - 34, cy - 34, 68, 68), 360 - (float)pitch, (float)pitch);
		}
		podpis(g, String::Format("pitch = {0:F1} stopni", pitch), 175, 165);

		delete pitchPen;
		delete osPen;
		delete wiatrPen;
		delete strzalka;
	}

	private: System::Void panelKompas_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		Graphics^ g = e->Graphics;
		g->SmoothingMode = SmoothingMode::AntiAlias;
		g->DrawImage(obrazKompasu, Rectangle(15, 15, 300, 300));
		rysujObrazObrocony(g, obrazIglyWiatru, Rectangle(115, 45, 100, 240), aktualnyKierunek);
		rysujObrazObrocony(g, obrazIglyWiezy, Rectangle(125, 60, 80, 210), ostatniStan->podajYaw());
		podpis(g, "niebieska: wiatr", 15, 304);
		podpis(g, "czerwona: wieża", 178, 304);
	}

	// Prosty rysunek masztu zostaje w GUI, a fizyka turbiny jest brana ze Sterownika.
	void rysujMaszt(Graphics^ g)
	{
		Pen^ pen = gcnew Pen(Color::DimGray, 8);
		g->DrawLine(pen, 172, 132, 172, 265);
		g->FillEllipse(Brushes::DarkSlateGray, 154, 112, 36, 36);
		delete pen;
	}

	void rysujWiatr(Graphics^ g, double kierunek)
	{
		Pen^ pen = gcnew Pen(Color::DodgerBlue, 2);
		AdjustableArrowCap^ strzalka = gcnew AdjustableArrowCap(4, 5);
		pen->CustomEndCap = strzalka;
		g->DrawLine(pen, 25, 250, 105, 250);
		podpis(g, String::Format("wiatr {0:F0} stopni", kierunek), 25, 260);
		delete pen;
		delete strzalka;
	}
	};
}
