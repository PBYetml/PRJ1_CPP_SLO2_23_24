//-----------------------------------------------------------------------------------//
// Nom du projet 		: Conversion Numérique 
// Nom du fichier 		: user.cpp
// Date de création 	: 08.03.2024
// Date de modification : 22.03.2024
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : ce programme est relié au projet n°1 C++ - SLO2
//
// Remarques			: conversion string en float 
//						  https://cplusplus.com/reference/string/stof/           
//----------------------------------------------------------------------------------//

//-- librairie standart --// 
#include <iostream>		//-- utilisation des entrées / sorties 
#include <string>		

//-- librairie personnelle --// 
#include "User.h"

//----------------------------------------------------------------------------------//
// Nom de la méthode	: user - ATTENTION -> constructeur
// Entrée				: limitmax	-> entier	-> 16bits 
//						  limitmin	-> entier	-> 16bits 
// Sortie				: -
// in-out				: - 
// Description			: permet d'afficher différents msg selon le choix de 
//						  l'utilsateur 
// Date modfification	: le 11.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
user::user(short limitmax, short limitmin) : CST_VAL_LIMIT_MAX(limitmax), CST_VAL_LIMIT_MIN(limitmin)
{
	// ne fait rien juste à initialiser les cst lié à l'objet
}


//----------------------------------------------------------------------------------//
// Nom de la méthode	: AfficherMsgUser
// Entrée				: msg	-> enumération	-> e_MsgInfo (class User) 
// Sortie				: -
// in-out				: - 
// Description			: permet d'afficher différents msg selon le choix de 
//						  l'utilsateur 
// Date modfification	: le 11.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
void user::AfficherMsgUser(user::e_MsgInfo msg)
{
	//-- déclaration variable --// 

	//-- condition d'affichage --// 
	//-> switch case 
	switch (msg)
	{
		//-- msg 1 : 
	case user::e_MsgInfo::message1:
		std::cout << "Inserez un nombre (ex: 3.00)  : ";
		break;
	case user::e_MsgInfo::message2:
		std::cout << "!! Erreur !! -> valeur hors limite" << std::endl;
		break;
	case user::e_MsgInfo::message3:
		std::cout << "!! Erreur !! -> valeur entière " << std::endl;
		break;
	default:
		break;
	}
}

//----------------------------------------------------------------------------------//
// Nom de la méthode	: GetNumberValue
// Entrée				: -
// Sortie				: valUser_m -> reel -> attribut privé 
// in-out				: - 
// Description			: permet d'obtenir un attribut specifique de la class USER
// Date modfification	: le 19.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
float user::GetNumberValue()
{
	return valUser_m;
}







//----------------------------------------------------------------------------------//
// Nom de la méthode	: SetNumberValue
// Entrée				: -
// Sortie				: -
// in-out				: - 
// Description			: récupère une valeur numérique (entier ou réel) 
// Date modfification	: le 11.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
float user::SetNumberValue()
{
	//-- déclaration variables --// 
	float valConvReel;

	//-- déclaration d'objet --//
	std::string valUser;

	//-- récupération info clavier -> string --// 
	std::cin >> valUser;

	//-- conversion string en float --// 
	valConvReel = std::stof(valUser);

	//-- retour de la valeur de l'utilisateur --// 
	return valConvReel;
}

//----------------------------------------------------------------------------------//
// Nom de la méthode	: ValiderValUser
// Entrée				: valATester	-> reel		-> 4bytes
// Sortie				: checkValeur	-> entier	-> vrai / faux 
// in-out				: - 
// Description			: 
// Date modfification	: le 11.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
bool user::ValiderValUser(float valATester)
{
	//-- déclaration de variable --//
	bool checkValeur = false;

	float difference;

	//-- test si valATester dans les limites --// 
	if ((valATester < CST_VAL_LIMIT_MAX) && (valATester >= CST_VAL_LIMIT_MIN))
	{
		//-- calcul pour savoir si il y a une différence entre valeur réelle et entière 
		difference = valATester - (int)valATester;

		//-- test si valeur est entière 
		if (difference == (float)0.0)
		{
			checkValeur = true;
			valUser_m = valATester;
		}
		else
		{
			//-- message user : non réel 
			this->AfficherMsgUser(e_MsgInfo::message3);
			checkValeur = false;
		}
	}
	else
	{
		//-- message user : hors lîmit 
		this->AfficherMsgUser(e_MsgInfo::message2);
		checkValeur = false;
	}

	return checkValeur;
}

//----------------------------------------------------------------------------------//
// Nom de la méthode	: AfficherValConvertie
// Entrée				: objAConvertir ->	ConversionNumerique	-> objet 
// Sortie				: 
// in-out				: - 
// Description			: 
// Date modfification	: le 22.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
void user::AfficherValConvertie(ConversionNumerique* objAConvertir)
{
	//-- délcaration variable --// 
	char iteration = 0;
	char iterationDigit = '0';
	char digit;

	//-- déclaration objet --// 
	std::string* valeurAfficher;

	//-- récupération chaine de caractère à afficher --// 
	valeurAfficher = objAConvertir->GetValeurConvertie();

	//-- msg user --// 
	std::cout << " valeur BCD : ";

	//-- affichage de la valeur binaire dans le bon sens --//
	//-- iteration 
	for (iteration = 0; iteration < objAConvertir->GetNbrDigitEntier(); iteration++)
	{
		//-- traitement pour chaque chaine de caractère --// 
		//-- afficher 4 digit --// 
		//-- lecture nbr digit disponible --// 
		digit = valeurAfficher[iteration].length();

		//-- préparation de l'affichage pour afficher les zéro 
		std::cout.width(5 - digit);
		std::cout.fill('0');

		//-- iteration permettant de lire le "LSB" en premier 
		for (digit; digit > 0; digit--)
			std::cout << valeurAfficher[iteration][digit - 1];

		//-- affichage d'une espace 
		std::cout << " ";
	}

	//-- retour à la ligne
	std::cout << std::endl;

}
