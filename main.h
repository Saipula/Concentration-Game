// ---------------------------------------------------------------------------

#ifndef mainH
#define mainH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.BaseImageCollection.hpp>
#include <Vcl.ImageCollection.hpp>
#include <Vcl.VirtualImageList.hpp>

// ---------------------------------------------------------------------------
class TForm1 : public TForm {
__published: // IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *Restart;
	TMenuItem *Next;
	TMenuItem *Settings;
	TMenuItem *Stats;
	TLabel *Label1;
	TImageList *kartinki;
	TTimer *Timer1;
	TButton *Button1;
	TTimer *Timer2;
	TLabel *Label2;
	TMenuItem *Pause;
	TLabel *Label3;
	TMenuItem *easyN1;
	TMenuItem *mediumN1;
	TMenuItem *hardN1;
	TMenuItem *easyN2;
	TMenuItem *easyN3;
	TMenuItem *easyN4;
	TMenuItem *easyN5;
	TMenuItem *mediumN2;
	TMenuItem *mediumN3;
	TMenuItem *mediumN4;
	TMenuItem *mediumN5;
	TMenuItem *hardN2;
	TMenuItem *hardN3;
	TMenuItem *hardN4;
	TMenuItem *hardN5;
	TTimer *stoptime;
	TImage *image;
	TImageList *kartinki2;
	TImageList *kartinki3;

	void __fastcall SettingsClick(TObject *Sender);
	void __fastcall RestartClick(TObject *Sender);
	void __fastcall KnopochkaClick(TObject *Sender);
	void __fastcall NextClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall PauseClick(TObject *Sender);
	void __fastcall StatsClick(TObject *Sender);
	void __fastcall stoptimeTimer(TObject *Sender);
	void __fastcall back(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TForm1(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
// ---------------------------------------------------------------------------
#endif
