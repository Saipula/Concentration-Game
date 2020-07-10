object Form2: TForm2
  Left = 470
  Top = 148
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Settings'
  ClientHeight = 252
  ClientWidth = 601
  Color = clSkyBlue
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object RadioGroup1: TRadioGroup
    Left = 0
    Top = 0
    Width = 281
    Height = 153
    Caption = 'Difficulty'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'SimSun-ExtB'
    Font.Style = [fsBold]
    Items.Strings = (
      'Easy'
      'Medium'
      'Hard')
    ParentFont = False
    TabOrder = 0
  end
  object BitBtn1: TBitBtn
    Left = 160
    Top = 179
    Width = 121
    Height = 42
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    Kind = bkOK
    NumGlyphs = 2
    ParentFont = False
    TabOrder = 1
  end
  object BitBtn2: TBitBtn
    Left = 304
    Top = 179
    Width = 121
    Height = 42
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    Kind = bkCancel
    NumGlyphs = 2
    ParentFont = False
    TabOrder = 2
  end
  object RadioGroup2: TRadioGroup
    Left = 312
    Top = 0
    Width = 281
    Height = 153
    Caption = 'Stile'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'SimSun-ExtB'
    Font.Style = [fsBold]
    Items.Strings = (
      'Nature'
      'Food'
      'Sport')
    ParentFont = False
    TabOrder = 3
  end
end
