// ---------------------------------------------------------------------------

#ifndef settingsH
#define settingsH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>

// ---------------------------------------------------------------------------
class TForm2 : public TForm {
__published: // IDE-managed Components
	TRadioGroup *RadioGroup1;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TRadioGroup *RadioGroup2;

private: // User declarations
public: // User declarations
	__fastcall TForm2(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
// ---------------------------------------------------------------------------
#endif
