//-----------------------------------------------------------------------------------//
// Nom du projet 		: Conversion Numérique 
// Nom du fichier 		: ConversionBCD.h
// Date de création 	: 11.03.2024
// Date de modification : 25.03.2024
//
// Auteur 				: Philou (Ph. Bovey)
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
		//-- attribut --// 
		//-> visibilité 
		//--> public
		//--> protected 
		//--> private 

		//-- prototype -> constructeur --//
		//-> visibilité 
public:
	ConversionBCD();

	ConversionBCD(e_codageBinaire choixCodage, float valUser);

		//--> public
		//--> protected 
		//--> private 


		//-- prototype -> destructeur --//
		//-> visibilité 
		//--> public
public:
	~ConversionBCD();
		//--> protected 
		//--> private 


		//-- prototype -> méthode --//
		//-> visibilité 
		//--> public 
		//--> protected
		//--> private
private:
	void CalculerNbrDigitEntier(float valUser);
	void RecupererDigitEntier(float valUser);
	void ConversionBinaire(void);

};

#endif // !CONV_NUM


