// Nom du fichier: Pacman.h //
// Charles Bertrand //
// Date de création: 14 Décembre 2017 //
// Fichier qui comporte toutes les définitions des fonctions et procédures pour Pacman //

#include "Pacman.h"
#include "sdlclg.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>

using namespace std;

void GererFruit(int& CompteurFruit, Objet Tableau[][Largeur], int Hauteur, Position& Pacman, ImageJeu Jeu, TypeFruit& Fruit, int& FruitRandom)
{
	// Quand le compteur est à 0, on génère un nombre aléatoire //
	if (CompteurFruit == 0)
	{
		FruitRandom = rand() % 4;
	}

	// Dépendant du nombre aléatoire, on lui assigne un fruit //
	switch (FruitRandom)
	{
	case 0:
		Fruit = Cerise;
		break;
	case 1:
		Fruit = Orange;
		break;
	case 2:
		Fruit = Fraise;
		break;
	case 3:
		Fruit = Pomme;
		break;
	}

	// Quand le compteur est plus grand que le temps fruit, dans le tableau, la case est un fruit //
	if (CompteurFruit >= TempsFruit)
	{
		Tableau[11][9] = F;
	}

	// Quand le compteur arrive à 200, le compteur devient -300 est la case du Tableau est vide //
	if (CompteurFruit == 200)
	{
		CompteurFruit = -300;
		Tableau[11][9] = V;
	}

	// Si la position du Pacman est un fruit, la case du Tableau devient vide //
	if (Tableau[Pacman.y][Pacman.x] == F)
	{
		Tableau[Pacman.y][Pacman.x] = V;
	}

	// Empêche que 200 soit affiché pendant longtemps //
	if (CompteurFruit > -280 && CompteurFruit < -200 && Tableau[11][9] == B)
	{
		Tableau[11][9] = V;
	}

	CompteurFruit++;
}

void AfficherPacmanDirection(OrientationImage& Direction, Position Pacman, ImageDirection ImagePacman)
{
	switch (Direction)
	{
	case Right:
		AfficherImage(ImagePacman.Droite, Pacman.x * NbPixelsParCase, Pacman.y * NbPixelsParCase);
		break;
	case Left:
		AfficherImage(ImagePacman.Gauche, Pacman.x * NbPixelsParCase, Pacman.y * NbPixelsParCase);
		break;
	case Up:
		AfficherImage(ImagePacman.Haut, Pacman.x * NbPixelsParCase, Pacman.y * NbPixelsParCase);
		break;
	case Down:
		AfficherImage(ImagePacman.Bas, Pacman.x * NbPixelsParCase, Pacman.y * NbPixelsParCase);
		break;
	default:
		AfficherImage(ImagePacman.Droite, Pacman.x * NbPixelsParCase, Pacman.y * NbPixelsParCase);
		break;
	}
}

void MouvementPacman(Position& Pacman, Objet Tableau[][Largeur], int Hauteur, int& Touche, OrientationImage& Direction)
{

	if (Touche == EVHaut && Pacman.y > 0 && Tableau[Pacman.y - 1][Pacman.x] != M)
	{
		Pacman.y -= 1; // Bouge Pacman en Haut //
		Direction = Up;
	}
	else if (Touche == EVBas && Pacman.y < Hauteur - 1 && Tableau[Pacman.y + 1][Pacman.x] != M)
	{
		Pacman.y += 1; // Bouge Pacman en Bas //
		Direction = Down;

	}
	else if (Touche == EVGauche && Pacman.x >= 0)
	{
		if (Pacman.x == 0 && Tableau[Pacman.y][Largeur - 1] != M) // Code pour le téléporteur à gauche //
		{
			Pacman.x = 19;
		}
		if (Tableau[Pacman.y][Pacman.x - 1] != M)
		{
			Pacman.x -= 1; // Bouge Pacman à Gauche //
		}

		Direction = Left;
	}
	else if (Touche == EVDroite && Pacman.x <= Largeur - 1)
	{
		if (Pacman.x == 18 && Tableau[Pacman.y][0] != M) // Code pour le téléporteur à droite //
		{
			Pacman.x = -1;
		}
		if (Tableau[Pacman.y][Pacman.x + 1] != M)
		{
			Pacman.x += 1; // Bouge le Pacman à droite //
		}

		Direction = Right;
	}
}

void MouvementHaut(Position& Fantome)
{
	Fantome.X = Fantome.x;
	Fantome.Y = Fantome.y;
	Fantome.y -= 1;
}

void MouvementBas(Position& Fantome)
{
	Fantome.X = Fantome.x;
	Fantome.Y = Fantome.y;
	Fantome.y += 1;
}

void MouvementDroite(Position& Fantome)
{
	Fantome.X = Fantome.x;
	Fantome.Y = Fantome.y;
	Fantome.x += 1;

}

void MouvementGauche(Position& Fantome)
{
	Fantome.X = Fantome.x;
	Fantome.Y = Fantome.y;
	Fantome.x -= 1;


}

void AfficherCarte(Objet Tableau[][Largeur], int Hauteur, ImageJeu Jeu, int& Score, TypeFruit& Fruit)
{
	for (int x = 0; x < Largeur; x++)
	{
		for (int y = 0; y < Hauteur; y++)
		{
			if (Tableau[y][x] == M) // Pour l'affichage du mur //
			{
				AfficherImage(Jeu.ImageMur, x * NbPixelsParCase, y * NbPixelsParCase);
			}
			else if (Tableau[y][x] == P) // Pour l'affichage des points //
			{
				AfficherImage(Jeu.ImagePoint, x * NbPixelsParCase, y * NbPixelsParCase);
				Score++; // Pour chaque point sur la carte il y a un point //
			}
			else if (Tableau[y][x] == PW) // Pour l'affiches des power //
			{
				AfficherImage(Jeu.ImagePower, x * NbPixelsParCase, y * NbPixelsParCase);
			}
			else if (Tableau[y][x] == F) // Pour l'affichage des fruits //
			{
				switch (Fruit)
				{
				case Cerise:
					AfficherImage(Jeu.ImageCerise, 9 * NbPixelsParCase, 11 * NbPixelsParCase);
					break;
				case Orange:
					AfficherImage(Jeu.ImageOrange, 9 * NbPixelsParCase, 11 * NbPixelsParCase);
					break;
				case Fraise:
					AfficherImage(Jeu.ImageFraise, 9 * NbPixelsParCase, 11 * NbPixelsParCase);
					break;
				case Pomme:
					AfficherImage(Jeu.ImagePomme, 9 * NbPixelsParCase, 11 * NbPixelsParCase);
				}
			}
			else if (Tableau[y][x] == B) // Pour l'affichage de l'image 200 //
			{
				AfficherImage(Jeu.ImagePoint200, 150, 243);
			}

		}
	}
}

void GererKeyEvent(int& KeyEvent, Objet Tableau[][Largeur], int Hauteur, bool& Fermer, Position& Pacman, OrientationImage& Direction)
{
	KeyEvent = LireEvenement();
	if (KeyEvent == EVQuitter)
	{
		Fermer = true;
	}
	else if (KeyEvent == EVHaut)
	{
		MouvementPacman(Pacman, Tableau, Hauteur, KeyEvent, Direction);
	}
	else if (KeyEvent == EVBas)
	{
		MouvementPacman(Pacman, Tableau, Hauteur, KeyEvent, Direction);
	}
	else if (KeyEvent == EVGauche)
	{
		MouvementPacman(Pacman, Tableau, Hauteur, KeyEvent, Direction);
	}
	else if (KeyEvent == EVDroite)
	{
		MouvementPacman(Pacman, Tableau, Hauteur, KeyEvent, Direction);
	}

}

void PacmanMangerObjet(int &Score, Objet Tableau[][Largeur], int Hauteur, Position Pacman, int& CompteurFruit, int& NombrePoint)
{
	if (Tableau[Pacman.y][Pacman.x] == P)
	{
		Tableau[Pacman.y][Pacman.x] = V;
		Score--; // Enlève un point lorsque Pacman passe dessus un Point //
		NombrePoint++;
	}

	if (Tableau[Pacman.y][Pacman.x] == F)
	{
		Tableau[Pacman.y][Pacman.x] = B; // Cette Case devient la case qui va afficher 200 //
		NombrePoint += 200;
		CompteurFruit = -300;
	}
}

void AvantPartie(ImageJeu Jeu, Position Pacman, Position Pokey, Position Speedy, Position Shadow, Position Bashful, ImageDirection ImagePacman)
{
	PlaySound(TEXT("Musique\\Pacman.wav"), NULL, SND_FILENAME | SND_ASYNC);
	AfficherImage(Jeu.ImageBashful, Bashful.x*NbPixelsParCase, Bashful.y*NbPixelsParCase);
	AfficherImage(Jeu.ImagePokey, Pokey.x*NbPixelsParCase, Pokey.y*NbPixelsParCase);
	AfficherImage(Jeu.ImageShadow, Shadow.x*NbPixelsParCase, Shadow.y*NbPixelsParCase);
	AfficherImage(Jeu.ImageSpeedy, Speedy.x*NbPixelsParCase, Speedy.y*NbPixelsParCase);
	AfficherImage(ImagePacman.Droite, Pacman.x * NbPixelsParCase, Pacman.y * NbPixelsParCase);
	AfficherImage(Jeu.ImageReady, 140, 243);
}

void VerifierPacmanMange(int Fuite, bool& PacmanMort, Position Pacman, Position& Pokey, Position& Shadow, Position& Bashful, Position& Speedy)
{
	if (Fuite == 0)
	{
		// Pacman mort lorsqu'il se fait manger par Pokey //
		if (Pacman.y == Pokey.y && Pacman.x == Pokey.x)
		{
			PlaySound(TEXT("Musique\\PacmanMort.wav"), NULL, SND_FILENAME | SND_ASYNC); // Produit un son lorsque Pacman se fait manger //
			PacmanMort = true;
		}

		// Pacman mort lorsqu'il se fait manger par Bashful //
		else if (Pacman.y == Bashful.y && Pacman.x == Bashful.x)
		{
			PlaySound(TEXT("Musique\\PacmanMort.wav"), NULL, SND_FILENAME | SND_ASYNC); // Produit un son lorsque Pacman se fait manger //
			PacmanMort = true;
		}

		// Pacman mort lorsqu'il se fait manger par Shadow //
		else if (Pacman.y == Shadow.y && Pacman.x == Shadow.x)
		{
			PlaySound(TEXT("Musique\\PacmanMort.wav"), NULL, SND_FILENAME | SND_ASYNC); // Produit un son lorsque Pacman se fait manger //
			PacmanMort = true;
		}

		// Pacman mort lorsqu'il se fait manger par Speedy //
		else if (Pacman.y == Speedy.y && Pacman.x == Speedy.x)
		{
			PlaySound(TEXT("Musique\\PacmanMort.wav"), NULL, SND_FILENAME | SND_ASYNC); // Produit un son lorsque Pacman se fait manger //
			PacmanMort = true;
		}
	}
	else
	{
		if (Pacman.y == Speedy.y && Pacman.x == Speedy.x)
		{
			PlaySound(TEXT("Musique\\PacmanManger.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Speedy.x = 9; Speedy.y = 9;
		}
		if (Pacman.y == Bashful.y && Pacman.x == Bashful.x)
		{
			PlaySound(TEXT("Musique\\PacmanManger.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Bashful.x = 9; Bashful.y = 9;
		}
		if (Pacman.y == Shadow.y && Pacman.x == Shadow.x)
		{
			PlaySound(TEXT("Musique\\PacmanManger.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Shadow.x = 9; Shadow.y = 9;
		}
		if (Pacman.y == Pokey.y && Pacman.x == Pokey.x)
		{
			PlaySound(TEXT("Musique\\PacmanManger.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Pokey.x = 9; Pokey.y = 9;
		}
	}
}

void VerifierGagne(bool Fermer, int Score, ImageJeu Jeu, int NombrePoint)
{
	// Ferme le jeu et affiche l'image que le joueur a perdu //
	if (Fermer == true)
	{
		AfficherImage(Jeu.ImagePerdu, 160, 185);
		RafraichirFenetre();
		Attendre(1000);
	}

	if (Fermer == false)
	{
		if (Score == 0)
		{
			AfficherImage(Jeu.ImageGagne, 160, 185);
			AfficherResultat(NombrePoint);
		}
		else
		{
			AfficherImage(Jeu.ImagePerdu, 160, 185);
			AfficherResultat(NombrePoint);


		}

		// On doit attendre un peu pour être en mesure de bien voir le message de fin de partie //
		RafraichirFenetre();
		Attendre(2500);
	}
}

void AfficherPacmanGagne(Position Pacman, ImageJeu Jeu, OrientationImage Direction, ImageDirection ImagePacman)
{
	// Selon la direction, l'image de Pacman sera différente //
	switch (Direction)
	{
	case Right:
		AfficherImage(ImagePacman.Droite, Pacman.x * NbPixelsParCase, Pacman.y * NbPixelsParCase);
		break;
	case Left:
		AfficherImage(ImagePacman.Gauche, Pacman.x * NbPixelsParCase, Pacman.y * NbPixelsParCase);
		break;
	case Up:
		AfficherImage(ImagePacman.Haut, Pacman.x * NbPixelsParCase, Pacman.y * NbPixelsParCase);
		break;
	case Down:
		AfficherImage(ImagePacman.Bas, Pacman.x * NbPixelsParCase, Pacman.y * NbPixelsParCase);
		break;
	default:
		AfficherImage(ImagePacman.Droite, Pacman.x * NbPixelsParCase, Pacman.y * NbPixelsParCase);
		break;
	}

}

void FantomeNonChasseur(Position& Fantome, Objet Tableau[][Largeur], int Hauteur, int& NombreRandom)
{
	// Lorsque Pacman est bloqué par le haut, la droite et le bas //
	if (Tableau[Fantome.y + 1][Fantome.x] == M && Tableau[Fantome.y][Fantome.x + 1] == M && Tableau[Fantome.y - 1][Fantome.x] == M)
	{
		MouvementGauche(Fantome);
	}
	// Lorsque Pacman est bloqué par la gauche, le haut et le bas //
	else if (Tableau[Fantome.y][Fantome.x - 1] == M && Tableau[Fantome.y + 1][Fantome.x] == M && Tableau[Fantome.y - 1][Fantome.x] == M)
	{
		MouvementDroite(Fantome);
	}

	// Condition pour que le fantôme se déplace en haut //
	if (Fantome.y - 1 != Fantome.Y && Tableau[Fantome.y - 1][Fantome.x] != M && NombreRandom == 0)
	{
		MouvementHaut(Fantome);
	}
	// Condition pour que le fantôme se déplace en bas //
	else if (Fantome.y + 1 != Fantome.Y && Tableau[Fantome.y + 1][Fantome.x] != M && NombreRandom == 1)
	{
		MouvementBas(Fantome);
	}
	// Condition pour que le fantôme se déplace à gauche //
	else if (Fantome.x - 1 != Fantome.X && Tableau[Fantome.y][Fantome.x - 1] != M && NombreRandom == 2)
	{
		MouvementGauche(Fantome);
	}
	// Condition pour que le fantôme se déplace à droite //
	else if (Fantome.x + 1 != Fantome.X && Tableau[Fantome.y][Fantome.x + 1] != M && NombreRandom == 3)
	{
		MouvementDroite(Fantome);
	}

	// Condition pour que le fantôme se déplace en haut //
	else if (Fantome.y - 1 != Fantome.Y && Tableau[Fantome.y - 1][Fantome.x] != M)
	{
		MouvementHaut(Fantome);
	}
	// Condition pour que le fantôme se déplace en bas //
	else if (Fantome.y + 1 != Fantome.Y && Tableau[Fantome.y + 1][Fantome.x] != M)
	{
		MouvementBas(Fantome);
	}
	// Condition pour que le fantôme se déplace à gauche //
	else if (Fantome.x - 1 != Fantome.X && Tableau[Fantome.y][Fantome.x - 1] != M)
	{
		MouvementGauche(Fantome);
	}
	// Condition pour que le fantôme se déplace à droite //
	else if (Fantome.x + 1 != Fantome.X && Tableau[Fantome.y][Fantome.x + 1] != M)
	{
		MouvementDroite(Fantome);
	}

}

void FantomeChasseur(Position& Fantome, Position Pacman, Objet Tableau[][Largeur], int Hauteur, int& NombreRandom)
{
	// Empêche les fantômes d'accéder au téléporteur //
	if (Fantome.y == 9 && Fantome.x == 0)
	{
		Fantome.X = 19;
	}
	else if (Fantome.y == 9 && Fantome.x == 18)
	{
		Fantome.X = -1;
	}

	// Code qui permet aux fantômes de suivre Pacman selon sa Position //
	if (Fantome.y - 1 != Fantome.Y && Tableau[Fantome.y - 1][Fantome.x] != M && Fantome.y > Pacman.y)
	{
		// Permet aux fantômex d'ajuster leur Position en connaissant si la Position de Pacman est plus grande ou plus petite //
		MouvementHaut(Fantome); // Haut //
	}
	else if (Fantome.y + 1 != Fantome.Y && Tableau[Fantome.y + 1][Fantome.x] != M && Fantome.y < Pacman.y)
	{
		// Permet aux fantômex d'ajuster leur Position en connaissant si la Position de Pacman est plus grande ou plus petite //
		MouvementBas(Fantome); // Bas //

	}
	else if (Fantome.x - 1 != Fantome.X && Tableau[Fantome.y][Fantome.x - 1] != M && Fantome.x > Pacman.x)
	{   // Permet aux fantômex d'ajuster leur Position en connaissant si la Position de Pacman est plus grande ou plus petite //
		MouvementGauche(Fantome); // Gauche //

	}
	else if (Fantome.x + 1 != Fantome.X && Tableau[Fantome.y][Fantome.x + 1] != M && Fantome.x < Pacman.x)
	{   // Permet aux fantômes d'ajuster leur Position en connaissant si la Position de Pacman est plus grande ou plus petite //
		MouvementDroite(Fantome); // Droite //

	}
	else
	{
		FantomeNonChasseur(Fantome, Tableau, Hauteur, NombreRandom);
	}

}

void DemarrerCompteur(int& Compteur, int& NombreRandom, Objet Tableau[][Largeur], int Hauteur, Position& Pacman, Position& Pokey, Position& Shadow, Position& Bashful, Position& Speedy, int& Fuite)
{

	if (Fuite > 0)
	{
		Fuite--;
	}

	// Permet de déplacer les fantôme un tour sur 10 sinon c'est trop dur. Le compteur est remis à 0 //
	// Pour augmenter la difficulté, ajuster la VitesseFantome //
	if (VitesseFantome <= Compteur)
	{
		Compteur = 0;
	}

	if (!Compteur)
	{
		// Déplacment de Pokey //
		NombreRandom = rand() % 4; // Génère un nombre entre 0 et 3 qui va permettre aux fantôme de se déplacer dans une certaine direction //
		if (Fuite == 0)
		{
			FantomeNonChasseur(Pokey, Tableau, Hauteur, NombreRandom);
		}
		else
		{
			FantomeFuite(NombreRandom, Pokey, Pacman, Tableau, Hauteur);
		}

		// Deplacement pour Bashful //
		NombreRandom = rand() % 4; // Génère un nombre entre 0 et 3 qui va permettre aux fantôme de se déplacer dans une certaine direction //
		if (Fuite == 0)
		{
			FantomeNonChasseur(Bashful, Tableau, Hauteur, NombreRandom);
		}
		else
			FantomeFuite(NombreRandom, Bashful, Pacman, Tableau, Hauteur);
		


		// Déplacement pour Shadow //
		NombreRandom = rand() % 4; // Génère un nombre entre 0 et 3 qui va permettre aux fantôme de se déplacer dans une certaine direction //
		if (Fuite == 0)
		{
			FantomeChasseur(Shadow, Pacman, Tableau, Hauteur, NombreRandom);
		}
		else
		{
			FantomeFuite(NombreRandom, Shadow, Pacman, Tableau, Hauteur);
		}


		// Déplacement de Speedy //
		NombreRandom = rand() % 4; // Génère un nombre entre 0 et 3 qui va permettre aux fantôme de se déplacer dans une certaine direction //
		if (Fuite == 0)
		{
			FantomeChasseur(Speedy, Pacman, Tableau, Hauteur, NombreRandom);
		}
		else
		{
			FantomeFuite(NombreRandom, Speedy, Pacman, Tableau, Hauteur);
		}

	}

	Compteur++;
}

void FantomeFuite(int NombreRandom, Position& Fantome, Position Pacman, Objet Tableau[][Largeur], int Hauteur)
{

	// Empêche les fantômes d'accéder au téléporteur //
	if (Fantome.y == 9 && Fantome.x == 0)
	{
		Fantome.X = 19;
	}
	else if (Fantome.y == 9 && Fantome.x == 18)
	{
		Fantome.X = -1;
	}
	// Muvement des chasseurs mais en inversé //
	if (Fantome.y < Pacman.y && Fantome.y - 1 != Fantome.Y && Tableau[Fantome.y - 1][Fantome.x] != M)
	{
		
		MouvementHaut(Fantome); // Haut //
	}
	else if (Fantome.y > Pacman.y && Fantome.y + 1 != Fantome.Y && Tableau[Fantome.y + 1][Fantome.x] != M)
	{
		
		MouvementBas(Fantome); // Bas //

	}
	else if (Fantome.x < Pacman.x && Fantome.x - 1 != Fantome.X && Tableau[Fantome.y][Fantome.x - 1] != M)
	{  
		MouvementGauche(Fantome); // Gauche //

	}
	else if (Fantome.x > Pacman.x && Fantome.x + 1 != Fantome.X && Tableau[Fantome.y][Fantome.x + 1] != M)
	{   
		MouvementDroite(Fantome); // Droite //

	}
	else
	{
		FantomeNonChasseur(Fantome, Tableau, Hauteur, NombreRandom);
	}
}

void DemarrerFuite(Objet Tableau[][Largeur], int Hauteur, Position& Pacman, int& Fuite)
{
	if (Tableau[Pacman.y][Pacman.x] == PW)
	{
		Tableau[Pacman.y][Pacman.x] = V;
		Fuite = 150;
		PlaySound(TEXT("Musique\\PacmanFuite.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
}

void AfficherFinPartie(ImageJeu Jeu, Position Pokey, Position Speedy, Position Bashful, Position Shadow)
{
	AfficherImage(Jeu.ImageBashful, Bashful.x*NbPixelsParCase, Bashful.y*NbPixelsParCase);
	AfficherImage(Jeu.ImagePokey, Pokey.x*NbPixelsParCase, Pokey.y*NbPixelsParCase);
	AfficherImage(Jeu.ImageShadow, Shadow.x*NbPixelsParCase, Shadow.y*NbPixelsParCase);
	AfficherImage(Jeu.ImageSpeedy, Speedy.x*NbPixelsParCase, Speedy.y*NbPixelsParCase);
}

void AfficherFantome(int Fuite, ImageJeu Jeu, Position Speedy, Position Pokey, Position Bashful, Position Shadow, Objet Tableau[][Largeur], int Hauteur)
{

	if (Fuite == 0) // Affichage en mode normal //
	{
		AfficherImage(Jeu.ImageBashful, Bashful.x*NbPixelsParCase, Bashful.y*NbPixelsParCase);
		AfficherImage(Jeu.ImagePokey, Pokey.x*NbPixelsParCase, Pokey.y*NbPixelsParCase);
		AfficherImage(Jeu.ImageShadow, Shadow.x*NbPixelsParCase, Shadow.y*NbPixelsParCase);
		AfficherImage(Jeu.ImageSpeedy, Speedy.x*NbPixelsParCase, Speedy.y*NbPixelsParCase);
	}
	// Change les fantomes en blanc pour avertir le joueur //
	else if (Fuite > 2 && Fuite < 25)
	{
		AfficherImage(Jeu.ImageWhite, Bashful.x*NbPixelsParCase, Bashful.y*NbPixelsParCase);
		AfficherImage(Jeu.ImageWhite, Pokey.x*NbPixelsParCase, Pokey.y*NbPixelsParCase);
		AfficherImage(Jeu.ImageWhite, Shadow.x*NbPixelsParCase, Shadow.y*NbPixelsParCase);
		AfficherImage(Jeu.ImageWhite, Speedy.x*NbPixelsParCase, Speedy.y*NbPixelsParCase);
	}
	else // Affichage en mode fuite //
	{
		AfficherImage(Jeu.ImagePeur, Bashful.x*NbPixelsParCase, Bashful.y*NbPixelsParCase);
		AfficherImage(Jeu.ImagePeur, Pokey.x*NbPixelsParCase, Pokey.y*NbPixelsParCase);
		AfficherImage(Jeu.ImagePeur, Shadow.x*NbPixelsParCase, Shadow.y*NbPixelsParCase);
		AfficherImage(Jeu.ImagePeur, Speedy.x*NbPixelsParCase, Speedy.y*NbPixelsParCase);

	}
}

void AfficherResultat(int NombrePoint)
{
	cout << "----------------------" << endl;
	cout << "| Total: " << NombrePoint << " points" << endl;
	cout << "----------------------" << endl;
	cout << "| Bonus: " << NombrePoint / 200 << " fruits" << endl;
	cout << "----------------------";
}