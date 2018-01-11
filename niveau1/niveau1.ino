/**
 *  Créé par Tatiana Grange, pour zBis et LeChaudron.io, sous licence CC-BY-SA 4.0
 *  Ce code est un petit jeu : la carte Arduino choisie un nombre et on doit le trouver dans le moniteur série
 */

/********** Variables **********/
// Les variables sont comme des bouts de papier sur lesquels on écrit au crayon à papier. 
// On peut remplacer le contenu de la variable en gommant et en écrivant la nouvelle valeur au crayon à papier

int devine = 0; //C'est dans cette variable que la carte Arduino va écrire le chiffre qu'elle choisie


/********** Fonctions **********/

/*La fonction setup est la toute première exécutée par la carte Arduino.*/
void setup() {
  Serial.begin(9600);                     // Utile pour trouver les bugs, Serial permet d'écrire dans le moniteur Série. 
                                          // C'est ce qui nous servira à communiquer avec Arduino
                                          // Ici, on écrira sur le canal 9600.
  
  randomSeed(analogRead(0));              // Un ordinateur est incapable de choisir "au hasard". Il a besoin qu'on lui donne un point de départ.
                                          // Cette ligne sert à donner ce point de départ.
  
  devine = random(1, 20);                 // La carte Arduino écrit dans la variable "devine" le chiffre tiré au hasard grâce à "random".
                                          // Ici, la carte prend un nombre entre 1 et 20
  
  Serial.println("J'ai choisi un nombre entre 1 et 20 ! Essaye de le trouver !");
}


/*La fonction loop est appelée en boucle par la carte Arduino*/
void loop() {
  // Il faut aller lire en permanence sur le port série. Pour ça, on utilise une boucle while.
  // Si il n'y a rien d'écrit sur le port série, Arduino ne rentre pas dans la boucle.
  
  while (Serial.available() > 0) {
    // Il y a quelque chose sur le port série.
    
    int data = Serial.parseInt();         // Ici, on récupère ce qu'il y a sur le port série
                                          // On ne s'intéresse qu'au chiffres entiers (integer en anglais)
                                          // parseInt est là pour préciser que c'est un entier
    
    // Il faut ensuite préciser si le chiffre récupéré est au dessus ou en dessous du nombre à deviner
    if(data < devine){                    // Ici, data est plus petit
      Serial.println("Essaye plus grand !");
    }else if(data > devine){              // Ici, data est plus grand
      Serial.println("Essaye plus petit !");
    }else{                                // S'il n'est ni plus grand, ni plus petit, 
                                          // c'est que le chiffre est correct
      Serial.print("C'est bien ");
      Serial.print(devine);
      Serial.print(" ! ");
      Serial.println("Bravo ! Redémarre la carte pour recommencer.");
    }
  }
}
