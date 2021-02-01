#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include "player.h"
#include "NPC.h"
#include "Actions.h"
#include <cstdlib>
#include <stdio.h> 
#include <Windows.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>

#pragma comment(lib, "Winmm.lib")

#define LEFT  224
#define RIGHT 77
#define SPACE 32
#define DIR_KEY -32
#define ONE 49
#define TWO 50
//IDK if this is right?
#define THREE 51
#define ESC 27

using namespace std;
void checkQuit(int num) {
	if (num == ESC) {
		// could make an if statment to confirm if they want to quit???
		/*
		//play confirmSound(); <--- make this a sound if you want it. 
		int confirm;

		confirm = _getch();
		if(confirm == SPACE){
			exit(1);
		}
		*/
		exit(1);// remove this line if you add the if statment with sound from above
	}
}
//Audio script cut out/will be implemented in future releases
void CharacterConfforDex() {
	PlaySound("CharacterConf(_forDex).wav", NULL, SND_SYNC);
	
}
void CharacterConfforInt() {
	PlaySound("CharacterConf(_forInt).wav", NULL, SND_SYNC);
}
void CharacterConfforStrAnd() {
	PlaySound("CharacterConf(_forStrAnd).wav", NULL, SND_SYNC);
}
void CharacterConfconfirmORreselect() {
	PlaySound("CharacterConf(confirmORreselect).wav", NULL, SND_SYNC);
}
void CharacterConfRaceChoice() {
	PlaySound("CharacterConf(Race Choice).wav", NULL, SND_SYNC);
}
void CharacterConfStatsof() {
	PlaySound("CharacterConf(Stats of).wav", NULL, SND_SYNC);
}
void CharacterCustDwarf() {
	PlaySound("CharacterCust(Dwarf).wav", NULL, SND_SYNC);
}
void CharacterCustElf() {
	PlaySound("CharacterCust(Elf).wav", NULL, SND_SYNC);
}
void CharacterCustHuman() {
	PlaySound("CharacterCust(Human).wav", NULL, SND_SYNC);
}
void CharacterCustOrc() {
	PlaySound("CharacterCust(Orc).wav", NULL, SND_SYNC);
}
void CharacterCustbaseDEX() {
	PlaySound("CharacterCust(baseDEX).wav", NULL, SND_SYNC);
}
void CharacterCustbaseINT() {
	PlaySound("CharacterCust(baseINT).wav", NULL, SND_SYNC);
}
void CharacterCustbaseSTR() {
	PlaySound("CharacterCust(baseSTR).wav", NULL, SND_SYNC);
}
void CharacterCustIntro() {
	PlaySound("CharacterCust(Intro).wav", NULL, SND_SYNC);
}
void haracterCustRaceSelect() {
	PlaySound("CharacterCust(RaceSelect).wav", NULL, SND_SYNC);
}

//Randomizer (KL)
void sayNumber(int num) {
	if (num > 0 && num <= 20) {
		string filename = "Numbers (female UK)" + to_string(num) + ".wav";
		PlaySound(filename.c_str(), NULL, SND_SYNC);
	}
}

//Num 1-20 (KL)
void one() {
	PlaySound("Numbers (female UK)1.wav", NULL, SND_SYNC);
}
void two() {
	PlaySound("Numbers (female UK)2.wav", NULL, SND_SYNC);
}
void three() {
	PlaySound("Numbers (female UK)3.wav", NULL, SND_SYNC);
}
void four() {
	PlaySound("Numbers (female UK)4.wav", NULL, SND_SYNC);
}
void five() {
	PlaySound("Numbers (female UK)5.wav", NULL, SND_SYNC);
}
void six() {
	PlaySound("Numbers (female UK)6.wav", NULL, SND_SYNC);
}
void seven() {
	PlaySound("Numbers (female UK)7.wav", NULL, SND_SYNC);
}
void eight() {
	PlaySound("Numbers (female UK)8.wav", NULL, SND_SYNC);
}
void nine() {
	PlaySound("Numbers (female UK)9.wav", NULL, SND_SYNC);
}
void ten() {
	PlaySound("Numbers (female UK)10.wav", NULL, SND_SYNC);
}
void eleven() {
	PlaySound("Numbers (female UK)11.wav", NULL, SND_SYNC);
}
void twelve() {
	PlaySound("Numbers (female UK)12.wav", NULL, SND_SYNC);
}
void thirteen() {
	PlaySound("Numbers (female UK)13.wav", NULL, SND_SYNC);
}
void fourteen() {
	PlaySound("Numbers (female UK)14.wav", NULL, SND_SYNC);
}
void fifteen() {
	PlaySound("Numbers (female UK)15.wav", NULL, SND_SYNC);
}
void sixteen() {
	PlaySound("Numbers (female UK)16.wav", NULL, SND_SYNC);
}
void seventeen() {
	PlaySound("Numbers (female UK)17.wav", NULL, SND_SYNC);
}
void eightteen() {
	PlaySound("Numbers (female UK)18.wav", NULL, SND_SYNC);
}
void nineteen() {
	PlaySound("Numbers (female UK)19.wav", NULL, SND_SYNC);
}
void twenty() {
	PlaySound("Numbers (female UK)20.wav", NULL, SND_SYNC);
}

//PickedSoundEffects (KL)
void DiceRoll() {
	PlaySound("(DiceRoll)441841__seanmporio__d20-rolling.wav", NULL, SND_SYNC);
}
void ExplodingBoulderEncounter() {
	PlaySound("(ExplodingBoulderEncounter)218721__bareform__boom-bang.wav", NULL, SND_SYNC);
}
void MoveingBoulderEncounter() {
	PlaySound("(MoveingBoulderEncounter)393865__agc66__boulderfall1.mp3", NULL, SND_SYNC);
}
void OpeningStoneDoor() {
	PlaySound("(OpeningStoneDoor)508578__wdomino__boulderpush.wav", NULL, SND_SYNC);
}
void QuakeInCave() {
	PlaySound("(QuakeInCave)17371__homejrande__earthquake-mix-foley.wav", NULL, SND_SYNC);
}
void QuakeInTownEarthEleEncounter() {
	PlaySound("(QuakeInTownEarthEleEncounter)222521__uagadugu__cracking-earthquake-cracking-soil-cracking-stone.wav", NULL, SND_SYNC);
}
void QuakeSealingOffCaveEND() {
	PlaySound("(QuakeSealingOffCaveEND)336023__adamgryu__rocks.wav", NULL, SND_SYNC);
}
void Attacksound() {
	PlaySound("(Attack)52458__audione__sword-01.wav", NULL, SND_SYNC);
}
void Defendsound() {
	PlaySound("(Defend)319590__hybrid-v__shield-bash-impact.wav", NULL, SND_SYNC);
}
void EarthDeath() {
	PlaySound("(EarthDeath)466871__resaural__calls-beyond-earth.wav", NULL, SND_SYNC);
}
void EarthEncounterSound() {
	PlaySound("(EarthEncounterSound)276577__mickboere__dragons-dying-breath.wav", NULL, SND_SYNC);
}
void FireDeath() {
	PlaySound("(FireDeath)145729__frasbr__dragon-roar.wav", NULL, SND_SYNC);
}
void FireEncounter() {
	PlaySound("(FireEncounter)423009__ogsoundfx__dragon-spit-fire-1-wav.wav", NULL, SND_SYNC);
}
void IceDeath() {
	PlaySound("(IceDeath)508779__missburusdeer2011__golem-mad.wav", NULL, SND_SYNC);
}
void IceEncounter() {
	PlaySound("(IceEncounter)192365__jamesrodavidson__dinosaur-footsteps-01.wav", NULL, SND_SYNC);
}
void ImpDeath() {
	PlaySound("(ImpDeath)249813__spookymodem__goblin-death.wav", NULL, SND_SYNC);
}
void ImpEncounter() {
	PlaySound("(ImpEncounter)316475__littlerobotsoundfactory__smallcreature1-05.wav", NULL, SND_SYNC);
}

//Menu sounds
void ConfirmSound() {
	PlaySound("(ConfirmSound)321103__nsstudios__blip1.wav", NULL, SND_SYNC);
}
void CyclingThroughOptions() {
	PlaySound("(CyclingThroughOptions)321104__nsstudios__blip2.wav", NULL, SND_SYNC);
}
void GoingBack() {
	PlaySound("(GoingBack)489486__mattix__access-denied.wav", NULL, SND_SYNC);
}

//Quit Option
void Quit() {
	PlaySound("QuitOption.wav", NULL, SND_SYNC);
}

//Volume Menu
void Music() {
	PlaySound("(VolumeAdjust)510948__theojt__peaceful - ambiance - music.wav", NULL, SND_SYNC);
}
void AdjustVolume() {
	PlaySound("AdjustVolume.wav", NULL, SND_SYNC);
}

//Player Option Prompt (KL)
void WhatDoYouDo() {
	PlaySound("WhatDoYouDo.wav", NULL, SND_SYNC);
}
void RollDice() {
	PlaySound("RollDice.wav", NULL, SND_SYNC);
}

//Player Option Prompt (Fight) (KL)
void BattleLeapToBattleNarration() {
	PlaySound("BattleLeapToBattleNarration.wav", NULL, SND_SYNC);
}
void BattleOptionFIGHT() {
	PlaySound("BattleOptionFIGHT.wav", NULL, SND_SYNC);
}

//Before Game Start (KL)
void controlls() {
	PlaySound("Controls(UPDATED).wav", NULL, SND_SYNC);
}
void OtherControls() {
	PlaySound("OtherControls.wav", NULL, SND_SYNC);
}
void info() {
	PlaySound("info.wav", NULL, SND_SYNC);
}
void menu() {
	PlaySound("Menu.wav", NULL, SND_SYNC);
}

//Prologue story (KL)
void prologue1() {
	PlaySound("Prologue(1).wav", NULL, SND_SYNC);
}
void prologue2() {
	PlaySound("Prologue(2).wav", NULL, SND_SYNC);
}

//Intro (KL)
void Intro1() {
	PlaySound("Intro(1).wav", NULL, SND_SYNC);
}
void Intro2Innkeeper() {
	PlaySound("Intro(2)InKeeper.wav", NULL, SND_SYNC);
}

//Start of game (KL)
void dontRemember() {
	PlaySound("DontRemember(Player).wav", NULL, SND_SYNC);
}
void innKeeperStart() {
	PlaySound("InnKeeper(Start).wav", NULL, SND_SYNC);
}
void Rorikstead() {
	PlaySound("Rorikstead.wav", NULL, SND_SYNC);
}
void rumble() {
	PlaySound("RumbeEarthELMEncounterINTRO.wav", NULL, SND_SYNC);
}
void StarterItems() {
	PlaySound("StarterItems.wav", NULL, SND_SYNC);
}
void steppingOut() {
	PlaySound("SteppingOutoftheInn.wav", NULL, SND_SYNC);
}

//BattleSequence (KL)
void BattleCretureDescEarth() {
	PlaySound("Battle(CretureDesc)Earth.wav", NULL, SND_SYNC);
}
void BattleCretureDescFire() {
	PlaySound("Battle(CretureDesc)Fire.wav", NULL, SND_SYNC);
}
void BattleCretureDescImps() {
	PlaySound("Battle(CretureDesc)Imps.wav", NULL, SND_SYNC);
}
void BattleInitiative() {
	PlaySound("Battle(Initiative).wav", NULL, SND_SYNC);
}
void BattleOptionsAttack() {
	PlaySound("Battle(Options)Attack.wav", NULL, SND_SYNC);
}
void BattleOptionsDefend() {
	PlaySound("Battle(Options)Defend.wav", NULL, SND_SYNC);
}
void BattleOptionsFlee() {
	PlaySound("Battle(Options)Flee.wav", NULL, SND_SYNC);
}
void BattleOptionsMove() {
	PlaySound("Battle(Options)Move.wav", NULL, SND_SYNC);
}
void BattleWinEndDescEarth() {
	PlaySound("Battle(WinEndDesc)Earth.wav", NULL, SND_SYNC);
}
void BattleWinEndDescFire() {
	PlaySound("Battle(WinEndDesc)Fire.wav", NULL, SND_SYNC);
}
void BattleWinEndDescIce() {
	PlaySound("Battle(WinEndDesc)Ice.wav", NULL, SND_SYNC);
}
void BattleWinEndDescImps() {
	PlaySound("Battle(WinEndDesc)Imps.wav", NULL, SND_SYNC);
}
void GameOver() {
	PlaySound("GameOver.wav", NULL, SND_SYNC);
}
void YouHave() {
	PlaySound("YouHave.wav", NULL, SND_SYNC);
}
void HitPoints() {
	PlaySound("HitPoints.wav", NULL, SND_SYNC);
}
void MonsterAttackFirst() {
	PlaySound("MonsterAttackFirst.wav", NULL, SND_SYNC);
}
void SuccAttack() {
	PlaySound("SuccAttack.wav", NULL, SND_SYNC);
}
void SuccDefend() {
	PlaySound("SuccDefend.wav", NULL, SND_SYNC);
}
void FailAttack() {
	PlaySound("FailAttack.wav", NULL, SND_SYNC);
}
void FailDefend() {
	PlaySound("FailDefend.wav", NULL, SND_SYNC);
}
void CounterAttack() {
	PlaySound("CounterAttack.wav", NULL, SND_SYNC);
}
void TryDefend() {
	PlaySound("TryDefend.wav", NULL, SND_SYNC);
}

//MainQuestGet (KL)
void CheifCliffs2() {
	PlaySound("Cheif(Cliffs)2.wav", NULL, SND_SYNC);
}
void CheifThanks1() {
	PlaySound("CheifThanks1.wav", NULL, SND_SYNC);
}
void ChiefHistory4() {
	PlaySound("Chief(History)4.wav", NULL, SND_SYNC);
}
void ChiefReward5() {
	PlaySound("Chief(Reward)5.wav", NULL, SND_SYNC);
}
void CliffDesc3() {
	PlaySound("CliffDesc3.wav", NULL, SND_SYNC);
}
void GoldReward() {
	PlaySound("GoldReward.wav", NULL, SND_SYNC);
}

//Dungeon Intro (KL)
void DungeonIntro() {
	PlaySound("Dungeon Intro.wav", NULL, SND_SYNC);
}

//EarthquakeBoulderEncounter (KL)
void BoulderChoicesINT() {
	PlaySound("BoulderChoicesINT.wav", NULL, SND_SYNC);
}
void BoulderChoicesSTR() {
	PlaySound("BoulderChoicesSTR.wav", NULL, SND_SYNC);
}
void BoulderChoicesDEX() {
	PlaySound("BoulderChoicesDEX.wav", NULL, SND_SYNC);
}
void BoulderChoicesOutcomesDEXfail() {
	PlaySound("BoulderChoicesOutcomesDEXfail.wav", NULL, SND_SYNC);
}
void BoulderChoicesOutcomesDEXpass() {
	PlaySound("BoulderChoicesOutcomesDEXpass.wav", NULL, SND_SYNC);
}
void BoulderChoicesOutcomesINTfail() {
	PlaySound("BoulderChoicesOutcomesINTfail.wav", NULL, SND_SYNC);
}
void BoulderChoicesOutcomesINTpass() {
	PlaySound("BoulderChoicesOutcomesINTpass.wav", NULL, SND_SYNC);
}
void BoulderChoicesOutcomesSTRfail() {
	PlaySound("BoulderChoicesOutcomesSTRfail.wav", NULL, SND_SYNC);
}
void BoulderChoicesOutcomesSTRpass() {
	PlaySound("BoulderChoicesOutcomesSTRpass.wav", NULL, SND_SYNC);
}
void PastBoulder() {
	PlaySound("PastBoulder.wav", NULL, SND_SYNC);
}

//ImpsEncounter (KL)
void EnteringRoom() {
	PlaySound("EnteringRoom.wav", NULL, SND_SYNC);
}
void ImpOptionsInspect() {
	PlaySound("ImpOptionsInspect.wav", NULL, SND_SYNC);
}
void ImpOptionsOutcomesInspectFail() {
	PlaySound("ImpOptionsOutcomesInspectFail.wav", NULL, SND_SYNC);
}
void ImpOptionsOutcomesInspectPass() {
	PlaySound("ImpOptionsOutcomesInspectPass.wav", NULL, SND_SYNC);
}
void ImpOptionsOutcomesSneakFail() {
	PlaySound("ImpOptionsOutcomesSneakFail.wav", NULL, SND_SYNC);
}
void ImpOptionsOutcomesSneakPass() {
	PlaySound("ImpOptionsOutcomesSneakPass.wav", NULL, SND_SYNC);
}
void ImpOptionsSneak() {
	PlaySound("ImpOptionsSneak.wav", NULL, SND_SYNC);
}

//DungeonInterior (KL)
void DryadDialogue() {
	PlaySound("DryadDialogue.wav", NULL, SND_SYNC);
}
void DryadEncounter() {
	PlaySound("DryadEncounter.wav", NULL, SND_SYNC);
}
void DryadSee() {
	PlaySound("DryadSee.wav", NULL, SND_SYNC);
}
void EnterNextRoom() {
	PlaySound("EnterNextRoom.wav", NULL, SND_SYNC);
}

//Fire Elemental Encounter (KL)
void FireEleDescript() {
	PlaySound("FireEleDescript.wav", NULL, SND_SYNC);
}
void FireEleOptionsDistract() {
	PlaySound("FireEleOptionsDistract.wav", NULL, SND_SYNC);
}
void FireEleOptionsOutcomesDistractFail() {
	PlaySound("FireEleOptionsOutcomesDistractFail.wav", NULL, SND_SYNC);
}
void FireEleOptionsOutcomesDistractPass() {
	PlaySound("FireEleOptionsOutcomesDistractPass.wav", NULL, SND_SYNC);
}
void FireEleOptionsOutcomesSneakFail() {
	PlaySound("FireEleOptionsOutcomesSneakFail.wav", NULL, SND_SYNC);
}
void FireEleOptionsOutcomesSneakPass() {
	PlaySound("FireEleOptionsOutcomesSneakPass.wav", NULL, SND_SYNC);
}
void FireEleOptionsSneak() {
	PlaySound("FireEleOptionsSneak.wav", NULL, SND_SYNC);
}

//Releasing Young Dryad From Prison (KL)
void DryadDialogueSave() {
	PlaySound("DryadDialogueSave.wav", NULL, SND_SYNC);
}
void DryadDialogueThanks() {
	PlaySound("DryadDialogueThanks.wav", NULL, SND_SYNC);
}
void FindingOtherDryad() {
	PlaySound("FindingOtherDryad.wav", NULL, SND_SYNC);
}
void HeadingBack() {
	PlaySound("HeadingBack.wav", NULL, SND_SYNC);
}

//Final boss encounter (KL)
void IceGolem() {
	PlaySound("IceGolem.wav", NULL, SND_SYNC);
}

//WinEnd (KL)
void END() {
	PlaySound("END.wav", NULL, SND_SYNC);
}
void IceShattered() {
	PlaySound("IceShattered.wav", NULL, SND_SYNC);
}
void ODryadThanks() {
	PlaySound("ODryadThanks.wav", NULL, SND_SYNC);
}
void TownCelebration() {
	PlaySound("TownCelebration.wav", NULL, SND_SYNC);
}
void UseKey() {
	PlaySound("UseKey.wav", NULL, SND_SYNC);
}
void YDryadFDialogue() {
	PlaySound("YDryadFDialogue.wav", NULL, SND_SYNC);
}


// this function is not mine got it from here
// https://www.codeproject.com/Tips/233484/Change-Master-Volume-in-Visual-Cplusplus
bool ChangeVolume(double nVolume, bool bScalar)
{

	HRESULT hr = NULL;
	bool decibels = false;
	bool scalar = false;
	double newVolume = nVolume;

	CoInitialize(NULL);
	IMMDeviceEnumerator *deviceEnumerator = NULL;
	hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER,
		__uuidof(IMMDeviceEnumerator), (LPVOID *)&deviceEnumerator);
	IMMDevice *defaultDevice = NULL;

	hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
	deviceEnumerator->Release();
	deviceEnumerator = NULL;

	IAudioEndpointVolume *endpointVolume = NULL;
	hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume),
		CLSCTX_INPROC_SERVER, NULL, (LPVOID *)&endpointVolume);
	defaultDevice->Release();
	defaultDevice = NULL;

	// -------------------------
	float currentVolume = 0;
	endpointVolume->GetMasterVolumeLevel(&currentVolume);
	//printf("Current volume in dB is: %f\n", currentVolume);

	hr = endpointVolume->GetMasterVolumeLevelScalar(&currentVolume);
	//CString strCur=L"";
	//strCur.Format(L"%f",currentVolume);
	//AfxMessageBox(strCur);

	// printf("Current volume as a scalar is: %f\n", currentVolume);
	if (bScalar == false)
	{
		hr = endpointVolume->SetMasterVolumeLevel((float)newVolume, NULL);
	}
	else if (bScalar == true)
	{
		hr = endpointVolume->SetMasterVolumeLevelScalar((float)newVolume, NULL);
	}
	endpointVolume->Release();

	CoUninitialize();

	return FALSE;
}

//GAME MAIN CODE
int main() 
{
	
	
	
	Player player;
	NPC current;
	srand(time(0));
	char key = 0;
	bool play = true;
	int randnum, getKey, choice, gameOverKey, gold = 0, hp = 5, rand1;
	bool defeated = false, restart = true;
	int rollKey;
	int iceGolemHp = 6, attackNum, defendNum, fireHp = 4;
	bool firstMove = true, KeepPlaying = true;
	int strength = 0;
	int intellex = 0;
	int dex = 0;
	//------------------------------------------------
	
	/*
	RULES for battles
	--------------------------------------------------
	Player health: 5 hit points
	Earth Elemental: 3 hit points
	Earth Elemental: attack - 9 or higher
	Earth Elemental - defend 9 or higher
	1. Player always starts with 5 health points at the beginning of every battle
	2. Earth elemental: 3 hit points, to attack: 9 or higher, to defend 7 or higher
	3. Imps: 2 hit points (there are 3 of them, so 6 in total), to attack: 5 or higher, to defend 4 or higher
	4. Fire elemental: 4 hit points, to attack 10 or higher, to defend 8 or higher
	5. Ice golem (boss): 6 hit points, to attack 11 or higher, defend 9 or higher
	*/
	
	vector<Action*> choices;
	choices.push_back(new attack);
	choices.push_back(new flee);
	while (KeepPlaying) {
		// asks the user what volume they want to be at.
		// user presses 1 to increase and 2 to decrease.

		//playWhatSoundLevel();
		// add this above???????????^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^




		bool userConfirm = false;
		double volNum = .5;// master volume is auto set to 50% or .5
		int volKey;
		ChangeVolume(volNum, true);
		while (!userConfirm) {
			volKey = _getch();
			while (volKey != SPACE && volKey != ONE && volKey != TWO) {
				volKey = _getch();
				checkQuit(volKey);
			}

			if (volKey == ONE) {
				
				volNum += .1; // increases the volume by 10% or .1
				
			}
			if (volKey == TWO) {
				volNum -= .1;
			}
			if (volKey == SPACE) {
				userConfirm = true;
			}
			if (volNum > 1) {
				volNum = 1.0;
			}
			if (volNum < 0) {
				volNum = 0;
			}
			ChangeVolume(volNum, true);
			ConfirmSound();
		}





		//Before the game start
		/*AdjustVolume();
		Music();
		controlls();
		info();
		menu();

		rollKey = _getch();
		checkQuit(rollKey);
		while (rollKey != SPACE) {
			rollKey = _getch();
			checkQuit(rollKey);

		}
		
		ConfirmSound();

		//Prologue Story
		prologue1();
		prologue2();

		//Intro
		Intro1();
		Intro2Innkeeper();

		//Character Customization (Audio/script cut out)
		//Will be implemented in future releases

		//Start of game
		dontRemember();
		innKeeperStart();
		StarterItems();

		steppingOut();
		rumble();
		QuakeInTownEarthEleEncounter();

		EarthEncounterSound();
		BattleCretureDescEarth();

		//First Battle (Cannot avoid)
		hp = 5;
		int earthHp = 3;
		firstMove = true;

		BattleInitiative(); //Must roll 11 or higher to hit first
		rollKey = _getch();
		checkQuit(rollKey);
		while (rollKey != SPACE) {
			rollKey = _getch();
			checkQuit(rollKey);
		}
		checkQuit(rollKey);
		DiceRoll();
		rand1 = (rand() % 20) + 1;
		sayNumber(rand1);

		if (rand1 < 9) {
			hp -= 1;

			firstMove = false;
			// they are going to be attacked if the monster goes first
		}

		restart = true;

		while (restart) {
			while (hp != 0 && earthHp != 0) {  // battle
				if (firstMove) { // if you go first or if you got attacked then you get to go.

					//Current health
					YouHave();
					sayNumber(hp);
					HitPoints();

					WhatDoYouDo();
					one();
					BattleOptionsAttack();
					two();
					BattleOptionsDefend();

					choice = _getch();
					checkQuit(rollKey);
					while (choice != ONE && choice != TWO) { // one is attack and 2 is defend.
						choice = _getch();
						checkQuit(rollKey);
					}
					
					sayNumber(choice);

					if (choice == ONE) { // attack
						one();
						DiceRoll();
						attackNum = (rand() % 20) + 1;
						//sayNumber(attackNum);
						if (attackNum > 9) {
							SuccAttack();
							earthHp -= 1;
							Attacksound();
						}
						else {
							FailAttack();
						}
					}
					else { // defend
						two();
						DiceRoll();
						defendNum = (rand() % 20) + 1;
						//sayNumber(defendNum);
						if (defendNum < 7) {
							FailDefend();
							hp -= 1;
						}
						else { // made it so that if you defend then you can attack after at a lower number.
							SuccDefend();
								Defendsound();
								BattleOptionsAttack();
								attackNum = (rand() % 20) + 1;
								sayNumber(attackNum);
								if (attackNum > 6) {
									CounterAttack();
									earthHp -= 1;
									Attacksound();
								}
						}
					}
				}
				else { // you lost and dont get to go first.
						MonsterAttackFirst();
						defendNum = (rand() % 20) + 1;
						sayNumber(defendNum);
						if (defendNum < 7) {
							hp -= 1;
							FailDefend();
						}
						else {
							Defendsound();
						}
						firstMove = true;
				}
			}
			if (earthHp == 0) {
				EarthDeath();
				BattleWinEndDescEarth();
				restart = false;
			}
			if (hp == 0) {
				YouHave();
				sayNumber(hp);
				HitPoints();
				GameOver();
				hp = 5;
				earthHp = 3;

				gameOverKey = _getch();
				checkQuit(gameOverKey);
				while (gameOverKey != SPACE && gameOverKey != LEFT) {
					choice = _getch();
					checkQuit(gameOverKey);
				}
				if (gameOverKey == LEFT) {
					exit(0);
				}
			}
		}

		//MainQuestGet
		CheifThanks1();
		CheifCliffs2();
		CliffDesc3();
		ChiefHistory4();
		ChiefReward5();
		GoldReward();
		gold += 100;

		//Dungeon Intro
		DungeonIntro();
		QuakeInCave();

		//EarthquakeBoulderEncounter
		bool NotPastBoulder = true;

		while (NotPastBoulder)
		{
			//Choices
			WhatDoYouDo();
			one();
			BoulderChoicesSTR();
			two();
			BoulderChoicesINT();
			three();
			BoulderChoicesDEX();

			//PLAYER NEEDS TO CHOOSE FROM 3 OPTIONS, ROLL FOR PASS/FAIL CONDITIONS
			choice = _getch();
			checkQuit(choice);
			while (choice != ONE && choice != TWO && choice != THREE) {
				choice = _getch();
				checkQuit(choice);
			}
			ConfirmSound();
			if (choice == ONE) {
				sayNumber(1);
				RollDice();
				rollKey = _getch();
				checkQuit(rollKey);
				while (rollKey != SPACE) {
					rollKey = _getch();
					checkQuit(rollKey);
				}
				DiceRoll();
				strength = (rand() % 20) + 1;
				sayNumber(strength);


				//If STR: Fail under 13
				if (strength < 13) {
					BoulderChoicesOutcomesSTRfail();
				}
				else {
					BoulderChoicesOutcomesSTRpass();
					MoveingBoulderEncounter();
					NotPastBoulder = false;
				}
			}
			if (choice == TWO) {
				sayNumber(2);
				RollDice();
				rollKey = _getch();
				checkQuit(rollKey);
				while (rollKey != SPACE) {
					rollKey = _getch();
					checkQuit(rollKey);
				}
				DiceRoll();
				intellex = (rand() % 20) + 1;
				sayNumber(intellex);

				//If INT: Fail under 12
				if (intellex < 12) {
					BoulderChoicesOutcomesINTfail();
				}
				else {
					BoulderChoicesOutcomesINTpass();
					ExplodingBoulderEncounter();
					NotPastBoulder = false;
				}
			}
			if (choice == THREE) {
				sayNumber(3);
				RollDice();
				rollKey = _getch();
				checkQuit(rollKey);
				while (rollKey != SPACE) {
					rollKey = _getch();
					checkQuit(rollKey);
				}
				DiceRoll();
				dex = (rand() % 20) + 1;
				sayNumber(dex);

				//If DEX: Fail under 14
				if (dex < 14) {
					BoulderChoicesOutcomesDEXfail();
				}
				else {
					BoulderChoicesOutcomesDEXpass();
					NotPastBoulder = false;
				}
			}
		}

		PastBoulder();

		//Imps Encounter
		EnteringRoom();
		WhatDoYouDo();

		one();
		ImpOptionsInspect(); // 11 or higher
		two();
		ImpOptionsSneak(); //15 or higher
		three();
		BattleOptionFIGHT();
		bool impPass = false;
		choice = _getch();
		checkQuit(rollKey);
		while (choice != ONE && choice != TWO && choice != THREE) {
			choice = _getch();
			checkQuit(rollKey);
		}
		ConfirmSound();

		if (choice == ONE) {
			sayNumber(1);
			RollDice();
			rollKey = _getch();
			checkQuit(rollKey);

			while (rollKey != SPACE) {
				rollKey = _getch();
				checkQuit(rollKey);

			}
			DiceRoll();

			intellex = (rand() % 20) + 1;
			sayNumber(intellex);

			//If INT: Fail under 11
			if (intellex < 11) {
				ImpOptionsOutcomesInspectFail();
			}
			else {
				ImpOptionsOutcomesInspectPass();
			}
		}
		if (choice == TWO) {
			sayNumber(2);
			RollDice();
			rollKey = _getch();
			checkQuit(rollKey);

			while (rollKey != SPACE) {
				rollKey = _getch();
				checkQuit(rollKey);

			}
			DiceRoll();

			dex = (rand() % 20) + 1;
			sayNumber(dex);

			//If DEX: Fail under 15
			if (dex < 15) {
				ImpOptionsOutcomesSneakFail();
			}
			else {
				ImpOptionsOutcomesSneakPass();
				impPass = true;
			}
		}
		if (choice == THREE) { //Go to battle
			sayNumber(3);
		}

		hp = 5;
		int impHp = 6;
		firstMove = true;
		if (!impPass) {

			BattleInitiative(); //Must roll 11 or higher to hit first
			rollKey = _getch();
			checkQuit(rollKey);

			while (rollKey != SPACE) {
				rollKey = _getch();
				checkQuit(rollKey);

			}
			DiceRoll();
			rand1 = (rand() % 20) + 1;
			sayNumber(rand1);
			if (rand1 < 5) {
				hp -= 1;

				firstMove = false;
				// they are going to be attacked if the monster goes first
			}

			restart = true;

			while (restart) {
				while (hp != 0 && impHp != 0) {
					if (firstMove) { // if you go first or if you got attacked then you get to go.

						YouHave();
						sayNumber(hp);
						HitPoints();
						WhatDoYouDo();
						one();
						BattleOptionsAttack();
						two();
						BattleOptionsDefend();

						choice = _getch();
						while (choice != ONE && choice != TWO) { //1 = attack, 2 = defend
							choice = _getch();
							checkQuit(choice);
						}
						ConfirmSound();
						sayNumber(choice);

						if (choice == ONE) { // attack
							RollDice();
							choice = _getch();
							checkQuit(choice);
							while (choice != SPACE) {
								choice = _getch();
								checkQuit(choice);
							}
							ConfirmSound();
							attackNum = (rand() % 20) + 1;
							sayNumber(attackNum);
							if (attackNum > 5) {
								SuccAttack();
								impHp -= 1;
								Attacksound();
							}
							else {
								FailAttack();
							}
						}
						else { // defend
							RollDice();
							choice = _getch();
							checkQuit(choice);
							while (choice != SPACE) {
								choice = _getch();
								checkQuit(choice);
							}
							ConfirmSound();
							defendNum = (rand() % 20) + 1;
							sayNumber(defendNum);
							if (defendNum < 4) {
								FailDefend();
								hp -= 1;
							}
							else { // made it so that if you defend then you can attack after at a lower number.
								SuccDefend();
								Defendsound();
								attackNum = (rand() % 20) + 1;
								if (attackNum > 3) {
									CounterAttack();
									impHp -= 1;
									Attacksound();
								}
							}
						}
					}
					else { //Not high enough initiative and player don't get to go first
						MonsterAttackFirst();
						TryDefend();
						RollDice();
						defendNum = (rand() % 20) + 1;
						sayNumber(defendNum);
						if (defendNum < 4) {
							hp -= 1;
							FailDefend();
						}
						else {
							SuccDefend();
							Defendsound();
						}
						firstMove = true;
					}
				}
				if (impHp == 0) {
					ImpDeath();
					BattleWinEndDescImps();
					restart = false;
				}
				if (hp == 0) {
					YouHave();
					sayNumber(hp);
					HitPoints();

					GameOver();
					hp = 5;
					impHp = 3;
					gameOverKey = _getch();
					checkQuit(gameOverKey);

					while (gameOverKey != SPACE && gameOverKey != LEFT) {
						choice = _getch();
						checkQuit(choice);
					}
					if (gameOverKey == LEFT) {
						exit(0);

					}
				}
			}
		}

		//DungeonInterior
		EnterNextRoom();
		DryadEncounter();
		DryadSee();
		DryadDialogue();*/

		//Fire Elemental Encounter
		//FireEleDescript();

		bool activateBattle = false;
		int sneakInt = 0;
		bool sneak = false;
		bool sneakAttempt = false;

		while (!activateBattle) {

			if (sneakAttempt) { // if sneak fails then this will play and wont say option 2 anymore.
				WhatDoYouDo();
				one();
				FireEleOptionsDistract();
				three();
				BattleOptionFIGHT();
			}
			else {
				//WhatDoYouDo();
				//one();
				//FireEleOptionsDistract();// intel 10 or higher disctract
				//two();
				//FireEleOptionsSneak();// 12 or higher  dex sneak and get key
				//three();
				//BattleOptionFIGHT();
			}
			choice = _getch();
			checkQuit(choice);

			while (choice != ONE && choice != TWO && choice != THREE) {
				choice = _getch();
				checkQuit(choice);
			}

			if (!sneak && !sneakAttempt) {
				if (choice == TWO) {
					sayNumber(2);
					FireEleOptionsSneak();

					rollKey = _getch();
					checkQuit(rollKey);
					while (rollKey != SPACE) {
						rollKey = _getch();
						checkQuit(rollKey);
					}
					DiceRoll();

					sneakInt = (rand() % 20) + 1;
					sayNumber(sneakInt);
					
					if (sneakInt > 12) {
						sneak = true;
						FireEleOptionsOutcomesSneakPass();
						activateBattle = true;
						sneakAttempt = true;
					}
					else {
						FireEleOptionsOutcomesSneakFail();
						sneak = false;
						sneakAttempt = true;
						activateBattle = true; // I think i need this???
					}
				}
			}

			if (choice == ONE) {
				sayNumber(1);

				RollDice();
				rollKey = _getch();
				checkQuit(rollKey);

				while (rollKey != SPACE) {
					rollKey = _getch();
					checkQuit(rollKey);
				}
				DiceRoll();

				int distInt = 0;
				distInt = (rand() % 20) + 1;
				sayNumber(distInt);

				//FIX (structure put in, need to finish
				if (distInt >= 10) {
					FireEleOptionsOutcomesDistractPass();
					activateBattle = true;
					sneak = true;
				}
				else {
					FireEleOptionsOutcomesDistractFail(); 
					activateBattle = true;
				}
			}
			if (choice == THREE) {
				sayNumber(3);
				activateBattle = true;
			}
		}

		hp = 5;
		firstMove = true;

		// Fire elemental: 4 hit points, to attack 10 or higher, to defend 8 or higher
		if (!sneak) {
			FireEncounter();
			BattleLeapToBattleNarration();
			BattleInitiative(); //Must roll 10 or higher to hit first
			rollKey = _getch();
			checkQuit(rollKey);

			while (rollKey != SPACE) {
				rollKey = _getch();
				checkQuit(rollKey);
			}
			DiceRoll();
			rand1 = (rand() % 20) + 1;
			sayNumber(rand1);
			if (rand1 < 10) {
				hp -= 1;

				firstMove = false;
				// they are going to be attacked if the monster goes first
			}
		}
		restart = false;

		while (restart) {
			if (!sneak) {
				while (hp != 0 && fireHp != 0) {
					if (firstMove) { // if you go first or if you got attacked then you get to go. 
						YouHave();
						sayNumber(hp);
						HitPoints();

						WhatDoYouDo();
						one();
						BattleOptionsAttack();
						two();
						BattleOptionsDefend();

						choice = _getch();
						checkQuit(choice);
						while (choice != ONE && choice != TWO) { // one is attack and 2 is defend. 
							choice = _getch();
							checkQuit(choice);
						}
						sayNumber(choice);

						if (choice == ONE) { // attack
							RollDice();
							choice = _getch();
							checkQuit(choice);
							while (choice != SPACE) {
								choice = _getch();
								checkQuit(choice);
							}
							ConfirmSound();
							attackNum = (rand() % 20) + 1;
							sayNumber(attackNum);
							if (attackNum > 11) {
								SuccAttack();
								fireHp -= 1;
								Attacksound();
							}
							else {
								FailAttack();
							}
						}
						else { // defend
							RollDice();
							choice = _getch();
							checkQuit(choice);
							while (choice != SPACE) {
								choice = _getch();
								checkQuit(choice);
							}
							ConfirmSound();
							defendNum = (rand() % 20) + 1;
							sayNumber(defendNum);
							if (defendNum < 8) {
								FailDefend();
								hp -= 1;
							}
							else { // made it so that if you defend then you can attack after at a lower number. 
								SuccDefend();
								Defendsound();
								attackNum = (rand() % 20) + 1;
								sayNumber(attackNum);
								if (attackNum > 7) {
									CounterAttack();
									fireHp -= 1;
									Attacksound();
								}
							}
						}
					}
					else { // you lost and dont get to go first. 
						MonsterAttackFirst();
						TryDefend();
						RollDice();
						defendNum = (rand() % 20) + 1;
						sayNumber(defendNum);
						if (defendNum < 8) {
							hp -= 1;
							FailDefend();
						}
						else {
							SuccDefend();
							Defendsound();
						}
						firstMove = true;
					}
				}
				if (fireHp == 0) {
					IceDeath();
					BattleWinEndDescIce();
					restart = false;
				}
				if (hp == 0) {
					GameOver();
					hp = 5;
					fireHp = 4;
					gameOverKey = _getch();
					checkQuit(choice);

					while (gameOverKey != SPACE && gameOverKey != LEFT) {
						choice = _getch();
						checkQuit(choice);
					}
					if (gameOverKey == LEFT) {
						exit(0);
					}
				}
			}
		}

		//Releasing Young Dryad From Prison
		HeadingBack();
		DryadDialogueThanks();
		FindingOtherDryad();
		DryadDialogueSave();

		hp = 5;
		firstMove = true;
		//Ice golem (boss): 6 hit points, to attack 11 or higher, defend 9 or higher
		//FinalBossEncounter - Cannot Avoid
		IceGolem();
		IceEncounter();
		BattleInitiative(); //Must roll 11 or higher to hit first
		rollKey = _getch();
		checkQuit(rollKey);

		while (rollKey != SPACE) {
			rollKey = _getch();
			checkQuit(rollKey);
		}
		DiceRoll();
		rand1 = (rand() % 20) + 1;
		sayNumber(rand1);
		if (rand1 < 11) {
			hp -= 1;

			firstMove = false;
			// they are going to be attacked if the monster goes first
		}

		restart = true;

		while (restart) {

			while (hp != 0 && iceGolemHp != 0) {
				if (firstMove) { // if you go first or if you got attacked then you get to go. 
					YouHave();
					sayNumber(hp);
					HitPoints();

					WhatDoYouDo();
					one();
					BattleOptionsAttack();
					two();
					BattleOptionsDefend();

					choice = _getch();
					checkQuit(choice);
					while (choice != ONE && choice != TWO) { // one is attack and 2 is defend. 
						choice = _getch();
						checkQuit(choice);
					}
					sayNumber(choice);

					if (choice == ONE) { // attack
						RollDice();
						choice = _getch();
						checkQuit(choice);
						while (choice != SPACE) {
							choice = _getch();
							checkQuit(choice);
						}
						ConfirmSound();
						attackNum = (rand() % 20) + 1;
						sayNumber(attackNum);
						if (attackNum > 11) {
							SuccAttack();
							iceGolemHp -= 1;
							Attacksound();
						}
						else {
							FailAttack();
						}
					}
					else { // defend
						RollDice();
						choice = _getch();
						checkQuit(choice);
						while (choice != SPACE) {
							choice = _getch();
							checkQuit(choice);
						}
						ConfirmSound();
						defendNum = (rand() % 20) + 1;
						sayNumber(defendNum);
						if (defendNum < 9) {
							FailDefend();
							hp -= 1;
						}
						else { // made it so that if you defend then you can attack after at a lower number. 
							SuccDefend();
							Defendsound();
							attackNum = (rand() % 20) + 1;
							sayNumber(attackNum);
							if (attackNum > 8) {
								CounterAttack();
								iceGolemHp -= 1;
								Attacksound();
							}
						}
					}
				}
				else { // you lost and dont get to go first. 
					MonsterAttackFirst();
					TryDefend();
					RollDice();
					choice = _getch();
					checkQuit(choice);
					while (choice != SPACE) {
						choice = _getch();
						checkQuit(choice);
					}
					ConfirmSound();
					defendNum = (rand() % 20) + 1;
					sayNumber(defendNum);
					if (defendNum < 9) {
						hp -= 1;
						FailDefend();
					}
					else {
						SuccDefend();
						Defendsound();
					}
					firstMove = true;
				}
			}
			if (iceGolemHp == 0) {
				IceDeath();
				BattleWinEndDescIce();
				restart = false;
			}
			if (hp == 0) {
				YouHave();
				sayNumber(hp);
				HitPoints();
				GameOver();
				hp = 5;
				iceGolemHp = 6;

				gameOverKey = _getch();
				checkQuit(gameOverKey);

				while (gameOverKey != SPACE && gameOverKey != LEFT) {
					choice = _getch();
					checkQuit(choice);
				}
				if (gameOverKey == LEFT) {
					exit(0);
				}
			}
		}

		//WinEnd
		IceShattered();
		YDryadFDialogue();
		UseKey();
		ODryadThanks();
		TownCelebration();
		END(); //space to restart left arrow to quit. 

		choice = _getch();
		checkQuit(choice);
		if (choice != SPACE && choice != LEFT) {
			choice = _getch();
			checkQuit(choice);
		}
		if (choice == SPACE) {
			ConfirmSound();
		}
		if (choice == LEFT) {
			GoingBack();
			KeepPlaying = false;
		}

		//JACOB CHECK: this needs to be in an if statement or something
		//If at any time ESC key hit to quit
		// think I fixed it so dont need this code but will leave it here just in case something doesnt work I will use this. 
		/*Quit();

		int QuitKey = _getch();

		while (QuitKey != SPACE) {
			QuitKey = _getch();
		}
		ConfirmSound();

		exit(0);*/

		//Key inputs
		while (play) {
			if (key == RIGHT) {
				if (choice >= choices.size() - 1)
					choice = 0;
				else
					choice++;
			}
			else if (key == LEFT) {
				if (choice <= 0)
					choice = choices.size() - 1;
				else
					choice--;
			}
			else if (key == SPACE) {

				choices.at(choice)->doAction(player, current);

			}
			if (key != 0 && key != DIR_KEY && key != SPACE) {
				cout << choices[choice]->GetName() << endl;
				key = 0;
			}
			else {
				key = _getch();
			}
		}

	}

	return 0;
}