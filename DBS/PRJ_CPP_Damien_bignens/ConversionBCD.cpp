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

//-- librairie personnelle --// 

#include "ConversionBCD.h"

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

ConversionBCD::ConversionBCD()
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
	if (choixCodage == ConversionNumerique::e_codageBinaire::BCD)
	{
		//-- création d'un tableau dynamique via pointeur --// 
		ConversionNumerique::m_ptTbDigitEntier [ConversionNumerique::m_nbrDigitMaxValEntier] ;
	
		//-- appel fonction : détermine le nb de digit du nombre entier --//
		this->CalculerNbrDigitEntier(valUser);

		//-- appel fonction : récuperation de chaque digit --//
		this->RecupererDigitEntier(valUser);

		//-- appel fonction : conversion binaire de chaque digit entier --// 
		this->conversionBinaire();

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
	char valtestuser = valUser;
	char nbdigitetest = 0 ;
	//-- itération pour connaitre le nbr de digit sur une valeur entière

	while (valtestuser != 0 )
	//-- fin de boucle -> égal à 0
	{
		
		valtestuser = valtestuser / 10;//-- division de la valeur entière par des puissance de 10 : 10^0 => (1), 10^1 => (10), 10^2 => (100) ..
									   //-- et MAJ de la valeur entière
		nbdigitetest++;					//-- MAJ du Digit => incrément de 1 --//
	} 


	//ConversionNumerique::m_ptTbDigitEntier = &nbdigitetest;


	//-- MAJ du membre parents -> nbrDigitEntier 
	ConversionNumerique::m_nbrDigitMaxValEntier = nbdigitetest;
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
	char contdigit = 0; 
	char valtestUser = 0;
	//-- itération pour remplire le tableau de digit --//
	while (contdigit <= ConversionNumerique::m_nbrDigitMaxValEntier)
	{
		
		valtestUser = valUser /  pow(10, ConversionNumerique::m_nbrDigitMaxValEntier - (contdigit+1));//-- MAJ facteur de puissance de 10 --// 
		
		valtestUser = valtestUser % 10;	
		//-- MAJ TAbleau -> digit 
		ConversionNumerique::m_ptTbDigitEntier[contdigit] = valtestUser; //pour mettre dans le tableaux ( faux)
		contdigit++; 
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
void ConversionBCD::conversionBinaire()
{

	//-- Creation du tableau dynamique de string en fct des digit entier --// 
	ConversionNumerique::m_ptTbBinaire[ConversionNumerique::m_nbrDigitMaxValEntier];

	//-- déclaration de variable --//
	int i = ConversionNumerique::m_nbrDigitMaxValEntier; 
	char valeaCouvertir = 0; 
	std::string binaryString = "";
	int hexsadesimaldigite  = 4 ;
	//-- boucle d'itération pour pour chaque digit --// 
	for (i ; i >= 0 ; i--)
	{ 
		//-- récupère la valeur du digit à convertir --// 
		valeaCouvertir = ConversionNumerique::m_ptTbDigitEntier[i];
		
		//-- itération de conversion binaire --// 	

			//-- conversion binaire -> modulo 2 (récupère le reste) --//
		for (hexsadesimaldigite - 1; hexsadesimaldigite >= 0; hexsadesimaldigite--)
		{
			//-- récuperation de l'info binaire --//
			// Ajoute 1 ou 0 au string en fonction de la valeur du LSB
			ConversionNumerique::m_ptTbBinaire[i] += ((valeaCouvertir & (1 << i)) != 0) ? "1" : "0";
		}
			
			//-- MAJ de la valeur à convertir --// 
			
			
			//-- MAJ du tabelau string --// 
	}

}

