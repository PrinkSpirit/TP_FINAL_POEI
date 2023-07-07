# Fonctionnement de l'algorythme #

## Entreprises (Nom, Trésorerie, Charges/jour, Pourcentage marge) : ##
> La Mine : Fourni toutes les matières premières nécessaire à la fabrication des produits. Ne vend qu'une certaines quantité par jour pour toute les entreprises
	
* La Mine (845 371 €, 5 912 €, 20 %): 			Bois, Fil de cuivre, Inox, Gaines plastique, Granulés plastique, Résine, Tissus, Mousse, Aluminium, Verre
* Verrutil (182 347 €, 1 061 €, 19 %) :			Écrans, Fenêtres, Abris de jardin, Lunettes
* Heavy Metal (550 645 €, 3 418 €, 16 %) : 		Vis, Circuits imprimés, Fil électrique, Ordinateurs, Écrans, Fenêtres
* Fantastic Plastic (198 269 €, 1 982 €, 18 %) :	Circuits imprimés, Coques ordinateurs, Lunettes, Ordinateurs
* Fabric Textil (129 921 €, 1 145 €, 21 %) : 		Matelas, Lits, Canapés, Fauteuils
* Super Bois (415 326 €, 2 987 €, 17 %) : 		Bureau, Fauteuils, Abris de jardin, Lits, Canapés


## Produits : ##
> Produits vendu par les entreprises et matières nécessaires à leurs fabrication

* Fil électrique : Fil de cuivre, Gaines plastique
* Circuit imprimés : Résine, Fil de cuivre
* Écrans : Circuits Imprimes, Fil de cuivre, Verre, Granules plastique, Vis
* Vis : Inox
* Fenêtres : Aluminium, Verre, Vis
* Abris de jardin : Bois, Vis, Fenêtre
* Matelas : Tissus, Mousse
* Bureau : Plaque de bois, Vis, Acier
* Coques ordinateurs : Granules plastique
* Ordinateurs : Ecran, Circuits imprimes, Fil de cuivre, Vis
* Lits : Bois, Vis, Matelas
* Canapés : Bois, Tissus,Mousse
* Lunettes : Verre, Inox
* Fauteuils : Tissus, Mousse, Granules Plastique, Vis


## Fabricatiom sous-produits : ##
> Les sous-produits sont fabriqués par certaines entreprises afin de fabriquer des articles (vis, écrans, circuits imprimés, fenêtres, matelas, coques ordinateurs)

Entreprise veut fabriquer "quantité" de "nomProduit"<br />
Achète "quantité" de "nomMatière" à "LaMine" pour "montant"<br />
Soustraction de "montant" - "trésorerie"<br />
Prix de vente = "montant" + "chargesEntreprises" + "pourcentageMarge"<br />
Enregistrement "nombreProduit" dans le stock<br />
Vend "nomProduit" pour "montant"<br />
Soustraction du stock<br />
Fabrication pour maintient du stock à "quantitéStock" par jour<br />


## Fabrication articles : ##
> Les articles sont la production prête à être vendu aux consommateur.rices

Entreprise fabrique "quantité" de "nomArticle"<br />
Achète "quantité" de "nomMatière" à "LaMine" pour "montant"<br />
Achète "nomProduits" à "nomEntreprise"<br />
Si "nomEntreprise" vend le même produit = concurrent direct donc prix de vente plus cher<br />
Soustraction de "montant" - "trésorerie"<br />
Prix de vente = "montant" + "chargesEntreprises" + "marge"<br />
Enregistrement "nombreProduit" dans le stock<br />
Vend "nomArticle" pour "montant"<br />
Soustraction du stock<br />
Fabrication pour maintient du stock à "quantitéStock" par jour<br />


## Qualité : ##
> Définit la qualité des articles et produit ce qui influera sur les ventes

Attribution du score de qualité à minimum 1 au début. Selon la catégorie du produit et le domaine de l'entreprise (si entreprise de métallurgie vend fil<br />
électrique : qualité supérieur, si entreprise de plastique : qualité inférieur)<br />
Score de qualité augmenté avec la recherche<br />
Augmentation du score de 0.2 à chaque niveau de recherche<br />
Augmentation du prix de vente : "prixVente" x "scoreQualité"<br />


## Recherche et développement : ##
> Augmente la qualité de ses produits afin de les vendrent mieux et plus cher

Entreprise investi "montantInvestissement" pour la recherche et le développement de "nomProduit"<br />
Déduction de "montantInvestissement" - "trésorerie"<br />
Augmentation niveau de recherche + 1<br />
Augmentation du score qualité de 0.2<br />
Augmentation du prix de vente de "nomProduit"<br />


## Exemple déroulement de l'algorythme : ##

1. Choix du produit à fabriquer : "Ordinateurs"
2. Vérification des matières nécessaires à la fabrication : Écrans, Circuits Imprimés, Fil de cuivre, Verre, Granules plastique, Vis
3. "Verrutil" et "Heavy Metal" fabriquent "Écrans" mais "Heavy Metal" et "Fantastic Plastic" fabriquent des "Circuits Imprimés"
4. "Verrutil" et "Heavy Metal" achètent "quantité" de matière à "La Mine" pour la fabrication des écrans
5. "Fantastic Plastic" et "Heavy Metal" achètent "quantité" de matière à "La Mine" pour la fabrication des circuits imprimés
6. Soustraction du montant des achats de matières de la trésorerie de l'entreprise
7. Fabrication des écrans et circuits imprimés lorsque toutes les matières sont acheté et en stock
8. Fabrication des ordinateurs lorsque toutes les pièces nécessaire à la fabrication sont fabriqué et en stock
9. "Heavy Metal" et "Fantastic Plastic" fabriques des ordinateurs
10. Ces deux entreprises achetent selon leurs besoins des sous-produits aux entreprises concurrentes afin de fabriquer les ordinateurs en fonction de la qualité souhaité
11. Fabrication des ordinateurs
12. Ajout des ordinateurs dans le stock des entreprises
13. "Heavy Metal" et "Verrutil" vendent des ordinateur pour "montant"
14. Consommateurs achètent selon le score de qualité
15. Soustraction du montant acheté par consommateurs du stock des entreprises
16. Nouvelle fabrication pour maintenir le stock
