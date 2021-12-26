# TurokLoader ideas

- Dropper mutating (each action) by using metamorphic modification through obfuscation
- Dropper gains Admin rights through UAC privilege elevation
- Dropper gains persistence through curver\run regkey
	- drops a .wav file into %TEMP%. The audio file contains the archived ransomware stub
	- injects stub into the newly created processes: firefoxx.exe and msil.exe
	- melts the dropper source and the ransomware source
- The created processes can not be taskkilled. if so == bsod, restart and the main crypt routine will be triggered
- polymorphic main routine is beeing triggered
	- every file within a specififc ext range will be encrypted using AES-RSA hybrid encryption
	- no private/public key will be generated. 
	- after each file is encrypted, the ransomware is modifying its own body using morphic routine
	- each encrypted file gets a .TUROK extension, so the malware can locate them better
- hidden by using steganographic methods: store payload stub within .wav file
- decryption routine:
	- payment of crypto
	- locate all .TUROK files
	- estimate time until aes-rsa key is known
	- brute-force the key
- extra features include:
	- constant obfuscation
	- anti-dbg: overwritten the stub of the dropper and the stub of the body with the mirai-antidbg bin
	- check if vm env is true
		- wmic computersystem get manufacturer && if manufacturer is like vmware && taskkil /F firefoxx.exe msil.exe
- dropped files: 
	- %TEMP%\TMP<PID>.wav: contains the archived body stub
	- %TEMP%\TMP<Mutex>.bin: contains the dropper
	- %TEMP%\{guid}\*.wav: all files that are necessary for the wannacry like popup forms. Those winforms files are all compressed into wav files using steganography routine
- file routine:
	1. TMP<Mutex>.bin is the main file. It can be loaded through an RCE or through any Office macro
	2. When TMP<Mutex>.bin is executed, it gains UAC elevation privilege, drops persistence regkey and drops the .wav files into %TEMP%
	3. Body stub and forms components are extracted from the .wav files and are splitted into processes: svchost.exe and firefox.exe
	4. Body gets executed and encrypts all files in ext range and adds .TUROK ext. 
	5. Forms popup is shown and demands for crypto payment.
	6. If payment is not confirmed after specific time range, the MFT master file table gets encrypted and the machine will reboot.

### Copyright (c) 2020 - 2022 Timo Sarkar, APT777

**This repository contains several advanced malware techniques. Beware, that I, the original author of TurokLoader, am not responsible for any damage caused by TurokLoader. This project was born solely with the idea of getting a better insight on malicious behaviour.** 

**Illegal use of TurokLoader is strictly prohibited**
