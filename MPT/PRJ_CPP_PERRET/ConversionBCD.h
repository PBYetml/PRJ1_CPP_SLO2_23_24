//-----------------------------------------------------------------------------------//
// Nom du projet 		: Conversion Numérique 
// Nom du fichier 		: ConversionBCD.h
// Date de création 	: 11.03.2024
// Date de modification : 25.03.2024
//
// Auteur 				: Philou (Ph. Bovey)
// Modification			: Mélissa Perret
//
// Description          : ce programme est relié au projet n°1 C++ - SLO2
//
// Remarques			: si héritage <=> attention la visibilité de la class parent 
//						  doit aussi figurer !!!          
//----------------------------------------------------------------------------------//
#ifndef CONV_BCD
#define CONV_BCD

//-- librairie standart --//


//-- librairie personnelle --//
#include "ConversionNum.h"


class ConversionBCD : public ConversionNumerique
{
public:
	//-- attribut --// 
	//-> visibilité 
	//--> public
	//--> protected 
	//--> private 

	//-- prototype -> constructeur --//
	ConversionBCD();
	//-> visibilité 
	//--> public
	//--> protected 
	//--> private 


	//-- prototype -> destructeur --//
	~ConversionBCD();
	//-> visibilité 
	//--> public
	//--> protected 
	//--> private 

	//-- prototype -> méthode --//
public:
	ConversionBCD(e_codageBinaire choixCodage, float valUser);

	//-> visibilité 
	//--> public 
	//--> protected
	//--> private
private:
	void CalculerNbrDigitEntier(float valUser);
	void RecupererDigitEntier(float valUser);
	void ConversionBinaire();
};

#endif // !CONV_NUM


