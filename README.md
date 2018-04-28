# Projects
All projects from Axel COMBE

Fillit :
Un programme qui doit placer des tetriminos (forme de tetris) dans le plus petit carre et le plus en haut a gauche possible. Utilisation du backtracking.

GNL : 
Get_next_line est un programme qui consiste a recuperer une seule ligne d'un fichier. Utilisation de variables statiques. Plus de leaks.

Printf :
Recreer notre propre printf en C.

Push_swap :
Un programme qui consiste a trier une liste de nombres en utilisant deux piles A et B, pour les avoir dans l'ordre croisant. Seuls certaines commandes sont autorises :
RA = Pousser a droite. (pile A, RB pour pile B)
RRA = pousser a gauche.
RR = pousser a droite pour les deux pile.
RRR = pousser a gauche pour les deux piles.
SA = inverser le premier et deuxieme nombre de la pile A. SB pour la pile B, SR pour les deux.
PA = mettrre le premier nombre de la pile B dans la pile A. PB pour l'inverse.
L'objectif etant de faire -7000 coup pour 500 nombre et -700 coups pour 100 nombres.


Lem-in : 
Une carte est generee en donnant des noms a des salles, et en les reliant. Un nombre de fourmis nous est donne. L'objectif est d'amener toutes les fourmis de la salle start a la salle end. Chaque fourmis ne peut en chevaucher une autre, et ne peut se deplacer que d'une case a la fois.

Corewar :
Projet de fin de branche requis pour pqrtir en stage. Projet a 4.
L'objectif est de creer un assembleur qui compilera des champioms fournis dans des fichiers .s pour les tranformes en .cor. Puis une VM qui utilisera ces .cor pour placer les champions dans uen arene de memoire, et les faire combattre. Le dernier champion a dire qu'il est en vie gagne.
Plusieurs commandes sont disponibles :
live : dire en vie.
ld : load un octet dans un autre avec une distance maximum regulee par un define.
lld : pareil, sans distance max.
ldi : pareil, mais permet de load un octet a l'adresse d'une valeur, et pas forcement la valeur direct du premier octet.
lldi : comme ldi sans distance maximum.
fork : creer un nouveau processus pour un champion avec distance maximum.
lfork : pareil sans distance max.
add : ajouter l'octet qui suit et celui d'apres et stoker le resultat dans le troisieme.
sub : pareil, mais soustrait au lieu d'ajouter.
aff : afficher la memoire.
or : ajoute le premier ou le deuxieme octet dans le troisieme.
st : stock un octet dans un autre.
sti : idem avec la possibilite d'utiliser l'adresse donnee par un octet.
zjmp : saute a l'adresse donnee.
