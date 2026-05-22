#pragma once

// ETAP 4
// Etap 3 + grafiki i animacja.
// Zachowane sa panel, suwaki, odczyty i Sterownik, a dochodza obrazy oraz Timer.

#include "Sterownik.h"
#include <cmath>

namespace TurbinaWiatrowa {

    using namespace System;
    using namespace System::Drawing;
    using namespace System::Drawing::Drawing2D;
    using namespace System::Windows::Forms;

    public ref class Form1 : public Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();
            sterownik = new Sterownik(0.25, 0, 0, 0.45, 0, 0, 0.10, 0, 0, 0.10, 0, 0, 6.0, 3.0, 0.02);
            ostatniStan = new StanTurbiny(0, 0, 0, 0, UI(0, 0, 0), UI(0, 0, 0));
            katWirnika = 0;
            obrazWirnika = Image::FromFile("obrazki\\wirnik.png");
            obrazLopaty = Image::FromFile("obrazki\\lopata.png");
            obrazKompasu = Image::FromFile("obrazki\\kompas.png");
            obrazIglyWiatru = Image::FromFile("obrazki\\igla_wiatr.png");
            obrazIglyWiezy = Image::FromFile("obrazki\\igla_wieza.png");
            aktualizujSymulacje();
            timerAnimacji->Start();
        }

    protected:
        ~Form1()
        {
            delete sterownik;
            delete ostatniStan;
            delete obrazWirnika;
            delete obrazLopaty;
            delete obrazKompasu;
            delete obrazIglyWiatru;
            delete obrazIglyWiezy;
        }

    private:
        Sterownik* sterownik;
        StanTurbiny* ostatniStan;
        Panel^ panelWirnik;
        Panel^ panelLopata;
        Panel^ panelKompas;
        TrackBar^ suwakPredkosc;
        TrackBar^ suwakKierunek;
        Label^ lblPredkosc;
        Label^ lblKierunek;
        Label^ lblPitch;
        Label^ lblYaw;
        Label^ lblObroty;
        Timer^ timerAnimacji;
        Image^ obrazWirnika;
        Image^ obrazLopaty;
        Image^ obrazKompasu;
        Image^ obrazIglyWiatru;
        Image^ obrazIglyWiezy;
        double predkoscWiatru;
        double kierunekWiatru;
        double katWirnika;

        void InitializeComponent(void)
        {
            panelWirnik = gcnew Panel();
            panelLopata = gcnew Panel();
            panelKompas = gcnew Panel();
            suwakPredkosc = gcnew TrackBar();
            suwakKierunek = gcnew TrackBar();
            lblPredkosc = gcnew Label();
            lblKierunek = gcnew Label();
            lblPitch = gcnew Label();
            lblYaw = gcnew Label();
            lblObroty = gcnew Label();
            timerAnimacji = gcnew Timer();

            panelWirnik->Location = Point(20, 20);
            panelWirnik->Size = Drawing::Size(320, 260);
            panelWirnik->BackColor = Color::White;
            panelWirnik->Paint += gcnew PaintEventHandler(this, &Form1::panelWirnik_Paint);

            panelLopata->Location = Point(20, 300);
            panelLopata->Size = Drawing::Size(320, 180);
            panelLopata->BackColor = Color::White;
            panelLopata->Paint += gcnew PaintEventHandler(this, &Form1::panelLopata_Paint);

            panelKompas->Location = Point(370, 20);
            panelKompas->Size = Drawing::Size(280, 280);
            panelKompas->BackColor = Color::White;
            panelKompas->Paint += gcnew PaintEventHandler(this, &Form1::panelKompas_Paint);

            suwakPredkosc->Location = Point(690, 40);
            suwakPredkosc->Maximum = 25;
            suwakPredkosc->Value = 6;
            suwakPredkosc->Scroll += gcnew EventHandler(this, &Form1::suwaki_Scroll);
            suwakKierunek->Location = Point(690, 110);
            suwakKierunek->Maximum = 359;
            suwakKierunek->Scroll += gcnew EventHandler(this, &Form1::suwaki_Scroll);

            lblPredkosc->Location = Point(690, 180);
            lblKierunek->Location = Point(690, 210);
            lblPitch->Location = Point(690, 240);
            lblYaw->Location = Point(690, 270);
            lblObroty->Location = Point(690, 300);
            lblPredkosc->Size = Drawing::Size(260, 20);
            lblKierunek->Size = Drawing::Size(260, 20);
            lblPitch->Size = Drawing::Size(260, 20);
            lblYaw->Size = Drawing::Size(260, 20);
            lblObroty->Size = Drawing::Size(260, 20);

            timerAnimacji->Interval = 30;
            timerAnimacji->Tick += gcnew EventHandler(this, &Form1::timerAnimacji_Tick);

            ClientSize = Drawing::Size(980, 520);
            Text = "Wizualizacja turbiny - etap 4";
            Controls->Add(panelWirnik);
            Controls->Add(panelLopata);
            Controls->Add(panelKompas);
            Controls->Add(suwakPredkosc);
            Controls->Add(suwakKierunek);
            Controls->Add(lblPredkosc);
            Controls->Add(lblKierunek);
            Controls->Add(lblPitch);
            Controls->Add(lblYaw);
            Controls->Add(lblObroty);
        }

        void suwaki_Scroll(Object^ sender, EventArgs^ e)
        {
            aktualizujSymulacje();
        }

        void timerAnimacji_Tick(Object^ sender, EventArgs^ e)
        {
            katWirnika += ostatniStan->podajObroty() * 0.35;
            if (katWirnika >= 360)
            {
                katWirnika = fmod(katWirnika, 360.0);
            }
            panelWirnik->Invalidate();
        }

        void aktualizujSymulacje()
        {
            predkoscWiatru = suwakPredkosc->Value;
            kierunekWiatru = suwakKierunek->Value;
            sterownik->zmierzWiatr(predkoscWiatru, kierunekWiatru);
            sterownik->czytajWartosci();
            sterownik->obliczNowyStan();
            *ostatniStan = sterownik->czytajWartosci();

            lblPredkosc->Text = String::Format("Predkosc wiatru: {0:F1} m/s", predkoscWiatru);
            lblKierunek->Text = String::Format("Kierunek wiatru: {0:F0} stopni", kierunekWiatru);
            lblPitch->Text = String::Format("Pitch: {0:F1} stopni", ostatniStan->podajPitch());
            lblYaw->Text = String::Format("Yaw: {0:F1} stopni", ostatniStan->podajYaw());
            lblObroty->Text = String::Format("Obroty: {0:F1} obr/min", ostatniStan->podajObroty());
            panelWirnik->Invalidate();
            panelLopata->Invalidate();
            panelKompas->Invalidate();
        }

        void rysujObrazObrocony(Graphics^ g, Image^ obraz, Rectangle prostokat, double kat)
        {
            GraphicsState^ zapis = g->Save();
            g->TranslateTransform((float)(prostokat.Left + prostokat.Width / 2.0), (float)(prostokat.Top + prostokat.Height / 2.0));
            g->RotateTransform((float)kat);
            g->DrawImage(obraz, -prostokat.Width / 2, -prostokat.Height / 2, prostokat.Width, prostokat.Height);
            g->Restore(zapis);
        }

        void panelWirnik_Paint(Object^ sender, PaintEventArgs^ e)
        {
            Graphics^ g = e->Graphics;
            g->SmoothingMode = SmoothingMode::AntiAlias;
            g->DrawLine(gcnew Pen(Color::DimGray, 8), 160, 125, 160, 235);
            rysujObrazObrocony(g, obrazWirnika, Rectangle(85, 40, 150, 150), katWirnika);
        }

        void panelLopata_Paint(Object^ sender, PaintEventArgs^ e)
        {
            Graphics^ g = e->Graphics;
            g->SmoothingMode = SmoothingMode::AntiAlias;
            g->DrawLine(gcnew Pen(Color::DodgerBlue, 3), 20, 90, 130, 90);
            rysujObrazObrocony(g, obrazLopaty, Rectangle(130, 55, 145, 65), -ostatniStan->podajPitch());
        }

        void panelKompas_Paint(Object^ sender, PaintEventArgs^ e)
        {
            Graphics^ g = e->Graphics;
            g->SmoothingMode = SmoothingMode::AntiAlias;
            g->DrawImage(obrazKompasu, Rectangle(15, 15, 250, 250));
            rysujObrazObrocony(g, obrazIglyWiatru, Rectangle(95, 35, 90, 200), kierunekWiatru);
            rysujObrazObrocony(g, obrazIglyWiezy, Rectangle(105, 45, 70, 180), ostatniStan->podajYaw());
        }
    };
}

