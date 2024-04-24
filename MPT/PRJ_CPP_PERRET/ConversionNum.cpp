//-----------------------------------------------------------------------------------/
// Nom du projet 		: Conversion Numérique 
// Nom du fichier 		: ConversionNum.cpp
// Date de création 	: 11.03.2024
// Date de modification : 21.03.2024
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : ce programme est relié au projet n°1 C++ - SLO2
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
// Nom de la méthode	: ConversionNumerique 
// Entrée				: 
// Sortie				: 
// in-out				:  
// Description			: constructeur
// Date modfification	: le 21.03.2024 
// Remarque				: si constructeur surchargé - il faut définir le constructeur 
//						  par défaut !!!
//----------------------------------------------------------------------------------//
ConversionNumerique::ConversionNumerique()
{
	//!! laisser vider -> redéfinie dans les class enfants !! 
}

//----------------------------------------------------------------------------------//
// Nom de la méthode	: ConversionNumerique 
// Entrée				: choixCodage	-> entier	-> enumération : e_codageBinaire
//						  valUser		-> reel		-> 4 octets  
// Sortie				: 
// in-out				:  
// Description			: constructeur
// Date modfification	: le 21.03.2024 
// Remarque				: si constructeur surchargé - il faut définir le constructeur 
//						  par défaut !!!
//----------------------------------------------------------------------------------//
ConversionNumerique::ConversionNumerique(e_codageBinaire choixCodage, float valUser)
{
	//!! laisser vider -> redéfinie dans les class enfants !! 
}

//----------------------------------------------------------------------------------//
// Nom de la méthode	: ConversionNumerique 
// Entrée				: 
// Sortie				: 
// in-out				:  
// Description			: destructeur
// Date modfification	: le 21.03.2024 
// Remarque				: fonction utiliser pour faire du polymorphisme 
//----------------------------------------------------------------------------------//
ConversionNumerique::~ConversionNumerique()
{
	//!! laisser vider -> redéfinie dans les class enfants !! 
}




//----------------------------------------------------------------------------------//
// Nom de la méthode	: CalculerNbrDigit 
// Entrée				: valUser	-> reel		-> 32bits 
// Sortie				: nbrDigit	-> entier	-> 8bits	-> non signé  
// in-out				: - 
// Description			: déterminer le nb de digit d'un nombre 
// Date modfification	: le 18.03.2024 
// Remarque				: virtual -> polymorphisme
//----------------------------------------------------------------------------------//
void ConversionNumerique::CalculerNbrDigitEntier(float valUser)
{
	//!! laisser vider -> redéfinie dans les class enfants !! 
}

//----------------------------------------------------------------------------------//
// Nom de la méthode	: RecupererDigitEntier 
// Entrée				: valUser	-> reel		-> 32bits 
// Sortie				: -  
// in-out				: - 
// Description			: détermine la valeur de chaque digit et l'enregistre dans 
//						  un tableau
// Date modfification	: le 21.03.2024 
// Remarque				: virtual -> polymorphisme
//----------------------------------------------------------------------------------//
void ConversionNumerique::RecupererDigitEntier(float valUser)
{
	//!! laisser vider -> redéfinie dans les class enfants !! 
}


//----------------------------------------------------------------------------------//
// Nom de la méthode	: GetValeurConvertie 
// Entrée				: 
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
// Nom de la méthode	: GetValeurConvertie 
// Entrée				: 
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