//-----------------------------------------------------------------------------------/
// Nom du projet 		: Conversion Numérique 
// Nom du fichier 		: ConversionNum.cpp
// Date de création 	: 21.03.2024
// Date de modification : 22.03.2024
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : ce programme est relié au projet n°1 C++ - SLO2
//
// Remarques			:        
//----------------------------------------------------------------------------------//

//-- librairie standart --// 

								// pour les objets de type chaine de caractère 
#include <iostream>				// pour les méthode cin et cout
#include <bitset>
	
//-- librairie personnelle --// 
#include "ConversionNum.h"	
#include "ConversionBCD.h"


//-- attribut --// 


//--> protected 
//--> private 

//-- prototype -> méthode --//
//-> visibilité 



//----------------------------------------------------------------------------------//
// Nom de la méthode	: ConversionBCD 
// Entrée				: 
// Sortie				: 
// in-out				:  
// Description			: constructeur 
// Date modfification	: le 21.03.2024 
// Remarque				: si constructeur surchargé - il faut définir le constructeur 
//						  par défaut + ajouter le lien de au constructeur parent !!!
//----------------------------------------------------------------------------------//
ConversionBCD::ConversionBCD() : ConversionNumerique()
{
}






//----------------------------------------------------------------------------------//
// Nom de la méthode	: ConversionBCD 
// Entrée				: choixCodage	-> entier	-> enumération : e_codageBinaire
//						  valUser		-> reel		-> 4 octets  
// Sortie				: 
// in-out				:  
// Description			: constructeur surchargé 
// Date modfification	: le 22.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
ConversionBCD::ConversionBCD(e_codageBinaire choixCodage, float valUser)
{
	//-- test le choixCodage correspond à l'énumération BCD 
	if (choixCodage == valUser)
	{
		//-- création d'un tableau dynamique via pointeur --// 
		
		m_ptTbDigitEntier[m_nbrDigitMaxValEntier];
	
		//-- appel fonction : détermine le nb de digit du nombre entier --//
		CalculerNbrDigitEntier(valUser);

		//-- appel fonction : récuperation de chaque digit --//
		RecupererDigitEntier(valUser);

		//-- appel fonction : conversion binaire de chaque digit entier --// 
		ConversionBinaire();
	}
	else
	{
		//ne fait rien 
	}
}



//----------------------------------------------------------------------------------//
// Nom de la méthode	: ~ConversionBCD 
// Entrée				: 
// Sortie				: 
// in-out				:  
// Description			: destructeur 
// Date modfification	: le 21.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
ConversionBCD::~ConversionBCD()
{

}



//----------------------------------------------------------------------------------//
// Nom de la méthode	: CalculerNbrDigitEntier 
// Entrée				: valUser		-> reel		-> 4 octets  
// Sortie				: 
// in-out				: 
// Description			: détermine le nb de digit d'un nombre entier 
// Date modfification	: le 21.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
void ConversionBCD::CalculerNbrDigitEntier(float valUser)
{
	//-- déclaration de variables --// 
	int valuser_transition;
	int cnt_digit = 0 ;

	valuser_transition = (int)valUser;

	//-- itération pour connaitre le nbr de digit sur une valeur entière

	do
	{
		//test si il y a un digit
		if ((valuser_transition % 10) != 0)
		{
			cnt_digit++;
			//suprimme le digit detecté
			valuser_transition = (valuser_transition / 10);
		}



	//tanque le nombre de digit n est pas totalement detecté
	} while (valuser_transition != 0);
	//-- fin de boucle -> égal à 0

	//-- MAJ du membre parents -> nbrDigitEntier 
	m_nbrDigitMaxValEntier  = cnt_digit;

}



//----------------------------------------------------------------------------------//
// Nom de la méthode	: RecupererDigitEntier 
// Entrée				: valUser		-> reel		-> 4 octets  
// Sortie				: 
// in-out				: 
// Description			: détermine la valeur de chaque digit et l'enregistre dans 
//						  un tableau
// Date modfification	: le 21.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//

void ConversionBCD::RecupererDigitEntier(float valUser)
{
	//-- déclaration variable --// 
	int valuser_transition;
	int cnt_digit = 0;

	valuser_transition = (int)valUser;

	//-- itération pour remplire le tableau de digit --//

	for (size_t i = 0; i < m_nbrDigitMaxValEntier; i++)
	{
		//recuperation du digite puis sauvegadre dans le tableau dans la case correspondnate

		m_ptTbDigitEntier[i] = (valuser_transition % 10) * 10;

		//mise a jour de la valeur entière a sauvegardé
		valuser_transition = (valuser_transition / 10);
	} 
}

//----------------------------------------------------------------------------------//
// Nom de la méthode	: ConversionBinaire
// Entrée				: 
// Sortie				: 
// in-out				: 
// Description			: convertir un valeur décimale selon les attributs de la 
//						  la classe parent 
// Date modfification	: le 22.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
void ConversionBCD::ConversionBinaire()
{

	//-- Creation du tableau dynamique de string en fct des digit entier --// 
	 m_ptTbBinaire[m_nbrDigitMaxValEntier];

	//-- déclaration de variable --//
	std::string Mot_bin = "default value";
	int ValueToConvert;


	//-- boucle d'itération pour pour chaque digit --// 

	for (size_t i = 0; i < m_nbrDigitMaxValEntier; i++)
	{
		//-- MAJ de la valeur à convertir --// 
		ValueToConvert = m_ptTbDigitEntier[1];

		// Utilisation de std::bitset pour convertir l'entier en binaire
		Mot_bin = std::bitset<sizeof(unsigned int) * 8>(ValueToConvert).to_string();

		//-- MAJ du tabelau string --// 
		m_ptTbBinaire[i] = Mot_bin;


	}
}