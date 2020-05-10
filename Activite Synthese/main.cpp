// Nom du fichier: main.cpp //
// Charles Bertrand //
// Date de création: 14 Décembre 2017 //
// Code du Programme principal //

#include "Pacman.h"
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
	// Permet de générer les nombres aléatoires plus tard //
	srand(static_cast<unsigned int>(time(0)));

	// Permet de créer une fenêtre graphique //
	InitialiserAffichage("Pacman Charles Bertrand", Largeur*NbPixelsParCase, Hauteur*NbPixelsParCase);

	// Déclaration de la Structure Jeu qui va servir à charger les images en mémoire //
	// Déclaration de la Structure ImagePacman qui va contenir les quatres images de Pacman //
	ImageJeu Jeu;
	ImageDirection ImagePacman;

	// Charge les images en mémoire //
	ImagePacman.Droite = ChargerImage("Image\\pacman.bmp");
	ImagePacman.Gauche = ChargerImage("Image\\pacman2.bmp");
	ImagePacman.Haut = ChargerImage("Image\\pacman3.bmp");
	ImagePacman.Bas = ChargerImage("Image\\pacman4.bmp");
	Jeu.ImageBashful = ChargerImage("Image\\bashful.bmp");
	Jeu.ImagePokey = ChargerImage("Image\\pokey.bmp");
	Jeu.ImageShadow = ChargerImage("Image\\shadow.bmp");
	Jeu.ImageSpeedy = ChargerImage("Image\\speedy.bmp");
	Jeu.ImageMur = ChargerImage("Image\\mur.bmp");
	Jeu.ImagePoint = ChargerImage("Image\\point.bmp");
	Jeu.ImageGagne = ChargerImage("Image\\gagne.bmp");
	Jeu.ImagePerdu = ChargerImage("Image\\perdu.bmp");
	Jeu.ImageReady = ChargerImage("Image\\ready.bmp");
	Jeu.ImagePower = ChargerImage("Image\\power.bmp");
	Jeu.ImagePeur = ChargerImage("Image\\peur.bmp");
	Jeu.ImageCerise = ChargerImage("Image\\cerise.bmp");
	Jeu.ImageFraise = ChargerImage("Image\\fraise.bmp");
	Jeu.ImageOrange = ChargerImage("Image\\orange.bmp");
	Jeu.ImagePomme = ChargerImage("Image\\pomme.bmp");
	Jeu.ImageWhite = ChargerImage("Image\\ghost.bmp");
	Jeu.ImagePoint200 = ChargerImage("Image\\200points.bmp");

	// Tableau représentant la carte(Map) du jeu //
	Objet Tableau[Hauteur][Largeur] =
	{
	{ M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M },
	{ M, PW, P, P, P, P, P, P, P, M, P, P, P, P, P, P, P, PW, M },
	{ M, P, M, M, P, M, M, M, P, M, P, M, M, M, P, M, M, P, M },
	{ M, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, M },
	{ M, P, M, M, P, M, P, M, M, M, M, M, P, M, P, M, M, P, M },
	{ M, P, P, P, P, M, P, P, P, M, P, P, P, M, P, P, P, P, M },
	{ M, M, M, M, P, M, M, M, V, M, V, M, M, M, P, M, M, M, M },
	{ V, V, V, M, P, M, V, V, V, V, V, V, V, M, P, M, V, V, V },
	{ M, M, M, M, P, M, V, M, M, V, M, M, V, M, P, M, M, M, M },
	{ V, V, V, V, P, V, V, M, V, V, V, M, V, V, P, V, V, V, V },
	{ M, M, M, M, P, M, V, M, M, V, M, M, V, M, P, M, M, M, M },
	{ V, V, V, M, P, M, V, V, V, V, V, V, V, M, P, M, V, V, V },
	{ M, M, M, M, P, M, V, M, M, M, M, M, V, M, P, M, M, M, M },
	{ M, P, P, P, P, P, P, P, P, M, P, P, P, P, P, P, P, P, M },
	{ M, P, M, M, P, M, M, M, P, M, P, M, M, M, P, M, M, P, M },
	{ M, P, P, M, P, P, P, P, P, P, P, P, P, P, P, M, P, P, M },
	{ M, M, P, M, P, M, P, M, M, M, M, M, P, M, P, M, P, M, M },
	{ M, P, P, P, P, M, P, P, P, M, P, P, P, M, P, P, P, P, M },
	{ M, P, M, M, M, M, M, M, P, M, P, M, M, M, M, M, M, P, M },
	{ M, PW, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, PW, M },
	{ M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M, M }
	};

	// Déclaration des Positions de chaque fantôme et de Pacman //
	Position Pacman;
	Position Bashful;
	Position Pokey;
	Position Shadow;
	Position Speedy;

	// Déclaration de la Structure PacmanDirection //
	OrientationImage PacmanDirection;

	// Position des fantômes et pacman avec la structure Position //
	Pacman.x = 9; Pacman.y = 15;
	Shadow.x = 9; Shadow.y = 8;
	Bashful.x = 8; Bashful.y = 9;
	Pokey.x = 10; Pokey.y = 9;
	Speedy.y = 9; Speedy.x = 9;

	// Déclaration des variables //
	int Compteur = 0, CompteurFruit = 0;
	bool PacmanMort = false, Fermer = false;
	int NombreRandom, KeyEvent, Score, Fuite = 0, FruitRandom = 0, NombrePoint = 0;
	
	// Énumération pour les fruits //
	TypeFruit Fruit;

	// Affiche la carte du jeux avant la partie pour voir le message ready //
	AfficherCarte(Tableau, Hauteur, Jeu, Score, Fruit);

	// Affiche le message ready en début de partie //
	AvantPartie(Jeu, Pacman, Pokey, Speedy, Shadow, Bashful, ImagePacman);
	RafraichirFenetre();
	Attendre(5500); // Donne le temps de voir le message ready //

	// Boucle principale du jeu //
	do
	{
		// Remplie la fenêtre en noir pour être en mesuer d'aller sur le vide sans que les Position se duplique //
		RemplirFenetre(0, 0, 0);
		Score = 0;

		// Affiche la carte du jeux après le message ready //
		AfficherCarte(Tableau, Hauteur, Jeu, Score, Fruit);

		// Affiche Pacman à sa Position //												
		AfficherPacmanDirection(PacmanDirection, Pacman, ImagePacman);

		// Affiche les fantômes à leur Position respective //
		AfficherFantome(Fuite, Jeu, Speedy, Pokey, Bashful, Shadow, Tableau, Hauteur);
		
		// Permet de contrôler l'affichage random des fruits //
		GererFruit(CompteurFruit, Tableau, Hauteur, Pacman, Jeu, Fruit, FruitRandom);
	
		// Permet de déplacer Pacman selon la touche appuyé //
		// Evenement KeyEvent va servir à détecter quelle touche est appuyée //
		GererKeyEvent(KeyEvent, Tableau, Hauteur, Fermer, Pacman, PacmanDirection);

		// Permet d'enlever les point quand Pacman passe dessus //
		PacmanMangerObjet(Score, Tableau, Hauteur, Pacman, CompteurFruit, NombrePoint);
		// Procédure qui va démarrer le Compteur et donc permettre de déplacer les fantôme au 10 tours ce qui va donner une chance au joueur //
		DemarrerCompteur(Compteur, NombreRandom, Tableau, Hauteur, Pacman, Pokey, Shadow, Bashful, Speedy, Fuite);
		
		DemarrerFuite(Tableau, Hauteur, Pacman, Fuite);
		// Procédure qui vérifie si Pacman à été mangé par un des fantômems //
		VerifierPacmanMange(Fuite, PacmanMort, Pacman, Pokey, Shadow, Bashful, Speedy);

		// Permet de rafraichir la fenêtre //
		RafraichirFenetre();
		
		// Attendre(30) permet de ralentir le jeu //
		Attendre(30);	
		
	} while (!PacmanMort && Score != 0 && KeyEvent != EVQuitter); // Tante que le joueur n'a pas fermé, que le nombre de point n'est pas 0 et que Pacman ne soit pas mort. Le jeu va continuer //


	// Remplie la fenêtre en noir pour être en mesuer d'aller sur le vide dans que notre personne se duplique //
	RemplirFenetre(0, 0, 0);

	// Affiche Pacman quand il gagane sinon il n'y a rien après //
	AfficherPacmanGagne(Pacman, Jeu, PacmanDirection, ImagePacman);

	// Affiche chaque fantôme pour qu'il soit par-dessus le Pacman lorsqu'il va le manger sinon il sera toujours une case avant lui ce qui rend le jeu très moche //
	AfficherFinPartie(Jeu, Pokey, Speedy, Bashful, Shadow);
	AfficherCarte(Tableau, Hauteur, Jeu, Score, Fruit);

	// Vérifie sur si gagne ou perdu et si le joueur quitter la partie et si le joueur ferme la partie, le message ImagePerdu sera affiché //
	VerifierGagne(Fermer, Score, Jeu, NombrePoint);

	// Permet de fermer la fenêtre	//
	QuitterAffichage();
	return 0;
}
