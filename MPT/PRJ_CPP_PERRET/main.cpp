//-----------------------------------------------------------------------------------//
// Nom du projet 		: Conversion Num�rique 
// Nom du fichier 		: main.cpp
// Date de cr�ation 	: 08.03.2024
// Date de modification : 22.03.2024
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : ce programme est reli� au projet n�1 C++ - SLO2
//
// Remarques :            lien pour la table ASCII :
// 						  -> http://www.asciitable.com/
//----------------------------------------------------------------------------------//

//-- librairie standart --// 
#include <cstdlib>		//-- pour certaine fonction syst�me 
#include <iostream>		//-- utilisation des entr�es / sorties 
#include <string>		//-- lib li� objet de type chaine de caract�re

//-- librairie personnelle --// 
#include "User.h"
#include "ConversionNum.h"
#include "ConversionBCD.h"

//-- d�finition propre � ce fichier --// 
#define NUM_PRJ	01 
#define VERSION 01 

//-- programme principale --// 
int main(void)
{
	//-- d�claration d'objet allocation statique --// 
	const std::string infoDev_o = "Philou";					// objet de type string 

	user actionUser_o((unsigned short)10000, 0);			// objet utilisateur -> gestion d'affichage 

	//-- d�claration d'objet allocation dynamique --// 

	//-- d�claration variables 
	bool validationValUser;
	float valUser = 0.0;

	//-- message bienvenu projet --// 
	//-> configuration affichage 
	std::cout << "PROJET ";
	//-> PARTIE A 
	std::cout.width(2);			// afficher 2 �l�ment 
	std::cout.fill('0');		// si champs non remplis -> remplace par 0
	std::cout << NUM_PRJ;
	std::cout << " CPP - Version : ";
	//-> PARTIE B 
	std::cout.width(2);			// afficher 2 �l�ment 
	std::cout.fill('0');		// si champs non remplis -> remplace par 0
	std::cout << VERSION;
	std::cout << " Auteur : " << infoDev_o << std::endl;

	//-- boucle de validation : valeur utilisateur pour conversion --// 
	do
	{
		//-- affichage du premier message --// 
		actionUser_o.AfficherMsgUser(user::e_MsgInfo::message1);

		//-- recup�ration d'une valeur r�el par l'utilistateur 
		//-- et la tester si rentre dans les crit�res
		validationValUser = actionUser_o.ValiderValUser(actionUser_o.SetNumberValue());

	} while (!validationValUser);

	//-- choix de la conversion avec l'envoi de la valeur de l'utilisateur --// 
	actionUser_o.pt_ObjetConversion = new ConversionBCD(ConversionNumerique::e_codageBinaire::BCD, actionUser_o.GetNumberValue());

	//-- affichage de la valeur � convertir --//
	actionUser_o.AfficherValConvertie(actionUser_o.pt_ObjetConversion);


	// pour la partie debug
	system("pause");

	return 0;
}
