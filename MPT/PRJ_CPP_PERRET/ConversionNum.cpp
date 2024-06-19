//-----------------------------------------------------------------------------------/
// Nom du projet 		: Conversion Num�rique 
// Nom du fichier 		: ConversionNum.cpp
// Date de cr�ation 	: 11.03.2024
// Date de modification : 21.03.2024
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : ce programme est reli� au projet n�1 C++ - SLO2
//
// Remarques			:        
//----------------------------------------------------------------------------------//

//-- librairie standart --// 
#include <cmath>
#include <string>
#include <iostream>

//-- librairie personnelle --// 
#include "ConversionNum.h"
#include "ConversionBCD.h"

//----------------------------------------------------------------------------------//
// Nom de la m�thode	: ConversionNumerique 
// Entr�e				: 
// Sortie				: 
// in-out				:  
// Description			: constructeur
// Date modfification	: le 21.03.2024 
// Remarque				: si constructeur surcharg� - il faut d�finir le constructeur 
//						  par d�faut !!!
//----------------------------------------------------------------------------------//
ConversionNumerique::ConversionNumerique()
{
	//!! laisser vider -> red�finie dans les class enfants !! 
}

//----------------------------------------------------------------------------------//
// Nom de la m�thode	: ConversionNumerique 
// Entr�e				: choixCodage	-> entier	-> enum�ration : e_codageBinaire
//						  valUser		-> reel		-> 4 octets  
// Sortie				: 
// in-out				:  
// Description			: constructeur
// Date modfification	: le 21.03.2024 
// Remarque				: si constructeur surcharg� - il faut d�finir le constructeur 
//						  par d�faut !!!
//----------------------------------------------------------------------------------//
ConversionNumerique::ConversionNumerique(e_codageBinaire choixCodage, float valUser)
{
	//!! laisser vider -> red�finie dans les class enfants !! 
}

//----------------------------------------------------------------------------------//
// Nom de la m�thode	: ConversionNumerique 
// Entr�e				: 
// Sortie				: 
// in-out				:  
// Description			: destructeur
// Date modfification	: le 21.03.2024 
// Remarque				: fonction utiliser pour faire du polymorphisme 
//----------------------------------------------------------------------------------//
ConversionNumerique::~ConversionNumerique()
{
	//!! laisser vider -> red�finie dans les class enfants !! 
}




//----------------------------------------------------------------------------------//
// Nom de la m�thode	: CalculerNbrDigit 
// Entr�e				: valUser	-> reel		-> 32bits 
// Sortie				: nbrDigit	-> entier	-> 8bits	-> non sign�  
// in-out				: - 
// Description			: d�terminer le nb de digit d'un nombre 
// Date modfification	: le 18.03.2024 
// Remarque				: virtual -> polymorphisme
//----------------------------------------------------------------------------------//
void ConversionNumerique::CalculerNbrDigitEntier(float valUser)
{
	//!! laisser vider -> red�finie dans les class enfants !! 
}

//----------------------------------------------------------------------------------//
// Nom de la m�thode	: RecupererDigitEntier 
// Entr�e				: valUser	-> reel		-> 32bits 
// Sortie				: -  
// in-out				: - 
// Description			: d�termine la valeur de chaque digit et l'enregistre dans 
//						  un tableau
// Date modfification	: le 21.03.2024 
// Remarque				: virtual -> polymorphisme
//----------------------------------------------------------------------------------//
void ConversionNumerique::RecupererDigitEntier(float valUser)
{
	//!! laisser vider -> red�finie dans les class enfants !! 
}


//----------------------------------------------------------------------------------//
// Nom de la m�thode	: GetValeurConvertie 
// Entr�e				: 
// Sortie				: -  
// in-out				: - 
// Description			: 
// Date modfification	: le 22.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
std::string* ConversionNumerique::GetValeurConvertie()
{

	return m_ptTbBinaire;
}

//----------------------------------------------------------------------------------//
// Nom de la m�thode	: GetValeurConvertie 
// Entr�e				: 
// Sortie				: -  
// in-out				: - 
// Description			: 
// Date modfification	: le 22.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
char ConversionNumerique::GetNbrDigitEntier()
{
	return m_nbrDigitMaxValEntier;
}