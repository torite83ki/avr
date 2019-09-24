avr 向け Cプログラム説明書
	gccとgnuツールを使って

概要
	avrマイコンのオブジェクトコードをavr用gccを使ってC言語でコーディングする。

1.ファイル一覧
	avr.h		: avr用ヘッダファイル  マクロ宣言、サブルーチン (C言語)
	2313def.h	: AT90S2313に特化した定義ヘッダファイル
	crt.S		: スタートアップルーチン(アセンブラファイル)
	crt.o		: スタートアップルーチン(オブジェクトファイル)
	gcc_elf.ls	: リンカファイル
	makefile	: メイクファイル
	avr_main.c	: C プログラムファイル
	avr_main.o	: C オブジェクトファイル
	avr_main.elf	: elf 形式出力ファイル(オブジェクトファイルとリンク済)
	avr_main.hex	: intel Hex形式出力ファイル
	out.gen		: flash rom(プログラム)のisp通信データ形式
	out.eep		: eeprom データのisp通信データ形式
	
	
	
